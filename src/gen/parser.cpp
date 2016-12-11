/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

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

#line 83 "gen/parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
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
#line 18 "parser.y" /* yacc.c:355  */

#include "run.hpp"

#line 117 "gen/parser.cpp" /* yacc.c:355  */

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

/* Copy the second part of user declarations.  */

#line 216 "gen/parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   688

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  195

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   330

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   115,   115,   116,   120,   121,   122,   123,   128,   129,
     133,   134,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   187,   188,   192,
     193,   197,   198,   199,   200,   204,   209,   210,   214,   215,
     216,   220,   221,   225,   226,   227,   228,   233,   234,   235,
     236,   237,   238,   242,   246,   247,   251,   255,   256,   260,
     261,   265,   269,   273,   277,   278,   279,   283,   284,   288,
     292,   293,   297,   298,   302,   303,   307,   308,   309,   310,
     314,   315,   320,   321
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"..\"", "\".\"", "\";\"", "\":\"",
  "\",\"", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"%=\"", "\"**=\"",
  "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"%\"", "\"**\"", "\"<<=\"",
  "\">>=\"", "\"<<\"", "\">>\"", "\"==\"", "\"!=\"", "\"<=>\"", "\"<=\"",
  "\">=\"", "\"<\"", "\">\"", "\"=\"", "\":=\"", "\"&=\"", "\"|=\"",
  "\"^=\"", "\"&\"", "\"|\"", "\"~\"", "\"^\"", "\"&&\"", "\"||\"",
  "\"!\"", "\"xor\"", "\"::\"", "\"->\"", "\":>\"", "\"{\"", "\"}\"",
  "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"=>\"", "VAR", "LET", "FINAL",
  "CONST", "IS", "ISSUB", "FUNCTION", "CLASS", "INTERFACE", "TRAIT",
  "ENUM", "IDENTIFIER", "SPECIAL_IDENTIFIER", "SPECIAL_ARGUMENT",
  "SPECIAL_LOOP_ARGUMENT", "NUMBER", "SINGLE_QUOTED_STRING",
  "DOUBLE_QUOTED_STRING", "REGEX", "CC", "EXPRESSIONS", "PREFIX",
  "$accept", "Program", "Statement", "CommandChain", "Expressions",
  "Expression", "Assignable", "VariableDeclaration", "DeclarationModifier",
  "ExpressionItem", "Property", "PropertyPrefix", "PropertySuffix",
  "PropertySuffixItem", "Literal", "Number", "String", "Array", "Tuple",
  "Set", "Regex", "Function", "Class", "Arguments", "Declarations",
  "Declaration", "Type", "Initializer", "OptionalIdentifier", "Extends",
  "Identifiers", "StatementTerminator", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330
};
# endif

#define YYPACT_NINF -93

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-93)))

