%{
//TODO: xor and cast precedence
//also "->" ":>" IS ISSUB
// reccomendation: `is` and `subof` instead
//value also includes tuples etc
//and trait/interface, class body
#include <iostream>
#include <functional>
#include "parser.hpp"
#include "operators.hpp"
#include "nodes.hpp"
extern "C" int yylex();
//extern "C" int yyparse();
extern "C" void yyerror(char const*);

void yyerror(const char *message);
%}

%code requires {
#include "run.hpp"
using VSLNode = VSL::Parser::Node;
using VSLNodeType = VSL::Parser::NodeType;
using Operator = VSL::Parser::Operator;
}

%token RANGE                 ".."
%token DOT                   "."
%token SEMICOLON             ";"
%token COLON                 ":"
%token COMMA                 ","
%token PLUS_EQUALS           "+="
%token MINUS_EQUALS          "-="
%token TIMES_EQUALS          "*="
%token DIVIDE_EQUALS         "/="
%token MODULO_EQUALS         "%="
%token POWER_EQUALS          "**="
%token PLUS                  "+"
%token MINUS                 "-"
%token TIMES                 "*"
%token DIVIDE                "/"
%token MODULO                "%"
%token POWER                 "**"
%token LEFT_SHIFT_EQUALS     "<<="
%token RIGHT_SHIFT_EQUALS    ">>="
%token LEFT_SHIFT            "<<"
%token RIGHT_SHIFT           ">>"
%token EQUAL                 "=="
%token NOT_EQUAL             "!="
%token SPACESHIP             "<=>"
%token LESS_THAN_OR_EQUAL    "<="
%token GREATER_THAN_OR_EQUAL ">="
%token LESS_THAN             "<"
%token GREATER_THAN          ">"
%token ASSIGN                "="
%token STRICT_ASSIGN         ":="
%token BITWISE_AND_EQUALS    "&="
%token BITWISE_OR_EQUALS     "|="
%token BITWISE_XOR_EQUALS    "^="
%token BITWISE_AND           "&"
%token BITWISE_OR            "|"
%token BITWISE_NOT           "~"
%token BITWISE_XOR           "^"
%token LOGICAL_AND           "&&"
%token LOGICAL_OR            "||"
%token LOGICAL_NOT           "!"
%token LOGICAL_XOR           "xor"
%token CAST                  "::"
%token MAP                   "->"
%token CHAIN                 ":>"
%token LEFT_BRACE            "{"
%token RIGHT_BRACE           "}"
%token LEFT_PARENTHESIS      "("
%token RIGHT_PARENTHESIS     ")"
%token LEFT_BRACKET          "["
%token RIGHT_BRACKET         "]"
%token LAMBDA                "=>"
%token VAR
%token LET
%token FINAL
%token CONST
%token IS
%token ISSUB
%token FUNCTION
%token CLASS
%token INTERFACE
%token TRAIT
%token ENUM
%token IF
%token FOR
%token WHILE
%token IDENTIFIER
%token SPECIAL_IDENTIFIER
%token SPECIAL_ARGUMENT
%token SPECIAL_LOOP_ARGUMENT
%token NUMBER
%token SINGLE_QUOTED_STRING
%token DOUBLE_QUOTED_STRING
%token REGEX

%left CC
%left EXPRESSIONS
%nonassoc ".."
%right "=" ":=" "<<=" ">>=" "+=" "-=" "/=" "*=" "%=" "**=" "&=" "|=" "^="
%left IS ISSUB
%left "==" "!=" "<=>" "<=" ">=" ">" "<"
%left "xor"
%left "||"
%left "&&"
%left "<<" ">>"
%left "+" "-"
%left "/" "*" "%"
%right "**"
%left "&" "|" "^"
%left "->" ":>"
%right "::"
%left PREFIX

%define api.value.type {VSL::Parser::Node}

%%
Program:
  Program Statement StatementTerminator { $1.add($2); std::swap($$, $1); std::cout << std::endl << $2.run(); }
