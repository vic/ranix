#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"
#include "node.h"
#include "parser.h"
#include "lexer_adapter.h"
/* enable parser debug trace when built with -DYYDEBUG=1 */
extern int yydebug;

static char *token_text(const LexResult *lr, int idx) {
    if (!lr || idx < 0 || idx >= (int)lr->ntokens) return NULL;
    int s = lr->tokens[idx].Pos;
    int e = lr->tokens[idx].End;
    int n = e - s;
    char *t = malloc(n + 1);
    if (!t) return NULL;
    memcpy(t, lr->data + s, n);
    t[n] = '\0';
    return t;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
        return 2;
    }

    int dump_tokens = 0;
    const char *path = NULL;
    if (argc >= 2 && strcmp(argv[1], "--dump-tokens") == 0) {
        if (argc < 3) {
            fprintf(stderr, "usage: %s --dump-tokens <file>\n", argv[0]);
            return 2;
        }
        dump_tokens = 1;
        path = argv[2];
    } else {
        path = argv[1];
    }

    FILE *f = fopen(path, "rb");
    if (!f) { perror("open"); return 2; }
    if (fseek(f, 0, SEEK_END) != 0) { perror("seek"); fclose(f); return 2; }
    long sz = ftell(f);
    if (sz < 0) { perror("tell"); fclose(f); return 2; }
    if (fseek(f, 0, SEEK_SET) != 0) { perror("seek"); fclose(f); return 2; }
    char *buf = malloc((size_t)sz);
    if (!buf) { fclose(f); return 2; }
    if (fread(buf, 1, (size_t)sz, f) != (size_t)sz) { perror("read"); fclose(f); free(buf); return 2; }
    fclose(f);

    void *scanner = create_scanner(buf, (int)sz, path);
    if (!scanner) { fprintf(stderr, "failed to create scanner\n"); free(buf); return 2; }

    void *ast = NULL;
    /* enable runtime parser tracing */
    yydebug = 0;
    int perr = yyparse(&ast, scanner);
    LexResult *lr = scanner_lexresult(scanner);

    /* If user requested token dump, print tokens in the legacy dump format to stdout
       so external comparison scripts can parse them. */
    if (dump_tokens && lr) {
        /* header line (optional) */
        printf("tokens: %zu comments: %zu lines: %zu\n", lr->ntokens, lr->ncomments, lr->nlines);
        for (size_t i = 0; i < lr->ntokens; ++i) {
            char *txt = token_text(lr, (int)i);
            printf("%4zu: sym=%s(%d) pos=%d end=%d txt='%s' prev=%d\n", i, symString(lr->tokens[i].Sym), lr->tokens[i].Sym, lr->tokens[i].Pos, lr->tokens[i].End, txt ? txt : "", lr->tokens[i].Prev);
            free(txt);
        }
    }

    if (perr) {
        fprintf(stderr, "parse failed\n");
        if (lr && lr->errmsg) fprintf(stderr, "lexing failed: %s\n", lr->errmsg);
        if (lr) {
            fprintf(stderr, "tokens: %zu comments: %zu lines: %zu\n", lr->ntokens, lr->ncomments, lr->nlines);
            /* print all tokens for full comparison with legacy lexer */
            for (size_t i = 0; i < lr->ntokens; ++i) {
                char *txt = token_text(lr, (int)i);
                fprintf(stderr, "%4zu: sym=%s(%d) pos=%d end=%d txt='%s' prev=%d\n", i, symString(lr->tokens[i].Sym), lr->tokens[i].Sym, lr->tokens[i].Pos, lr->tokens[i].End, txt ? txt : "", lr->tokens[i].Prev);
                free(txt);
            }
        }
        free_scanner(scanner);
        free(buf);
        return 1;
    }

    if (ast && lr) {
        char *s = node_lisp_format((Node*)ast, lr);
        if (s) {
            puts(s);
            free(s);
        }
    } else if (lr && !dump_tokens) {
        /* only print summary to stdout when not in dump mode */
        printf("got %zu tokens, %zu comments, %zu lines\n", lr->ntokens, lr->ncomments, lr->nlines);
    }

    free_scanner(scanner);
    free(buf);
    return 0;
}