#define YYTABLE_NINF -59

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-59)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -93,    93,   -93,   197,   197,   197,   197,   197,   197,   197,
     -93,   -93,   -93,   -93,   -15,   -15,   -93,   -93,   -93,   -93,
     -93,    27,   197,    28,   424,   -18,   -93,    67,    98,   -93,
      47,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,     2,   320,    32,   267,    94,   -17,
      -4,   -16,   -93,   -93,    28,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,    74,   103,    45,    46,
     171,   197,    47,   -93,   -93,    64,   197,    63,   -93,   -93,
     -93,   109,    91,   -93,   -93,   -93,   111,   424,   476,   528,
     528,   528,   528,   528,   528,   642,   642,   626,   626,   626,
     626,   528,   528,   638,   638,   215,   215,   215,   215,   215,
     215,   215,   528,   528,   528,   -34,   -34,   -34,   605,   594,
     561,    75,    75,    75,     1,     1,   528,   528,   197,   -93,
     -93,   -93,    95,    99,   -93,   -93,   372,   -93,    55,    90,
      57,   -93,   119,    30,    76,   424,   -93,   -93,   -93,   -93,
      59,   -93,   -93,   -93,    60,   120,   -93,   -93,   -93,    62,
      60,   145,   -93,    62,   -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,     0,     0,     0,     0,     0,     0,
      61,    62,    63,    64,    96,    96,    69,    83,    84,    85,
      91,   113,     7,     9,    11,     0,     4,     0,    56,    65,
      67,    68,    77,    78,    79,    80,    81,    82,     5,     6,
      54,    55,    52,    53,     0,    11,     0,     0,     0,     0,
       0,   105,   112,     2,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,    58,     0,     0,
       0,     0,    66,    72,    89,     0,     0,     0,    70,    86,
      95,   101,     0,    98,     3,   104,   109,    10,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    36,    37,     0,    57,
      73,    76,     0,     0,    71,    90,    10,    88,     0,   103,
       0,    94,     0,     0,     0,    59,    75,    74,    87,   100,
       0,    99,    97,    92,     0,   107,     3,   102,   111,   108,
       0,     0,   110,   106,    93
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -92,   -93,   -93,    -1,    -3,   101,   -93,   -93,   116,
     -93,   -93,   -93,    50,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   141,   -93,     7,   -93,   -93,   -93,   -93,
     -21,   -93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,   102,   103,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    50,   112,   113,   169,   181,   116,   174,
     189,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    41,    42,    43,    45,    47,    44,    46,    48,    55,
      89,    90,    91,    94,    95,    63,    64,    65,    66,    67,
      68,    54,   172,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    52,   110,    49,    55,   184,    83,    84,   106,
      85,    86,    87,   114,    88,    89,    90,    91,   111,   115,
     104,    99,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     2,   191,   185,   100,   170,   101,   162,
     163,    55,    55,   166,    98,   158,    55,     3,     4,    98,
     159,   160,   165,   167,     7,   168,     8,   173,     9,    89,
     179,   180,   111,   186,   187,   188,   190,   192,    96,   -58,
     -58,     5,    16,     3,     4,     6,    17,    18,    19,    20,
       7,   171,     8,    97,     9,   176,   109,    10,    11,    12,
      13,   177,   164,    14,    15,   175,    51,     5,    16,     3,
       4,     6,    17,    18,    19,    20,     7,   183,     8,   193,
       9,     0,     0,    10,    11,    12,    13,   182,     0,    14,
      15,     0,     0,     5,    16,     3,     4,     6,    17,    18,
      19,    20,     7,   194,     8,     0,     9,     0,     0,    10,
      11,    12,    13,     0,     0,    14,    15,     0,     0,     5,
      16,     3,     4,     6,    17,    18,    19,    20,     7,     0,
       8,   161,     9,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,     5,    16,    71,    72,     6,
      17,    18,    19,    20,     7,     0,     8,     0,     9,     0,
       0,    83,    84,     0,    85,    86,    87,     0,    88,    89,
      90,    91,    16,     0,     0,     0,    17,    18,    19,    20,
      56,     0,     0,     0,   107,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,     0,     0,
      80,    81,    82,    83,    84,     0,    85,    86,    87,     0,
      88,    89,    90,    91,     0,     0,     0,   108,     0,     0,
       0,     0,     0,    56,     0,    92,    93,   105,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,     0,    80,    81,    82,    83,    84,     0,    85,
      86,    87,     0,    88,    89,    90,    91,     0,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,    92,    93,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,    80,    81,    82,    83,    84,
       0,    85,    86,    87,     0,    88,    89,    90,    91,     0,
       0,     0,   178,     0,     0,     0,     0,    56,     0,     0,
      92,    93,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,     0,    80,    81,    82,
      83,    84,     0,    85,    86,    87,     0,    88,    89,    90,
      91,     0,     0,     0,     0,     0,     0,     0,     0,   -59,
       0,     0,    92,    93,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,     0,     0,    80,
      81,    82,    83,    84,     0,    85,    86,    87,     0,    88,
      89,    90,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,    93,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,    80,    81,    82,    83,    84,     0,    85,    86,    87,
       0,    88,    89,    90,    91,    63,    64,    65,    66,    67,
      68,     0,     0,    71,    72,     0,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,    84,     0,
      85,    86,    87,     0,     0,    89,    90,    91,    63,    64,
      65,    66,    67,    68,     0,     0,    71,    72,     0,    63,
      64,    65,    66,    67,    68,     0,     0,    71,    72,     0,
      83,    84,     0,    85,    86,     0,     0,     0,    89,    90,
      91,    83,    84,     0,    85,    68,     0,     0,     0,    89,
      90,    91,    63,    64,    65,    66,    67,    68,    65,    66,
      67,    68,    83,    84,     0,    85,     0,     0,     0,     0,
      89,    90,    91,     0,    83,    84,     0,    85,    83,    84,
       0,    85,    89,    90,    91,     0,    89,    90,    91
};