| { $$ = VSLNode(VSLNodeType::PROGRAM); }
  ;

Statement:
  VariableDeclaration { $$ = VSLNode({$1}, VSLNodeType::STATEMENT); }
| Function { $$ = $1; }
| Class
| CommandChain { $$ = VSLNode({$1}, VSLNodeType::STATEMENT); }
  ;

// Top-Level Statements
CommandChain:
  CommandChain Expressions { $1.add($2); std::swap($$, $1); }
| Expressions %prec CC { $$ = VSLNode({$1}, VSLNodeType::COMMAND_CHAIN); }
  ;

Expressions:
  Expressions "," Expression { $1.add($3); std::swap($$, $1); }
| Expression %prec EXPRESSIONS { $$ = VSLNode({$1}, VSLNodeType::EXPRESSIONS); }
  ;

// Expressions
Expression:
  Expression ".." Expression { $$ = VSLNode({$1, $3}, Operator::RANGE, VSLNodeType::BINARY_EXPRESSION); }
| Expression "+=" Expression { $$ = VSLNode({$1, $3}, Operator::PLUS_EQUALS, VSLNodeType::BINARY_EXPRESSION); }
| Expression "-=" Expression { $$ = VSLNode({$1, $3}, Operator::MINUS_EQUALS, VSLNodeType::BINARY_EXPRESSION); }
| Expression "*=" Expression { $$ = VSLNode({$1, $3}, Operator::TIMES_EQUALS, VSLNodeType::BINARY_EXPRESSION); }
| Expression "/=" Expression { $$ = VSLNode({$1, $3}, Operator::DIVIDE_EQUALS, VSLNodeType::BINARY_EXPRESSION); }
| Expression "%=" Expression { $$ = VSLNode({$1, $3}, Operator::MODULO_EQUALS, VSLNodeType::BINARY_EXPRESSION); }
| Expression "**=" Expression { $$ = VSLNode({$1, $3}, Operator::POWER_EQUALS, VSLNodeType::BINARY_EXPRESSION); }
| Expression "+" Expression { $$ = VSLNode({$1, $3}, Operator::PLUS, VSLNodeType::BINARY_EXPRESSION); }
| Expression "-" Expression { $$ = VSLNode({$1, $3}, Operator::MINUS, VSLNodeType::BINARY_EXPRESSION); }
| Expression "*" Expression { $$ = VSLNode({$1, $3}, Operator::TIMES, VSLNodeType::BINARY_EXPRESSION); }
| Expression "/" Expression { $$ = VSLNode({$1, $3}, Operator::DIVIDE, VSLNodeType::BINARY_EXPRESSION); }
| Expression "%" Expression { $$ = VSLNode({$1, $3}, Operator::MODULO, VSLNodeType::BINARY_EXPRESSION); }
| Expression "**" Expression { $$ = VSLNode({$1, $3}, Operator::POWER, VSLNodeType::BINARY_EXPRESSION); }
| Expression "<<=" Expression { $$ = VSLNode({$1, $3}, Operator::LEFT_SHIFT_EQUALS, VSLNodeType::BINARY_EXPRESSION); }
| Expression ">>=" Expression { $$ = VSLNode({$1, $3}, Operator::RIGHT_SHIFT_EQUALS, VSLNodeType::BINARY_EXPRESSION); }
| Expression "<<" Expression { $$ = VSLNode({$1, $3}, Operator::LEFT_SHIFT, VSLNodeType::BINARY_EXPRESSION); }
| Expression ">>" Expression { $$ = VSLNode({$1, $3}, Operator::RIGHT_SHIFT, VSLNodeType::BINARY_EXPRESSION); }
| Expression "==" Expression { $$ = VSLNode({$1, $3}, Operator::EQUAL, VSLNodeType::BINARY_EXPRESSION); }
| Expression "!=" Expression { $$ = VSLNode({$1, $3}, Operator::NOT_EQUAL, VSLNodeType::BINARY_EXPRESSION); }
| Expression "<=>" Expression { $$ = VSLNode({$1, $3}, Operator::SPACESHIP, VSLNodeType::BINARY_EXPRESSION); }
| Expression "<=" Expression { $$ = VSLNode({$1, $3}, Operator::LESS_THAN_OR_EQUAL, VSLNodeType::BINARY_EXPRESSION); }
| Expression ">=" Expression { $$ = VSLNode({$1, $3}, Operator::GREATER_THAN_OR_EQUAL, VSLNodeType::BINARY_EXPRESSION); }
| Expression "<" Expression { $$ = VSLNode({$1, $3}, Operator::LESS_THAN, VSLNodeType::BINARY_EXPRESSION); }
| Expression ">" Expression { $$ = VSLNode({$1, $3}, Operator::GREATER_THAN, VSLNodeType::BINARY_EXPRESSION); }
| Assignable "=" Expression { $$ = VSLNode({$1, $3}, Operator::ASSIGN, VSLNodeType::BINARY_EXPRESSION); }
| Assignable ":=" Expression { $$ = VSLNode({$1, $3}, Operator::STRICT_ASSIGN, VSLNodeType::BINARY_EXPRESSION); }
| Expression "&=" Expression { $$ = VSLNode({$1, $3}, Operator::BITWISE_AND_EQUALS, VSLNodeType::BINARY_EXPRESSION); }
| Expression "|=" Expression { $$ = VSLNode({$1, $3}, Operator::BITWISE_OR_EQUALS, VSLNodeType::BINARY_EXPRESSION); }
| Expression "^=" Expression { $$ = VSLNode({$1, $3}, Operator::BITWISE_XOR_EQUALS, VSLNodeType::BINARY_EXPRESSION); }
| Expression "&" Expression { $$ = VSLNode({$1, $3}, Operator::BITWISE_AND, VSLNodeType::BINARY_EXPRESSION); }
| Expression "|" Expression { $$ = VSLNode({$1, $3}, Operator::BITWISE_OR, VSLNodeType::BINARY_EXPRESSION); }
| Expression "^" Expression { $$ = VSLNode({$1, $3}, Operator::BITWISE_XOR, VSLNodeType::BINARY_EXPRESSION); }
| Expression "&&" Expression { $$ = VSLNode({$1, $3}, Operator::LOGICAL_AND, VSLNodeType::BINARY_EXPRESSION); }
| Expression "||" Expression { $$ = VSLNode({$1, $3}, Operator::LOGICAL_OR, VSLNodeType::BINARY_EXPRESSION); }
| Expression "xor" Expression { $$ = VSLNode({$1, $3}, Operator::LOGICAL_XOR, VSLNodeType::BINARY_EXPRESSION); }
| Expression "::" Expression { $$ = VSLNode({$1, $3}, Operator::CAST, VSLNodeType::BINARY_EXPRESSION); }
| Expression "->" Expression { $$ = VSLNode({$1, $3}, Operator::MAP, VSLNodeType::BINARY_EXPRESSION); }
| Expression ":>" Expression { $$ = VSLNode({$1, $3}, Operator::CHAIN, VSLNodeType::BINARY_EXPRESSION); }
| Expression IS Expression { $$ = VSLNode({$1, $3}, Operator::IS, VSLNodeType::BINARY_EXPRESSION); }
| Expression ISSUB Expression { $$ = VSLNode({$1, $3}, Operator::ISSUB, VSLNodeType::BINARY_EXPRESSION); }
| "~" Expression %prec PREFIX { $$ = VSLNode({$2}, Operator::BITWISE_NOT, VSLNodeType::UNARY_EXPRESSION); }
| "!" Expression %prec PREFIX { $$ = VSLNode({$2}, Operator::LOGICAL_NOT, VSLNodeType::UNARY_EXPRESSION); }
| "+" Expression %prec PREFIX { $$ = VSLNode({$2}, Operator::POSITIVE, VSLNodeType::UNARY_EXPRESSION); }
| "-" Expression %prec PREFIX { $$ = VSLNode({$2}, Operator::NEGATE, VSLNodeType::UNARY_EXPRESSION); }
| ExpressionItem { std::swap($$, $1); }
  ;

