#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexer.h"
#include "tokens.h"

/* Portable strdup replacement */
static char *my_strdup(const char *s) {
    if (!s) return NULL;
    size_t n = strlen(s) + 1;
    char *p = malloc(n);
    if (!p) return NULL;
    memcpy(p, s, n);
    return p;
}

/* Capacity helpers */
static void ensure_tokens_capacity(LexResult *r) {
    if (r->ntokens >= r->ctokens) {
        size_t nc = r->ctokens ? r->ctokens * 2 : 64;
        lexerToken *t = realloc(r->tokens, nc * sizeof(lexerToken));
        if (!t) return; /* OOM, keep old state */
        r->tokens = t;
        r->ctokens = nc;
    }
}

static void ensure_comments_capacity(LexResult *r) {
    if (r->ncomments >= r->ccomments) {
        size_t nc = r->ccomments ? r->ccomments * 2 : 16;
        lexerToken *t = realloc(r->comments, nc * sizeof(lexerToken));
        if (!t) return;
        r->comments = t;
        r->ccomments = nc;
    }
}

static void ensure_lines_capacity(LexResult *r) {
    if (r->nlines >= r->clines) {
        size_t nc = r->clines ? r->clines * 2 : 16;
        int *t = realloc(r->lines, nc * sizeof(int));
        if (!t) return;
        r->lines = t;
        r->clines = nc;
    }
}

/* Return a newly allocated string for file:line:col: like legacy At() */
static char *lex_at(const LexResult *r, int offset) {
    if (!r) return NULL;
    const char *filename = r->filename ? r->filename : "(string)";
    int line = 1;
    int col = offset + 1;
    if (r->nlines > 0) {
        int idx = 0;
        for (size_t i = 0; i < r->nlines; ++i) {
            if (r->lines[i] <= offset) idx = (int)i; else break;
        }
        line = idx + 1;
        col = offset - r->lines[idx] + 1;
    }
    char buf[512];
    snprintf(buf, sizeof(buf), "%s:%d:%d: ", filename, line, col);
    return my_strdup(buf);
}

/* Map legacy token numbers to human names similar to Go symString. Returns a
   pointer to a static buffer for ASCII tokens or a static string for named tokens. */
const char *symString(int sym) {
    switch (sym) {
    case ASSERT_: return "assert";
    case IF_: return "if";
    case THEN: return "then";
    case ELSE_: return "else";
    case LET: return "let";
    case IN: return "in";
    case WITH: return "with";
    case OR_: return "or";
    case REC: return "rec";
    case INHERIT: return "inherit";
    case ELLIPSIS: return "...";
    case INTERP: return "interp";
    case SPACE: return "space";
    case COMMENT: return "comment";
    case II: return "ii";
    case URI: return "uri";
    case PATH: return "path";
    case FLOAT: return "float";
    case INT_: return "int";
    case T_ID: return "id";
    case TEXT: return "text";
    case ARG_ID: return "argID";
    case ARG_BRACKET: return "argBracket";
    case IMPL: return "->";
    case OR: return "||";
    case AND: return "&&";
    case EQ: return "==";
    case NEQ: return "!=";
    case LEQ: return "<=";
    case GEQ: return ">=";
    case UPDATE: return "//";
    case CONCAT: return "++";
    case NEGATE: return "!";
    default: {
        static char buf[8];
        if (sym >= 0 && sym < 256) {
            int c = sym;
            buf[0] = '\'';
            buf[1] = (char)c;
            buf[2] = '\'';
            buf[3] = '\0';
            return buf;
        }
        return "?";
    }
    }
}

LexResult *newLexResult(const char *path, int size) {
    LexResult *r = calloc(1, sizeof(*r));
    if (!r) return NULL;
    if (path) {
        r->filename = malloc(strlen(path) + 1);
        if (r->filename) memcpy(r->filename, path, strlen(path) + 1);
    }
    r->data = NULL;
    r->len = size;
    r->tokens = NULL;
    r->ntokens = r->ctokens = 0;
    r->comments = NULL;
    r->ncomments = r->ccomments = 0;
    r->lines = NULL;
    r->nlines = r->clines = 0;
    r->errmsg = NULL;
    /* ensure there is an initial line at offset 0 to match Go behavior */
    ensure_lines_capacity(r);
    r->lines[r->nlines++] = 0;
    return r;
}

void freeLexResult(LexResult *r) {
    if (!r) return;
    free(r->filename);
    free(r->data);
    free(r->tokens);
    free(r->comments);
    free(r->lines);
    free(r->errmsg);
    free(r);
}