static const yytype_int16 yycheck[] =
{
       3,     4,     5,     6,     7,     8,     7,     8,     9,     7,
      44,    45,    46,    31,    32,    14,    15,    16,    17,    18,
      19,    22,   114,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     5,    50,    49,     7,     6,    36,    37,     7,
      39,    40,    41,    47,    43,    44,    45,    46,    65,    65,
      48,     4,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,   186,    65,    49,     6,    51,   100,
     101,     7,     7,   106,     6,    31,     7,    14,    15,     6,
      65,    65,    48,    50,    47,     6,    49,     6,    51,    44,
      65,    31,    65,    47,    65,    65,     6,    65,    27,    31,
      32,    38,    65,    14,    15,    42,    69,    70,    71,    72,
      47,    50,    49,    27,    51,    50,    52,    54,    55,    56,
      57,    52,   102,    60,    61,   158,    15,    38,    65,    14,
      15,    42,    69,    70,    71,    72,    47,    48,    49,   190,
      51,    -1,    -1,    54,    55,    56,    57,   170,    -1,    60,
      61,    -1,    -1,    38,    65,    14,    15,    42,    69,    70,
      71,    72,    47,    48,    49,    -1,    51,    -1,    -1,    54,
      55,    56,    57,    -1,    -1,    60,    61,    -1,    -1,    38,
      65,    14,    15,    42,    69,    70,    71,    72,    47,    -1,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    19,    38,    65,    22,    23,    42,
      69,    70,    71,    72,    47,    -1,    49,    -1,    51,    -1,
      -1,    36,    37,    -1,    39,    40,    41,    -1,    43,    44,
      45,    46,    65,    -1,    -1,    -1,    69,    70,    71,    72,
       3,    -1,    -1,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
      33,    34,    35,    36,    37,    -1,    39,    40,    41,    -1,
      43,    44,    45,    46,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    58,    59,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    -1,    33,    34,    35,    36,    37,    -1,    39,
      40,    41,    -1,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    58,    59,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    33,    34,    35,    36,    37,
      -1,    39,    40,    41,    -1,    43,    44,    45,    46,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,     3,    -1,    -1,
      58,    59,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    33,    34,    35,
      36,    37,    -1,    39,    40,    41,    -1,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    58,    59,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    33,
      34,    35,    36,    37,    -1,    39,    40,    41,    -1,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    33,    34,    35,    36,    37,    -1,    39,    40,    41,
      -1,    43,    44,    45,    46,    14,    15,    16,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,
      39,    40,    41,    -1,    -1,    44,    45,    46,    14,    15,
      16,    17,    18,    19,    -1,    -1,    22,    23,    -1,    14,
      15,    16,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      36,    37,    -1,    39,    40,    -1,    -1,    -1,    44,    45,
      46,    36,    37,    -1,    39,    19,    -1,    -1,    -1,    44,
      45,    46,    14,    15,    16,    17,    18,    19,    16,    17,
      18,    19,    36,    37,    -1,    39,    -1,    -1,    -1,    -1,
      44,    45,    46,    -1,    36,    37,    -1,    39,    36,    37,
      -1,    39,    44,    45,    46,    -1,    44,    45,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    77,     0,    14,    15,    38,    42,    47,    49,    51,
      54,    55,    56,    57,    60,    61,    65,    69,    70,    71,
      72,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      81,    81,    81,    81,    80,    81,    80,    81,    80,    49,
      99,    99,     5,   107,    80,     7,     3,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      33,    34,    35,    36,    37,    39,    40,    41,    43,    44,
      45,    46,    58,    59,    31,    32,    82,    85,     6,     4,
      49,    51,    88,    89,    48,     7,     7,     7,    50,    52,
      50,    65,   100,   101,    47,    65,   104,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    31,    65,
      65,    50,    80,    80,    89,    48,    81,    50,     6,   102,
       6,    50,    77,     6,   105,    81,    50,    52,    50,    65,
      31,   103,   101,    48,     6,    65,    47,    65,    65,   106,
       6,    77,    65,   106,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    77,    78,    78,    78,    78,    79,    79,
      80,    80,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    84,    85,    86,    86,    87,    87,
      87,    88,    88,    89,    89,    89,    89,    90,    90,    90,
      90,    90,    90,    91,    92,    92,    93,    94,    94,    95,
      95,    96,    97,    98,    99,    99,    99,   100,   100,   101,
     102,   102,   103,   103,   104,   104,   105,   105,   105,   105,
     106,   106,   107,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     1,     1,     1,     1,     2,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     1,     3,     1,     4,
       2,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       3,     2,     1,     2,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     5,     4,     3,
       4,     1,     5,     7,     3,     2,     0,     3,     1,     3,
       2,     0,     2,     0,     1,     0,     4,     2,     3,     0,
       2,     1,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2]).add((yyvsp[-1])); std::swap((yyval), (yyvsp[-2])); std::cout << std::endl << (yyvsp[-1]).run(); }
