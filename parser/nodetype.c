#include "node.h"
#include "parser.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

/* forward declaration to satisfy calls before definition */
void add_child(Node* parent, Node* child);

Node* new_node(NodeType type, int token_start) {
    Node *n = calloc(1, sizeof(Node));
    n->type = type;
    n->token_start = token_start;
    n->token_end = 0;
    n->op = 0;
    n->children = NULL;
    n->nchildren = n->cchildren = 0;
    return n;
}

Node* new_node1(NodeType type, int token_start, Node* n1) {
    Node *n = new_node(type, token_start);
    add_child(n, n1);
    return n;
}

Node* new_node2(NodeType type, int token_start, Node* n1, Node* n2) {
    Node *n = new_node(type, token_start);
    add_child(n, n1);
    add_child(n, n2);
    return n;
}

Node* new_node3(NodeType type, int token_start, Node* n1, Node* n2, Node* n3) {
    Node *n = new_node(type, token_start);
    add_child(n, n1);
    add_child(n, n2);
    add_child(n, n3);
    return n;
}

void set_node_type(Node* node, NodeType type) {
    if (!node) return;
    node->type = type;
}

void add_child(Node* parent, Node* child) {
    if (!parent || !child) return;
    if (parent->nchildren >= parent->cchildren) {
        size_t nc = parent->cchildren ? parent->cchildren * 2 : 4;
        parent->children = realloc(parent->children, nc * sizeof(Node*));
        parent->cchildren = nc;
    }
    parent->children[parent->nchildren++] = child;
}

void set_token_end(Node* node, int token_end) {
    if (!node) return;
    node->token_end = token_end;
}

/* Operator node helpers required by the generated parser */
Node* op_node1(int op, int token_start, Node* n1) {
    Node *n = new_node(OP_NODE, token_start);
    n->op = op;
    add_child(n, n1);
    return n;
}

Node* op_node2(int op, int token_start, Node* n1, Node* n2) {
    Node *n = new_node(OP_NODE, token_start);
    n->op = op;
    add_child(n, n1);
    add_child(n, n2);
    return n;
}

/* Node type names mapping (partial; mirror legacy names) */
static const char *node_names[] = {
    "apply",
    "arg",
    "argset",
    "assert",
    "attrpath",
    "bind",
    "binds",
    "float",
    "function",
    "id",
    "istring",
    "if",
    "inheritfrom",
    "inheritlist",
    "inherit",
    "int",
    "interp",
    "let",
    "list",
    "parens",
    "path",
    "recset",
    "select",
    "selector",
    "set",
    "string",
    "text",
    "uri",
    "with",
    "op",
};

const char *node_type_name(NodeType t) {
    if ((size_t)t < sizeof(node_names)/sizeof(node_names[0])) return node_names[t];
    return "unknown";
}

/* Helper to get token text from LexResult */
static char *token_text(LexResult *lr, int token_index) {
    if (!lr || token_index < 0 || token_index >= (int)lr->ntokens) {
        char *empty = malloc(1);
        if (empty) empty[0] = '\0';
        return empty;
    }
    int s = lr->tokens[token_index].Pos;
    int e = lr->tokens[token_index].End;
    size_t n = (size_t)(e - s);
    char *tmp = malloc(n+1);
    if (!tmp) return NULL;
    memcpy(tmp, lr->data + s, n);
    tmp[n] = '\0';
    return tmp; /* caller must free */
}

static void appendf(char **outp, size_t *lenp, size_t *capp, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    va_list ap2;
    va_copy(ap2, ap);
    int need = vsnprintf(NULL, 0, fmt, ap2);
    va_end(ap2);
    if (need < 0) { va_end(ap); return; }
    if (*lenp + (size_t)need + 1 > *capp) {
        *capp = (*lenp + (size_t)need + 1) * 2;
        *outp = realloc(*outp, *capp);
    }
    vsnprintf(*outp + *lenp, (size_t)need + 1, fmt, ap);
    *lenp += (size_t)need;
    va_end(ap);
}

char *node_lisp_format(Node *n, LexResult *lr) {
    if (!n) return NULL;
    size_t cap = 256;
    char *out = malloc(cap);
    if (!out) return NULL;
    size_t len = 0;

    /* For OP_NODE emit the operator symbol as the node name to match legacy
       output: e.g. '(? <left> <right>)' or '(// <a> <b>)'. If op is 0 use
       the '//' token; if op is a printable ASCII char use that char. */
    if (n->type == OP_NODE) {
        char opname_buf[4] = {0};
        char *optext = NULL;
        const char *oname = NULL;
        if (n->op == 0) {
            oname = "//";
        } else {
            /* Prefer the original token text from the lexer if available
               (covers multi-char tokens like '++', '>=', '!=', etc.). */
            optext = token_text(lr, n->token_start);
            if (optext && optext[0] != '\0') {
                oname = optext;
            } else if (n->op >= 32 && n->op <= 126) {
                opname_buf[0] = (char)n->op;
                opname_buf[1] = '\0';
                oname = opname_buf;
            } else {
                oname = node_type_name(n->type);
            }
        }
        appendf(&out, &len, &cap, "(%s", oname);
        if (optext) free(optext);
    } else {
        appendf(&out, &len, &cap, "(%s", node_type_name(n->type));
    }

    /* Coalesce adjacent TEXT children to preserve original string pieces
       (legacy keeps things like "$CXX" as a single text token). */
    size_t i = 0;
    while (i < n->nchildren) {
        Node *child = n->children[i];
        if (child->type == TEXT_NODE) {
            char *t = token_text(lr, child->token_start);
            if (t) {
                appendf(&out, &len, &cap, " (text \"%s\")", t);
            } else {
                appendf(&out, &len, &cap, " (text \"\")");
            }
            free(t);
            i++;
        } else {
            char *c = node_lisp_format(child, lr);
            appendf(&out, &len, &cap, " %s", c ? c : "");
            free(c);
            i++;
        }
    }
    switch (n->type) {
        case URI_NODE:
        case PATH_NODE:
        case FLOAT_NODE:
        case INT_NODE: {
            char *t = token_text(lr, n->token_start);
            appendf(&out, &len, &cap, " %s", t ? t : "");
            free(t);
            break;
        }
        case ID_NODE: {
            char *t = token_text(lr, n->token_start);
            appendf(&out, &len, &cap, " |%s|", t ? t : "");
            free(t);
            break;
        }
        case TEXT_NODE: {
            char *t = token_text(lr, n->token_start);
            if (t) {
                size_t lt = strlen(t);
                /* If the lexer included surrounding double-quotes, strip them so
                   the emitted value matches the legacy TokenString (which returns
                   the inner text). */
                if (lt >= 2 && t[0] == '"' && t[lt-1] == '"') {
                    t[lt-1] = '\0';
                    appendf(&out, &len, &cap, " \"%s\"", t + 1);
                } else if (lt >= 1 && t[0] == '"') {
                    /* strip leading quote only */
                    appendf(&out, &len, &cap, " \"%s\"", t + 1);
                } else {
                    appendf(&out, &len, &cap, " \"%s\"", t);
                }
            } else {
                appendf(&out, &len, &cap, " \"\"");
            }
            free(t);
            break;
        }
        case OP_NODE: {
            /* operator already used as node name; do not append trailing op
               character after the children (legacy prints operator as the
               node name). */
            break;
        }
        default: break;
    }
    appendf(&out, &len, &cap, ")");
    return out;
}
