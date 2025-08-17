%{
#include "node.h"
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>

/* Forward declarations of node helpers implemented in parser/nodetype.c */
Node* new_node(NodeType type, int token_start);
Node* new_node1(NodeType type, int token_start, Node* n1);
Node* new_node2(NodeType type, int token_start, Node* n1, Node* n2);
Node* new_node3(NodeType type, int token_start, Node* n1, Node* n2, Node* n3);
Node* op_node1(int op, int token_start, Node* n1);
Node* op_node2(int op, int token_start, Node* n1, Node* n2);
void set_node_type(Node* node, NodeType type);
void add_child(Node* parent, Node* child);
void set_token_end(Node* node, int token_end);

/* yyerror matching the generated parser expectations */
void yyerror(void **ast_root, void *scanner, const char *s) {
    (void)ast_root; (void)scanner;
    fprintf(stderr, "parse error: %s\n", s);
}

/* yylex prototype using void* so it's visible before YYSTYPE is defined in the generated file */
int yylex(void *yylval_param, void *scanner);

%}

%parse-param { void** ast_root }
%parse-param { void* scanner }
%lex-param { void* scanner }


%union {
    int token;
    Node* node;
}

%type <node> Main Expression Interp String ID Atom Select Apply Op InterpID AttrPath List Binds InheritList Function ArgSet Arg

%define api.pure full
%debug

%token <token> ASSERT_ IF_ THEN ELSE_ LET IN WITH OR_ REC INHERIT ELLIPSIS INTERP SPACE COMMENT II
%token <token> URI PATH FLOAT INT_ T_ID TEXT ARG_ID ARG_BRACKET

%token <token> ':' '@' ',' ';' '"' '.' '(' ')' '[' ']' '{' '}' '='

%right <token> IMPL
%left <token> OR
%left <token> AND
%nonassoc <token> EQ NEQ
%left <token> '<' '>' LEQ GEQ
%right <token> UPDATE
%nonassoc <token> '!'
%left <token> '+' '-'
%left <token> '*' '/'
%right <token> CONCAT
%nonassoc <token> '?'
%nonassoc <token> NEGATE

%%


Main
: Expression
{ *ast_root = $1; }
;

Expression
: Op
| ASSERT_ Expression ';' Expression
{ $$ = new_node2(ASSERT_NODE, $1, $2, $4); set_token_end($$, $3); }
| IF_ Expression THEN Expression ELSE_ Expression
{ $$ = new_node3(IF_NODE, $1, $2, $4, $6); set_token_end($$, $3); }
| LET Binds IN Expression
{ $$ = new_node2(LET_NODE, $1, $2, $4); set_token_end($$, $3); }
| WITH Expression ';' Expression
{ $$ = new_node2(WITH_NODE, $1, $2, $4); set_token_end($$, $3); }
| Function
;

Interp
: INTERP Expression '}'
{ $$ = new_node1(INTERP_NODE, $1, $2); set_token_end($$, $3); }
;

String
:
{ $$ = new_node(STRING_NODE, 0); }
| String TEXT
{ add_child($1, new_node(TEXT_NODE, $2)); $$ = $1; }
| String Interp
{ add_child($1, $2); $$ = $1; }
;

ID
: T_ID
{ $$ = new_node(ID_NODE, $1); }
;

Atom
: URI
{ $$ = new_node(URI_NODE, $1); }
| PATH
{ $$ = new_node(PATH_NODE, $1); }
| FLOAT
{ $$ = new_node(FLOAT_NODE, $1); }
| INT_
{ $$ = new_node(INT_NODE, $1); }
| ID
| '"' String '"'
{ set_token_end($2, $3); $$ = $2; }
| II String II
{ set_node_type($2, I_STRING_NODE); set_token_end($2, $3); $$ = $2; }
| '(' Expression ')'
{ $$ = new_node1(PARENS_NODE, $1, $2); set_token_end($$, $3); }
| '[' List ']'
{ set_token_end($2, $3); $$ = $2; }
| '{' Binds '}'
{ set_node_type($2, SET_NODE); set_token_end($2, $3); $$ = $2; }
| REC '{' Binds '}'
{ set_node_type($3, REC_SET_NODE); set_token_end($3, $4); $$ = $3; }
;

Select
: Atom
| Atom '.' AttrPath
{ $$ = new_node2(SELECT_NODE, $2, $1, $3); }
| Atom '.' AttrPath OR_ Select
{ $$ = new_node3(SELECT_OR_NODE, $2, $1, $3, $5); set_token_end($$, $4); }
;