#line 1545 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval) = ProgramNode(); }
#line 1551 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval) = StatementNode({(yyvsp[0])}); }
#line 1557 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval) = StatementNode({(yyvsp[0])}); }
#line 1563 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1]).add((yyvsp[0])); std::swap((yyval), (yyvsp[-1])); }
#line 1569 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval) = CommandChainNode({(yyvsp[0])}); }
#line 1575 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 133 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2]).add((yyvsp[0])); std::swap((yyval), (yyvsp[-2])); }
#line 1581 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 134 "parser.y" /* yacc.c:1646  */
    { (yyval) = TupleNode({(yyvsp[0])}); }
#line 1587 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::RANGE, (yyvsp[-2]), (yyvsp[0])); }
#line 1593 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::PLUS_EQUALS, (yyvsp[-2]), (yyvsp[0])); }
#line 1599 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::MINUS_EQUALS, (yyvsp[-2]), (yyvsp[0])); }
#line 1605 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::TIMES_EQUALS, (yyvsp[-2]), (yyvsp[0])); }
#line 1611 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::DIVIDE_EQUALS, (yyvsp[-2]), (yyvsp[0])); }
#line 1617 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::MODULO_EQUALS, (yyvsp[-2]), (yyvsp[0])); }
#line 1623 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::POWER_EQUALS, (yyvsp[-2]), (yyvsp[0])); }
#line 1629 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::PLUS, (yyvsp[-2]), (yyvsp[0])); }
#line 1635 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::MINUS, (yyvsp[-2]), (yyvsp[0])); }
#line 1641 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::TIMES, (yyvsp[-2]), (yyvsp[0])); }
#line 1647 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 149 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::DIVIDE, (yyvsp[-2]), (yyvsp[0])); }
#line 1653 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::MODULO, (yyvsp[-2]), (yyvsp[0])); }
#line 1659 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::POWER, (yyvsp[-2]), (yyvsp[0])); }
#line 1665 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::LEFT_SHIFT_EQUALS, (yyvsp[-2]), (yyvsp[0])); }
#line 1671 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::RIGHT_SHIFT_EQUALS, (yyvsp[-2]), (yyvsp[0])); }
#line 1677 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 154 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::LEFT_SHIFT, (yyvsp[-2]), (yyvsp[0])); }
#line 1683 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::RIGHT_SHIFT, (yyvsp[-2]), (yyvsp[0])); }
#line 1689 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::EQUAL, (yyvsp[-2]), (yyvsp[0])); }
#line 1695 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::NOT_EQUAL, (yyvsp[-2]), (yyvsp[0])); }
#line 1701 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::SPACESHIP, (yyvsp[-2]), (yyvsp[0])); }
#line 1707 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::LESS_THAN_OR_EQUAL, (yyvsp[-2]), (yyvsp[0])); }
#line 1713 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::GREATER_THAN_OR_EQUAL, (yyvsp[-2]), (yyvsp[0])); }
#line 1719 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::LESS_THAN, (yyvsp[-2]), (yyvsp[0])); }
#line 1725 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::GREATER_THAN, (yyvsp[-2]), (yyvsp[0])); }
#line 1731 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::ASSIGN, (yyvsp[-2]), (yyvsp[0])); }
#line 1737 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::STRICT_ASSIGN, (yyvsp[-2]), (yyvsp[0])); }
#line 1743 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::BITWISE_AND_EQUALS, (yyvsp[-2]), (yyvsp[0])); }
#line 1749 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::BITWISE_OR_EQUALS, (yyvsp[-2]), (yyvsp[0])); }
#line 1755 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::BITWISE_XOR_EQUALS, (yyvsp[-2]), (yyvsp[0])); }
#line 1761 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::BITWISE_AND, (yyvsp[-2]), (yyvsp[0])); }
#line 1767 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::BITWISE_OR, (yyvsp[-2]), (yyvsp[0])); }
#line 1773 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::BITWISE_XOR, (yyvsp[-2]), (yyvsp[0])); }
#line 1779 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::LOGICAL_AND, (yyvsp[-2]), (yyvsp[0])); }
#line 1785 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::LOGICAL_OR, (yyvsp[-2]), (yyvsp[0])); }
#line 1791 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::LOGICAL_XOR, (yyvsp[-2]), (yyvsp[0])); }
#line 1797 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::CAST, (yyvsp[-2]), (yyvsp[0])); }
#line 1803 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::MAP, (yyvsp[-2]), (yyvsp[0])); }
#line 1809 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::CHAIN, (yyvsp[-2]), (yyvsp[0])); }
#line 1815 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::IS, (yyvsp[-2]), (yyvsp[0])); }
#line 1821 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::ISSUB, (yyvsp[-2]), (yyvsp[0])); }
#line 1827 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval) = UnaryExpressionNode(Operator::BITWISE_NOT, (yyvsp[0])); }
#line 1833 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval) = UnaryExpressionNode(Operator::LOGICAL_NOT, (yyvsp[0])); }
#line 1839 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyval) = UnaryExpressionNode(Operator::POSITIVE, (yyvsp[0])); }
#line 1845 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval) = UnaryExpressionNode(Operator::NEGATE, (yyvsp[0])); }
#line 1851 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 183 "parser.y" /* yacc.c:1646  */
    { std::swap((yyval), (yyvsp[0])); }