ParenthesizedExpression:
  "(" Expression ")" { $$ = $2; }
  ;

Assignable:
  ExpressionItem ":" IDENTIFIER { $$ = VSLNode({$1, $3}, VSLNodeType::TYPED); }
| ExpressionItem { std::swap($$, $1); }
  ;

VariableDeclaration:
  DeclarationModifier Assignable "=" Expression { $$ = VSLNode({VSLNode({$1, $2}, VSLNodeType::VARIABLE_DECLARATION), $4}, Operator::ASSIGN, VSLNodeType::BINARY_EXPRESSION); }
| DeclarationModifier Assignable { $$ = VSLNode({$1, $2}, VSLNodeType::VARIABLE_DECLARATION); }
  ;

DeclarationModifier:
  VAR { $$ = VSLNode("var", VSLNodeType::DATA); }
| LET { $$ = VSLNode("let", VSLNodeType::DATA); }
| FINAL { $$ = VSLNode("final", VSLNodeType::DATA); }
| CONST { $$ = VSLNode("const", VSLNodeType::DATA); }
  ;

ExpressionItem:
  Property { std::swap($$, $1); }
  ;

If:
  IF CommandChain "{" Program "}" { $$ = VSLNode({$1, $2}, VSLNodeType::IF); }
| IF Expressions Expression { $$ = VSLNode({$1, $2}, VSLNodeType::IF); } // TODO: ono this bork everything?
  ;
  
