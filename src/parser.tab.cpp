/* A Bison parser, made by GNU Bison 3.4.2.  */

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
#define YYBISON_VERSION "3.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.ypp"

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include "visitor/ast.cpp"
#include "visitor/printerV.cpp"
#include "visitor/codeGenV.cpp"
#include "visitor/pass1V.cpp"
#include "visitor/symbolTable.cpp"


using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
// extern "C" voIDENTIFIER yyerror(char *s); // lol
extern "C" void yyerror(string s);
extern "C" int yywrap(void){return 1;};

extern "C" void yydebug(string s);

extern FILE *yyin;

StartA* start;



#line 100 "parser.tab.cpp"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    LOWEST = 312,
    UMINUS = 313,
    UPLUS = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 106 "parser.ypp"

    char*       s;
    int         i;
    double      d;
    bool        b;
    char        c;

    class AST*          ast;
    class ClassA*       classA;
    class StartA*       startA;
    class ListA*        listA;
    class FieldA*       fieldA;
    class MethodA*      methodA;
    class ConstructorA* constructorA;
    class LitA*         litA;
    class TypeA*        typeA;
    class PrimTypeA*    primTypeA;
    class FormalA*      formalA;
    class BlockA*       blockA;
    class StatementA*   statementA;
    class ExpressionA*  expressionA;
    class ArrayRefA*    arrayRefA;
    class VarDeclA*     varDeclA;
    class DimensionA*   dimensionA;
    class SuperA*       superA;
    class ModifierA*    modifierA;
    class NewArrayA*    newArrayA;
    class PrimaryExprA* primaryExprA;
    class NameA*        nameA;


#line 235 "parser.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYLAST   503

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  195

#define YYUNDEFTOK  2
#define YYMAXUTOK   314

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
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   167,   167,   171,   179,   183,   187,   191,   197,   203,
     207,   213,   217,   221,   227,   235,   247,   251,   257,   261,
     267,   271,   277,   281,   285,   289,   295,   299,   305,   309,
     315,   321,   325,   329,   335,   339,   345,   349,   353,   357,
     363,   367,   373,   377,   383,   387,   393,   397,   403,   407,
     413,   417,   421,   426,   430,   434,   438,   442,   446,   450,
     454,   458,   462,   473,   477,   481,   485,   489,   493,   497,
     501,   505,   509,   513,   517,   521,   525,   529,   533,   537,
     543,   547,   551,   557,   561,   567,   574,   581,   587,   591,
     595,   599,   603,   608,   612,   616,   620,   626,   630,   636,
     640,   646,   650,   654,   658,   662,   668,   672,   678,   683
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
  "CHAR", "UNRECOG_ERROR", "TYPER_INT", "VOID", "LOWEST", "UMINUS",
  "UPLUS", "$accept", "class_list", "single_class", "super", "member_list",
  "member", "field", "modifier_list", "method_decl", "ctor", "modifier",
  "formal_args", "formal_arg_list", "formal_arg", "type_decl",
  "bracket_list", "primitive_type", "var_decl_list", "var_decl",
  "var_decl_id", "block", "statement_list", "statement", "expr", "primary",
  "new_array_expr", "dimension_list", "dimension", "non_new_array_expr",
  "field_expr", "array_expr", "literal", "actual_args", "expr_list", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF -141

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-141)))