Apply
: Select
| Apply Select
{ $$ = new_node2(APPLY_NODE, 0, $1, $2); }
;

Op
: Apply
| '-' Op %prec NEGATE
{ $$ = op_node1('-', $1, $2); }
| Op '?' AttrPath
{ $$ = op_node2('?', $2, $1, $3); }
| Op CONCAT Op
{ $$ = op_node2(CONCAT, $2, $1, $3); }
| Op '/' Op
{ $$ = op_node2('/', $2, $1, $3); }
| Op '*' Op
{ $$ = op_node2('*', $2, $1, $3); }
| Op '-' Op
{ $$ = op_node2('-', $2, $1, $3); }
| Op '+' Op
{ $$ = op_node2('+', $2, $1, $3); }
| '!' Op
{ $$ = op_node1('!', $1, $2); }
| Op UPDATE Op
{ $$ = op_node2(UPDATE, $2, $1, $3); }
| Op GEQ Op
{ $$ = op_node2(GEQ, $2, $1, $3); }
| Op LEQ Op
{ $$ = op_node2(LEQ, $2, $1, $3); }
| Op '>' Op
{ $$ = op_node2('>', $2, $1, $3); }
| Op '<' Op
{ $$ = op_node2('<', $2, $1, $3); }
| Op NEQ Op
{ $$ = op_node2(NEQ, $2, $1, $3); }
| Op EQ Op
{ $$ = op_node2(EQ, $2, $1, $3); }
| Op AND Op
{ $$ = op_node2(AND, $2, $1, $3); }
| Op OR Op
{ $$ = op_node2(OR, $2, $1, $3); }
| Op IMPL Op
{ $$ = op_node2(IMPL, $2, $1, $3); }
;

InterpID
: ID
| OR_
{ $$ = new_node(ID_NODE, $1); }
| Interp
| '"' String '"'
{ set_token_end($2, $3); $$ = $2; }
;

AttrPath
: InterpID
{ $$ = new_node1(ATTR_PATH_NODE, 0, $1); }
| AttrPath '.' InterpID
{ add_child($1, $3); set_token_end($1, 0); $$ = $1; }
;

List
:
{ $$ = new_node(LIST_NODE, 0); }
| List Select
{ add_child($1, $2); $$ = $1; }
;

Binds
:
{ $$ = new_node(BINDS_NODE, 0); }
| Binds AttrPath '=' Expression ';'
{ add_child($1, new_node2(BIND_NODE, $3, $2, $4)); $$ = $1; }
| Binds INHERIT InheritList ';'
{ add_child($1, new_node1(INHERIT_NODE, $2, $3)); $$ = $1; }
| Binds INHERIT '(' Expression ')' InheritList ';'
{ add_child($1, new_node2(INHERIT_FROM_NODE, $2, $4, $6)); $$ = $1; }
;

InheritList
:
{ $$ = new_node(INHERIT_LIST_NODE, 0); }
| InheritList InterpID
{ add_child($1, $2); $$ = $1; }
;

Function
: ARG_ID ':' Expression
{ $$ = new_node2(FUNCTION_NODE, $2, new_node(ID_NODE, $1), $3); }
| ARG_BRACKET ArgSet '}' ':' Expression
{ $$ = new_node2(FUNCTION_NODE, $4, $2, $5); set_token_end($2, $3); }
| ARG_ID '@' ARG_BRACKET ArgSet '}' ':' Expression
{ $$ = new_node3(FUNCTION_NODE, $2, new_node(ID_NODE, $1), $4, $7); set_token_end($4, $5); }
| ARG_BRACKET ArgSet '}' '@' ID ':' Expression
{ $$ = new_node3(FUNCTION_NODE, $4, $5, $2, $7); set_token_end($2, $3); }
| ARG_BRACKET ArgSet '}' '@' ARG_ID ':' Expression
{ $$ = new_node3(FUNCTION_NODE, $4, new_node(ID_NODE, $5), $2, $7); set_token_end($2, $3); }
;

ArgSet
:
{ $$ = new_node(ARG_SET_NODE, 0); }
| Arg
{ $$ = new_node1(ARG_SET_NODE, 0, $1); }
| ELLIPSIS
{ $$ = new_node1(ARG_SET_NODE, 0, new_node(ARG_NODE, $1)); }
| Arg ',' ArgSet
{ add_child($3, $1); $$ = $3; }
;

Arg
: ID
{ $$ = new_node1(ARG_NODE, 0, $1); }
| ID '?' Expression
{ $$ = new_node2(ARG_NODE, $2, $1, $3); }
;

%%
