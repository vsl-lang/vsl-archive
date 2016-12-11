/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_GEN_PARSER_HPP_INCLUDED
# define YY_YY_GEN_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 18 "parser.y" /* yacc.c:1909  */

#include "run.hpp"

#line 48 "gen/parser.hpp" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    RANGE = 258,
    DOT = 259,
    SEMICOLON = 260,
    COLON = 261,
    COMMA = 262,
    PLUS_EQUALS = 263,
    MINUS_EQUALS = 264,
    TIMES_EQUALS = 265,
    DIVIDE_EQUALS = 266,
    MODULO_EQUALS = 267,
    POWER_EQUALS = 268,
    PLUS = 269,
    MINUS = 270,
    TIMES = 271,
    DIVIDE = 272,
    MODULO = 273,
    POWER = 274,
    LEFT_SHIFT_EQUALS = 275,
    RIGHT_SHIFT_EQUALS = 276,
    LEFT_SHIFT = 277,
    RIGHT_SHIFT = 278,
    EQUAL = 279,
    NOT_EQUAL = 280,
    SPACESHIP = 281,
    LESS_THAN_OR_EQUAL = 282,
    GREATER_THAN_OR_EQUAL = 283,
    LESS_THAN = 284,
    GREATER_THAN = 285,
    ASSIGN = 286,
    STRICT_ASSIGN = 287,
    BITWISE_AND_EQUALS = 288,
    BITWISE_OR_EQUALS = 289,
    BITWISE_XOR_EQUALS = 290,
    BITWISE_AND = 291,
    BITWISE_OR = 292,
    BITWISE_NOT = 293,
    BITWISE_XOR = 294,
    LOGICAL_AND = 295,
    LOGICAL_OR = 296,
    LOGICAL_NOT = 297,
    LOGICAL_XOR = 298,
    CAST = 299,
    MAP = 300,
    CHAIN = 301,
    LEFT_BRACE = 302,
    RIGHT_BRACE = 303,
    LEFT_PARENTHESIS = 304,
    RIGHT_PARENTHESIS = 305,
    LEFT_BRACKET = 306,
    RIGHT_BRACKET = 307,
    LAMBDA = 308,
    VAR = 309,
    LET = 310,
    FINAL = 311,
    CONST = 312,
    IS = 313,
    ISSUB = 314,
    FUNCTION = 315,
    CLASS = 316,
    INTERFACE = 317,
    TRAIT = 318,
    ENUM = 319,
    IDENTIFIER = 320,
    SPECIAL_IDENTIFIER = 321,
    SPECIAL_ARGUMENT = 322,
    SPECIAL_LOOP_ARGUMENT = 323,
    NUMBER = 324,
    SINGLE_QUOTED_STRING = 325,
    DOUBLE_QUOTED_STRING = 326,
    REGEX = 327,
    CC = 328,
    EXPRESSIONS = 329,
    PREFIX = 330
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef Node YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GEN_PARSER_HPP_INCLUDED  */