#define YYTABLE_NINF -33

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-33)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,   -38,    12,     5,     1,  -141,  -141,   -34,   100,   -19,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
      -4,     6,    20,  -141,   147,  -141,  -141,   217,     4,  -141,
     250,   230,    15,  -141,  -141,    -4,     7,  -141,    29,    -4,
    -141,     2,    16,   -22,  -141,    22,  -141,  -141,    45,    44,
      19,    87,  -141,    15,    -4,    54,    50,    15,  -141,    61,
     206,    71,  -141,  -141,   234,  -141,    74,    75,    76,    88,
     255,   159,    24,  -141,    89,   206,   206,   206,   206,  -141,
    -141,   121,  -141,  -141,  -141,  -141,  -141,    19,  -141,    85,
     138,   280,    86,  -141,    94,  -141,  -141,  -141,  -141,    15,
    -141,  -141,  -141,  -141,    96,    47,   424,  -141,  -141,  -141,
    -141,   206,   106,    94,  -141,   298,   185,   101,   105,   206,
    -141,  -141,  -141,   373,   206,   185,   113,  -141,  -141,   123,
    -141,  -141,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,  -141,   125,   206,  -141,  -141,
     390,  -141,    94,  -141,  -141,  -141,  -141,   338,   135,   139,
    -141,   407,  -141,   424,   316,   139,  -141,   251,   251,   251,
     466,   251,   466,   452,   438,    62,    62,  -141,  -141,  -141,
    -141,   354,   138,  -141,   206,  -141,  -141,   138,  -141,  -141,
     174,  -141,  -141,   138,  -141
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,     2,     0,     0,     0,
       8,    24,    25,    23,    22,    39,    38,    36,    37,     4,
      32,     0,    10,    11,     0,    12,    13,    17,     0,    31,
       0,     0,     0,     5,     9,    32,     0,    16,     0,    45,
      33,     0,    41,    43,     7,     0,    27,    32,     0,    29,
       0,     0,    21,     0,    45,     0,    35,     0,    15,     0,
       0,     0,     6,    26,     0,    45,    30,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,    47,
      50,    82,   101,   102,   103,   105,   104,     0,    60,     0,
      49,     0,    79,    80,    81,    96,    95,    88,    20,     0,
      14,    34,    19,    40,     0,    82,    42,    44,    28,    59,
      58,     0,     0,     0,    56,     0,     0,     0,     0,     0,
      76,    77,    78,     0,     0,     0,     0,    99,    92,     0,
      46,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,     0,     0,   100,    18,
       0,    83,    86,    91,    84,    57,   107,   109,     0,    98,
      61,     0,    90,    62,   109,     0,    51,    67,    64,    63,
      65,    66,    68,    73,    74,    69,    70,    71,    72,    75,
      97,     0,     0,    85,     0,   106,    94,     0,    87,    93,
      52,   108,    55,     0,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,   179,  -141,  -141,   -17,  -141,  -141,   156,  -141,  -141,
    -141,   -14,   120,  -141,    -2,   140,   129,   -33,  -141,   151,
     -30,   112,  -140,   -60,  -141,  -141,  -109,   -48,  -141,  -141,
    -141,  -141,   -71,    30
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    21,    22,    23,    24,    25,    26,
      27,    32,    48,    49,    87,    40,    29,    41,    42,    43,
      88,    89,    90,    91,    92,    93,   151,   152,    94,    95,
      96,    97,   128,   158
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     106,   118,    52,    55,   154,    34,    28,    60,     7,     1,
       4,   115,     5,    45,    10,   120,   121,   122,   123,    61,
      28,    53,    36,    98,    30,    57,   103,   102,    28,    50,
      11,    12,    13,   127,    14,    31,    15,    16,    17,    18,
      99,   153,   190,   183,     8,    38,   148,   192,    38,    58,
      33,   150,    39,   194,   129,    54,   157,   127,    51,   161,
      38,    59,    50,   116,   163,   164,    62,    65,    20,   149,
     117,    56,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,    63,   125,   181,   186,    64,
      67,    38,    68,   126,   189,    69,    70,   142,   143,   144,
      71,   100,    72,    15,    16,    17,    18,    73,    74,    65,
      11,    12,    13,   107,    14,    61,    15,    16,    17,    18,
      75,    76,   109,   110,   157,    77,    78,   111,   119,   130,
      51,    79,   146,   147,    80,    81,    82,    83,    84,    85,
      86,    67,   117,    68,    19,   125,    69,    70,    20,   159,
     124,    71,   160,    72,    15,    16,    17,    18,    73,    74,
     125,   165,   -32,    15,    16,    17,    18,   126,    70,   -32,
     166,    75,    76,   180,   104,   185,    77,    78,   116,    73,
     193,    51,     6,    37,   108,    80,    81,    82,    83,    84,
      85,    86,    75,    76,    70,    35,   101,    77,    78,   113,
     104,    66,   131,     0,     0,    73,   114,   105,    82,    83,
      84,    85,    86,     0,   191,    70,     0,     0,    75,    76,
       0,   104,     0,    77,    78,   156,    73,    11,    12,    13,
       0,    14,     0,   105,    82,    83,    84,    85,    86,    75,
      76,     0,     0,     0,    77,    78,    15,    16,    17,    18,
      15,    16,    17,    18,   105,    82,    83,    84,    85,    86,
      11,    12,    13,     0,    14,     0,    15,    16,    17,    18,
      46,    15,    16,    17,    18,   -33,   -33,   -33,    47,   -33,
       0,     0,    47,     0,   140,   141,   142,   143,   144,     0,
       0,     0,     0,     0,    44,     0,     0,     0,    20,     0,
       0,     0,     0,   112,   132,   133,   134,   135,   136,     0,
     137,   138,   139,   140,   141,   142,   143,   144,     0,     0,
       0,     0,   132,   133,   134,   135,   136,   145,   137,   138,
     139,   140,   141,   142,   143,   144,     0,     0,     0,     0,
     132,   133,   134,   135,   136,   155,   137,   138,   139,   140,
     141,   142,   143,   144,     0,     0,     0,     0,   188,     0,
       0,   184,   132,   133,   134,   135,   136,     0,   137,   138,
     139,   140,   141,   142,   143,   144,     0,     0,   132,   133,
     134,   135,   136,   184,   137,   138,   139,   140,   141,   142,
     143,   144,     0,     0,     0,     0,   188,   132,   133,   134,
     135,   136,     0,   137,   138,   139,   140,   141,   142,   143,
     144,     0,     0,   162,   132,   133,   134,   135,   136,     0,
     137,   138,   139,   140,   141,   142,   143,   144,     0,     0,
     182,   132,   133,   134,   135,   136,     0,   137,   138,   139,
     140,   141,   142,   143,   144,     0,     0,   187,   132,   133,
     134,   135,   136,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   132,   133,   134,   135,   136,     0,   137,   138,
       0,   140,   141,   142,   143,   144,   132,   133,   134,   135,
     136,     0,   137,     0,     0,   140,   141,   142,   143,   144,
     132,   133,   134,     0,   136,     0,     0,     0,     0,   140,
     141,   142,   143,   144
};