void lexresult_push_token(LexResult *r, int sym, int ts, int te) {
    ensure_tokens_capacity(r);
    r->tokens[r->ntokens].Sym = sym;
    r->tokens[r->ntokens].Pos = ts;
    r->tokens[r->ntokens].End = te;
    /* legacy Go lexer leaves Prev as zero (Go zero-value); keep same semantics */
    r->tokens[r->ntokens].Prev = 0;
    r->ntokens++;
}

void lexresult_push_comment(LexResult *r, int sym, int ts, int te) {
    ensure_comments_capacity(r);
    r->comments[r->ncomments].Sym = sym;
    r->comments[r->ncomments].Pos = ts;
    r->comments[r->ncomments].End = te;
    r->comments[r->ncomments].Prev = 0;
    r->ncomments++;
}

void backrefs_push(Backrefs *s, int i, int fin) {
    if (s->n + 2 > s->c) {
        size_t nc = s->c ? s->c * 2 : 16;
        int *t = realloc(s->v, nc * sizeof(int));
        if (!t) return;
        s->v = t;
        s->c = nc;
    }
    s->v[s->n++] = i;
    s->v[s->n++] = fin;
}

int backrefs_pop(Backrefs *s, int *i, int *fin) {
    if (s->n < 2) return 0;
    s->n -= 2;
    *fin = s->v[s->n+1];
    *i = s->v[s->n];
    return 1;
}

size_t backrefs_len(const Backrefs *s) { return s->n / 2; }
void backrefs_free(Backrefs *s) { free(s->v); s->v = NULL; s->n = s->c = 0; }

void tokenter_impl(int sym, int fin, LexResult *r, Backrefs *backrefs, int ts, int te) {
    backrefs_push(backrefs, (int)r->ntokens, fin);
    lexresult_push_token(r, sym, ts, te);
}

int tokleave_impl(int sym, LexResult *r, Backrefs *backrefs, int *top, int ts, int te) {
    lexresult_push_token(r, sym, ts, te);
    if (backrefs_len(backrefs) == 0) {
        if (r->errmsg) free(r->errmsg);
        r->errmsg = my_strdup("does not close anything");
        return 0;
    }
    int iprev, prevsym;
    if (!backrefs_pop(backrefs, &iprev, &prevsym)) return 0;
    if (prevsym != sym) {
        /* construct error similar to legacy: "<file:line:col: >%s is not terminated" style */
        char *at = lex_at(r, r->tokens[iprev].Pos);
        const char *name = symString(r->tokens[iprev].Sym);
        size_t n = 0;
        if (at) n += strlen(at);
        if (name) n += strlen(name);
        n += 32;
        char *msg = malloc(n);
        if (msg) {
            if (at) snprintf(msg, n, "%s%s does not close %s", at, "", name);
            else snprintf(msg, n, "does not close %s", name);
        }
        if (r->errmsg) free(r->errmsg);
        if (msg) r->errmsg = msg;
        free(at);
        return 0;
    }
    r->tokens[r->ntokens-1].Prev = iprev;
    return 1;
}

int tokarg_impl(LexResult *r, int ts, int te) {
    /* push token whose Sym is the byte at ts (mirrors legacy int(data[ts])) */
    int sym = (unsigned char)r->data[ts];
    lexresult_push_token(r, sym, ts, te);
    if (r->ntokens == 1) {
        if (r->errmsg) free(r->errmsg);
        r->errmsg = my_strdup("does not follow anything");
        return 0;
    }
    int previdx = r->ntokens - 2;
    int prevsym = r->tokens[previdx].Sym;
    if (prevsym == T_ID || prevsym == ID) {
        r->tokens[previdx].Sym = ARG_ID;
    } else if (prevsym == '}') {
        int prevprev = r->tokens[previdx].Prev;
        if (prevprev >= 0) r->tokens[prevprev].Sym = ARG_BRACKET;
    } else {
        if (r->errmsg) free(r->errmsg);
        r->errmsg = my_strdup("does not follow an argument of a function");
        return 0;
    }
    return 1;
}

void add_lines_impl(LexResult *r, int ts, int te) {
    for (int i = ts; i < te; i++) {
        if ((unsigned char)r->data[i] == '\n') {
            ensure_lines_capacity(r);
            r->lines[r->nlines++] = i;
        }
    }
}

void add_line_impl(LexResult *r, int ts) {
    ensure_lines_capacity(r);
    r->lines[r->nlines++] = ts;
}
