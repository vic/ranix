#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexer.h"
#include "node.h"
#include "parser.h" /* provides parser token enums and YYSTYPE */

/* Legacy token numeric values from parser/tokens.h (copied here to avoid include-order issues)
   These are the values produced by the Ragel lexer (legacy mapping). */
#define LEG_ASSERT_ 57346
#define LEG_IF_ 57347
#define LEG_THEN 57348
#define LEG_ELSE_ 57349
#define LEG_LET 57350
#define LEG_IN 57351
#define LEG_WITH 57352
#define LEG_OR_ 57353
#define LEG_REC 57354
#define LEG_INHERIT 57355
#define LEG_ELLIPSIS 57356
#define LEG_INTERP 57357
#define LEG_SPACE 57358
#define LEG_COMMENT 57359
#define LEG_II 57360
#define LEG_URI 57361
#define LEG_PATH 57362
#define LEG_FLOAT 57363
#define LEG_INT_ 57364
#define LEG_T_ID 57365
#define LEG_TEXT 57366
#define LEG_ARG_ID 57367
#define LEG_ARG_BRACKET 57368
#define LEG_IMPL 57369
#define LEG_OR 57370
#define LEG_AND 57371
#define LEG_EQ 57372
#define LEG_NEQ 57373
#define LEG_LEQ 57374
#define LEG_GEQ 57375
#define LEG_UPDATE 57376
#define LEG_CONCAT 57377
#define LEG_NEGATE 57378

/* Scanner context passed as 'scanner' to yyparse/yylex */
typedef struct Scanner {
    LexResult *lr;     /* lex result, created on demand by yylex */
    int pos;           /* next token index to return */
    char *buf;         /* owned copy of input */
    int len;
    char *filename;    /* owned */
} Scanner;

void *create_scanner_from_buffer(const char *buf, int len, const char *filename) {
    Scanner *s = calloc(1, sizeof(*s));
    if (!s) return NULL;
    s->buf = malloc(len);
    if (!s->buf) { free(s); return NULL; }
    memcpy(s->buf, buf, len);
    s->len = len;
    s->pos = 0;
    s->lr = NULL;
    if (filename) {
        size_t n = strlen(filename) + 1;
        s->filename = malloc(n);
        if (s->filename) memcpy(s->filename, filename, n);
    }
    return s;
}

void destroy_scanner(void *scannerp) {
    if (!scannerp) return;
    Scanner *s = (Scanner*)scannerp;
    if (s->lr) freeLexResult(s->lr);
    free(s->buf);
    free(s->filename);
    free(s);
}

/* Translate legacy lexer token numbers to the parser's token enums. When the
   legacy token is an ASCII single-char (small value < 256), return it as-is. */
static int translate_token(int legacy) {
    switch (legacy) {
        case LEG_ASSERT_: return ASSERT_;
        case LEG_IF_: return IF_;
        case LEG_THEN: return THEN;
        case LEG_ELSE_: return ELSE_;
        case LEG_LET: return LET;
        case LEG_IN: return IN;
        case LEG_WITH: return WITH;
        case LEG_OR_: return OR_;
        case LEG_REC: return REC;
        case LEG_INHERIT: return INHERIT;
        case LEG_ELLIPSIS: return ELLIPSIS;
        case LEG_INTERP: return INTERP;
        case LEG_SPACE: return SPACE;
        case LEG_COMMENT: return COMMENT;
        case LEG_II: return II;
        case LEG_URI: return URI;
        case LEG_PATH: return PATH;
        case LEG_FLOAT: return FLOAT;
        case LEG_INT_: return INT_;
        case LEG_T_ID: return T_ID;
        case LEG_TEXT: return TEXT;
        case LEG_ARG_ID: return ARG_ID;
        case LEG_ARG_BRACKET: return ARG_BRACKET;
        case LEG_IMPL: return IMPL;
        case LEG_OR: return OR;
        case LEG_AND: return AND;
        case LEG_EQ: return EQ;
        case LEG_NEQ: return NEQ;
        case LEG_LEQ: return LEQ;
        case LEG_GEQ: return GEQ;
        case LEG_UPDATE: return UPDATE;
        case LEG_CONCAT: return CONCAT;
        case LEG_NEGATE: return NEGATE;
        default:
            if (legacy >= 0 && legacy < 256) return legacy; /* ASCII token */
            return legacy; /* fallback (may be out of range) */
    }
}

/* The parser expects yylex to fill YYSTYPE and return token numbers.
   We'll run the Ragel lexData once per input and then stream tokens from the
   resulting LexResult. yylval->token will be set to the token's start position
   (this mirrors the original grammar expecting integer token values). */
int yylex(YYSTYPE *yylval, void *scannerp) {
    if (!scannerp) return 0;
    Scanner *s = (Scanner*)scannerp;
    if (!s->lr) {
        s->lr = newLexResult(s->filename, s->len);
        if (!s->lr) {
            fprintf(stderr, "out of memory creating LexResult\n");
            return 0;
        }
        int err = lexData(s->buf, s->len, s->lr);
        if (err) {
            fprintf(stderr, "lexing failed: %s\n", s->lr->errmsg ? s->lr->errmsg : "unknown");
            return 0;
        }
    }
    if (s->pos >= (int)s->lr->ntokens) return 0; /* EOF */
    lexerToken *t = &s->lr->tokens[s->pos];
    int sym = translate_token(t->Sym);
    if (yylval) yylval->token = s->pos; /* return token index, not byte offset */
    s->pos++;
    return sym;
}

/* Simple helper used by main.c to create/destroy scanner */

/* Keep these symbols available to other translation units */

void *create_scanner(const char *buf, int len, const char *filename) {
    return create_scanner_from_buffer(buf, len, filename);
}

void free_scanner(void *scanner) {
    destroy_scanner(scanner);
}

LexResult *scanner_lexresult(void *scanner) {
    if (!scanner) return NULL;
    Scanner *s = (Scanner*)scanner;
    return s->lr;
}