static const yytype_int16 yycheck[] =
{
      60,    72,    32,    36,   113,    22,     8,    29,     7,     4,
      48,    71,     0,    30,    48,    75,    76,    77,    78,    41,
      22,    35,    24,    53,    43,    39,    59,    57,    30,    31,
      10,    11,    12,    81,    14,    39,    16,    17,    18,    19,
      54,   112,   182,   152,    43,    41,    94,   187,    41,    47,
      44,   111,    48,   193,    87,    48,   116,   105,    43,   119,
      41,    45,    64,    39,   124,   125,    44,    48,    48,    99,
      46,    42,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    40,    39,   147,   159,    45,
       3,    41,     5,    46,   165,     8,     9,    35,    36,    37,
      13,    47,    15,    16,    17,    18,    19,    20,    21,    48,
      10,    11,    12,    42,    14,    41,    16,    17,    18,    19,
      33,    34,    47,    47,   184,    38,    39,    39,    39,    44,
      43,    44,    46,    39,    47,    48,    49,    50,    51,    52,
      53,     3,    46,     5,    44,    39,     8,     9,    48,    48,
      29,    13,    47,    15,    16,    17,    18,    19,    20,    21,
      39,    48,    41,    16,    17,    18,    19,    46,     9,    48,
      47,    33,    34,    48,    15,    40,    38,    39,    39,    20,
       6,    43,     3,    27,    64,    47,    48,    49,    50,    51,
      52,    53,    33,    34,     9,    48,    56,    38,    39,    70,
      15,    50,    90,    -1,    -1,    20,    47,    48,    49,    50,
      51,    52,    53,    -1,   184,     9,    -1,    -1,    33,    34,
      -1,    15,    -1,    38,    39,    40,    20,    10,    11,    12,
      -1,    14,    -1,    48,    49,    50,    51,    52,    53,    33,
      34,    -1,    -1,    -1,    38,    39,    16,    17,    18,    19,
      16,    17,    18,    19,    48,    49,    50,    51,    52,    53,
      10,    11,    12,    -1,    14,    -1,    16,    17,    18,    19,
      40,    16,    17,    18,    19,    24,    25,    26,    48,    28,
      -1,    -1,    48,    -1,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    48,    24,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    47,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    47,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    45,    24,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    24,    25,
      26,    27,    28,    45,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    24,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    24,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      40,    24,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    24,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    24,    25,    26,    27,    28,    -1,    30,    31,
      -1,    33,    34,    35,    36,    37,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    33,    34,    35,    36,    37,
      24,    25,    26,    -1,    28,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    61,    62,    48,     0,    61,     7,    43,    63,
      48,    10,    11,    12,    14,    16,    17,    18,    19,    44,
      48,    64,    65,    66,    67,    68,    69,    70,    74,    76,
      43,    39,    71,    44,    64,    48,    74,    67,    41,    48,
      75,    77,    78,    79,    44,    64,    40,    48,    72,    73,
      74,    43,    80,    71,    48,    77,    42,    71,    47,    45,
      29,    41,    44,    40,    45,    48,    79,     3,     5,     8,
       9,    13,    15,    20,    21,    33,    34,    38,    39,    44,
      47,    48,    49,    50,    51,    52,    53,    74,    80,    81,
      82,    83,    84,    85,    88,    89,    90,    91,    80,    71,
      47,    75,    80,    77,    15,    48,    83,    42,    72,    47,
      47,    39,    48,    76,    47,    83,    39,    46,    92,    39,
      83,    83,    83,    83,    29,    39,    46,    87,    92,    77,
      44,    81,    24,    25,    26,    27,    28,    30,    31,    32,
      33,    34,    35,    36,    37,    47,    46,    39,    87,    80,
      83,    86,    87,    92,    86,    47,    40,    83,    93,    48,
      47,    83,    40,    83,    83,    48,    47,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      48,    83,    40,    86,    45,    40,    92,    40,    42,    92,
      82,    93,    82,     6,    82
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    62,    62,    63,    64,
      64,    65,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    71,    71,    72,    72,
      73,    74,    74,    74,    75,    75,    76,    76,    76,    76,
      77,    77,    78,    78,    79,    79,    80,    80,    81,    81,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      84,    84,    84,    85,    85,    86,    86,    87,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    89,    89,    90,
      90,    91,    91,    91,    91,    91,    92,    92,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     4,     5,     6,     5,     2,     2,
       1,     1,     1,     1,     4,     3,     2,     1,     5,     4,
       4,     3,     1,     1,     1,     1,     3,     2,     3,     1,
       2,     1,     1,     2,     3,     2,     1,     1,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     2,     2,     1,
       1,     3,     5,     7,     2,     5,     2,     3,     2,     2,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     1,
       1,     1,     1,     3,     3,     2,     1,     3,     1,     1,
       3,     3,     2,     4,     4,     1,     1,     3,     3,     2,
       2,     1,     1,     1,     1,     1,     3,     2,     3,     1
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
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
#line 167 "parser.ypp"
    {
        yydebug(" $$ = $2; $$->addf($1); ");
        (yyval.startA) = (yyvsp[0].startA); (yyval.startA)->addf((yyvsp[-1].classA));
    }
#line 1538 "parser.tab.cpp"
    break;

  case 3:
#line 171 "parser.ypp"
    {
        yydebug(" $$ = new StartA(); $$->addf($1); ");
        (yyval.startA) = new StartA(); (yyval.startA)->addf((yyvsp[0].classA));
        start = (yyval.startA);
    }
#line 1548 "parser.tab.cpp"
    break;

  case 4:
#line 179 "parser.ypp"
    {
        yydebug(" $$ = new ClassA($2, new SuperA( \"Object\"); ");
        (yyval.classA) = new ClassA((yyvsp[-2].s), new SuperA("Object"));
    }
#line 1557 "parser.tab.cpp"
    break;

  case 5:
#line 183 "parser.ypp"
    {
        yydebug(" $$ = new ClassA($2, new SuperA(\"Object\"), $4); ");
        (yyval.classA) = new ClassA((yyvsp[-3].s), new SuperA("Object"), (yyvsp[-1].listA));
    }
#line 1566 "parser.tab.cpp"
    break;

  case 6:
#line 187 "parser.ypp"
    {
        yydebug(" $$ = new ClassA($2, $3, $5); ");
        (yyval.classA) = new ClassA((yyvsp[-4].s), (yyvsp[-3].superA), (yyvsp[-1].listA));
    }
#line 1575 "parser.tab.cpp"
    break;

  case 7:
#line 191 "parser.ypp"
    {
        yydebug(" $$ = new ClassA( $2, $3); ");
        (yyval.classA) = new ClassA((yyvsp[-3].s), (yyvsp[-2].superA));
    }
#line 1584 "parser.tab.cpp"
    break;

  case 8:
#line 197 "parser.ypp"
    {
        yydebug(" $$ = new SuperA($2); ");
        (yyval.superA) = new SuperA((yyvsp[0].s));
     }
#line 1593 "parser.tab.cpp"
    break;

  case 9:
#line 203 "parser.ypp"
    {
        yydebug(" $$ = $2; $$->addf($1); ");
        (yyval.listA) = (yyvsp[0].listA); (yyval.listA)->addf((yyvsp[-1].ast));
    }
#line 1602 "parser.tab.cpp"
    break;

  case 10:
#line 207 "parser.ypp"
    {
        yydebug(" $$ = new ListA(); $$->addf($1); ");
        (yyval.listA) = new ListA(); (yyval.listA)->addf((yyvsp[0].ast));
    }
#line 1611 "parser.tab.cpp"
    break;

  case 11:
#line 213 "parser.ypp"
    {
        yydebug(" $$ = $1; ");
        (yyval.ast) = (yyvsp[0].listA);
    }
#line 1620 "parser.tab.cpp"
    break;

  case 12:
#line 217 "parser.ypp"
    {
        yydebug(" $$ = $1; ");
        (yyval.ast) = (yyvsp[0].methodA);
    }
#line 1629 "parser.tab.cpp"
    break;

  case 13:
#line 221 "parser.ypp"
    {
        yydebug(" $$ = $1; ");
        (yyval.ast) = (yyvsp[0].constructorA);
    }
#line 1638 "parser.tab.cpp"
    break;

  case 14:
#line 227 "parser.ypp"
    {
        yydebug("$$ = new ListA();\n for(auto const field : $3->getASTs()) \n{\n \t $$->addb(new FieldA($1, $2, field));\n}");
        (yyval.listA) = new ListA();
        for(auto const field : (yyvsp[-1].listA)->getASTs())
        {
            (yyval.listA)->addb(new FieldA((yyvsp[-3].listA), (yyvsp[-2].typeA), static_cast<VarDeclA*>(field)));
        }
    }
#line 1651 "parser.tab.cpp"
    break;

  case 15:
#line 235 "parser.ypp"
    {
        yydebug("$$ = new ListA();\nfor(auto const field : $2)\n{\n \t$$->addb(new FieldA(\"public\", $1, field));\n}");
        (yyval.listA) = new ListA();
        for(auto const field : (yyvsp[-1].listA)->getASTs())
        {
            auto list = new ListA();
            list->addf(new ModifierA("public"));
            (yyval.listA)->addb(new FieldA(list, (yyvsp[-2].typeA), static_cast<VarDeclA*>(field)));
        }
    }
#line 1666 "parser.tab.cpp"
    break;

  case 16:
#line 247 "parser.ypp"
    {
        yydebug(" $$ = $2; $$->addf($1); ");
        (yyval.listA) = (yyvsp[0].listA); (yyval.listA)->addf((yyvsp[-1].modifierA));
    }
#line 1675 "parser.tab.cpp"
    break;

  case 17:
#line 251 "parser.ypp"
    {
        yydebug(" $$ = new ListA(); $$->addf($1); ");
        (yyval.listA) = new ListA(); (yyval.listA)->addf((yyvsp[0].modifierA));
    }
#line 1684 "parser.tab.cpp"
    break;

  case 18:
#line 257 "parser.ypp"
    {
        yydebug(" $$ = new MethodA($1, $2, $3, $4, new MethodBodyA($4, $5->getStatementList())); ");
        (yyval.methodA) = new MethodA((yyvsp[-4].listA), (yyvsp[-3].typeA), (yyvsp[-2].s), (yyvsp[-1].listA), new MethodBodyA((yyvsp[-1].listA), (yyvsp[0].blockA)->getStatementList()));
    }
#line 1693 "parser.tab.cpp"
    break;

  case 19:
#line 261 "parser.ypp"
    {
        yydebug(" $$ = new MethodA($1, $2, $3, new MethodBodyA($3, $4->getStatementList())); ");
        (yyval.methodA) = new MethodA((yyvsp[-3].typeA), (yyvsp[-2].s), (yyvsp[-1].listA), new MethodBodyA((yyvsp[-1].listA), (yyvsp[0].blockA)->getStatementList()));
    }
#line 1702 "parser.tab.cpp"
    break;

  case 20:
#line 267 "parser.ypp"
    {
        yydebug(" $$ = new ConstructorA(new ClassTypeA(new NameA($2, 1)), $1, new MethodBodyA($3, $4->getStatementList())); ");
        (yyval.constructorA) = new ConstructorA(new ClassTypeA(new NameA((yyvsp[-2].s), 1)), (yyvsp[-3].listA), new MethodBodyA((yyvsp[-1].listA), (yyvsp[0].blockA)->getStatementList()));
    }
#line 1711 "parser.tab.cpp"
    break;

  case 21:
#line 271 "parser.ypp"
    {
        yydebug(" $$ = new ConstructorA(new ClassTypeA(new NameA($1, 1)), new MethodBodyA($2, $3->getStatementList())); ");
        (yyval.constructorA) = new ConstructorA(new ClassTypeA(new NameA((yyvsp[-2].s), 1)), new MethodBodyA((yyvsp[-1].listA), (yyvsp[0].blockA)->getStatementList()));
    }
#line 1720 "parser.tab.cpp"
    break;

  case 22:
#line 277 "parser.ypp"
    {
        yydebug(" $$ = new ModifierA(\"static\"); ");
        (yyval.modifierA) = new ModifierA("static");
    }
#line 1729 "parser.tab.cpp"
    break;

  case 23:
#line 281 "parser.ypp"
    {
        yydebug(" $$ = new ModifierA(\"public\"); ");
        (yyval.modifierA) = new ModifierA("public");
    }
#line 1738 "parser.tab.cpp"
    break;

  case 24:
#line 285 "parser.ypp"
    {
        yydebug(" $$ = new ModifierA(\"private\"); ");
        (yyval.modifierA) = new ModifierA("private");
    }
#line 1747 "parser.tab.cpp"
    break;

  case 25:
#line 289 "parser.ypp"
    {
        yydebug(" $$ = new ModifierA(\"protected\"); ");
        (yyval.modifierA) = new ModifierA("protected");
    }
#line 1756 "parser.tab.cpp"
    break;

  case 26:
#line 295 "parser.ypp"
    {
        yydebug(" $$ = $2; ");
        (yyval.listA) = (yyvsp[-1].listA);
    }
#line 1765 "parser.tab.cpp"
    break;

  case 27:
#line 299 "parser.ypp"
    {
        yydebug(" $$ = new ListA(); ");
        (yyval.listA) = new ListA();
    }
#line 1774 "parser.tab.cpp"
    break;

  case 28:
#line 305 "parser.ypp"
    {
        yydebug(" $$ = $3; $$->addf($1); ");
        (yyval.listA) = (yyvsp[0].listA); (yyval.listA)->addf((yyvsp[-2].formalA));
    }
#line 1783 "parser.tab.cpp"
    break;

  case 29:
#line 309 "parser.ypp"
    {
        yydebug(" $$ = new ListA(); $$->addf($1); ");
        (yyval.listA) = new ListA(); (yyval.listA)->addf((yyvsp[0].formalA));
    }
#line 1792 "parser.tab.cpp"
    break;

  case 30:
#line 315 "parser.ypp"
    {
        yydebug(" $$ = new FormalA($1, $2);");
        (yyval.formalA) = new FormalA((yyvsp[-1].typeA), (yyvsp[0].s));
    }
#line 1801 "parser.tab.cpp"
    break;

  case 31:
#line 321 "parser.ypp"
    {
        yydebug(" $$ = $1; ");
        (yyval.typeA) = (yyvsp[0].primTypeA);
    }
#line 1810 "parser.tab.cpp"
    break;

  case 32:
#line 325 "parser.ypp"
    {
        yydebug(" $$ = new ClassTypeA(new NameA($1, 1)); ");
        (yyval.typeA) = new ClassTypeA(new NameA((yyvsp[0].s), 1));
    }
#line 1819 "parser.tab.cpp"
    break;

  case 33:
#line 329 "parser.ypp"
    {
        yydebug(" $$ = new ArrayTypeA($1, $2); ");
        (yyval.typeA) = new ArrayTypeA((yyvsp[-1].typeA), (yyvsp[0].i));
    }
#line 1828 "parser.tab.cpp"
    break;

  case 34:
#line 335 "parser.ypp"
    {
        yydebug(" $$ = ++$3; ");
        (yyval.i) = ++(yyvsp[0].i);
    }
#line 1837 "parser.tab.cpp"
    break;

  case 35:
#line 339 "parser.ypp"
    {
        yydebug(" $$ = 1; ");
        (yyval.i) = 1;
    }
#line 1846 "parser.tab.cpp"
    break;

  case 36:
#line 345 "parser.ypp"
    {
        yydebug(" $$ = new PrimTypeA(new NameA($1, 1)); ");
        (yyval.primTypeA) = new PrimTypeA(new NameA((yyvsp[0].s), 1));
    }
#line 1855 "parser.tab.cpp"
    break;

  case 37:
#line 349 "parser.ypp"
    {
        yydebug(" $$ = new PrimTypeA(new NameA($1, 1)); ");
        (yyval.primTypeA) = new PrimTypeA(new NameA((yyvsp[0].s), 1));
    }
#line 1864 "parser.tab.cpp"
    break;

  case 38:
#line 353 "parser.ypp"
    {
        yydebug(" $$ = new PrimTypeA(new NameA($1, 1)); ");
        (yyval.primTypeA) = new PrimTypeA(new NameA((yyvsp[0].s), 1));
    }
#line 1873 "parser.tab.cpp"
    break;

  case 39:
#line 357 "parser.ypp"
    {
        yydebug(" $$ = new PrimTypeA(new NameA($1, 1)); ");
        (yyval.primTypeA) = new PrimTypeA(new NameA((yyvsp[0].s), 1));
    }
#line 1882 "parser.tab.cpp"
    break;

  case 40:
#line 363 "parser.ypp"
    {
        yydebug(" $$ = $3; $$->addf($1); ");
        (yyval.listA) = (yyvsp[0].listA); (yyval.listA)->addf((yyvsp[-2].varDeclA));
    }
#line 1891 "parser.tab.cpp"
    break;

  case 41:
#line 367 "parser.ypp"
    {
        yydebug(" $$ = new StartA(); $$->addf($1); ");
        (yyval.listA) = new ListA(); (yyval.listA)->addf((yyvsp[0].varDeclA));
    }
#line 1900 "parser.tab.cpp"
    break;

  case 42:
#line 373 "parser.ypp"
    {
        yydebug(" $$ = new VarDeclA($1, $3); ");
        (yyval.varDeclA) = new VarDeclA((yyvsp[-2].s), (yyvsp[0].expressionA));
    }
#line 1909 "parser.tab.cpp"
    break;

  case 43:
#line 377 "parser.ypp"
    {
        yydebug(" $$ = new VarDeclA($1); ");
        (yyval.varDeclA) = new VarDeclA((yyvsp[0].s));
    }
#line 1918 "parser.tab.cpp"
    break;

  case 44:
#line 383 "parser.ypp"
    {
        yyerror(" $$ = $1+\"[]\"; ");
        (yyval.s) = (yyvsp[-2].s);
    }
#line 1927 "parser.tab.cpp"
    break;

  case 45:
#line 387 "parser.ypp"
    {
        yydebug(" $$ = $1; ");
        (yyval.s) = (yyvsp[0].s);
    }
#line 1936 "parser.tab.cpp"
    break;

  case 46:
#line 393 "parser.ypp"
    {
        yydebug(" $$ = new BlockA($2); ");
            (yyval.blockA) = new BlockA((yyvsp[-1].listA));
        }
#line 1945 "parser.tab.cpp"
    break;

  case 47:
#line 397 "parser.ypp"
    {
        yydebug(" $$ = new BlockA(); ");
        (yyval.blockA) = new BlockA();
    }
#line 1954 "parser.tab.cpp"
    break;

  case 48:
#line 403 "parser.ypp"
    {
        yydebug(" $$ = $2; $$->addf($1); ");
        (yyval.listA) = (yyvsp[0].listA); (yyval.listA)->addf((yyvsp[-1].statementA));
    }
#line 1963 "parser.tab.cpp"
    break;

  case 49:
#line 407 "parser.ypp"
    {
        yydebug(" $$ = new ListA(); $$->addf($1); ");
        (yyval.listA) = new ListA(); (yyval.listA)->addf((yyvsp[0].statementA));
    }
#line 1972 "parser.tab.cpp"
    break;

  case 50:
#line 413 "parser.ypp"
    {
        yydebug(" $$ =new EmptyStatement() ");
        (yyval.statementA) = new EmptyStatementA();
    }
#line 1981 "parser.tab.cpp"
    break;

  case 51:
#line 417 "parser.ypp"
    {
        yydebug(" $$ = new DeclStatementA($1, $2); ");
        (yyval.statementA) = new DeclStatementA((yyvsp[-2].typeA), (yyvsp[-1].listA));
    }
#line 1990 "parser.tab.cpp"
    break;

  case 52:
#line 422 "parser.ypp"
    {
            yydebug(" $$ = new IfStatementA($3, $5, NULL); ");
            (yyval.statementA) = new IfStatementA((yyvsp[-2].expressionA), (yyvsp[0].statementA));
    }
#line 1999 "parser.tab.cpp"
    break;

  case 53:
#line 426 "parser.ypp"
    {
        yydebug(" $$ = new IfStatementA($3, $5, $7); ");
        (yyval.statementA) = new IfStatementA((yyvsp[-4].expressionA), (yyvsp[-2].statementA), (yyvsp[0].statementA));
    }
#line 2008 "parser.tab.cpp"
    break;

  case 54:
#line 430 "parser.ypp"
    {
        yydebug(" $$ = new ExpressionStatementA($1); ");
        (yyval.statementA) = new ExpressionStatementA((yyvsp[-1].expressionA));
    }
#line 2017 "parser.tab.cpp"
    break;

  case 55:
#line 434 "parser.ypp"
    {
        yydebug(" $$ = new WhileStatement(new symbolTable(), $3, $5); ");
        (yyval.statementA) = new WhileStatementA((yyvsp[-2].expressionA), (yyvsp[0].statementA));
    }
#line 2026 "parser.tab.cpp"
    break;

  case 56:
#line 438 "parser.ypp"
    {
        yydebug(" $$ = new ReturnStatement(NULL); ");
        (yyval.statementA) = new ReturnStatementA(NULL);
    }
#line 2035 "parser.tab.cpp"
    break;

  case 57:
#line 442 "parser.ypp"
    {
        yydebug(" $$ = new ReturnStatement($2); ");
        (yyval.statementA) = new ReturnStatementA((yyvsp[-1].expressionA));
    }
#line 2044 "parser.tab.cpp"
    break;

  case 58:
#line 446 "parser.ypp"
    {
        yydebug(" $$ = new ContinueStatement(); ");
        (yyval.statementA) = new ContinueStatementA();
    }
#line 2053 "parser.tab.cpp"
    break;

  case 59:
#line 450 "parser.ypp"
    {
        yydebug(" $$ = new BreakStatement(); ");
        (yyval.statementA) = new BreakStatementA();
    }
#line 2062 "parser.tab.cpp"
    break;

  case 60:
#line 454 "parser.ypp"
    {
        yydebug(" $$ = new Block($1); ");
        (yyval.statementA) = new BlockStatementA((yyvsp[0].blockA));
    }
#line 2071 "parser.tab.cpp"
    break;

  case 61:
#line 458 "parser.ypp"
    {
        yydebug(" $$ = new SuperStatementA($2); ");
        (yyval.statementA) = new SuperStatementA((yyvsp[-1].listA));
    }
#line 2080 "parser.tab.cpp"
    break;

  case 62:
#line 462 "parser.ypp"
    {
        yydebug(" $$ = new AssignmentA($1, $3); ");
        (yyval.statementA) = new AssignmentA(new NameA((yyvsp[-2].s)), (yyvsp[0].expressionA));
    }
#line 2089 "parser.tab.cpp"
    break;

  case 63:
#line 473 "parser.ypp"
    {
        yydebug(" $$ = new OpExpressionA($2, $1, $3); ");
        (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));
    }
