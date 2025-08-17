#ifndef PARSER_TOKENS_H
#define PARSER_TOKENS_H

/* Token numbers derived from the legacy Go parser (yyPrivate based). */
#define YYPRIVATE 57344

#define ASSERT_ 57346
#define IF_ 57347
#define THEN 57348
#define ELSE_ 57349
#define LET 57350
#define IN 57351
#define WITH 57352
#define OR_ 57353
#define REC 57354
#define INHERIT 57355
#define ELLIPSIS 57356
#define INTERP 57357
#define SPACE 57358
#define COMMENT 57359
#define II 57360
#define URI 57361
#define PATH 57362
#define FLOAT 57363
#define INT_ 57364
#define T_ID 57365
#define ID 57365 /* alias */
#define TEXT 57366
#define ARG_ID 57367
#define ARG_BRACKET 57368

#define IMPL 57369
#define OR 57370
#define AND 57371
#define EQ 57372
#define NEQ 57373
#define LEQ 57374
#define GEQ 57375
#define UPDATE 57376
#define CONCAT 57377
#define NEGATE 57378

#endif /* PARSER_TOKENS_H */
