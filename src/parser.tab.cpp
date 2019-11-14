/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.ypp" /* yacc.c:337  */

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" voIDENTIFIER yyerror(char *s);
extern "C" int yywrap(void){return 1;};




#line 88 "parser.tab.cpp" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
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
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BREAK = 258,
    CLASS = 259,
    CONTINUE = 260,
    ELSE = 261,
    EXTENDS = 262,
    IF = 263,
    NEW = 264,
    PRIVATE = 265,
    PROTECTED = 266,
    PUBLIC = 267,
    RETURN = 268,
    STATIC = 269,
    SUPER = 270,
    TYPE_VOID = 271,
    TYPE_INT = 272,
    TYPE_BOOL = 273,
    TYPE_CHAR = 274,
    THIS = 275,
    WHILE = 276,
    FORBIDDEN = 277,
    UNENDED_COM = 278,
    LEQ = 279,
    LESS = 280,
    GREATER = 281,
    EQEQ = 282,
    GEQ = 283,
    EQ = 284,
    NEQ = 285,
    LAND = 286,
    LOR = 287,
    PLUS = 288,
    MINUS = 289,
    TIMES = 290,
    DIV = 291,
    MOD = 292,
    NOT = 293,
    OP = 294,
    CP = 295,
    OB = 296,
    CB = 297,
    OC = 298,
    CC = 299,
    COMMA = 300,
    DOT = 301,
    SEMICOLON = 302,
    IDENTIFIER = 303,
    NILL = 304,
    BOOLEAN = 305,
    INTEGER = 306,
    STRING = 307,
    CHAR = 308,
    UNRECOG_ERROR = 309,
    TYPER_INT = 310,
    VOID = 311,
    UMINUS = 312,
    UPLUS = 313,
    ADD = 314,
    SUBS = 315,
    LOWER_THAN_IF = 316
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   516

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  194

#define YYUNDEFTOK  2
#define YYMAXUTOK   316

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,    97,   101,   103,   105,   107,   111,   115,
     116,   120,   121,   122,   126,   129,   135,   136,   140,   141,
     145,   146,   150,   151,   152,   153,   157,   158,   162,   163,
     167,   194,   195,   196,   197,   201,   202,   206,   207,   208,
     209,   213,   214,   218,   222,   229,   230,   234,   235,   239,
     240,   244,   245,   246,   248,   250,   251,   252,   253,   254,
     255,   256,   257,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   282,   285,   288,   292,   295,   301,   302,   306,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   322,   323,
     327,   330,   336,   337,   338,   339,   340,   344,   345,   349,
     350
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BREAK", "CLASS", "CONTINUE", "ELSE",
  "EXTENDS", "IF", "NEW", "PRIVATE", "PROTECTED", "PUBLIC", "RETURN",
  "STATIC", "SUPER", "TYPE_VOID", "TYPE_INT", "TYPE_BOOL", "TYPE_CHAR",
  "THIS", "WHILE", "FORBIDDEN", "UNENDED_COM", "LEQ", "LESS", "GREATER",
  "EQEQ", "GEQ", "EQ", "NEQ", "LAND", "LOR", "PLUS", "MINUS", "TIMES",
  "DIV", "MOD", "NOT", "OP", "CP", "OB", "CB", "OC", "CC", "COMMA", "DOT",
  "SEMICOLON", "IDENTIFIER", "NILL", "BOOLEAN", "INTEGER", "STRING",
  "CHAR", "UNRECOG_ERROR", "TYPER_INT", "VOID", "UMINUS", "UPLUS", "ADD",
  "SUBS", "LOWER_THAN_IF", "$accept", "class_list", "single_class",
  "super", "member_list", "member", "field", "modifier_list",
  "method_decl", "ctor", "modifier", "formal_args", "formal_arg_list",
  "formal_arg", "type_decl", "bracket_list", "primitive_type",
  "var_decl_list", "var_decl", "var_decl_id", "block", "statement_list",
  "statement", "expr", "primary", "new_array_expr", "dimension_list",
  "dimension", "non_new_array_expr", "field_expr", "array_expr", "literal",
  "actual_args", "expr_list", YY_NULLPTR
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
     315,   316
};
# endif

#define YYPACT_NINF -127

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-127)))

