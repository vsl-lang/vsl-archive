%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "utils.h"

#define OP(type, a, b) make_ast_node(type,\
                       make_ast_data(1, NULL, a),\
                       make_ast_data(1, NULL, b))
#define PAIR(a, b)     OP(AST_PAIR, a, b)

int yylex();
void yyerror(struct ast_node_t *ast, char *s);
FILE *yyin;
%}
%union {
    struct ast_node_t *node;
}

%token <node> INT
%token <node> FLOAT
%token <node> COMPLEX
%token <node> STRING
%token <node> NAME

%token IF
%token UNLESS
%token ELSE
%token WHILE
%token UNTIL

%token SEMI
%token COLON
%token COMMA
%token DOT

%token LPAR
%token RPAR
%token LBRACE
%token RBRACE
%token LSQUARE
%token RSQUARE

%token OP_PLUS
%token OP_MINUS
%token OP_TIMES
%token OP_SLASH
%token OP_MOD
%token OP_POW
%token OP_AND
%token OP_OR
%token OP_XOR
%token OP_LSH
%token OP_RSH

%type <node> expr
%type <node> args
%type <node> stmt
%type <node> program

%left  OP_LSH OP_RSH
%left  OP_AND OP_OR OP_XOR
%left  OP_PLUS OP_MINUS
%left  OP_TIMES OP_SLASH OP_MOD
%right OP_POW
%left  LPAR
%left  DOT

%start ast

%parse-param {struct ast_node_t *ast}
%%
expr    : INT | FLOAT | COMPLEX | STRING | NAME
        | LSQUARE args RSQUARE  { $$ = $2; }
        | LPAR expr RPAR        { $$ = $2; }
        | expr LPAR args RPAR   { $$ = OP(AST_CALL, $1, $3); }
        | expr OP_PLUS expr     { $$ = OP(AST_OP_ADD, $1, $3); }
        | expr OP_MINUS expr    { $$ = OP(AST_OP_SUB, $1, $3); }
        | expr OP_TIMES expr    { $$ = OP(AST_OP_MULT, $1, $3); }
        | expr OP_SLASH expr    { $$ = OP(AST_OP_DIV, $1, $3); }
        | expr OP_MOD expr      { $$ = OP(AST_OP_MOD, $1, $3); }
        | expr OP_POW expr      { $$ = OP(AST_OP_POW, $1, $3); }
        | expr OP_AND expr      { $$ = OP(AST_OP_AND, $1, $3); }
        | expr OP_OR expr       { $$ = OP(AST_OP_OR, $1, $3); }
        | expr OP_XOR expr      { $$ = OP(AST_OP_XOR, $1, $3); }
        | expr OP_LSH expr      { $$ = OP(AST_OP_LSH, $1, $3); }
        | expr OP_RSH expr      { $$ = OP(AST_OP_RSH, $1, $3); }
        | expr DOT expr         { $$ = OP(AST_MEMBER, $1, $3); };
args    : expr                  { $$ = $1; }
        | expr COMMA args       { $$ = PAIR($1, $3); };
stmt    : expr SEMI
        | IF expr stmt          { $$ = OP(AST_IF, $2, $3); }
        | UNLESS expr stmt      { $$ = OP(AST_UNLESS, $2, $3); }
        | WHILE expr stmt       { $$ = OP(AST_WHILE, $2, $3); }
        | UNTIL expr stmt       { $$ = OP(AST_UNTIL, $2, $3); }
        | LBRACE program RBRACE { $$ = $2; };
program : stmt                  { $$ = $1; }
        | stmt program          { $$ = PAIR($1, $2); };
ast     : program               { memcpy(ast, $1, sizeof(struct ast_node_t)); };
%%
int main(int argc, char **argv) {
    if (argc != 2) {
        puts("\tVSL interpreter");
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fputs("Error while opening the file", stderr);
        return -1;
    }
    struct ast_node_t *ast = malloc(sizeof(struct ast_node_t));
    yyin = file;
    do {
        yyparse(ast);
    } while (!feof(file));
    fclose(file);
    print_ast_node(ast, 0);
    destroy_ast_node(ast);
    return 0;
}

void yyerror(struct ast_node_t *ast, char *s) {
    fprintf(stderr, "error: %s\n", s);
    exit(1);
}