#line 2098 "parser.tab.cpp"
    break;

  case 64:
#line 477 "parser.ypp"
    {
        yydebug(" $$ = new OpExpressionA($2, $1, $3); ");
        (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));
    }
#line 2107 "parser.tab.cpp"
    break;

  case 65:
#line 481 "parser.ypp"
    {
        yydebug(" $$ = new OpExpressionA($2, $1, $3); ");
        (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));
    }
#line 2116 "parser.tab.cpp"
    break;

  case 66:
#line 485 "parser.ypp"
    {
        yydebug(" $$ = new OpExpressionA($2, $1, $3); ");
        (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));
    }
#line 2125 "parser.tab.cpp"
    break;

  case 67:
#line 489 "parser.ypp"
    {
        yydebug(" $$ = new OpExpressionA($2, $1, $3); ");
        (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));
    }
#line 2134 "parser.tab.cpp"
    break;

  case 68:
#line 493 "parser.ypp"
    {
        yydebug(" $$ = new OpExpressionA($2, $1, $3); ");
        (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));
    }
#line 2143 "parser.tab.cpp"
    break;

  case 69:
#line 497 "parser.ypp"
    {
        yydebug(" $$ = new OpExpressionA($2, $1, $3); ");
        (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));
    }
#line 2152 "parser.tab.cpp"
    break;

  case 70:
#line 501 "parser.ypp"
    {
        yydebug(" $$ = new OpExpressionA($2, $1, $3); ");
        (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));
    }
#line 2161 "parser.tab.cpp"
    break;

  case 71:
#line 505 "parser.ypp"
    {
        yydebug(" $$ = new OpExpressionA($2, $1, $3); ");
        (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));
    }
#line 2170 "parser.tab.cpp"
    break;

  case 72:
#line 509 "parser.ypp"
    {
        yydebug(" $$ = new OpExpressionA($2, $1, $3); ");
        (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));
    }
#line 2179 "parser.tab.cpp"
    break;

  case 73:
#line 513 "parser.ypp"
    {
        yydebug(" $$ = new OpExpressionA($2, $1, $3); ");
        (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));
    }
#line 2188 "parser.tab.cpp"
    break;

  case 74:
#line 517 "parser.ypp"
    {
        yydebug(" $$ = new OpExpressionA($2, $1, $3); ");
        (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));
    }
#line 2197 "parser.tab.cpp"
    break;

  case 75:
#line 521 "parser.ypp"
    {
        yydebug(" $$ = new OpExpressionA($2, $1, $3); ");
        (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));
    }
#line 2206 "parser.tab.cpp"
    break;

  case 76:
#line 525 "parser.ypp"
    {
        yydebug(" $$ = new OpExpressionA($1, $2); ");
        (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[0].expressionA));
    }