#define YYTABLE_NINF -33

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-33)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,   -33,    21,     1,     0,  -127,  -127,   -24,   152,    -4,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,    50,  -127,
    -127,   -11,   199,  -127,    -8,  -127,  -127,   169,   -13,    11,
     187,   -10,    20,    10,  -127,  -127,  -127,    50,    13,  -127,
      28,    37,    23,     3,  -127,  -127,    41,  -127,    11,    62,
      64,    69,    11,    85,  -127,    10,    28,    65,    10,  -127,
      69,   265,    68,  -127,  -127,    95,  -127,    79,  -127,    74,
      78,    87,   185,   212,    19,  -127,    88,   265,   265,   265,
     265,  -127,  -127,    60,  -127,  -127,  -127,  -127,  -127,    69,
    -127,    86,   139,   295,    93,  -127,    92,  -127,  -127,  -127,
    -127,    10,  -127,  -127,  -127,    99,   107,   457,  -127,  -127,
    -127,  -127,   265,   107,    92,  -127,   319,   257,   101,   106,
     265,   457,   457,   457,   406,   257,  -127,  -127,   108,  -127,
    -127,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,  -127,   113,   265,  -127,  -127,
     423,  -127,    92,  -127,  -127,  -127,  -127,   365,   116,   126,
    -127,   440,  -127,   343,  -127,   471,   471,   471,   191,   471,
      82,   191,    63,    82,   457,   457,   482,   482,   482,   126,
     387,   139,  -127,   265,  -127,  -127,   139,  -127,  -127,   161,
    -127,  -127,   139,  -127
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,     2,     0,     0,     0,
       8,    24,    25,    23,    22,    37,    38,     4,    32,    39,
      40,     0,    10,    11,     0,    12,    13,    17,     0,    31,
       0,     0,     0,     0,    34,     6,     9,    32,     0,    16,
      46,     0,    42,    44,    33,     5,     0,    27,    32,     0,
      29,     0,    36,     0,    21,     0,    46,     0,     0,    15,
       0,     0,     0,     7,    26,     0,    46,    30,    35,     0,
       0,     0,     0,     0,     0,    90,     0,     0,     0,     0,
       0,    48,    51,    83,   102,   103,   104,   106,   105,     0,
      61,     0,    50,     0,    80,    81,    82,    97,    96,    89,
      20,     0,    14,    19,    41,     0,    83,    43,    45,    28,
      60,    59,     0,     0,     0,    57,     0,     0,     0,     0,
       0,    77,    78,    79,     0,     0,   100,    93,     0,    47,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,   101,    18,
       0,    84,    87,    92,    85,    58,   108,   110,     0,    99,
      62,     0,    91,   110,    52,    68,    65,    64,    66,    67,
      63,    69,    74,    75,    70,    71,    72,    73,    76,    98,
       0,     0,    86,     0,   107,    95,     0,    88,    94,    53,
     109,    56,     0,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,   165,  -127,  -127,    27,  -127,  -127,   142,  -127,  -127,
    -127,    -6,   109,  -127,    -2,   -16,   103,   -35,  -127,   125,
     -32,   110,  -126,   -61,  -127,  -127,  -110,   -69,  -127,  -127,
    -127,  -127,   -72,     2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    21,    22,    23,    24,    25,    26,
      27,    33,    49,    50,    89,    34,    29,    41,    42,    43,
      90,    91,    92,    93,    94,    95,   151,   152,    96,    97,
      98,    99,   127,   158
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     107,    54,   119,    57,   154,     1,    28,     7,    15,    16,
      15,    16,   116,    44,   126,     4,   121,   122,   123,   124,
      28,     5,    38,   100,    10,   104,   103,   148,    28,    51,
      47,    55,    61,    35,    58,    40,    68,   126,    48,    30,
      37,   153,   182,     8,    62,    19,    20,    19,    20,    36,
     101,   150,    32,    53,   128,   189,   157,    46,   117,   161,
     191,    56,    52,    51,   163,   118,   193,    31,    60,   149,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,    59,    63,   180,   185,    69,    31,
      70,    32,   136,    71,    72,   139,   140,   141,    73,   125,
      74,    32,    64,    15,    16,    75,    76,   188,   -32,    65,
     108,   136,   102,    15,    16,   140,   141,    66,    77,    78,
      62,   110,   157,    79,    80,   111,   112,   120,    53,    81,
     129,   147,    82,    83,    84,    85,    86,    87,    88,   146,
      19,    20,    69,    48,    70,   118,   125,    71,    72,   159,
      19,    20,    73,   160,    74,   164,   184,    15,    16,    75,
      76,   179,    11,    12,    13,   117,    14,   192,     6,    39,
      15,    16,    77,    78,   109,   114,    67,    79,    80,    11,
      12,    13,    53,    14,     0,   190,    82,    83,    84,    85,
      86,    87,    88,     0,    19,    20,    17,    11,    12,    13,
      18,    14,   130,    15,    16,    15,    16,    19,    20,    11,
      12,    13,     0,    14,     0,     0,     0,    15,    16,     0,
     136,    72,   138,   139,   140,   141,     0,   105,     0,     0,
       0,    45,    75,   113,     0,    18,     0,     0,     0,     0,
      19,    20,    19,    20,     0,    77,    78,    18,     0,     0,
      79,    80,     0,     0,    19,    20,     0,     0,     0,   115,
     106,    84,    85,    86,    87,    88,    72,     0,     0,     0,
       0,     0,   105,     0,    72,     0,     0,    75,     0,     0,
     105,     0,     0,     0,     0,    75,     0,     0,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   156,    77,    78,
       0,     0,     0,    79,    80,   106,    84,    85,    86,    87,
      88,     0,     0,   106,    84,    85,    86,    87,    88,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   155,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,     0,     0,     0,     0,   187,     0,     0,   183,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,     0,     0,     0,     0,     0,     0,     0,
     183,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,     0,     0,     0,     0,   187,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,     0,     0,   162,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,     0,     0,   181,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,     0,     0,
     186,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   -33,   -33,   -33,   134,   -33,
     136,   137,   138,   139,   140,   141,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141
};

