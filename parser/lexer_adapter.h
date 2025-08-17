#ifndef PARSER_LEXER_ADAPTER_H
#define PARSER_LEXER_ADAPTER_H

#include "lexer.h"

void *create_scanner(const char *buf, int len, const char *filename);
void free_scanner(void *scanner);

/* Expose lexresult for inspection (lexer.h already defines LexResult) */
LexResult *scanner_lexresult(void *scanner);

#endif /* PARSER_LEXER_ADAPTER_H */
