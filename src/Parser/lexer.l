%{
#include <string>
#include "parser.hpp"
#include "run.hpp"
#include "nodes.hpp"
#define YY_DECL extern "C" int yylex()
using VSLNode = VSL::Parser::Node;
using VSLNodeType = VSL::Parser::NodeType;
int comment_depth;
//TODO: slice(1) for special identifier

%}

%x COMMENT
%x S_STRING
%x D_STRING
%%
[\s\r\n]+        ;
"//"[^\r\n]+     ;
<INITIAL,COMMENT>"/*" { comment_depth++; BEGIN(COMMENT); }
<COMMENT>(?:[^/*]|"*"[^/]|"/"[^*])+ ;
<COMMENT>"*/"    { comment_depth--; if(!comment_depth) BEGIN(INITIAL); }
"\""             BEGIN(D_STRING);
"'"              BEGIN(S_STRING);
<D_STRING>([^\\"]|\\.)* {
    yylval = VSLNode(yytext, VSLNodeType::DATA);
    return DOUBLE_QUOTED_STRING;
}
<S_STRING>([^\\']|\\.)* {
    yylval = VSLNode(yytext, VSLNodeType::DATA);
    return SINGLE_QUOTED_STRING;
}
<D_STRING>"\""   BEGIN(INITIAL);
<S_STRING>"'"    BEGIN(INITIAL);
(?:[^*]|"*"[^/])+"*/";
".."             return RANGE;
"."              return DOT;
";"              return SEMICOLON;
":"              return COLON;
","              return COMMA;
"+="             return PLUS_EQUALS;
"-="             return MINUS_EQUALS;
"*="             return TIMES_EQUALS;
"/="             return DIVIDE_EQUALS;
"%="             return MODULO_EQUALS;
"**="            return POWER_EQUALS;
"+"              return PLUS;
"-"              return MINUS;
"*"              return TIMES;
"/"              return DIVIDE;
"%"              return MODULO;
"**"             return POWER;
"<<="            return LEFT_SHIFT_EQUALS;
">>="            return RIGHT_SHIFT_EQUALS;
"<<"             return LEFT_SHIFT;
">>"             return RIGHT_SHIFT;
"=="             return EQUAL;
"!="             return NOT_EQUAL;
"<=>"            return SPACESHIP;
"<="             return LESS_THAN_OR_EQUAL;
">="             return GREATER_THAN_OR_EQUAL;
"<"              return LESS_THAN;
">"              return GREATER_THAN;
"="              return ASSIGN;
":="             return STRICT_ASSIGN;
"&="             return BITWISE_AND_EQUALS;
"|="             return BITWISE_OR_EQUALS;
"^="             return BITWISE_XOR_EQUALS;
"&"              return BITWISE_AND;
"|"              return BITWISE_OR;
"~"              return BITWISE_NOT;
"^"              return BITWISE_XOR;
"&&"             return LOGICAL_AND;
"||"             return LOGICAL_OR;
"!"              return LOGICAL_NOT;
"and"            return LOGICAL_AND;
"or"             return LOGICAL_OR;
"not"            return LOGICAL_NOT;
"xor"            return LOGICAL_XOR;
"::"             return CAST;
"->"             return MAP;
":>"             return CHAIN;
"{"              return LEFT_BRACE;
"}"              return RIGHT_BRACE;
"("              return LEFT_PARENTHESIS;
")"              return RIGHT_PARENTHESIS;
"["              return LEFT_BRACKET;
"]"              return RIGHT_BRACKET;
"=>"             return LAMBDA;
"var"            return VAR;
"let"            return LET;
"final"          return FINAL;
"const"          return CONST;
"is"             return IS;
"issub"          return ISSUB;
"isinstance"     return ISSUB;
"function"       return FUNCTION;
"fn"             return FUNCTION;
"class"          return CLASS;
"cls"            return CLASS;
"interface"      return INTERFACE;
"itf"            return INTERFACE;
"trait"          return TRAIT;
"trt"            return TRAIT;
"enum"           return ENUM;
"if"             return IF;
"for"            return FOR;
"while"          return WHILE;

$[0-9]+ {
    yylval = VSLNode(yytext, VSLNodeType::DATA);
    return SPECIAL_ARGUMENT;
}

$_[0-9]+ {
    yylval = VSLNode(yytext, VSLNodeType::DATA);
    return SPECIAL_LOOP_ARGUMENT;
}

$?[a-zA-Z_][a-zA-Z0-9_]* {
    if (yytext[0] == '$') {
        yylval =  VSLNode(yytext, VSLNodeType::DATA);
        return SPECIAL_IDENTIFIER;
    }
    yylval = VSLNode(yytext, VSLNodeType::DATA);
    return IDENTIFIER;
}

-?\.[0-9_]+ {
    yylval = VSLNode(yytext, VSLNodeType::DATA);
    return NUMBER;
}
-?[0-9][0-9_]*\.?[0-9_]* {
    yylval = VSLNode(yytext, VSLNodeType::DATA);
    return NUMBER;
}

"/"[^\/\*]([^\\/\r\n]|\\[^\r\n])+"/"[gmixc]* {
    yylval = VSLNode(yytext, VSLNodeType::DATA);
    return REGEX;
}
%%