static const yytype_int16 yycheck[] =
{
      61,    33,    74,    38,   114,     4,     8,     7,    18,    19,
      18,    19,    73,    29,    83,    48,    77,    78,    79,    80,
      22,     0,    24,    55,    48,    60,    58,    96,    30,    31,
      40,    37,    29,    44,    40,    48,    52,   106,    48,    43,
      48,   113,   152,    43,    41,    55,    56,    55,    56,    22,
      56,   112,    41,    43,    89,   181,   117,    30,    39,   120,
     186,    48,    42,    65,   125,    46,   192,    39,    45,   101,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    47,    44,   147,   159,     3,    39,
       5,    41,    29,     8,     9,    32,    33,    34,    13,    39,
      15,    41,    40,    18,    19,    20,    21,   179,    48,    45,
      42,    29,    47,    18,    19,    33,    34,    48,    33,    34,
      41,    47,   183,    38,    39,    47,    39,    39,    43,    44,
      44,    39,    47,    48,    49,    50,    51,    52,    53,    46,
      55,    56,     3,    48,     5,    46,    39,     8,     9,    48,
      55,    56,    13,    47,    15,    47,    40,    18,    19,    20,
      21,    48,    10,    11,    12,    39,    14,     6,     3,    27,
      18,    19,    33,    34,    65,    72,    51,    38,    39,    10,
      11,    12,    43,    14,    -1,   183,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    44,    10,    11,    12,
      48,    14,    92,    18,    19,    18,    19,    55,    56,    10,
      11,    12,    -1,    14,    -1,    -1,    -1,    18,    19,    -1,
      29,     9,    31,    32,    33,    34,    -1,    15,    -1,    -1,
      -1,    44,    20,    48,    -1,    48,    -1,    -1,    -1,    -1,
      55,    56,    55,    56,    -1,    33,    34,    48,    -1,    -1,
      38,    39,    -1,    -1,    55,    56,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,     9,    -1,    -1,    -1,
      -1,    -1,    15,    -1,     9,    -1,    -1,    20,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      33,    34,    -1,    -1,    -1,    38,    39,    40,    33,    34,
      -1,    -1,    -1,    38,    39,    48,    49,    50,    51,    52,
      53,    -1,    -1,    48,    49,    50,    51,    52,    53,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    42,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    40,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      40,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    63,    64,    48,     0,    63,     7,    43,    65,
      48,    10,    11,    12,    14,    18,    19,    44,    48,    55,
      56,    66,    67,    68,    69,    70,    71,    72,    76,    78,
      43,    39,    41,    73,    77,    44,    66,    48,    76,    69,
      48,    79,    80,    81,    77,    44,    66,    40,    48,    74,
      75,    76,    42,    43,    82,    73,    48,    79,    73,    47,
      45,    29,    41,    44,    40,    45,    48,    81,    77,     3,
       5,     8,     9,    13,    15,    20,    21,    33,    34,    38,
      39,    44,    47,    48,    49,    50,    51,    52,    53,    76,
      82,    83,    84,    85,    86,    87,    90,    91,    92,    93,
      82,    73,    47,    82,    79,    15,    48,    85,    42,    74,
      47,    47,    39,    48,    78,    47,    85,    39,    46,    94,
      39,    85,    85,    85,    85,    39,    89,    94,    79,    44,
      83,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    47,    46,    39,    89,    82,
      85,    88,    89,    94,    88,    47,    40,    85,    95,    48,
      47,    85,    40,    85,    47,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    48,
      85,    40,    88,    45,    40,    94,    40,    42,    94,    84,
      95,    84,     6,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    63,    64,    64,    64,    64,    65,    66,
      66,    67,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    72,    72,    73,    73,    74,    74,
      75,    76,    76,    76,    76,    77,    77,    78,    78,    78,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    86,    86,    86,    87,    87,    88,    88,    89,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    91,    91,
      92,    92,    93,    93,    93,    93,    93,    94,    94,    95,
      95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     4,     5,     5,     6,     2,     2,
       1,     1,     1,     1,     4,     3,     2,     1,     5,     4,
       4,     3,     1,     1,     1,     1,     3,     2,     3,     1,
       2,     1,     1,     2,     2,     3,     2,     1,     1,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     2,     2,
       1,     1,     3,     5,     7,     2,     5,     2,     3,     2,
       2,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       1,     1,     1,     1,     3,     3,     2,     1,     3,     1,
       1,     3,     3,     2,     4,     4,     1,     1,     3,     3,
       2,     2,     1,     1,     1,     1,     1,     3,     2,     3,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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
#line 96 "parser.ypp" /* yacc.c:1652  */
    { yyval->push_back(yyvsp[-1]); }
#line 1491 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 3:
#line 97 "parser.ypp" /* yacc.c:1652  */
    { yyval->push_back(yyvsp[0]); }
#line 1497 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 4:
#line 101 "parser.ypp" /* yacc.c:1652  */
    { yyval = new Class(yyvsp[-2], object_class, []); }
#line 1503 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 5:
#line 103 "parser.ypp" /* yacc.c:1652  */
    { yyval = new Class(yyvsp[-3], yyvsp[-2], []); }
#line 1509 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 6:
#line 105 "parser.ypp" /* yacc.c:1652  */
    { yyval = new Class(yyvsp[-3], object_class, yyvsp[-1]); }
#line 1515 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 7:
#line 107 "parser.ypp" /* yacc.c:1652  */
    { yyval = new Class(yyvsp[-4], yyvsp[-3], yyvsp[-1]); }
#line 1521 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 8:
#line 111 "parser.ypp" /* yacc.c:1652  */
    { yyval = new Super(yyvsp[0]) }
#line 1527 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 9:
#line 115 "parser.ypp" /* yacc.c:1652  */
    { yyval->push_back(yyvsp[-1]); }
#line 1533 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 10:
#line 116 "parser.ypp" /* yacc.c:1652  */
    { yyval->push_back(yyvsp[0]); }
#line 1539 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 11:
#line 120 "parser.ypp" /* yacc.c:1652  */
    { yyval = yyvsp[0]; }
#line 1545 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 12:
#line 121 "parser.ypp" /* yacc.c:1652  */
    { yyval = yyvsp[0]; }
#line 1551 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 13:
#line 122 "parser.ypp" /* yacc.c:1652  */
    { yyval = yyvsp[0]; }
#line 1557 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 14:
#line 126 "parser.ypp" /* yacc.c:1652  */
    { List.map
                                                  (fun d -> Field(yyvsp[-3], yyvsp[-2], d))
                                                  yyvsp[-1] }
#line 1565 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 15:
#line 129 "parser.ypp" /* yacc.c:1652  */
    { List.map
                                                  (fun d ->
                                                  Field([Public], yyvsp[-2], d)) yyvsp[-1] }
#line 1573 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 16:
#line 135 "parser.ypp" /* yacc.c:1652  */
    { yyval->push_back(yyvsp[-1]); }
#line 1579 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 17:
#line 136 "parser.ypp" /* yacc.c:1652  */
    { yyval->push_back(yyvsp[0]); }
#line 1585 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 18:
#line 140 "parser.ypp" /* yacc.c:1652  */
    { yyval->push_back(new Method(yyvsp[-2], yyvsp[-3], yyvsp[-4], yyvsp[-1], yyvsp[0]); }
#line 1591 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 19:
#line 141 "parser.ypp" /* yacc.c:1652  */
    { yyval->push_back(new Method(yyvsp[-2], yyvsp[-3], "public", yyvsp[-1], yyvsp[0])); }
#line 1597 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 20:
#line 145 "parser.ypp" /* yacc.c:1652  */
    { yyval = new Constructor(new ClassType(yyvsp[-2]), yyvsp[-3], yyvsp[-1], yyvsp[0]) }
#line 1603 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 21:
#line 146 "parser.ypp" /* yacc.c:1652  */
    { yyval = new Constructor(new ClassType(yyvsp[-2]), "public", yyvsp[-1], yyvsp[0]); }
#line 1609 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 22:
#line 150 "parser.ypp" /* yacc.c:1652  */
    { yyval = "static" }
#line 1615 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 23:
#line 151 "parser.ypp" /* yacc.c:1652  */
    { yyval = "public" }
#line 1621 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 24:
#line 152 "parser.ypp" /* yacc.c:1652  */
    { yyval = "private" }
#line 1627 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 25:
#line 153 "parser.ypp" /* yacc.c:1652  */
    { yyval = "protected" }
#line 1633 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 26:
#line 157 "parser.ypp" /* yacc.c:1652  */
    { yyval = yyvsp[-1] }
#line 1639 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 27:
#line 158 "parser.ypp" /* yacc.c:1652  */
    { yyval = {} }
#line 1645 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 28:
#line 162 "parser.ypp" /* yacc.c:1652  */
    { yyval->push_back(yyvsp[-2]); }
#line 1651 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 29:
#line 163 "parser.ypp" /* yacc.c:1652  */
    { yyval->push_back(yyvsp[0]); }
#line 1657 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 30:
#line 168 "parser.ypp" /* yacc.c:1652  */
    {
        let declName, declCnt = yyvsp[0] in
        if declCnt != 0 then
            match yyvsp[-1] with
            | ClassType s ->
                {name = declName; t = ArrayType(ClassType(s), declCnt)}
            | ArrayType (arrayT, c) ->
                {name = declName; t = ArrayType(arrayT, c + declCnt)}
            | BoolType ->
                {name = declName; t = ArrayType(BoolType, declCnt)}
            | CharType ->
                {name = declName; t = ArrayType(CharType, declCnt)}
            | IntType ->
                {name = declName; t = ArrayType(IntType, declCnt)}
            (* TODO should a void type in a formal arg be a parse error? Or
               maybe offload to type checker *)
            | VoIDENTIFIERType ->
                {name = declName; t = ArrayType(VoIDENTIFIERType, declCnt)}
            (* TODO these arent really parse errors but semantic errors *)
            | MethodType (_, _, _) -> raise Parsing.Parse_error
        else
            {name = declName; t = yyvsp[-1]}
    }
#line 1685 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 31:
#line 194 "parser.ypp" /* yacc.c:1652  */
    { yyval = yyvsp[0]; }
#line 1691 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 32:
#line 195 "parser.ypp" /* yacc.c:1652  */
    { yyval = new ClassType(yyvsp[0]); }
#line 1697 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 33:
#line 196 "parser.ypp" /* yacc.c:1652  */
    { yyval = new ArrayType(yyvsp[-1], yyvsp[0]) }
#line 1703 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 34:
#line 197 "parser.ypp" /* yacc.c:1652  */
    { yyval = new ArrayType(new ClassType(yyvsp[-1]), yyvsp[0]) }
#line 1709 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 35:
#line 201 "parser.ypp" /* yacc.c:1652  */
    { yyval = 1 + yyvsp[0];}
#line 1715 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 36:
#line 202 "parser.ypp" /* yacc.c:1652  */
    { yyval = 1; }
#line 1721 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 37:
#line 206 "parser.ypp" /* yacc.c:1652  */
    { new BoolType() }
#line 1727 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 38:
#line 207 "parser.ypp" /* yacc.c:1652  */
    { new CharType() }
#line 1733 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 39:
#line 208 "parser.ypp" /* yacc.c:1652  */
    { new IntType() }
#line 1739 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 40:
#line 209 "parser.ypp" /* yacc.c:1652  */
    { new Void() }
#line 1745 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 41:
#line 213 "parser.ypp" /* yacc.c:1652  */
    { yyval->push_back(yyvsp[-2]); }
#line 1751 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 42:
#line 214 "parser.ypp" /* yacc.c:1652  */
    {  yyval->push_back(yyvsp[0]); }
#line 1757 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 43:
#line 218 "parser.ypp" /* yacc.c:1652  */
    { { name = fst yyvsp[-2]
                                                  ; dim = snd yyvsp[-2]
                                                  ; expr = Some yyvsp[0]
                                                  } }
#line 1766 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 44:
#line 222 "parser.ypp" /* yacc.c:1652  */
    { { name = fst yyvsp[0]
                                                  ; dim = snd yyvsp[0]
                                                  ; expr = None
                                                  } }
#line 1775 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 45:
#line 229 "parser.ypp" /* yacc.c:1652  */
    { fst yyvsp[-2], snd yyvsp[-2] + 1 }
#line 1781 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 46:
#line 230 "parser.ypp" /* yacc.c:1652  */
    { yyvsp[0], 0 }
#line 1787 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 47:
#line 234 "parser.ypp" /* yacc.c:1652  */
    { yyval = yyvsp[-1]; }
#line 1793 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 48:
#line 235 "parser.ypp" /* yacc.c:1652  */
    { yyval = {} }
#line 1799 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 49:
#line 239 "parser.ypp" /* yacc.c:1652  */
    { yyval->push_back(yyvsp[-1]); }
#line 1805 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 50:
#line 240 "parser.ypp" /* yacc.c:1652  */
    { yyval->push_back(yyvsp[0]); }
#line 1811 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 51:
#line 244 "parser.ypp" /* yacc.c:1652  */
    { yyval =new EmptyStatement() }
#line 1817 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 52:
#line 245 "parser.ypp" /* yacc.c:1652  */
    { yyval = new DeclStatement(yyvsp[-2], yyvsp[-1]) }
#line 1823 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 53:
#line 247 "parser.ypp" /* yacc.c:1652  */
    { yyval = new If(yyvsp[-2], yyvsp[0], NULL); }
#line 1829 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 54:
#line 249 "parser.ypp" /* yacc.c:1652  */
    { yyval = new If(yyvsp[-4], yyvsp[-2], yyvsp[0]); }
#line 1835 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 55:
#line 250 "parser.ypp" /* yacc.c:1652  */
    { yyval = new ExprStatement(yyvsp[-1]); }
#line 1841 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 56:
#line 251 "parser.ypp" /* yacc.c:1652  */
    { yyval = new WhileStatement(new symbolTable(), yyvsp[-2], yyvsp[0]); }
#line 1847 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 57:
#line 252 "parser.ypp" /* yacc.c:1652  */
    { yyval = new ReturnStatement(NULL); }
#line 1853 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 58:
#line 253 "parser.ypp" /* yacc.c:1652  */
    { yyval = new ReturnStatement(yyvsp[-1]); }
#line 1859 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 59:
#line 254 "parser.ypp" /* yacc.c:1652  */
    { yyval = new ContinueStatement(); }
#line 1865 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 60:
#line 255 "parser.ypp" /* yacc.c:1652  */
    { yyval = new BreakStatement(); }
#line 1871 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 61:
#line 256 "parser.ypp" /* yacc.c:1652  */
    { yyval = new Block(yyvsp[0]); }
#line 1877 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 62:
#line 257 "parser.ypp" /* yacc.c:1652  */
    { yyval = new SuperStatement(yyvsp[-1]); }
#line 1883 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 63:
#line 261 "parser.ypp" /* yacc.c:1652  */
    {yyval = new BinOpExpr(string(yyvsp[-1]), yyvsp[-2], yyvsp[0]); }
#line 1889 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 64:
#line 262 "parser.ypp" /* yacc.c:1652  */
    { yyval = new BinOpExpr(string(yyvsp[-1]), yyvsp[-2], yyvsp[0]); }
#line 1895 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 65:
#line 263 "parser.ypp" /* yacc.c:1652  */
    { yyval = new BinOpExpr(string(yyvsp[-1]), yyvsp[-2], yyvsp[0]); }
#line 1901 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 66:
#line 264 "parser.ypp" /* yacc.c:1652  */
    { yyval = new BinOpExpr(string(yyvsp[-1]), yyvsp[-2], yyvsp[0]); }
#line 1907 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 67:
#line 265 "parser.ypp" /* yacc.c:1652  */
    { yyval = new BinOpExpr(string(yyvsp[-1]), yyvsp[-2], yyvsp[0]); }
#line 1913 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 68:
#line 266 "parser.ypp" /* yacc.c:1652  */
    { yyval = new BinOpExpr(string(yyvsp[-1]), yyvsp[-2], yyvsp[0]); }
#line 1919 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 69:
#line 267 "parser.ypp" /* yacc.c:1652  */
    { yyval = new BinOpExpr(string(yyvsp[-1]), yyvsp[-2], yyvsp[0]); }
#line 1925 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 70:
#line 268 "parser.ypp" /* yacc.c:1652  */
    { yyval = new BinOpExpr(string(yyvsp[-1]), yyvsp[-2], yyvsp[0]); }
#line 1931 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 71:
#line 269 "parser.ypp" /* yacc.c:1652  */
    { yyval = new BinOpExpr(string(yyvsp[-1]), yyvsp[-2], yyvsp[0]); }
#line 1937 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 72:
#line 270 "parser.ypp" /* yacc.c:1652  */
    { yyval = new BinOpExpr(string(yyvsp[-1]), yyvsp[-2], yyvsp[0]); }
#line 1943 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 73:
#line 271 "parser.ypp" /* yacc.c:1652  */
    { yyval = new BinOpExpr(string(yyvsp[-1]), yyvsp[-2], yyvsp[0]); }
#line 1949 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 74:
#line 272 "parser.ypp" /* yacc.c:1652  */
    { yyval = new BinOpExpr(string(yyvsp[-1]), yyvsp[-2], yyvsp[0]); }
#line 1955 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 75:
#line 273 "parser.ypp" /* yacc.c:1652  */
    { yyval = new BinOpExpr(string(yyvsp[-1]), yyvsp[-2], yyvsp[0]); }
#line 1961 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 76:
#line 274 "parser.ypp" /* yacc.c:1652  */
    { yyval = new BinOpExpr(string(yyvsp[-1]), yyvsp[-2], yyvsp[0]); }
#line 1967 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 77:
#line 275 "parser.ypp" /* yacc.c:1652  */
    { yyval = new UnOpExpr(string(yyvsp[0]), yyvsp[0]); }
#line 1973 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 78:
#line 276 "parser.ypp" /* yacc.c:1652  */
    { yyval = new UnOpExpr(string(yyvsp[0]), yyvsp[0]); }
#line 1979 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 79:
#line 277 "parser.ypp" /* yacc.c:1652  */
    { yyval = new UnOpExpr(string(yyvsp[0]), yyvsp[0]); }
#line 1985 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 80:
#line 278 "parser.ypp" /* yacc.c:1652  */
    { yyval = new PrimaryExpr(yyvsp[0]); }
#line 1991 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 81:
#line 282 "parser.ypp" /* yacc.c:1652  */
    { yyval = new NewArrayPrimary(
                                                    new defaultTypebox(),
                                                    yyvsp[0]) }
#line 1999 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 82:
#line 285 "parser.ypp" /* yacc.c:1652  */
    { yyval = new NonNewArrayPrimary(
                                                    new default_typebox(),
                                                    yyvsp[0]) }
#line 2007 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 83:
#line 288 "parser.ypp" /* yacc.c:1652  */
    { yyval = new IdPrimary( new defaultTypebox(), yyvsp[0]); }
#line 2013 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 84:
#line 292 "parser.ypp" /* yacc.c:1652  */
    { { t = ClassType(yyvsp[-1])
                                                  ; dimList = yyvsp[0]
                                                  } }
#line 2021 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 85:
#line 295 "parser.ypp" /* yacc.c:1652  */
    { { t = yyvsp[-1]
                                                  ; dimList = yyvsp[0]
                                                  }}
#line 2029 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 86:
#line 301 "parser.ypp" /* yacc.c:1652  */
    { yyval->push_back(yyvsp[-1]); }
#line 2035 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 87:
#line 302 "parser.ypp" /* yacc.c:1652  */
    { yyval->push_back(yyvsp[0]); }
#line 2041 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 88:
#line 306 "parser.ypp" /* yacc.c:1652  */
    { yyval = yyvsp[-1] }
#line 2047 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 89:
#line 310 "parser.ypp" /* yacc.c:1652  */
    { yyval = new LiteralExpr(yyvsp[0]) }
#line 2053 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 90:
#line 311 "parser.ypp" /* yacc.c:1652  */
    { yyval = new ThisExpr(); }
#line 2059 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 91:
#line 312 "parser.ypp" /* yacc.c:1652  */
    { yyval = new ParenExpr(yyvsp[-1]); }
#line 2065 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 92:
#line 313 "parser.ypp" /* yacc.c:1652  */
    { yyval = new NewObjExpr(yyvsp[-1], yyvsp[0]); }
#line 2071 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 93:
#line 314 "parser.ypp" /* yacc.c:1652  */
    { yyval = new ThisCallExpr(yyvsp[-1], yyvsp[0]); }
#line 2077 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 94:
#line 315 "parser.ypp" /* yacc.c:1652  */
    { yyval = new MethodCallExpr(yyvsp[-3], yyvsp[-1], yyvsp[0]); }
#line 2083 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 95:
#line 316 "parser.ypp" /* yacc.c:1652  */
    { yyval = new SuperCallExpr(yyvsp[-1], yyvsp[0]); }
#line 2089 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 96:
#line 317 "parser.ypp" /* yacc.c:1652  */
    { yyval = yyvsp[0]; }
#line 2095 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 97:
#line 318 "parser.ypp" /* yacc.c:1652  */
    { yyval = yyvsp[0]; }
#line 2101 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 98:
#line 322 "parser.ypp" /* yacc.c:1652  */
    { yyval = new fieldExpr(yyvsp[-2], yyvsp[0]);}
#line 2107 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 99:
#line 323 "parser.ypp" /* yacc.c:1652  */
    { yyval = new SuperfieldExpr(yyvsp[0]); }
#line 2113 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 100:
#line 327 "parser.ypp" /* yacc.c:1652  */
    { yyval = new ArrayExpr(new IdPrimary(
                                                    new DefaultTypebox(),
                                                    yyvsp[-1]), yyvsp[0];) }
#line 2121 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 101:
#line 330 "parser.ypp" /* yacc.c:1652  */
    { yyval = new ArrayExpr(new NonNewArrayPrimary(
                                                    new DefaultTypebox(),
                                                    yyvsp[-1]), yyvsp[0]); }
#line 2129 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 102:
#line 336 "parser.ypp" /* yacc.c:1652  */
    { yyval = new NullLiteral(); }
#line 2135 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 103:
#line 337 "parser.ypp" /* yacc.c:1652  */
    { yyval = new BoolLiteral(yyvsp[0]); }
#line 2141 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 104:
#line 338 "parser.ypp" /* yacc.c:1652  */
    { yyval = new IntLiteral(yyvsp[0]); }
#line 2147 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 105:
#line 339 "parser.ypp" /* yacc.c:1652  */
    { yyval = new CharLiteral(yyvsp[0]); }
#line 2153 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 106:
#line 340 "parser.ypp" /* yacc.c:1652  */
    { yyval = new StringLiteral(yyvsp[0]); }
#line 2159 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 107:
#line 344 "parser.ypp" /* yacc.c:1652  */
    { yyval = yyvsp[-1] }
#line 2165 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 108:
#line 345 "parser.ypp" /* yacc.c:1652  */
    { yyval = {} }
#line 2171 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 109:
#line 349 "parser.ypp" /* yacc.c:1652  */
    { yyval->push_back(yyvsp[-2]); }
#line 2177 "parser.tab.cpp" /* yacc.c:1652  */
    break;

  case 110:
#line 350 "parser.ypp" /* yacc.c:1652  */
    { yyval->push_back(yyvsp[0]); }
#line 2183 "parser.tab.cpp" /* yacc.c:1652  */
    break;


#line 2187 "parser.tab.cpp" /* yacc.c:1652  */
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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 353 "parser.ypp" /* yacc.c:1918  */


void yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}