For:
  FOR CommandChain "{" Program "}" //{ $$ = VSLNode({$1, $2}, VSLNodeType::For); }
| FOR Expressions Expression //{ $$ = VSLNode({$1, $2}, VSLNodeType::For); } // TODO: ono this bork everything?
  ;

While:
  WHILE CommandChain "{" Program "}" //{ $$ = VSLNode({$1, $2}, VSLNodeType::While); }
| WHILE Expressions Expression //{ $$ = VSLNode({$1, $2}, VSLNodeType::While); } // TODO: ono this bork everything?
  ;

// Expression Items
Property:
  PropertyPrefix PropertySuffix { $$ = VSLNode({$1, $2}, VSLNodeType::PROPERTY); }
| PropertyPrefix { std::swap($$, $1); }
  ;

PropertyPrefix:
  Literal { std::swap($$, $1); }
| IDENTIFIER { std::swap($$, $1); }
| ParenthesizedExpression { std::swap($$, $1); }
  ;

PropertySuffix:
  PropertySuffix PropertySuffixItem { $1.add($2); std::swap($$, $1); }
| PropertySuffixItem { $$ = VSLNode({$1}, VSLNodeType::PROPERTY_SUFFIX); }
  ;

PropertySuffixItem:
  "." IDENTIFIER { std::swap($$, $2); }
| "[" Expressions "]" { $$ = VSLNode({$2.children}, VSLNodeType::SUBSCRIPT); }
| "(" Expressions ")" { $$ = VSLNode({$2.children}, VSLNodeType::CALL); }
| "(" ")" { $$ = VSLNode(VSLNodeType::CALL); }
  ;

// Literals
Literal:
  Number { std::swap($$, $1); }
| String { std::swap($$, $1); }
| Array { std::swap($$, $1); }
| Tuple { std::swap($$, $1); }
| Set { std::swap($$, $1); }
| Regex { std::swap($$, $1); }
  ;

Number:
  NUMBER { $$ = VSLNode({$1}, VSLNodeType::NUMBER); }
  ;

String:
  SINGLE_QUOTED_STRING { $$ = VSLNode({$1}, VSLNodeType::STRING); }