#line 2215 "parser.tab.cpp"
    break;

  case 77:
#line 529 "parser.ypp"
    {
        yydebug(" $$ = new OpExpressionA($1, $2); ");
        (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[0].expressionA));
    }
#line 2224 "parser.tab.cpp"
    break;

  case 78:
#line 533 "parser.ypp"
    {
        yydebug(" $$ = new OpExpressionA($1, $2); ");
        (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[0].expressionA));
    }
#line 2233 "parser.tab.cpp"
    break;

  case 79:
#line 537 "parser.ypp"
    {
        yydebug(" $$ = $1; ");
        (yyval.expressionA) = (yyvsp[0].primaryExprA);
    }
#line 2242 "parser.tab.cpp"
    break;

  case 80:
#line 543 "parser.ypp"
    {
        yyerror(" $$ = $1 ");
        (yyval.primaryExprA) = new PrimaryArrayA((yyvsp[0].newArrayA));
    }
#line 2251 "parser.tab.cpp"
    break;

  case 81:
#line 547 "parser.ypp"
    {
        yydebug(" $$ = $1; ");
        (yyval.primaryExprA) = new NonArrayPrimaryA((yyvsp[0].expressionA));
    }
#line 2260 "parser.tab.cpp"
    break;

  case 82:
#line 551 "parser.ypp"
    {
        yydebug(" $$ = $1; ");
        (yyval.primaryExprA) = new NameA((yyvsp[0].s), 6);
    }
