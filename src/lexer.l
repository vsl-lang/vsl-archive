%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
#include "ast.h"
#include "utils.h"
#define YYDECL int yylex()
#define LITERAL(type) \
    char *tmp = malloc(strlen(yytext)); \
    if (tmp == NULL) yyerror(NULL, "failed to allocate"); \
    strcpy(tmp, yytext); \
    yylval.node = make_ast_node(type, \
                  make_ast_data(0, tmp, NULL), \
                                NULL);
int fileno();
void yyerror(struct ast_node_t *ast, char *s);
%}

%option noyywrap

integer_ [0-9]+
integer  {integer_}|0b[01]+|0x[0-1a-fA-F]+|0o[0-7]+
float_   {integer_}\.{integer_}?
float    {float_}(e[-+]?({integer_}|{float_}))?
complex  ({float_}|{integer_})[ijk]
whitesp  [ \t\n]+

%%
{integer} {
    LITERAL(AST_STRING);
    return INT;
};
{float} {
    LITERAL(AST_FLOAT);
    return FLOAT;
};
{complex} {
    LITERAL(AST_COMPLEX);
    return COMPLEX;
};
\"([^"\\]|\\.)*\" {
    LITERAL(AST_STRING);
    return STRING;
};
[a-zA-Z_][a-zA-Z0-9_]* { 
    if (strcmp(yytext, "if") == 0) return IF;
    else if (strcmp(yytext, "unless") == 0) return UNLESS;
    else if (strcmp(yytext, "else") == 0) return ELSE;
    else if (strcmp(yytext, "while") == 0) return WHILE;
    else if (strcmp(yytext, "until") == 0) return UNTIL;
    LITERAL(AST_NAME);
    return NAME;
};

";"  return SEMI;
":"  return COLON;
","  return COMMA;
"."  return DOT;

"("  return LPAR;
")"  return RPAR;
"{"  return LBRACE;
"}"  return RBRACE;
"["  return LSQUARE;
"]"  return RSQUARE;

"+"  return OP_PLUS;
"-"  return OP_MINUS;
"*"  return OP_TIMES;
"/"  return OP_SLASH;
"%"  return OP_MOD;
"**" return OP_POW;

"&"  return OP_AND;
"|"  return OP_OR;
"^"  return OP_XOR;
"<<" return OP_LSH;
">>" return OP_RSH;

{whitesp} {}

.   yyerror(NULL, "can't lex a character");
