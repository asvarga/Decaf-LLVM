[1mdiff --git a/src/Makefile b/src/Makefile[m
[1mindex c1a801c..93641a1 100644[m
[1m--- a/src/Makefile[m
[1m+++ b/src/Makefile[m
[36m@@ -5,7 +5,7 @@[m [mparser: parser.ypp lexer.l ast.h ast.cpp[m
 [m
 compiler: parser[m
 	# g++ -std=c++11 -o parser parser.tab.cpp lex.yy.c ast.cpp -ll -g -ldl -lfl `llvm-config --cppflags --libs --libfiles core --ldflags --system-libs`[m
[31m-	g++ -std=c++11 -o parser parser.tab.cpp lex.yy.c[m
[32m+[m	[32mg++ -std=c++11 -Wfatal-errors -o parser parser.tab.cpp lex.yy.c[m
 [m
 [m
 # TESTS #[m
[36m@@ -17,3 +17,8 @@[m [mtest0: compiler[m
 	./parser test2/test0.decaf[m
 test1: compiler[m
 	./parser test/adder.decaf[m
[32m+[m
[32m+[m[32m.PHONY: clean[m
[32m+[m
[32m+[m[32mclean:[m
[32m+[m	[32mrm *.o parser.tab.cpp parser.tab.hpp lex.yy.c[m
[1mdiff --git a/src/lex.yy.c b/src/lex.yy.c[m
[1mindex 6f718db..6bd1995 100644[m
[1m--- a/src/lex.yy.c[m
[1m+++ b/src/lex.yy.c[m
[36m@@ -1,5 +1,5 @@[m
 [m
[31m-#line 2 "lex.yy.c"[m
[32m+[m[32m#line 3 "lex.yy.c"[m
 [m
 #define  YY_INT_ALIGNED short int[m
 [m
[36m@@ -652,10 +652,10 @@[m [mchar *yytext;[m
 [m
 #define YY_DECL extern "C" int yylex()[m
 [m
[31m-#line 655 "lex.yy.c"[m
[32m+[m[32m#line 656 "lex.yy.c"[m
 #line 16 "lexer.l"[m
     /* Macros */[m
[31m-#line 658 "lex.yy.c"[m
[32m+[m[32m#line 659 "lex.yy.c"[m
 [m
 #define INITIAL 0[m
 [m
[36m@@ -875,7 +875,7 @@[m [mYY_DECL[m
 #line 30 "lexer.l"[m
 [m
     /* Key Words*/[m
[31m-#line 878 "lex.yy.c"[m
[32m+[m[32m#line 879 "lex.yy.c"[m
 [m
 	while ( /*CONSTCOND*/1 )		/* loops until end-of-file is reached */[m
 		{[m
[36m@@ -1590,7 +1590,7 @@[m [mYY_RULE_SETUP[m
 #line 263 "lexer.l"[m
 ECHO;[m
 	YY_BREAK[m
[31m-#line 1593 "lex.yy.c"[m
[32m+[m[32m#line 1594 "lex.yy.c"[m
 case YY_STATE_EOF(INITIAL):[m
 	yyterminate();[m
 [m
[1mdiff --git a/src/parser b/src/parser[m
[1mindex 9d05ebd..8754d28 100755[m
Binary files a/src/parser and b/src/parser differ
[1mdiff --git a/src/parser.tab.cpp b/src/parser.tab.cpp[m
[1mindex 4574f41..6347f7b 100644[m
[1m--- a/src/parser.tab.cpp[m
[1m+++ b/src/parser.tab.cpp[m
[36m@@ -1,9 +1,8 @@[m
[31m-/* A Bison parser, made by GNU Bison 3.4.2.  */[m
[32m+[m[32m/* A Bison parser, made by GNU Bison 3.0.4.  */[m
 [m
 /* Bison implementation for Yacc-like parsers in C[m
 [m
[31m-   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,[m
[31m-   Inc.[m
[32m+[m[32m   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.[m
 [m
    This program is free software: you can redistribute it and/or modify[m
    it under the terms of the GNU General Public License as published by[m
[36m@@ -41,14 +40,11 @@[m
    define necessary library symbols; they are noted "INFRINGES ON[m
    USER NAME SPACE" below.  */[m
 [m
[31m-/* Undocumented macros, especially those whose name start with YY_,[m
[31m-   are private implementation details.  Do not rely on them.  */[m
[31m-[m
 /* Identify Bison output.  */[m
 #define YYBISON 1[m
 [m
 /* Bison version.  */[m
[31m-#define YYBISON_VERSION "3.4.2"[m
[32m+[m[32m#define YYBISON_VERSION "3.0.4"[m
 [m
 /* Skeleton name.  */[m
 #define YYSKELETON_NAME "yacc.c"[m
[36m@@ -65,8 +61,8 @@[m
 [m
 [m
 [m
[31m-/* First part of user prologue.  */[m
[31m-#line 1 "parser.ypp"[m
[32m+[m[32m/* Copy the first part of user declarations.  */[m
[32m+[m[32m#line 1 "parser.ypp" /* yacc.c:339  */[m
 [m
 #include <stdio.h>[m
 #include <iostream>[m
[36m@@ -92,17 +88,13 @@[m [mStartA* start;[m
 [m
 [m
 [m
[31m-#line 96 "parser.tab.cpp"[m
[32m+[m[32m#line 92 "parser.tab.cpp" /* yacc.c:339  */[m
 [m
 # ifndef YY_NULLPTR[m
[31m-#  if defined __cplusplus[m
[31m-#   if 201103L <= __cplusplus[m
[31m-#    define YY_NULLPTR nullptr[m
[31m-#   else[m
[31m-#    define YY_NULLPTR 0[m
[31m-#   endif[m
[32m+[m[32m#  if defined __cplusplus && 201103L <= __cplusplus[m
[32m+[m[32m#   define YY_NULLPTR nullptr[m
 #  else[m
[31m-#   define YY_NULLPTR ((void*)0)[m
[32m+[m[32m#   define YY_NULLPTR 0[m
 #  endif[m
 # endif[m
 [m
[36m@@ -114,8 +106,8 @@[m [mStartA* start;[m
 # define YYERROR_VERBOSE 0[m
 #endif[m
 [m
[31m-/* Use api.header.include to #include this header[m
[31m-   instead of duplicating it here.  */[m
[32m+[m[32m/* In a future release of Bison, this section will be replaced[m
[32m+[m[32m   by #include "parser.tab.hpp".  */[m
 #ifndef YY_YY_PARSER_TAB_HPP_INCLUDED[m
 # define YY_YY_PARSER_TAB_HPP_INCLUDED[m
 /* Debug traces.  */[m
[36m@@ -193,9 +185,10 @@[m [mextern int yydebug;[m
 [m
 /* Value type.  */[m
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED[m
[32m+[m
 union YYSTYPE[m
 {[m
[31m-#line 102 "parser.ypp"[m
[32m+[m[32m#line 102 "parser.ypp" /* yacc.c:355  */[m
 [m
     char*       s;[m
     int         i;[m
[36m@@ -225,9 +218,9 @@[m [munion YYSTYPE[m
     class NewArrayA*    newArrayA;[m
     class PrimaryExprA* primaryExprA;[m
 [m
[31m-#line 229 "parser.tab.cpp"[m
[31m-[m
[32m+[m[32m#line 222 "parser.tab.cpp" /* yacc.c:355  */[m
 };[m
[32m+[m
 typedef union YYSTYPE YYSTYPE;[m
 # define YYSTYPE_IS_TRIVIAL 1[m
 # define YYSTYPE_IS_DECLARED 1[m
[36m@@ -240,7 +233,9 @@[m [mint yyparse (void);[m
 [m
 #endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */[m
 [m
[32m+[m[32m/* Copy the second part of user declarations.  */[m
 [m
[32m+[m[32m#line 239 "parser.tab.cpp" /* yacc.c:358  */[m
 [m
 #ifdef short[m
 # undef short[m
[36m@@ -261,13 +256,13 @@[m [mtypedef signed char yytype_int8;[m
 #ifdef YYTYPE_UINT16[m
 typedef YYTYPE_UINT16 yytype_uint16;[m
 #else[m
[31m-typedef unsigned short yytype_uint16;[m
[32m+[m[32mtypedef unsigned short int yytype_uint16;[m
 #endif[m
 [m
 #ifdef YYTYPE_INT16[m
 typedef YYTYPE_INT16 yytype_int16;[m
 #else[m
[31m-typedef short yytype_int16;[m
[32m+[m[32mtypedef short int yytype_int16;[m
 #endif[m
 [m
 #ifndef YYSIZE_T[m
[36m@@ -279,7 +274,7 @@[m [mtypedef short yytype_int16;[m
 #  include <stddef.h> /* INFRINGES ON USER NAME SPACE */[m
 #  define YYSIZE_T size_t[m
 # else[m
[31m-#  define YYSIZE_T unsigned[m
[32m+[m[32m#  define YYSIZE_T unsigned int[m
 # endif[m
 #endif[m
 [m
[36m@@ -315,6 +310,15 @@[m [mtypedef short yytype_int16;[m
 # define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))[m
 #endif[m
 [m
[32m+[m[32m#if !defined _Noreturn \[m
[32m+[m[32m     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)[m
[32m+[m[32m# if defined _MSC_VER && 1200 <= _MSC_VER[m
[32m+[m[32m#  define _Noreturn __declspec (noreturn)[m
[32m+[m[32m# else[m
[32m+[m[32m#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))[m
[32m+[m[32m# endif[m
[32m+[m[32m#endif[m
[32m+[m
 /* Suppress unused-variable warnings by "using" E.  */[m
 #if ! defined lint || defined __GNUC__[m
 # define YYUSE(E) ((void) (E))[m
[36m@@ -322,7 +326,7 @@[m [mtypedef short yytype_int16;[m
 # define YYUSE(E) /* empty */[m
 #endif[m
 [m
[31m-#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__[m
[32m+[m[32m#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__[m
 /* Suppress an incorrect diagnostic about yylval being uninitialized.  */[m
 # define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \[m
     _Pragma ("GCC diagnostic push") \[m
[36m@@ -342,8 +346,6 @@[m [mtypedef short yytype_int16;[m
 #endif[m
 [m
 [m
[31m-#define YY_ASSERT(E) ((void) (0 && (E)))[m
[31m-[m
 #if ! defined yyoverflow || YYERROR_VERBOSE[m
 [m
 /* The parser invokes alloca or malloc; define the necessary symbols.  */[m
[36m@@ -486,16 +488,16 @@[m [munion yyalloc[m
 /* YYNSTATES -- Number of states.  */[m
 #define YYNSTATES  193[m
 [m
[32m+[m[32m/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned[m
[32m+[m[32m   by yylex, with out-of-bounds checking.  */[m
 #define YYUNDEFTOK  2[m
 #define YYMAXUTOK   314[m
 [m
[31m-/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM[m
[31m-   as returned by yylex, with out-of-bounds checking.  */[m
 #define YYTRANSLATE(YYX)                                                \[m
[31m-  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)[m
[32m+[m[32m  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)[m
 [m
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM[m
[31m-   as returned by yylex.  */[m
[32m+[m[32m   as returned by yylex, without out-of-bounds checking.  */[m
 static const yytype_uint8 yytranslate[] =[m
 {[m
        0,     2,     2,     2,     2,     2,     2,     2,     2,     2,[m
[36m@@ -536,17 +538,17 @@[m [mstatic const yytype_uint8 yytranslate[] =[m
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */[m
 static const yytype_uint16 yyrline[] =[m
 {[m
[31m-       0,   162,   162,   166,   173,   177,   181,   185,   191,   197,[m
[31m-     201,   207,   211,   215,   221,   229,   241,   245,   251,   255,[m
[31m-     261,   265,   271,   275,   279,   283,   289,   293,   299,   303,[m
[31m-     309,   315,   319,   323,   329,   333,   339,   343,   347,   351,[m
[31m-     357,   361,   367,   371,   377,   381,   387,   391,   397,   401,[m
[31m-     407,   411,   415,   420,   424,   428,   432,   436,   440,   444,[m
[31m-     448,   452,   458,   462,   466,   470,   474,   478,   482,   486,[m
[31m-     490,   494,   498,   502,   506,   510,   514,   518,   522,   526,[m
[31m-     532,   536,   540,   546,   550,   556,   563,   570,   576,   580,[m
[31m-     584,   588,   592,   596,   600,   604,   608,   614,   618,   624,[m
[31m-     628,   634,   638,   642,   646,   650,   656,   660,   666,   671[m
[32m+[m[32m       0,   162,   162,   166,   174,   178,   182,   186,   192,   198,[m
[32m+[m[32m     202,   208,   212,   216,   222,   230,   242,   246,   252,   256,[m
[32m+[m[32m     262,   266,   272,   276,   280,   284,   290,   294,   300,   304,[m
[32m+[m[32m     310,   316,   320,   324,   330,   334,   340,   344,   348,   352,[m
[32m+[m[32m     358,   362,   368,   372,   378,   382,   388,   392,   398,   402,[m
[32m+[m[32m     408,   412,   416,   421,   425,   429,   433,   437,   441,   445,[m
[32m+[m[32m     449,   453,   459,   463,   467,   471,   475,   479,   483,   487,[m
[32m+[m[32m     491,   495,   499,   503,   507,   511,   515,   519,   523,   527,[m
[32m+[m[32m     533,   537,   541,   547,   551,   557,   564,   571,   577,   581,[m
[32m+[m[32m     585,   589,   593,   597,   601,   605,   609,   615,   619,   625,[m
[32m+[m[32m     629,   635,   639,   643,   647,   651,   657,   661,   667,   672[m
 };[m
 #endif[m
 [m
[36m@@ -846,22 +848,22 @@[m [mstatic const yytype_uint8 yyr2[] =[m
 [m
 #define YYRECOVERING()  (!!yyerrstatus)[m
 [m
[31m-#define YYBACKUP(Token, Value)                                    \[m
[31m-  do                                                              \[m
[31m-    if (yychar == YYEMPTY)                                        \[m
[31m-      {                                                           \[m
[31m-        yychar = (Token);                                         \[m
[31m-        yylval = (Value);                                         \[m
[31m-        YYPOPSTACK (yylen);                                       \[m
[31m-        yystate = *yyssp;                                         \[m
[31m-        goto yybackup;                                            \[m
[31m-      }                                                           \[m
[31m-    else                                                          \[m
[31m-      {                                                           \[m
[31m-        yyerror (YY_("syntax error: cannot back up")); \[m
[31m-        YYERROR;                                                  \[m
[31m-      }                                                           \[m
[31m-  while (0)[m
[32m+[m[32m#define YYBACKUP(Token, Value)                                  \[m
[32m+[m[32mdo                                                              \[m
[32m+[m[32m  if (yychar == YYEMPTY)                                        \[m
[32m+[m[32m    {                                                           \[m
[32m+[m[32m      yychar = (Token);                                         \[m
[32m+[m[32m      yylval = (Value);                                         \[m
[32m+[m[32m      YYPOPSTACK (yylen);                                       \[m
[32m+[m[32m      yystate = *yyssp;                                         \[m
[32m+[m[32m      goto yybackup;                                            \[m
[32m+[m[32m    }                                                           \[m
[32m+[m[32m  else                                                          \[m
[32m+[m[32m    {                                                           \[m
[32m+[m[32m      yyerror (YY_("syntax error: cannot back up")); \[m
[32m+[m[32m      YYERROR;                                                  \[m
[32m+[m[32m    }                                                           \[m
[32m+[m[32mwhile (0)[m
 [m
 /* Error token number */[m
 #define YYTERROR        1[m
[36m@@ -901,39 +903,37 @@[m [mdo {                                                                      \[m
 } while (0)[m
 [m
 [m
[31m-/*-----------------------------------.[m
[31m-| Print this symbol's value on YYO.  |[m
[31m-`-----------------------------------*/[m
[32m+[m[32m/*----------------------------------------.[m
[32m+[m[32m| Print this symbol's value on YYOUTPUT.  |[m
[32m+[m[32m`----------------------------------------*/[m
 [m
 static void[m
[31m-yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)[m
[32m+[m[32myy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)[m
 {[m
[31m-  FILE *yyoutput = yyo;[m
[31m-  YYUSE (yyoutput);[m
[32m+[m[32m  FILE *yyo = yyoutput;[m
[32m+[m[32m  YYUSE (yyo);[m
   if (!yyvaluep)[m
     return;[m
 # ifdef YYPRINT[m
   if (yytype < YYNTOKENS)[m
[31m-    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);[m
[32m+[m[32m    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);[m
 # endif[m
[31m-  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN[m
   YYUSE (yytype);[m
[31m-  YY_IGNORE_MAYBE_UNINITIALIZED_END[m
 }[m
 [m
 [m
[31m-/*---------------------------.[m
[31m-| Print this symbol on YYO.  |[m
[31m-`---------------------------*/[m
[32m+[m[32m/*--------------------------------.[m
[32m+[m[32m| Print this symbol on YYOUTPUT.  |[m
[32m+[m[32m`--------------------------------*/[m
 [m
 static void[m
[31m-yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)[m
[32m+[m[32myy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)[m
 {[m
[31m-  YYFPRINTF (yyo, "%s %s (",[m
[32m+[m[32m  YYFPRINTF (yyoutput, "%s %s (",[m
              yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);[m
 [m
[31m-  yy_symbol_value_print (yyo, yytype, yyvaluep);[m
[31m-  YYFPRINTF (yyo, ")");[m
[32m+[m[32m  yy_symbol_value_print (yyoutput, yytype, yyvaluep);[m
[32m+[m[32m  YYFPRINTF (yyoutput, ")");[m
 }[m
 [m
 /*------------------------------------------------------------------.[m
[36m@@ -967,7 +967,7 @@[m [mdo {                                                            \[m
 static void[m
 yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)[m
 {[m
[31m-  unsigned long yylno = yyrline[yyrule];[m
[32m+[m[32m  unsigned long int yylno = yyrline[yyrule];[m
   int yynrhs = yyr2[yyrule];[m
   int yyi;[m
   YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",[m
[36m@@ -978,7 +978,7 @@[m [myy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)[m
       YYFPRINTF (stderr, "   $%d = ", yyi + 1);[m
       yy_symbol_print (stderr,[m
                        yystos[yyssp[yyi + 1 - yynrhs]],[m
[31m-                       &yyvsp[(yyi + 1) - (yynrhs)][m
[32m+[m[32m                       &(yyvsp[(yyi + 1) - (yynrhs)])[m
                                               );[m
       YYFPRINTF (stderr, "\n");[m
     }[m
[36m@@ -1082,10 +1082,7 @@[m [myytnamerr (char *yyres, const char *yystr)[m
           case '\\':[m
             if (*++yyp != '\\')[m
               goto do_not_strip_quotes;[m
[31m-            else[m
[31m-              goto append;[m
[31m-[m
[31m-          append:[m
[32m+[m[32m            /* Fall through.  */[m
           default:[m
             if (yyres)[m
               yyres[yyn] = *yyp;[m
[36m@@ -1103,7 +1100,7 @@[m [myytnamerr (char *yyres, const char *yystr)[m
   if (! yyres)[m
     return yystrlen (yystr);[m
 [m
[31m-  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);[m
[32m+[m[32m  return yystpcpy (yyres, yystr) - yyres;[m
 }[m
 # endif[m
 [m
[36m@@ -1181,10 +1178,10 @@[m [myysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,[m
                 yyarg[yycount++] = yytname[yyx];[m
                 {[m
                   YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);[m
[31m-                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)[m
[31m-                    yysize = yysize1;[m
[31m-                  else[m
[32m+[m[32m                  if (! (yysize <= yysize1[m
[32m+[m[32m                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))[m
                     return 2;[m
[32m+[m[32m                  yysize = yysize1;[m
                 }[m
               }[m
         }[m
[36m@@ -1196,7 +1193,6 @@[m [myysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,[m
       case N:                               \[m
         yyformat = S;                       \[m
       break[m
[31m-    default: /* Avoid compiler warnings. */[m
       YYCASE_(0, YY_("syntax error"));[m
       YYCASE_(1, YY_("syntax error, unexpected %s"));[m
       YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));[m
[36m@@ -1208,10 +1204,9 @@[m [myysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,[m
 [m
   {[m
     YYSIZE_T yysize1 = yysize + yystrlen (yyformat);[m
[31m-    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)[m
[31m-      yysize = yysize1;[m
[31m-    else[m
[32m+[m[32m    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))[m
       return 2;[m
[32m+[m[32m    yysize = yysize1;[m
   }[m
 [m
   if (*yymsg_alloc < yysize)[m
[36m@@ -1337,33 +1332,23 @@[m [myyparse (void)[m
   yychar = YYEMPTY; /* Cause a token to be read.  */[m
   goto yysetstate;[m
 [m
[31m-[m
 /*------------------------------------------------------------.[m
[31m-| yynewstate -- push a new state, which is found in yystate.  |[m
[32m+[m[32m| yynewstate -- Push a new state, which is found in yystate.  |[m
 `------------------------------------------------------------*/[m
[31m-yynewstate:[m
[32m+[m[32m yynewstate:[m
   /* In all cases, when you get here, the value and location stacks[m
      have just been pushed.  So pushing a state here evens the stacks.  */[m
   yyssp++;[m
 [m
[31m-[m
[31m-/*--------------------------------------------------------------------.[m
[31m-| yynewstate -- set current state (the top of the stack) to yystate.  |[m
[31m-`--------------------------------------------------------------------*/[m
[31m-yysetstate:[m
[31m-  YYDPRINTF ((stderr, "Entering state %d\n", yystate));[m
[31m-  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);[m
[31m-  *yyssp = (yytype_int16) yystate;[m
[32m+[m[32m yysetstate:[m
[32m+[m[32m  *yyssp = yystate;[m
 [m
   if (yyss + yystacksize - 1 <= yyssp)[m
[31m-#if !defined yyoverflow && !defined YYSTACK_RELOCATE[m
[31m-    goto yyexhaustedlab;[m
[31m-#else[m
     {[m
       /* Get the current used size of the three stacks, in elements.  */[m
[31m-      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);[m
[32m+[m[32m      YYSIZE_T yysize = yyssp - yyss + 1;[m
 [m
[31m-# if defined yyoverflow[m
[32m+[m[32m#ifdef yyoverflow[m
       {[m
         /* Give user a chance to reallocate the stack.  Use copies of[m
            these so that the &'s don't force the real ones into[m
[36m@@ -1379,10 +1364,14 @@[m [myysetstate:[m
                     &yyss1, yysize * sizeof (*yyssp),[m
                     &yyvs1, yysize * sizeof (*yyvsp),[m
                     &yystacksize);[m
[32m+[m
         yyss = yyss1;[m
         yyvs = yyvs1;[m
       }[m
[31m-# else /* defined YYSTACK_RELOCATE */[m
[32m+[m[32m#else /* no yyoverflow */[m
[32m+[m[32m# ifndef YYSTACK_RELOCATE[m
[32m+[m[32m      goto yyexhaustedlab;[m
[32m+[m[32m# else[m
       /* Extend the stack our own way.  */[m
       if (YYMAXDEPTH <= yystacksize)[m
         goto yyexhaustedlab;[m
[36m@@ -1398,33 +1387,35 @@[m [myysetstate:[m
           goto yyexhaustedlab;[m
         YYSTACK_RELOCATE (yyss_alloc, yyss);[m
         YYSTACK_RELOCATE (yyvs_alloc, yyvs);[m
[31m-# undef YYSTACK_RELOCATE[m
[32m+[m[32m#  undef YYSTACK_RELOCATE[m
         if (yyss1 != yyssa)[m
           YYSTACK_FREE (yyss1);[m
       }[m
 # endif[m
[32m+[m[32m#endif /* no yyoverflow */[m
 [m
       yyssp = yyss + yysize - 1;[m
       yyvsp = yyvs + yysize - 1;[m
 [m
       YYDPRINTF ((stderr, "Stack size increased to %lu\n",[m
[31m-                  (unsigned long) yystacksize));[m
[32m+[m[32m                  (unsigned long int) yystacksize));[m
 [m
       if (yyss + yystacksize - 1 <= yyssp)[m
         YYABORT;[m
     }[m
[31m-#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */[m
[32m+[m
[32m+[m[32m  YYDPRINTF ((stderr, "Entering state %d\n", yystate));[m
 [m
   if (yystate == YYFINAL)[m
     YYACCEPT;[m
 [m
   goto yybackup;[m
 [m
[31m-[m
 /*-----------.[m
 | yybackup.  |[m
 `-----------*/[m
 yybackup:[m
[32m+[m
   /* Do appropriate processing given the current state.  Read a[m
      lookahead token if we need one and don't already have one.  */[m
 [m
[36m@@ -1482,6 +1473,7 @@[m [myybackup:[m
   YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN[m
   *++yyvsp = yylval;[m
   YY_IGNORE_MAYBE_UNINITIALIZED_END[m
[32m+[m
   goto yynewstate;[m
 [m
 [m
[36m@@ -1496,7 +1488,7 @@[m [myydefault:[m
 [m
 [m
 /*-----------------------------.[m
[31m-| yyreduce -- do a reduction.  |[m
[32m+[m[32m| yyreduce -- Do a reduction.  |[m
 `-----------------------------*/[m
 yyreduce:[m
   /* yyn is the number of a rule to reduce with.  */[m
[36m@@ -1516,116 +1508,117 @@[m [myyreduce:[m
   YY_REDUCE_PRINT (yyn);[m
   switch (yyn)[m
     {[m
[31m-  case 2:[m
[31m-#line 162 "parser.ypp"[m
[32m+[m[32m        case 2:[m
[32m+[m[32m#line 162 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $2; $$->addf($1); ");[m
         (yyval.startA) = (yyvsp[0].startA); (yyval.startA)->addf((yyvsp[-1].classA));[m
     }[m
[31m-#line 1526 "parser.tab.cpp"[m
[32m+[m[32m#line 1518 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 3:[m
[31m-#line 166 "parser.ypp"[m
[32m+[m[32m#line 166 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new StartA(); $$->addf($1); ");[m
         (yyval.startA) = new StartA(); (yyval.startA)->addf((yyvsp[0].classA));[m
[32m+[m[32m        start = (yyval.startA);[m
     }[m
[31m-#line 1535 "parser.tab.cpp"[m
[32m+[m[32m#line 1528 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 4:[m
[31m-#line 173 "parser.ypp"[m
[32m+[m[32m#line 174 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ClassA(new NameA($2), new SuperA( new NameA(\"Object\"))); ");[m
         (yyval.classA) = new ClassA(new NameA((yyvsp[-2].s)), new SuperA( new NameA("Object")));[m
     }[m
[31m-#line 1544 "parser.tab.cpp"[m
[32m+[m[32m#line 1537 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 5:[m
[31m-#line 177 "parser.ypp"[m
[32m+[m[32m#line 178 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ClassA( new NameA($2), new SuperA(new NameA(\"Object\")), $4); ");[m
         (yyval.classA) = new ClassA( new NameA((yyvsp[-3].s)), new SuperA(new NameA("Object")), (yyvsp[-1].listA));[m
     }[m
[31m-#line 1553 "parser.tab.cpp"[m
[32m+[m[32m#line 1546 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 6:[m
[31m-#line 181 "parser.ypp"[m
[32m+[m[32m#line 182 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ClassA( new NameA($2), $3, $5); ");[m
         (yyval.classA) = new ClassA( new NameA((yyvsp[-4].s)), (yyvsp[-3].superA), (yyvsp[-1].listA));[m
     }[m
[31m-#line 1562 "parser.tab.cpp"[m
[32m+[m[32m#line 1555 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 7:[m
[31m-#line 185 "parser.ypp"[m
[32m+[m[32m#line 186 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ClassA( new NameA($2), $3); ");[m
         (yyval.classA) = new ClassA( new NameA((yyvsp[-3].s)), (yyvsp[-2].superA));[m
     }[m
[31m-#line 1571 "parser.tab.cpp"[m
[32m+[m[32m#line 1564 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 8:[m
[31m-#line 191 "parser.ypp"[m
[32m+[m[32m#line 192 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new SuperA(NameA($2)); ");[m
         (yyval.superA) = new SuperA(new NameA((yyvsp[0].s)));[m
      }[m
[31m-#line 1580 "parser.tab.cpp"[m
[32m+[m[32m#line 1573 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 9:[m
[31m-#line 197 "parser.ypp"[m
[32m+[m[32m#line 198 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $2; $$->addf($1); ");[m
         (yyval.listA) = (yyvsp[0].listA); (yyval.listA)->addf((yyvsp[-1].ast));[m
     }[m
[31m-#line 1589 "parser.tab.cpp"[m
[32m+[m[32m#line 1582 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 10:[m
[31m-#line 201 "parser.ypp"[m
[32m+[m[32m#line 202 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ListA(); $$->addf($1); ");[m
         (yyval.listA) = new ListA(); (yyval.listA)->addf((yyvsp[0].ast));[m
     }[m
[31m-#line 1598 "parser.tab.cpp"[m
[32m+[m[32m#line 1591 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 11:[m
[31m-#line 207 "parser.ypp"[m
[32m+[m[32m#line 208 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $1; ");[m
         (yyval.ast) = (yyvsp[0].listA);[m
     }[m
[31m-#line 1607 "parser.tab.cpp"[m
[32m+[m[32m#line 1600 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 12:[m
[31m-#line 211 "parser.ypp"[m
[32m+[m[32m#line 212 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $1; ");[m
         (yyval.ast) = (yyvsp[0].methodA);[m
     }[m
[31m-#line 1616 "parser.tab.cpp"[m
[32m+[m[32m#line 1609 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 13:[m
[31m-#line 215 "parser.ypp"[m
[32m+[m[32m#line 216 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $1; ");[m
         (yyval.ast) = (yyvsp[0].constructorA);[m
     }[m
[31m-#line 1625 "parser.tab.cpp"[m
[32m+[m[32m#line 1618 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 14:[m
[31m-#line 221 "parser.ypp"[m
[32m+[m[32m#line 222 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug("$$ = new ListA();\n for(auto const field : $3->getASTs()) \n{\n \t $$->addb(new FieldA($1, $2, field));\n}");[m
         (yyval.listA) = new ListA();[m
[36m@@ -1634,11 +1627,11 @@[m [myyreduce:[m
             (yyval.listA)->addb(new FieldA((yyvsp[-3].listA), (yyvsp[-2].typeA), static_cast<VarDeclA*>(field)));[m
         }[m
     }[m
[31m-#line 1638 "parser.tab.cpp"[m
[32m+[m[32m#line 1631 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 15:[m
[31m-#line 229 "parser.ypp"[m
[32m+[m[32m#line 230 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug("$$ = new ListA();\nfor(auto const field : $2)\n{\n \t$$->addb(new FieldA(\"public\", $1, field));\n}");[m
         (yyval.listA) = new ListA();[m
[36m@@ -1649,632 +1642,632 @@[m [myyreduce:[m
             (yyval.listA)->addb(new FieldA(list, (yyvsp[-2].typeA), static_cast<VarDeclA*>(field)));[m
         }[m
     }[m
[31m-#line 1653 "parser.tab.cpp"[m
[32m+[m[32m#line 1646 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 16:[m
[31m-#line 241 "parser.ypp"[m
[32m+[m[32m#line 242 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $2; $$->addf($1); ");[m
         (yyval.listA) = (yyvsp[0].listA); (yyval.listA)->addf((yyvsp[-1].modifierA));[m
     }[m
[31m-#line 1662 "parser.tab.cpp"[m
[32m+[m[32m#line 1655 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 17:[m
[31m-#line 245 "parser.ypp"[m
[32m+[m[32m#line 246 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ListA(); $$->addf($1); ");[m
         (yyval.listA) = new ListA(); (yyval.listA)->addf((yyvsp[0].modifierA));[m
     }[m
[31m-#line 1671 "parser.tab.cpp"[m
[32m+[m[32m#line 1664 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 18:[m
[31m-#line 251 "parser.ypp"[m
[32m+[m[32m#line 252 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new MethodA($1, $2, $3, $4, new MethodBodyA($4, $5->getStatementList())); ");[m
         (yyval.methodA) = new MethodA((yyvsp[-4].listA), (yyvsp[-3].typeA), (yyvsp[-2].s), (yyvsp[-1].listA), new MethodBodyA((yyvsp[-1].listA), (yyvsp[0].blockA)->getStatementList()));[m
     }[m
[31m-#line 1680 "parser.tab.cpp"[m
[32m+[m[32m#line 1673 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 19:[m
[31m-#line 255 "parser.ypp"[m
[32m+[m[32m#line 256 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new MethodA($1, $2, $3, new MethodBodyA($3, $4->getStatementList())); ");[m
         (yyval.methodA) = new MethodA((yyvsp[-3].typeA), (yyvsp[-2].s), (yyvsp[-1].listA), new MethodBodyA((yyvsp[-1].listA), (yyvsp[0].blockA)->getStatementList()));[m
     }[m
[31m-#line 1689 "parser.tab.cpp"[m
[32m+[m[32m#line 1682 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 20:[m
[31m-#line 261 "parser.ypp"[m
[32m+[m[32m#line 262 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ConstructorA(new NameA($2), $1, new MethodBodyA($3, $4->getStatementList())); ");[m
         (yyval.constructorA) = new ConstructorA(new ClassTypeA(new NameA((yyvsp[-2].s))), (yyvsp[-3].listA), new MethodBodyA((yyvsp[-1].listA), (yyvsp[0].blockA)->getStatementList()));[m
     }[m
[31m-#line 1698 "parser.tab.cpp"[m
[32m+[m[32m#line 1691 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 21:[m
[31m-#line 265 "parser.ypp"[m
[32m+[m[32m#line 266 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ConstructorA(new NameA($1), new MethodBodyA($2, $3->getStatementList())); ");[m
         (yyval.constructorA) = new ConstructorA(new ClassTypeA(new NameA((yyvsp[-2].s))), new MethodBodyA((yyvsp[-1].listA), (yyvsp[0].blockA)->getStatementList()));[m
     }[m
[31m-#line 1707 "parser.tab.cpp"[m
[32m+[m[32m#line 1700 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 22:[m
[31m-#line 271 "parser.ypp"[m
[32m+[m[32m#line 272 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ModifierA(\"static\"); ");[m
         (yyval.modifierA) = new ModifierA("static");[m
     }[m
[31m-#line 1716 "parser.tab.cpp"[m
[32m+[m[32m#line 1709 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 23:[m
[31m-#line 275 "parser.ypp"[m
[32m+[m[32m#line 276 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ModifierA(\"public\"); ");[m
         (yyval.modifierA) = new ModifierA("public");[m
     }[m
[31m-#line 1725 "parser.tab.cpp"[m
[32m+[m[32m#line 1718 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 24:[m
[31m-#line 279 "parser.ypp"[m
[32m+[m[32m#line 280 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ModifierA(\"private\"); ");[m
         (yyval.modifierA) = new ModifierA("private");[m
     }[m
[31m-#line 1734 "parser.tab.cpp"[m
[32m+[m[32m#line 1727 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 25:[m
[31m-#line 283 "parser.ypp"[m
[32m+[m[32m#line 284 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ModifierA(\"protected\"); ");[m
         (yyval.modifierA) = new ModifierA("protected");[m
     }[m
[31m-#line 1743 "parser.tab.cpp"[m
[32m+[m[32m#line 1736 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 26:[m
[31m-#line 289 "parser.ypp"[m
[32m+[m[32m#line 290 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $2; ");[m
         (yyval.listA) = (yyvsp[-1].listA);[m
     }[m
[31m-#line 1752 "parser.tab.cpp"[m
[32m+[m[32m#line 1745 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 27:[m
[31m-#line 293 "parser.ypp"[m
[32m+[m[32m#line 294 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ListA(); ");[m
         (yyval.listA) = new ListA();[m
     }[m
[31m-#line 1761 "parser.tab.cpp"[m
[32m+[m[32m#line 1754 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 28:[m
[31m-#line 299 "parser.ypp"[m
[32m+[m[32m#line 300 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $3; $$->addf($1); ");[m
         (yyval.listA) = (yyvsp[0].listA); (yyval.listA)->addf((yyvsp[-2].formalA));[m
     }[m
[31m-#line 1770 "parser.tab.cpp"[m
[32m+[m[32m#line 1763 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 29:[m
[31m-#line 303 "parser.ypp"[m
[32m+[m[32m#line 304 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ListA(); $$->addf($1); ");[m
         (yyval.listA) = new ListA(); (yyval.listA)->addf((yyvsp[0].formalA));[m
     }[m
[31m-#line 1779 "parser.tab.cpp"[m
[32m+[m[32m#line 1772 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 30:[m
[31m-#line 309 "parser.ypp"[m
[32m+[m[32m#line 310 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new FormalA($1, $2);");[m
         (yyval.formalA) = new FormalA((yyvsp[-1].typeA), (yyvsp[0].s));[m
     }[m
[31m-#line 1788 "parser.tab.cpp"[m
[32m+[m[32m#line 1781 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 31:[m
[31m-#line 315 "parser.ypp"[m
[32m+[m[32m#line 316 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $1; ");[m
         (yyval.typeA) = (yyvsp[0].primTypeA);[m
     }[m
[31m-#line 1797 "parser.tab.cpp"[m
[32m+[m[32m#line 1790 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 32:[m
[31m-#line 319 "parser.ypp"[m
[32m+[m[32m#line 320 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ClassTypeA($1); ");[m
         (yyval.typeA) = new ClassTypeA(new NameA((yyvsp[0].s)));[m
     }[m
[31m-#line 1806 "parser.tab.cpp"[m
[32m+[m[32m#line 1799 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 33:[m
[31m-#line 323 "parser.ypp"[m
[32m+[m[32m#line 324 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ArrayTypeA(new NameA($1), $2); ");[m
         (yyval.typeA) = new ArrayTypeA((yyvsp[-1].typeA), (yyvsp[0].i));[m
     }[m
[31m-#line 1815 "parser.tab.cpp"[m
[32m+[m[32m#line 1808 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 34:[m
[31m-#line 329 "parser.ypp"[m
[32m+[m[32m#line 330 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = ++$3; ");[m
         (yyval.i) = ++(yyvsp[0].i);[m
     }[m
[31m-#line 1824 "parser.tab.cpp"[m
[32m+[m[32m#line 1817 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 35:[m
[31m-#line 333 "parser.ypp"[m
[32m+[m[32m#line 334 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = 1; ");[m
         (yyval.i) = 1;[m
     }[m
[31m-#line 1833 "parser.tab.cpp"[m
[32m+[m[32m#line 1826 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 36:[m
[31m-#line 339 "parser.ypp"[m
[32m+[m[32m#line 340 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new PrimTypeA(new NameA($1)); ");[m
         (yyval.primTypeA) = new PrimTypeA(new NameA((yyvsp[0].s)));[m
     }[m
[31m-#line 1842 "parser.tab.cpp"[m
[32m+[m[32m#line 1835 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 37:[m
[31m-#line 343 "parser.ypp"[m
[32m+[m[32m#line 344 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new PrimTypeA(new NameA($1)); ");[m
         (yyval.primTypeA) = new PrimTypeA(new NameA((yyvsp[0].s)));[m
     }[m
[31m-#line 1851 "parser.tab.cpp"[m
[32m+[m[32m#line 1844 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 38:[m
[31m-#line 347 "parser.ypp"[m
[32m+[m[32m#line 348 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new PrimTypeA(new NameA($1)); ");[m
         (yyval.primTypeA) = new PrimTypeA(new NameA((yyvsp[0].s)));[m
     }[m
[31m-#line 1860 "parser.tab.cpp"[m
[32m+[m[32m#line 1853 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 39:[m
[31m-#line 351 "parser.ypp"[m
[32m+[m[32m#line 352 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new PrimTypeA(new NameA($1)); ");[m
         (yyval.primTypeA) = new PrimTypeA(new NameA((yyvsp[0].s)));[m
     }[m
[31m-#line 1869 "parser.tab.cpp"[m
[32m+[m[32m#line 1862 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 40:[m
[31m-#line 357 "parser.ypp"[m
[32m+[m[32m#line 358 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $3; $$->addf($1); ");[m
         (yyval.listA) = (yyvsp[0].listA); (yyval.listA)->addf((yyvsp[-2].varDeclA));[m
     }[m
[31m-#line 1878 "parser.tab.cpp"[m
[32m+[m[32m#line 1871 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 41:[m
[31m-#line 361 "parser.ypp"[m
[32m+[m[32m#line 362 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new StartA(); $$->addf($1); ");[m
         (yyval.listA) = new ListA(); (yyval.listA)->addf((yyvsp[0].varDeclA));[m
     }[m
[31m-#line 1887 "parser.tab.cpp"[m
[32m+[m[32m#line 1880 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 42:[m
[31m-#line 367 "parser.ypp"[m
[32m+[m[32m#line 368 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new VarDeclA($1, $3); ");[m
         (yyval.varDeclA) = new VarDeclA((yyvsp[-2].s), (yyvsp[0].expressionA));[m
     }[m
[31m-#line 1896 "parser.tab.cpp"[m
[32m+[m[32m#line 1889 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 43:[m
[31m-#line 371 "parser.ypp"[m
[32m+[m[32m#line 372 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new VarDeclA($1); ");[m
         (yyval.varDeclA) = new VarDeclA((yyvsp[0].s));[m
     }[m
[31m-#line 1905 "parser.tab.cpp"[m
[32m+[m[32m#line 1898 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 44:[m
[31m-#line 377 "parser.ypp"[m
[32m+[m[32m#line 378 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yyerror(" $$ = $1+\"[]\"; ");[m
         (yyval.s) = (yyvsp[-2].s);[m
     }[m
[31m-#line 1914 "parser.tab.cpp"[m
[32m+[m[32m#line 1907 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 45:[m
[31m-#line 381 "parser.ypp"[m
[32m+[m[32m#line 382 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $1; ");[m
         (yyval.s) = (yyvsp[0].s);[m
     }[m
[31m-#line 1923 "parser.tab.cpp"[m
[32m+[m[32m#line 1916 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 46:[m
[31m-#line 387 "parser.ypp"[m
[32m+[m[32m#line 388 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new BlockA($2); ");[m
             (yyval.blockA) = new BlockA((yyvsp[-1].listA));[m
         }[m
[31m-#line 1932 "parser.tab.cpp"[m
[32m+[m[32m#line 1925 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 47:[m
[31m-#line 391 "parser.ypp"[m
[32m+[m[32m#line 392 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new BlockA(); ");[m
         (yyval.blockA) = new BlockA();[m
     }[m
[31m-#line 1941 "parser.tab.cpp"[m
[32m+[m[32m#line 1934 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 48:[m
[31m-#line 397 "parser.ypp"[m
[32m+[m[32m#line 398 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $2; $$->addf($1); ");[m
         (yyval.listA) = (yyvsp[0].listA); (yyval.listA)->addf((yyvsp[-1].statementA));[m
     }[m
[31m-#line 1950 "parser.tab.cpp"[m
[32m+[m[32m#line 1943 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 49:[m
[31m-#line 401 "parser.ypp"[m
[32m+[m[32m#line 402 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ListA(); $$->addf($1); ");[m
         (yyval.listA) = new ListA(); (yyval.listA)->addf((yyvsp[0].statementA));[m
     }[m
[31m-#line 1959 "parser.tab.cpp"[m
[32m+[m[32m#line 1952 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 50:[m
[31m-#line 407 "parser.ypp"[m
[32m+[m[32m#line 408 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yyerror(" $$ =new EmptyStatement() ");[m
         (yyval.statementA) = new EmptyStatementA();[m
     }[m
[31m-#line 1968 "parser.tab.cpp"[m
[32m+[m[32m#line 1961 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 51:[m
[31m-#line 411 "parser.ypp"[m
[32m+[m[32m#line 412 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new DeclStatementA($1, $2); ");[m
         (yyval.statementA) = new DeclStatementA((yyvsp[-2].typeA), (yyvsp[-1].listA));[m
     }[m
[31m-#line 1977 "parser.tab.cpp"[m
[32m+[m[32m#line 1970 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 52:[m
[31m-#line 416 "parser.ypp"[m
[32m+[m[32m#line 417 "parser.ypp" /* yacc.c:1646  */[m
     {[m
             yyerror(" $$ = new IfStatementA($3, $5, NULL); ");[m
             (yyval.statementA) = new IfStatementA((yyvsp[-2].expressionA), (yyvsp[0].statementA), NULL);[m
     }[m
[31m-#line 1986 "parser.tab.cpp"[m
[32m+[m[32m#line 1979 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 53:[m
[31m-#line 420 "parser.ypp"[m
[32m+[m[32m#line 421 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yyerror(" $$ = new IfStatementA($3, $5, $7); ");[m
         (yyval.statementA) = new IfStatementA((yyvsp[-4].expressionA), (yyvsp[-2].statementA), (yyvsp[0].statementA));[m
     }[m
[31m-#line 1995 "parser.tab.cpp"[m
[32m+[m[32m#line 1988 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 54:[m
[31m-#line 424 "parser.ypp"[m
[32m+[m[32m#line 425 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ExpressionStatementA($1); ");[m
         (yyval.statementA) = new ExpressionStatementA((yyvsp[-1].expressionA));[m
     }[m
[31m-#line 2004 "parser.tab.cpp"[m
[32m+[m[32m#line 1997 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 55:[m
[31m-#line 428 "parser.ypp"[m
[32m+[m[32m#line 429 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yyerror(" $$ = new WhileStatement(new symbolTable(), $3, $5); ");[m
         (yyval.statementA) = new WhileStatementA((yyvsp[-2].expressionA), (yyvsp[0].statementA));[m
     }[m
[31m-#line 2013 "parser.tab.cpp"[m
[32m+[m[32m#line 2006 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 56:[m
[31m-#line 432 "parser.ypp"[m
[32m+[m[32m#line 433 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yyerror(" $$ = new ReturnStatement(NULL); ");[m
         (yyval.statementA) = new ReturnStatementA(NULL);[m
     }[m
[31m-#line 2022 "parser.tab.cpp"[m
[32m+[m[32m#line 2015 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 57:[m
[31m-#line 436 "parser.ypp"[m
[32m+[m[32m#line 437 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yyerror(" $$ = new ReturnStatement($2); ");[m
         (yyval.statementA) = new ReturnStatementA((yyvsp[-1].expressionA));[m
     }[m
[31m-#line 2031 "parser.tab.cpp"[m
[32m+[m[32m#line 2024 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 58:[m
[31m-#line 440 "parser.ypp"[m
[32m+[m[32m#line 441 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yyerror(" $$ = new ContinueStatement(); ");[m
         (yyval.statementA) = new ContinueStatementA();[m
     }[m
[31m-#line 2040 "parser.tab.cpp"[m
[32m+[m[32m#line 2033 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 59:[m
[31m-#line 444 "parser.ypp"[m
[32m+[m[32m#line 445 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yyerror(" $$ = new BreakStatement(); ");[m
         (yyval.statementA) = new BreakStatementA();[m
     }[m
[31m-#line 2049 "parser.tab.cpp"[m
[32m+[m[32m#line 2042 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 60:[m
[31m-#line 448 "parser.ypp"[m
[32m+[m[32m#line 449 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yyerror(" $$ = new Block($1); ");[m
         (yyval.statementA) = new BlockStatementA((yyvsp[0].blockA));[m
     }[m
[31m-#line 2058 "parser.tab.cpp"[m
[32m+[m[32m#line 2051 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 61:[m
[31m-#line 452 "parser.ypp"[m
[32m+[m[32m#line 453 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yyerror(" $$ = new SuperStatementA($2); ");[m
         (yyval.statementA) = new SuperStatementA((yyvsp[-1].listA));[m
     }[m
[31m-#line 2067 "parser.tab.cpp"[m
[32m+[m[32m#line 2060 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 62:[m
[31m-#line 458 "parser.ypp"[m
[32m+[m[32m#line 459 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new OpExpressionA($2, $1, $3); ");[m
         (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));[m
         }[m
[31m-#line 2076 "parser.tab.cpp"[m
[32m+[m[32m#line 2069 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 63:[m
[31m-#line 462 "parser.ypp"[m
[32m+[m[32m#line 463 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new OpExpressionA($2, $1, $3); ");[m
         (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));[m
     }[m
[31m-#line 2085 "parser.tab.cpp"[m
[32m+[m[32m#line 2078 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 64:[m
[31m-#line 466 "parser.ypp"[m
[32m+[m[32m#line 467 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new OpExpressionA($2, $1, $3); ");[m
         (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));[m
     }[m
[31m-#line 2094 "parser.tab.cpp"[m
[32m+[m[32m#line 2087 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 65:[m
[31m-#line 470 "parser.ypp"[m
[32m+[m[32m#line 471 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new OpExpressionA($2, $1, $3); ");[m
         (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));[m
     }[m
[31m-#line 2103 "parser.tab.cpp"[m
[32m+[m[32m#line 2096 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 66:[m
[31m-#line 474 "parser.ypp"[m
[32m+[m[32m#line 475 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new OpExpressionA($2, $1, $3); ");[m
         (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));[m
     }[m
[31m-#line 2112 "parser.tab.cpp"[m
[32m+[m[32m#line 2105 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 67:[m
[31m-#line 478 "parser.ypp"[m
[32m+[m[32m#line 479 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new OpExpressionA($2, $1, $3); ");[m
         (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));[m
     }[m
[31m-#line 2121 "parser.tab.cpp"[m
[32m+[m[32m#line 2114 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 68:[m
[31m-#line 482 "parser.ypp"[m
[32m+[m[32m#line 483 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new OpExpressionA($2, $1, $3); ");[m
         (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));[m
     }[m
[31m-#line 2130 "parser.tab.cpp"[m
[32m+[m[32m#line 2123 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 69:[m
[31m-#line 486 "parser.ypp"[m
[32m+[m[32m#line 487 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new OpExpressionA($2, $1, $3); ");[m
         (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));[m
     }[m
[31m-#line 2139 "parser.tab.cpp"[m
[32m+[m[32m#line 2132 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 70:[m
[31m-#line 490 "parser.ypp"[m
[32m+[m[32m#line 491 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new OpExpressionA($2, $1, $3); ");[m
         (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));[m
     }[m
[31m-#line 2148 "parser.tab.cpp"[m
[32m+[m[32m#line 2141 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 71:[m
[31m-#line 494 "parser.ypp"[m
[32m+[m[32m#line 495 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new OpExpressionA($2, $1, $3); ");[m
         (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));[m
     }[m
[31m-#line 2157 "parser.tab.cpp"[m
[32m+[m[32m#line 2150 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 72:[m
[31m-#line 498 "parser.ypp"[m
[32m+[m[32m#line 499 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new OpExpressionA($2, $1, $3); ");[m
         (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));[m
     }[m
[31m-#line 2166 "parser.tab.cpp"[m
[32m+[m[32m#line 2159 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 73:[m
[31m-#line 502 "parser.ypp"[m
[32m+[m[32m#line 503 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new OpExpressionA($2, $1, $3); ");[m
         (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));[m
     }[m
[31m-#line 2175 "parser.tab.cpp"[m
[32m+[m[32m#line 2168 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 74:[m
[31m-#line 506 "parser.ypp"[m
[32m+[m[32m#line 507 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new OpExpressionA($2, $1, $3); ");[m
         (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));[m
     }[m
[31m-#line 2184 "parser.tab.cpp"[m
[32m+[m[32m#line 2177 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 75:[m
[31m-#line 510 "parser.ypp"[m
[32m+[m[32m#line 511 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new OpExpressionA($2, $1, $3); ");[m
         (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[-2].expressionA), (yyvsp[0].expressionA));[m
     }[m
[31m-#line 2193 "parser.tab.cpp"[m
[32m+[m[32m#line 2186 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 76:[m
[31m-#line 514 "parser.ypp"[m
[32m+[m[32m#line 515 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new OpExpressionA($1, $2); ");[m
         (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[0].expressionA));[m
     }[m
[31m-#line 2202 "parser.tab.cpp"[m
[32m+[m[32m#line 2195 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 77:[m
[31m-#line 518 "parser.ypp"[m
[32m+[m[32m#line 519 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new OpExpressionA($1, $2); ");[m
         (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[0].expressionA));[m
     }[m
[31m-#line 2211 "parser.tab.cpp"[m
[32m+[m[32m#line 2204 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 78:[m
[31m-#line 522 "parser.ypp"[m
[32m+[m[32m#line 523 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new OpExpressionA($1, $2); ");[m
         (yyval.expressionA) = new OpExpressionA((yyvsp[-1].s), (yyvsp[0].expressionA));[m
     }[m
[31m-#line 2220 "parser.tab.cpp"[m
[32m+[m[32m#line 2213 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 79:[m
[31m-#line 526 "parser.ypp"[m
[32m+[m[32m#line 527 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $1; ");[m
         (yyval.expressionA) = (yyvsp[0].primaryExprA);[m
     }[m
[31m-#line 2229 "parser.tab.cpp"[m
[32m+[m[32m#line 2222 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 80:[m
[31m-#line 532 "parser.ypp"[m
[32m+[m[32m#line 533 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yyerror(" $$ = $1 ");[m
         (yyval.primaryExprA) = new PrimaryArrayA((yyvsp[0].newArrayA));[m
     }[m
[31m-#line 2238 "parser.tab.cpp"[m
[32m+[m[32m#line 2231 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 81:[m
[31m-#line 536 "parser.ypp"[m
[32m+[m[32m#line 537 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $1; ");[m
         (yyval.primaryExprA) = new NonArrayPrimaryA((yyvsp[0].expressionA));[m
     }[m
[31m-#line 2247 "parser.tab.cpp"[m
[32m+[m[32m#line 2240 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 82:[m
[31m-#line 540 "parser.ypp"[m
[32m+[m[32m#line 541 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $1; ");[m
         (yyval.primaryExprA) = new NameA((yyvsp[0].s));[m
     }[m
[31m-#line 2256 "parser.tab.cpp"[m
[32m+[m[32m#line 2249 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 83:[m
[31m-#line 546 "parser.ypp"[m
[32m+[m[32m#line 547 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" new NewArrayA( new NameA($2), $3) ");[m
         new NewArrayA( new ClassTypeA(new NameA((yyvsp[-1].s))), (yyvsp[0].listA));[m
     }[m
[31m-#line 2265 "parser.tab.cpp"[m
[32m+[m[32m#line 2258 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 84:[m
[31m-#line 550 "parser.ypp"[m
[32m+[m[32m#line 551 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug("new newArrayA($2, $3);");[m
         new NewArrayA((yyvsp[-1].primTypeA), (yyvsp[0].listA));[m
     }[m
[31m-#line 2274 "parser.tab.cpp"[m
[32m+[m[32m#line 2267 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 85:[m
[31m-#line 556 "parser.ypp"[m
[32m+[m[32m#line 557 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $2; $$->addf(new DimensionA($1)); ");[m
         (yyval.listA) = (yyvsp[0].listA);[m
[36m@@ -2282,231 +2275,230 @@[m [myyreduce:[m
 [m
 [m
     }[m
[31m-#line 2286 "parser.tab.cpp"[m
[32m+[m[32m#line 2279 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 86:[m
[31m-#line 563 "parser.ypp"[m
[32m+[m[32m#line 564 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ListA(); $$->addf($1);; ");[m
         (yyval.listA) = new ListA();[m
         (yyval.listA)->addf((yyvsp[0].dimensionA));[m
     }[m
[31m-#line 2296 "parser.tab.cpp"[m
[32m+[m[32m#line 2289 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 87:[m
[31m-#line 570 "parser.ypp"[m
[32m+[m[32m#line 571 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new DimensionA($2); ");[m
         (yyval.dimensionA) = new DimensionA((yyvsp[-1].expressionA));[m
     }[m
[31m-#line 2305 "parser.tab.cpp"[m
[32m+[m[32m#line 2298 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 88:[m
[31m-#line 576 "parser.ypp"[m
[32m+[m[32m#line 577 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $1; ");[m
         (yyval.expressionA) = (yyvsp[0].litA);[m
     }[m
[31m-#line 2314 "parser.tab.cpp"[m
[32m+[m[32m#line 2307 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 89:[m
[31m-#line 580 "parser.ypp"[m
[32m+[m[32m#line 581 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ThisExprA(); ");[m
         (yyval.expressionA) = new ThisExprA();[m
     }[m
[31m-#line 2323 "parser.tab.cpp"[m
[32m+[m[32m#line 2316 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 90:[m
[31m-#line 584 "parser.ypp"[m
[32m+[m[32m#line 585 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $2; ");[m
         (yyval.expressionA) = (yyvsp[-1].expressionA);[m
     }[m
[31m-#line 2332 "parser.tab.cpp"[m
[32m+[m[32m#line 2325 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 91:[m
[31m-#line 588 "parser.ypp"[m
[32m+[m[32m#line 589 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new NewObjExprA(new NameA($2), $3); ");[m
         (yyval.expressionA) = new NewObjExprA(new NameA((yyvsp[-1].s)), (yyvsp[0].listA));[m
     }[m
[31m-#line 2341 "parser.tab.cpp"[m
[32m+[m[32m#line 2334 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 92:[m
[31m-#line 592 "parser.ypp"[m
[32m+[m[32m#line 593 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ThisCallExprA($1, $2); ");[m
         (yyval.expressionA) = new ThisCallExprA(new NameA((yyvsp[-1].s)), (yyvsp[0].listA));[m
     }[m
[31m-#line 2350 "parser.tab.cpp"[m
[32m+[m[32m#line 2343 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 93:[m
[31m-#line 596 "parser.ypp"[m
[32m+[m[32m#line 597 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new MethodCallExprA($1, $3, $4); ");[m
         (yyval.expressionA) = new MethodCallExprA((yyvsp[-3].primaryExprA), new NameA((yyvsp[-1].s)), (yyvsp[0].listA));[m
     }[m
[31m-#line 2359 "parser.tab.cpp"[m
[32m+[m[32m#line 2352 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 94:[m
[31m-#line 600 "parser.ypp"[m
[32m+[m[32m#line 601 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new SuperCallExprA($3, $4); ");[m
         (yyval.expressionA) = new SuperCallExprA(new NameA((yyvsp[-1].s)), (yyvsp[0].listA));[m
     }[m
[31m-#line 2368 "parser.tab.cpp"[m
[32m+[m[32m#line 2361 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 95:[m
[31m-#line 604 "parser.ypp"[m
[32m+[m[32m#line 605 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $1; ");[m
         (yyval.expressionA) = (yyvsp[0].arrayRefA);[m
     }[m
[31m-#line 2377 "parser.tab.cpp"[m
[32m+[m[32m#line 2370 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 96:[m
[31m-#line 608 "parser.ypp"[m
[32m+[m[32m#line 609 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $1; ");[m
         (yyval.expressionA) = (yyvsp[0].expressionA);[m
     }[m
[31m-#line 2386 "parser.tab.cpp"[m
[32m+[m[32m#line 2379 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 97:[m
[31m-#line 614 "parser.ypp"[m
[32m+[m[32m#line 615 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new FieldExprA($1, $3);");[m
         (yyval.expressionA) = new FieldExprA((yyvsp[-2].primaryExprA), new NameA((yyvsp[0].s)));[m
     }[m
[31m-#line 2395 "parser.tab.cpp"[m
[32m+[m[32m#line 2388 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 98:[m
[31m-#line 618 "parser.ypp"[m
[32m+[m[32m#line 619 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new SuperfieldExpr($3); ");[m
         (yyval.expressionA) = new SuperFieldExprA(new NameA((yyvsp[0].s)));[m
     }[m
[31m-#line 2404 "parser.tab.cpp"[m
[32m+[m[32m#line 2397 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 99:[m
[31m-#line 624 "parser.ypp"[m
[32m+[m[32m#line 625 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ArrayRefA(new NameA($1), $2); ");[m
         (yyval.arrayRefA) = new ArrayRefA(new NameA((yyvsp[-1].s)), (yyvsp[0].dimensionA));[m
     }[m
[31m-#line 2413 "parser.tab.cpp"[m
[32m+[m[32m#line 2406 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 100:[m
[31m-#line 628 "parser.ypp"[m
[32m+[m[32m#line 629 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ArrayRefA($1, $2); ");[m
         (yyval.arrayRefA) = new ArrayRefA((yyvsp[-1].expressionA), (yyvsp[0].dimensionA));[m
     }[m
[31m-#line 2422 "parser.tab.cpp"[m
[32m+[m[32m#line 2415 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 101:[m
[31m-#line 634 "parser.ypp"[m
[32m+[m[32m#line 635 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yyerror(" $$ = new NullLiteral(); ");[m
         (yyval.litA) = new NullLitA();[m
     }[m
[31m-#line 2431 "parser.tab.cpp"[m
[32m+[m[32m#line 2424 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 102:[m
[31m-#line 638 "parser.ypp"[m
[32m+[m[32m#line 639 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yyerror(" $$ = new BoolLiteral($1); ");[m
         (yyval.litA) = new BoolLitA((yyvsp[0].b));[m
     }[m
[31m-#line 2440 "parser.tab.cpp"[m
[32m+[m[32m#line 2433 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 103:[m
[31m-#line 642 "parser.ypp"[m
[32m+[m[32m#line 643 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new IntLitA($1); ");[m
         (yyval.litA) = new IntLitA((yyvsp[0].i));[m
     }[m
[31m-#line 2449 "parser.tab.cpp"[m
[32m+[m[32m#line 2442 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 104:[m
[31m-#line 646 "parser.ypp"[m
[32m+[m[32m#line 647 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yyerror(" $$ = new CharLitA($1); ");[m
         (yyval.litA) = new CharLitA((yyvsp[0].c));[m
     }[m
[31m-#line 2458 "parser.tab.cpp"[m
[32m+[m[32m#line 2451 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 105:[m
[31m-#line 650 "parser.ypp"[m
[32m+[m[32m#line 651 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new StrLitA($1); ");[m
         (yyval.litA) = new StrLitA((yyvsp[0].s));[m
     }[m
[31m-#line 2467 "parser.tab.cpp"[m
[32m+[m[32m#line 2460 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 106:[m
[31m-#line 656 "parser.ypp"[m
[32m+[m[32m#line 657 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $2 ");[m
         (yyval.listA) = (yyvsp[-1].listA);[m
     }[m
[31m-#line 2476 "parser.tab.cpp"[m
[32m+[m[32m#line 2469 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 107:[m
[31m-#line 660 "parser.ypp"[m
[32m+[m[32m#line 661 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = ListA(); ");[m
         (yyval.listA) = new ListA();[m
     }[m
[31m-#line 2485 "parser.tab.cpp"[m
[32m+[m[32m#line 2478 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 108:[m
[31m-#line 666 "parser.ypp"[m
[32m+[m[32m#line 667 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = $2; $$->addf($1); ");[m
         (yyval.listA) = (yyvsp[0].listA);[m
         (yyval.listA)->addf((yyvsp[-2].expressionA));[m
     }[m
[31m-#line 2495 "parser.tab.cpp"[m
[32m+[m[32m#line 2488 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
   case 109:[m
[31m-#line 671 "parser.ypp"[m
[32m+[m[32m#line 672 "parser.ypp" /* yacc.c:1646  */[m
     {[m
         yydebug(" $$ = new ListA(); $$->addf($1); ");[m
         (yyval.listA) = new ListA();[m
         (yyval.listA)->addf((yyvsp[0].expressionA));[m
     }[m
[31m-#line 2505 "parser.tab.cpp"[m
[32m+[m[32m#line 2498 "parser.tab.cpp" /* yacc.c:1646  */[m
     break;[m
 [m
 [m
[31m-#line 2509 "parser.tab.cpp"[m
[31m-[m
[32m+[m[32m#line 2502 "parser.tab.cpp" /* yacc.c:1646  */[m
       default: break;[m
     }[m
   /* User semantic actions sometimes alter yychar, and that requires[m
[36m@@ -2531,13 +2523,14 @@[m [myyreduce:[m
   /* Now 'shift' the result of the reduction.  Determine what state[m
      that goes to, based on the state we popped back to and the rule[m
      number reduced by.  */[m
[31m-  {[m
[31m-    const int yylhs = yyr1[yyn] - YYNTOKENS;[m
[31m-    const int yyi = yypgoto[yylhs] + *yyssp;[m
[31m-    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp[m
[31m-               ? yytable[yyi][m
[31m-               : yydefgoto[yylhs]);[m
[31m-  }[m
[32m+[m
[32m+[m[32m  yyn = yyr1[yyn];[m
[32m+[m
[32m+[m[32m  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;[m
[32m+[m[32m  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)[m
[32m+[m[32m    yystate = yytable[yystate];[m
[32m+[m[32m  else[m
[32m+[m[32m    yystate = yydefgoto[yyn - YYNTOKENS];[m
 [m
   goto yynewstate;[m
 [m
[36m@@ -2620,10 +2613,12 @@[m [myyerrlab:[m
 | yyerrorlab -- error raised explicitly by YYERROR.  |[m
 `---------------------------------------------------*/[m
 yyerrorlab:[m
[31m-  /* Pacify compilers when the user code never invokes YYERROR and the[m
[31m-     label yyerrorlab therefore never appears in user code.  */[m
[31m-  if (0)[m
[31m-    YYERROR;[m
[32m+[m
[32m+[m[32m  /* Pacify compilers like GCC when the user code never invokes[m
[32m+[m[32m     YYERROR and the label yyerrorlab therefore never appears in user[m
[32m+[m[32m     code.  */[m
[32m+[m[32m  if (/*CONSTCOND*/ 0)[m
[32m+[m[32m     goto yyerrorlab;[m
 [m
   /* Do not reclaim the symbols of the rule whose action triggered[m
      this YYERROR.  */[m
[36m@@ -2685,7 +2680,6 @@[m [myyacceptlab:[m
   yyresult = 0;[m
   goto yyreturn;[m
 [m
[31m-[m
 /*-----------------------------------.[m
 | yyabortlab -- YYABORT comes here.  |[m
 `-----------------------------------*/[m
[36m@@ -2693,7 +2687,6 @@[m [myyabortlab:[m
   yyresult = 1;[m
   goto yyreturn;[m
 [m
[31m-[m
 #if !defined yyoverflow || YYERROR_VERBOSE[m
 /*-------------------------------------------------.[m
 | yyexhaustedlab -- memory exhaustion comes here.  |[m
[36m@@ -2704,10 +2697,6 @@[m [myyexhaustedlab:[m
   /* Fall through.  */[m
 #endif[m
 [m
[31m-[m
[31m-/*-----------------------------------------------------.[m
[31m-| yyreturn -- parsing is finished, return the result.  |[m
[31m-`-----------------------------------------------------*/[m
 yyreturn:[m
   if (yychar != YYEMPTY)[m
     {[m
[36m@@ -2737,7 +2726,7 @@[m [myyreturn:[m
 #endif[m
   return yyresult;[m
 }[m
[31m-#line 677 "parser.ypp"[m
[32m+[m[32m#line 678 "parser.ypp" /* yacc.c:1906  */[m
 [m
 [m
 void yyerror(string s)[m
[1mdiff --git a/src/parser.tab.hpp b/src/parser.tab.hpp[m
[1mindex 1bfc760..51c52ce 100644[m
[1m--- a/src/parser.tab.hpp[m
[1m+++ b/src/parser.tab.hpp[m
[36m@@ -1,9 +1,8 @@[m
[31m-/* A Bison parser, made by GNU Bison 3.4.2.  */[m
[32m+[m[32m/* A Bison parser, made by GNU Bison 3.0.4.  */[m
 [m
 /* Bison interface for Yacc-like parsers in C[m
 [m
[31m-   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,[m
[31m-   Inc.[m
[32m+[m[32m   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.[m
 [m
    This program is free software: you can redistribute it and/or modify[m
    it under the terms of the GNU General Public License as published by[m
[36m@@ -31,9 +30,6 @@[m
    This special exception was added by the Free Software Foundation in[m
    version 2.2 of Bison.  */[m
 [m
[31m-/* Undocumented macros, especially those whose name start with YY_,[m
[31m-   are private implementation details.  Do not rely on them.  */[m
[31m-[m
 #ifndef YY_YY_PARSER_TAB_HPP_INCLUDED[m
 # define YY_YY_PARSER_TAB_HPP_INCLUDED[m
 /* Debug traces.  */[m
[36m@@ -111,9 +107,10 @@[m [mextern int yydebug;[m
 [m
 /* Value type.  */[m
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED[m
[32m+[m
 union YYSTYPE[m
 {[m
[31m-#line 102 "parser.ypp"[m
[32m+[m[32m#line 102 "parser.ypp" /* yacc.c:1909  */[m
 [m
     char*       s;[m
     int         i;[m
[36m@@ -143,9 +140,9 @@[m [munion YYSTYPE[m
     class NewArrayA*    newArrayA;[m
     class PrimaryExprA* primaryExprA;[m
 [m
[31m-#line 147 "parser.tab.hpp"[m
[31m-[m
[32m+[m[32m#line 144 "parser.tab.hpp" /* yacc.c:1909  */[m
 };[m
[32m+[m
 typedef union YYSTYPE YYSTYPE;[m
 # define YYSTYPE_IS_TRIVIAL 1[m
 # define YYSTYPE_IS_DECLARED 1[m
[1mdiff --git a/src/parser.ypp b/src/parser.ypp[m
[1mindex c10a975..6f437b4 100644[m
[1m--- a/src/parser.ypp[m
[1m+++ b/src/parser.ypp[m
[36m@@ -166,6 +166,7 @@[m [mclass_list[m
     | single_class {[m
         yydebug(" $$ = new StartA(); $$->addf($1); ");[m
         $$ = new StartA(); $$->addf($1);[m
[32m+[m[32m        start = $$;[m
     }[m
 [m
 [m