#line 1857 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 187 "parser.y" /* yacc.c:1646  */
    { (yyval) = TypedNode((yyvsp[-2]), (yyvsp[0])); }
#line 1863 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 188 "parser.y" /* yacc.c:1646  */
    { std::swap((yyval), (yyvsp[0])); }
#line 1869 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval) = BinaryExpressionNode(Operator::ASSIGN, (Node) DeclarationNode((yyvsp[-3]), (yyvsp[-2])), (yyvsp[0])); }
#line 1875 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyval) = DeclarationNode((yyvsp[-1]), (yyvsp[0])); }
#line 1881 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval) = DataNode("var"); }
#line 1887 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 198 "parser.y" /* yacc.c:1646  */
    { (yyval) = DataNode("let"); }
#line 1893 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 199 "parser.y" /* yacc.c:1646  */
    { (yyval) = DataNode("final"); }
#line 1899 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval) = DataNode("const"); }
#line 1905 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 204 "parser.y" /* yacc.c:1646  */
    { std::swap((yyval), (yyvsp[0])); }
#line 1911 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval) = PropertyNode((yyvsp[-1]), (yyvsp[0])); }
#line 1917 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 210 "parser.y" /* yacc.c:1646  */
    { std::swap((yyval), (yyvsp[0])); }
