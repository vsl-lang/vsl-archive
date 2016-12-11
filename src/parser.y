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
extern "C" int yylex();
//extern "C" int yyparse();
extern "C" void yyerror(char const*);

void yyerror(const char *message);
%}

%code requires {
#include "run.hpp"
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

%define api.value.type {Node}

%%
Program:
  Program Statement StatementTerminator { $1.add($2); std::swap($$, $1); std::cout << std::endl << $2.run(); }
| { $$ = ProgramNode(); }
  ;

Statement:
  VariableDeclaration { $$ = StatementNode({$1}); }
| Function
| Class
| CommandChain { $$ = StatementNode({$1}); }
  ;

// Top-Level Statements
CommandChain:
  CommandChain Expressions { $1.add($2); std::swap($$, $1); }
| Expressions %prec CC { $$ = CommandChainNode({$1}); }
  ;

Expressions:
  Expressions "," Expression { $1.add($3); std::swap($$, $1); }
| Expression %prec EXPRESSIONS { $$ = TupleNode({$1}); }
  ;

// Expressions
Expression:
  Expression ".." Expression { $$ = BinaryExpressionNode(Operator::RANGE, $1, $3); }
| Expression "+=" Expression { $$ = BinaryExpressionNode(Operator::PLUS_EQUALS, $1, $3); }
| Expression "-=" Expression { $$ = BinaryExpressionNode(Operator::MINUS_EQUALS, $1, $3); }
| Expression "*=" Expression { $$ = BinaryExpressionNode(Operator::TIMES_EQUALS, $1, $3); }
| Expression "/=" Expression { $$ = BinaryExpressionNode(Operator::DIVIDE_EQUALS, $1, $3); }
| Expression "%=" Expression { $$ = BinaryExpressionNode(Operator::MODULO_EQUALS, $1, $3); }
| Expression "**=" Expression { $$ = BinaryExpressionNode(Operator::POWER_EQUALS, $1, $3); }
| Expression "+" Expression { $$ = BinaryExpressionNode(Operator::PLUS, $1, $3); }
| Expression "-" Expression { $$ = BinaryExpressionNode(Operator::MINUS, $1, $3); }
| Expression "*" Expression { $$ = BinaryExpressionNode(Operator::TIMES, $1, $3); }
| Expression "/" Expression { $$ = BinaryExpressionNode(Operator::DIVIDE, $1, $3); }
| Expression "%" Expression { $$ = BinaryExpressionNode(Operator::MODULO, $1, $3); }
| Expression "**" Expression { $$ = BinaryExpressionNode(Operator::POWER, $1, $3); }
| Expression "<<=" Expression { $$ = BinaryExpressionNode(Operator::LEFT_SHIFT_EQUALS, $1, $3); }
| Expression ">>=" Expression { $$ = BinaryExpressionNode(Operator::RIGHT_SHIFT_EQUALS, $1, $3); }
| Expression "<<" Expression { $$ = BinaryExpressionNode(Operator::LEFT_SHIFT, $1, $3); }
| Expression ">>" Expression { $$ = BinaryExpressionNode(Operator::RIGHT_SHIFT, $1, $3); }
| Expression "==" Expression { $$ = BinaryExpressionNode(Operator::EQUAL, $1, $3); }
| Expression "!=" Expression { $$ = BinaryExpressionNode(Operator::NOT_EQUAL, $1, $3); }
| Expression "<=>" Expression { $$ = BinaryExpressionNode(Operator::SPACESHIP, $1, $3); }
| Expression "<=" Expression { $$ = BinaryExpressionNode(Operator::LESS_THAN_OR_EQUAL, $1, $3); }
| Expression ">=" Expression { $$ = BinaryExpressionNode(Operator::GREATER_THAN_OR_EQUAL, $1, $3); }
| Expression "<" Expression { $$ = BinaryExpressionNode(Operator::LESS_THAN, $1, $3); }
| Expression ">" Expression { $$ = BinaryExpressionNode(Operator::GREATER_THAN, $1, $3); }
| Assignable "=" Expression { $$ = BinaryExpressionNode(Operator::ASSIGN, $1, $3); }
| Assignable ":=" Expression { $$ = BinaryExpressionNode(Operator::STRICT_ASSIGN, $1, $3); }
| Expression "&=" Expression { $$ = BinaryExpressionNode(Operator::BITWISE_AND_EQUALS, $1, $3); }
| Expression "|=" Expression { $$ = BinaryExpressionNode(Operator::BITWISE_OR_EQUALS, $1, $3); }
| Expression "^=" Expression { $$ = BinaryExpressionNode(Operator::BITWISE_XOR_EQUALS, $1, $3); }
| Expression "&" Expression { $$ = BinaryExpressionNode(Operator::BITWISE_AND, $1, $3); }
| Expression "|" Expression { $$ = BinaryExpressionNode(Operator::BITWISE_OR, $1, $3); }
| Expression "^" Expression { $$ = BinaryExpressionNode(Operator::BITWISE_XOR, $1, $3); }
| Expression "&&" Expression { $$ = BinaryExpressionNode(Operator::LOGICAL_AND, $1, $3); }
| Expression "||" Expression { $$ = BinaryExpressionNode(Operator::LOGICAL_OR, $1, $3); }
| Expression "xor" Expression { $$ = BinaryExpressionNode(Operator::LOGICAL_XOR, $1, $3); }
| Expression "::" Expression { $$ = BinaryExpressionNode(Operator::CAST, $1, $3); }
| Expression "->" Expression { $$ = BinaryExpressionNode(Operator::MAP, $1, $3); }
| Expression ":>" Expression { $$ = BinaryExpressionNode(Operator::CHAIN, $1, $3); }
| Expression IS Expression { $$ = BinaryExpressionNode(Operator::IS, $1, $3); }
| Expression ISSUB Expression { $$ = BinaryExpressionNode(Operator::ISSUB, $1, $3); }
| "~" Expression %prec PREFIX { $$ = UnaryExpressionNode(Operator::BITWISE_NOT, $2); }
| "!" Expression %prec PREFIX { $$ = UnaryExpressionNode(Operator::LOGICAL_NOT, $2); }
| "+" Expression %prec PREFIX { $$ = UnaryExpressionNode(Operator::POSITIVE, $2); }
| "-" Expression %prec PREFIX { $$ = UnaryExpressionNode(Operator::NEGATE, $2); }
| ExpressionItem { std::swap($$, $1); }
  ;

Assignable:
  ExpressionItem ":" IDENTIFIER { $$ = TypedNode($1, $3); }
| ExpressionItem { std::swap($$, $1); }
  ;

VariableDeclaration:
  DeclarationModifier Assignable "=" Expression { $$ = BinaryExpressionNode(Operator::ASSIGN, (Node) DeclarationNode($1, $2), $4); }
| DeclarationModifier Assignable { $$ = DeclarationNode($1, $2); }
  ;

DeclarationModifier:
  VAR { $$ = DataNode("var"); }
| LET { $$ = DataNode("let"); }
| FINAL { $$ = DataNode("final"); }
| CONST { $$ = DataNode("const"); }
  ;

ExpressionItem:
  Property { std::swap($$, $1); }
  ;

// Expression Items
Property:
  PropertyPrefix PropertySuffix { $$ = PropertyNode($1, $2); }
| PropertyPrefix { std::swap($$, $1); }
  ;

PropertyPrefix:
  Literal { std::swap($$, $1); }
| IDENTIFIER { std::swap($$, $1); }
| "(" Expression ")" { std::swap($$, $2); }
  ;

PropertySuffix:
  PropertySuffix PropertySuffixItem { $1.add($2); std::swap($$, $1); }
| PropertySuffixItem { $$ = PropertySuffixNode({$1}); }
  ;

PropertySuffixItem:
  "." IDENTIFIER { std::swap($$, $2); }
| "[" Expressions "]" { $$ = SubscriptNode($2.children); }
| "(" Expressions ")" { $$ = CallNode($2.children); }
| "(" ")" { $$ = CallNode(); }
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
  NUMBER { $$ = NumberNode($1); }
  ;

String:
  SINGLE_QUOTED_STRING { $$ = StringNode($1); }
| DOUBLE_QUOTED_STRING { $$ = StringNode($1); }
  ;

Array:
  "[" Expressions "]" { $$ = ArrayNode($2); }
  ;

Tuple:
  "(" Expressions "," Expression ")" { $2.add($4); $$ = TupleNode($2.children); }
| "(" Expression "," ")" { $$ = TupleNode({$2}); }
  ;

Set:
  "{" Expressions "}" { $$ = SetNode($2.children); }
| "{" Expression "," "}" { $$ = SetNode({$2}); }
  ;

Regex:
  REGEX { $$ = RegexNode($1); }
  ;

Function:
  FUNCTION Arguments "{" Program "}"
  ;

Class:
  CLASS Arguments OptionalIdentifier Extends "{" Program "}"
  ;

Arguments:
  "(" Declarations ")"
| "(" ")"
|
  ;

Declarations:
  Declarations ":" Declaration
| Declaration
  ;

Declaration:
  IDENTIFIER Type Initializer
  ;
  
Type:
  ":" IDENTIFIER
|
  ;

Initializer:
  "=" IDENTIFIER
|
  ;

OptionalIdentifier:
  IDENTIFIER
|
  ;

Extends:
  ":" IDENTIFIER ":" Identifiers
| ":" IDENTIFIER
| ":" ":" Identifiers
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