#line 2269 "parser.tab.cpp"
    break;

  case 83:
#line 557 "parser.ypp"
    {
        yydebug(" new NewArrayA( new NameA($2), $3) ");
        new NewArrayA( new ClassTypeA(new NameA((yyvsp[-1].s), 2)), (yyvsp[0].listA));
    }
#line 2278 "parser.tab.cpp"
    break;

  case 84:
#line 561 "parser.ypp"
    {
        yydebug("new newArrayA($2, $3);");
        new NewArrayA((yyvsp[-1].primTypeA), (yyvsp[0].listA));
    }
#line 2287 "parser.tab.cpp"
    break;

  case 85:
#line 567 "parser.ypp"
    {
        yydebug(" $$ = $2; $$->addf(new DimensionA($1)); ");
        (yyval.listA) = (yyvsp[0].listA);
        (yyval.listA)->addf((yyvsp[-1].dimensionA));


    }
#line 2299 "parser.tab.cpp"
    break;

  case 86:
#line 574 "parser.ypp"
    {
        yydebug(" $$ = new ListA(); $$->addf($1);; ");
        (yyval.listA) = new ListA();
        (yyval.listA)->addf((yyvsp[0].dimensionA));
    }
#line 2309 "parser.tab.cpp"
    break;

  case 87:
#line 581 "parser.ypp"
    {
        yydebug(" $$ = new DimensionA($2); ");
        (yyval.dimensionA) = new DimensionA((yyvsp[-1].expressionA));
    }
#line 2318 "parser.tab.cpp"
    break;

  case 88:
#line 587 "parser.ypp"
    {
        yydebug(" $$ = $1; ");
        (yyval.expressionA) = (yyvsp[0].litA);
    }
#line 2327 "parser.tab.cpp"
    break;

  case 89:
#line 591 "parser.ypp"
    {
        yydebug(" $$ = new ThisExprA(); ");
        (yyval.expressionA) = new ThisExprA();
    }
#line 2336 "parser.tab.cpp"
    break;

  case 90:
#line 595 "parser.ypp"
    {
        yydebug(" $$ = $2; ");
        (yyval.expressionA) = (yyvsp[-1].expressionA);
    }
#line 2345 "parser.tab.cpp"
    break;

  case 91:
#line 599 "parser.ypp"
    {
        yydebug(" $$ = new NewObjExprA(new NameA($2), $3); ");
        (yyval.expressionA) = new NewObjExprA(new NameA((yyvsp[-1].s), 2), (yyvsp[0].listA));
    }
#line 2354 "parser.tab.cpp"
    break;

  case 92:
#line 603 "parser.ypp"
    {
        yydebug(" $$ = new ThisCallExprA($1, $2); ");
        (yyval.expressionA) = new ThisCallExprA(new NameA((yyvsp[-1].s), 2), (yyvsp[0].listA));
    }
#line 2363 "parser.tab.cpp"
    break;

  case 93:
#line 608 "parser.ypp"
    {
        yydebug(" $$ = new MethodCallExprA($1, $3, $4); ");
        (yyval.expressionA) = new MethodCallExprA(new NameA((yyvsp[-3].s)), new NameA((yyvsp[-1].s), 3), (yyvsp[0].listA));
    }
#line 2372 "parser.tab.cpp"
    break;

  case 94:
#line 612 "parser.ypp"
    {
        yydebug(" $$ = new SuperCallExprA($3, $4); ");
        (yyval.expressionA) = new SuperCallExprA(new NameA((yyvsp[-1].s), 3), (yyvsp[0].listA));
    }
#line 2381 "parser.tab.cpp"
    break;

  case 95:
#line 616 "parser.ypp"
    {
        yydebug(" $$ = $1; ");
        (yyval.expressionA) = (yyvsp[0].arrayRefA);
    }
#line 2390 "parser.tab.cpp"
    break;

  case 96:
#line 620 "parser.ypp"
    {
        yydebug(" $$ = $1; ");
        (yyval.expressionA) = (yyvsp[0].expressionA);
    }
#line 2399 "parser.tab.cpp"
    break;

  case 97:
#line 626 "parser.ypp"
    {
        yydebug(" $$ = new FieldExprA($1, new NameA($3, 6));");
        (yyval.expressionA) = new FieldExprA((yyvsp[-2].primaryExprA), new NameA((yyvsp[0].s), 5));
    }
#line 2408 "parser.tab.cpp"
    break;

  case 98:
#line 630 "parser.ypp"
    {
        yydebug(" $$ = new SuperfieldExpr($3); ");
        (yyval.expressionA) = new SuperFieldExprA(new NameA((yyvsp[0].s), 5));
    }
#line 2417 "parser.tab.cpp"
    break;

  case 99:
#line 636 "parser.ypp"
    {
        yydebug(" $$ = new ArrayRefA(new NameA($1, 1), $2); ");
        (yyval.arrayRefA) = new ArrayRefA(new NameA((yyvsp[-1].s), 1), (yyvsp[0].dimensionA));
    }
#line 2426 "parser.tab.cpp"
    break;

  case 100:
#line 640 "parser.ypp"
    {
        yydebug(" $$ = new ArrayRefA($1, $2); ");
        (yyval.arrayRefA) = new ArrayRefA((yyvsp[-1].expressionA), (yyvsp[0].dimensionA));
    }
#line 2435 "parser.tab.cpp"
    break;

  case 101:
#line 646 "parser.ypp"
    {
        yydebug(" $$ = new NullLiteral(); ");
        (yyval.litA) = new NullLitA();
    }
#line 2444 "parser.tab.cpp"
    break;

  case 102:
#line 650 "parser.ypp"
    {
        yydebug(" $$ = new BoolLiteral($1); ");
        (yyval.litA) = new BoolLitA((yyvsp[0].b));
    }
#line 2453 "parser.tab.cpp"
    break;

  case 103:
#line 654 "parser.ypp"
    {
        yydebug(" $$ = new IntLitA($1); ");
        (yyval.litA) = new IntLitA((yyvsp[0].i));
    }
#line 2462 "parser.tab.cpp"
    break;

  case 104:
#line 658 "parser.ypp"
    {
        yydebug(" $$ = new CharLitA($1); ");
        (yyval.litA) = new CharLitA((yyvsp[0].c));
    }
#line 2471 "parser.tab.cpp"
    break;

  case 105:
#line 662 "parser.ypp"
    {
        yydebug(" $$ = new StrLitA($1); ");
        (yyval.litA) = new StrLitA((yyvsp[0].s));
    }
#line 2480 "parser.tab.cpp"
    break;

  case 106:
#line 668 "parser.ypp"
    {
        yydebug(" $$ = $2 ");
        (yyval.listA) = (yyvsp[-1].listA);
    }
#line 2489 "parser.tab.cpp"
    break;

  case 107:
#line 672 "parser.ypp"
    {
        yydebug(" $$ = ListA(); ");
        (yyval.listA) = new ListA();
    }
#line 2498 "parser.tab.cpp"
    break;

  case 108:
#line 678 "parser.ypp"
    {
        yydebug(" $$ = $2; $$->addf($1); ");
        (yyval.listA) = (yyvsp[0].listA);
        (yyval.listA)->addf((yyvsp[-2].expressionA));
    }
#line 2508 "parser.tab.cpp"
    break;

  case 109:
#line 683 "parser.ypp"
    {
        yydebug(" $$ = new ListA(); $$->addf($1); ");
        (yyval.listA) = new ListA();
        (yyval.listA)->addf((yyvsp[0].expressionA));
    }
#line 2518 "parser.tab.cpp"
    break;


#line 2522 "parser.tab.cpp"

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
#line 689 "parser.ypp"


void yyerror(string s)
{
    cout << "XXXX error: " << s << " XXXXXXXXXXXXXXXXXXXXXXX\n";
}

void yydebug(string s) {
    // cout << "\t" << s << "\n";
}

int main(int argc, char **argv) {
    // cout << "\n===[PARSING]===\n";

    yyin = fopen(argv[1], "r");
	yyparse();

    // cout << "\n===[PRINTING]===\n";
    // cout << "\n";
    // start->accept(*(new PrinterV()));
    // cout << "\n";

    // cout << "\n===[PASS1-ING]===\n";
    // cout << "\n";
    start->accept(*(new Pass1V()));


    // cout << "\n===[CODEGEN-ING]===\n";
    // cout << "\n";

    // Create a new pass manager attached to it.
    TheFPM = make_unique<legacy::FunctionPassManager>(TheModule.get());
    // Promote allocas to registers.
    TheFPM->add(createPromoteMemoryToRegisterPass());
    // Do simple "peephole" optimizations and bit-twiddling optzns.
    TheFPM->add(createInstructionCombiningPass());
    // Reassociate expressions.
    TheFPM->add(createReassociatePass());
    // Eliminate Common SubExpressions.
    TheFPM->add(createGVNPass());
    // // Simplify the control flow graph (deleting unreachable blocks, etc).
    // TheFPM->add(createCFGSimplificationPass());
    TheFPM->doInitialization();

    start->accept(*(new CodeGenV()));
    // cout << "\n";

    // cout << "\n===[FINALIZING]===\n";
    // cout << "\n";

    // TheModule->print(errs(), nullptr);

    // cout << "Main Register: " << start->getMain()->getReg() << "\n";
    // cout << "Main BasicBlock: " << start->getMain()->getBB() << "\n";

    // Print out all of the generated code.
    // TheModule->print(errs(), nullptr);
    // cout << "\n";

    if (start->getMain() == nullptr) { 
        fprintf(stderr, "No main method defined"); 
        return 1; 
    }

    // Initialize the target registry etc.
    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    auto TargetTriple = sys::getDefaultTargetTriple();
    TheModule->setTargetTriple(TargetTriple);

    std::string Error;
    auto Target = TargetRegistry::lookupTarget(TargetTriple, Error);

    // Print an error and exit if we couldn't find the requested target.
    // This generally occurs if we've forgotten to initialise the
    // TargetRegistry or we have a bogus target triple.
    if (!Target) {
        errs() << Error;
        return 1;
    }
    auto CPU = "generic";
    auto Features = "";

    TargetOptions opt;
    auto RM = Optional<Reloc::Model>();
    auto TheTargetMachine =
        Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

    TheModule->setDataLayout(TheTargetMachine->createDataLayout());

    string Filename(argv[1]);
    Filename = Filename.substr(0, Filename.size()-5)+"o";
    std::error_code EC;
    raw_fd_ostream dest(Filename, EC, sys::fs::OF_None);

    // TODO:
    if (EC) {
        errs() << "Could not open file:" << EC.message();
        return 1;
    }

    legacy::PassManager pass;
    auto FileType = llvm::LLVMTargetMachine::CGFT_ObjectFile; //CGFT_ObjectFile;

    if (TheTargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType)) {
        errs() << "TheTargetMachine can't emit a file of this type";
        return 1;
    }

    pass.run(*TheModule);
    dest.flush();




    // cout << "\n";
    // cout << "\n===[DONE]===\n";
    // cout << "\n";


	return 0;
}