| DOUBLE_QUOTED_STRING { $$ = VSLNode({$1}, VSLNodeType::STRING); }
  ;

Array:
  "[" Expressions "]" { $$ = VSLNode({$2}, VSLNodeType::ARRAY); }
  ;

Tuple:
  "(" Expressions "," Expression ")" { $2.add($4); $$ = VSLNode({$2.children}, VSLNodeType::TUPLE); }
| "(" Expression "," ")" { $$ = VSLNode({$2}, VSLNodeType::TUPLE); }
  ;

Set:
  "{" Expressions "}" { $$ = VSLNode({$2.children}, VSLNodeType::SET); }
| "{" Expression "," "}" { $$ = VSLNode({$2}, VSLNodeType::SET); }
  ;

Dictionary:
  "{" KeyValuePairs "}" { $$ = VSLNode({$2.children}, VSLNodeType::DICTIONARY); }
| "{" KeyValuePair "," "}" { $$ = VSLNode({$2}, VSLNodeType::DICTIONARY); }

Regex:
  REGEX { $$ = VSLNode({$1}, VSLNodeType::REGEX); }
  ;

KeyValuePairs:
  KeyValuePairs KeyValuePair { $1.add($2); std::swap($$, $1); }
| { $$ = VSLNode(VSLNodeType::KEY_VALUE_PAIRS); }
  ;

KeyValuePair:
  Expression ":" Expression { $$ = VSLNode({$1, $3}, VSLNodeType::KEY_VALUE_PAIR); }
  ;

Function:
  FUNCTION Arguments "{" Program "}" { $$ = VSLNode({$2, $4}, VSLNodeType::FUNCTION); }
| FUNCTION IDENTIFIER Arguments "{" Program "}" { $$ = VSLNode({$2, $3, $5}, VSLNodeType::FUNCTION); }
  ;
//TODO: allow function without keyword?

Class:
  CLASS Arguments OptionalIdentifier Extends "{" Program "}"
  ;

Arguments:
  "(" Declarations ")" { $$ = VSLNode({$2}, VSLNodeType::ARGUMENTS); }
| "(" ")" { $$ = VSLNode(VSLNodeType::ARGUMENTS); }
|
  ;

Declarations:
  Declarations ":" Declaration
| Declaration
  ;

Declaration:
  IDENTIFIER Type Initializer { $$ = VSLNode({$1, $2, $3}, VSLNodeType::DECLARATION); }
  ;
  
Type:
  ":" IDENTIFIER { $$ = VSLNode({$2}, VSLNodeType::TYPE); }
| { $$ = VSLNode(VSLNodeType::TYPE); }
  ;

Initializer:
  "=" IDENTIFIER { $$ = VSLNode({$2}, VSLNodeType::INITIALIZER); }
| { $$ = VSLNode(VSLNodeType::INITIALIZER); }
  ;

OptionalIdentifier:
  IDENTIFIER
|
  ;

Extends:
| ":" MoreExtends
|
  ;

MoreExtends:
  MoreExtends Identifiers
|
  ;

Identifiers:
  Identifiers IDENTIFIER
| IDENTIFIER
  ;

// Other
StatementTerminator:
  SEMICOLON
|
  ;
%%

int main(int, char**) {
    yyparse();
}

void yyerror(const char *message) {
    std::cout << "ParseError: " << message << std::endl;
    exit(1);
}

/*     ___.
 *   //  \\
 *  ((   ''
 *   \\__,
 *  /6 (%)\,
 * (__/:";,;\--____----_
 *  ;; :';,:';`;,';,;';`,`_
 *    ;:,;;';';,;':,';';,-Y\
 *     ;,;,;';';,;':;';'; Z/
 *     / ;,';';,;';,;';;'
 *    / / |';/~~~~~\';;'
 *   ( K  | |      || |
 *    \_\ | |      || |      
 *     \Z | |      || |
 *        L_|      LL_|
 *        LW/      LLW/
 */
