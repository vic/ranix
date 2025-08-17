#ifndef PARSER_NODE_H
#define PARSER_NODE_H

#include <stddef.h>
#include "lexer.h"

typedef enum {
    APPLY_NODE,
    ARG_NODE,
    ARG_SET_NODE,
    ASSERT_NODE,
    ATTR_PATH_NODE,
    BIND_NODE,
    BINDS_NODE,
    FLOAT_NODE,
    FUNCTION_NODE,
    ID_NODE,
    I_STRING_NODE,
    IF_NODE,
    INHERIT_FROM_NODE,
    INHERIT_LIST_NODE,
    INHERIT_NODE,
    INT_NODE,
    INTERP_NODE,
    LET_NODE,
    LIST_NODE,
    PARENS_NODE,
    PATH_NODE,
    REC_SET_NODE,
    SELECT_NODE,
    SELECT_OR_NODE,
    SET_NODE,
    STRING_NODE,
    TEXT_NODE,
    URI_NODE,
    WITH_NODE,
    OP_NODE
} NodeType;

typedef struct Node {
    NodeType type;
    int token_start;
    int token_end;
    int op; /* operator code for OP_NODE (ASCII or token id) */
    struct Node **children;
    size_t nchildren;
    size_t cchildren;
} Node;

/* Produce a lisp-format string representation of the node using the
   provided LexResult (for token text lookup). Caller must free result. */
char *node_lisp_format(Node *n, LexResult *lr);

/* Return canonical node type name used in legacy lisp format. */
const char *node_type_name(NodeType t);

#endif /* PARSER_NODE_H */