#line 1923 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 214 "parser.y" /* yacc.c:1646  */
    { std::swap((yyval), (yyvsp[0])); }
#line 1929 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 215 "parser.y" /* yacc.c:1646  */
    { std::swap((yyval), (yyvsp[0])); }
#line 1935 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 216 "parser.y" /* yacc.c:1646  */
    { std::swap((yyval), (yyvsp[-1])); }
#line 1941 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 220 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1]).add((yyvsp[0])); std::swap((yyval), (yyvsp[-1])); }
#line 1947 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval) = PropertySuffixNode({(yyvsp[0])}); }
#line 1953 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 225 "parser.y" /* yacc.c:1646  */
    { std::swap((yyval), (yyvsp[0])); }
#line 1959 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval) = SubscriptNode((yyvsp[-1]).children); }
#line 1965 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 227 "parser.y" /* yacc.c:1646  */
    { (yyval) = CallNode((yyvsp[-1]).children); }
#line 1971 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 228 "parser.y" /* yacc.c:1646  */
    { (yyval) = CallNode(); }
#line 1977 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 233 "parser.y" /* yacc.c:1646  */
    { std::swap((yyval), (yyvsp[0])); }
#line 1983 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 234 "parser.y" /* yacc.c:1646  */
    { std::swap((yyval), (yyvsp[0])); }
#line 1989 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 235 "parser.y" /* yacc.c:1646  */
    { std::swap((yyval), (yyvsp[0])); }
#line 1995 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 236 "parser.y" /* yacc.c:1646  */
    { std::swap((yyval), (yyvsp[0])); }
#line 2001 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 237 "parser.y" /* yacc.c:1646  */
    { std::swap((yyval), (yyvsp[0])); }
#line 2007 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 238 "parser.y" /* yacc.c:1646  */
    { std::swap((yyval), (yyvsp[0])); }
#line 2013 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 242 "parser.y" /* yacc.c:1646  */
    { (yyval) = NumberNode((yyvsp[0])); }
#line 2019 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 246 "parser.y" /* yacc.c:1646  */
    { (yyval) = StringNode((yyvsp[0])); }
#line 2025 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 247 "parser.y" /* yacc.c:1646  */
    { (yyval) = StringNode((yyvsp[0])); }
#line 2031 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 251 "parser.y" /* yacc.c:1646  */
    { (yyval) = ArrayNode((yyvsp[-1])); }
#line 2037 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 255 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-3]).add((yyvsp[-1])); (yyval) = TupleNode((yyvsp[-3]).children); }
#line 2043 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 256 "parser.y" /* yacc.c:1646  */
    { (yyval) = TupleNode({(yyvsp[-2])}); }
#line 2049 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyval) = SetNode((yyvsp[-1]).children); }
#line 2055 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 261 "parser.y" /* yacc.c:1646  */
    { (yyval) = SetNode({(yyvsp[-2])}); }
#line 2061 "gen/parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 265 "parser.y" /* yacc.c:1646  */
    { (yyval) = RegexNode((yyvsp[0])); }
#line 2067 "gen/parser.cpp" /* yacc.c:1646  */
    break;


#line 2071 "gen/parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 323 "parser.y" /* yacc.c:1906  */


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
