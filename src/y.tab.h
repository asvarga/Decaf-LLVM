/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ADD = 288,
    SUBS = 289,
    MULT = 290,
    DIV = 291,
    MOD = 292,
    NEG = 293,
    OP = 294,
    CP = 295,
    OB = 296,
    CB = 297,
    OC = 298,
    CC = 299,
    COMMA = 300,
    PERIOD = 301,
    IDENTIFIER = 302,
    NULL = 303,
    BOOLEAN = 304,
    INTEGER = 305,
    STRING = 306,
    CHAR = 307,
    UNRECOG_ERROR = 308,
    UMINUS = 309
  };
#endif
/* Tokens.  */
#define BREAK 258
#define CLASS 259
#define CONTINUE 260
#define ELSE 261
#define EXTENDS 262
#define IF 263
#define NEW 264
#define PRIVATE 265
#define PROTECTED 266
#define PUBLIC 267
#define RETURN 268
#define STATIC 269
#define SUPER 270
#define TYPE_VOID 271
#define TYPE_INT 272
#define TYPE_BOOL 273
#define TYPE_CHAR 274
#define THIS 275
#define WHILE 276
#define FORBIDDEN 277
#define UNENDED_COM 278
#define LEQ 279
#define LESS 280
#define GREATER 281
#define EQEQ 282
#define GEQ 283
#define EQ 284
#define NEQ 285
#define LAND 286
#define LOR 287
#define ADD 288
#define SUBS 289
#define MULT 290
#define DIV 291
#define MOD 292
#define NEG 293
#define OP 294
#define CP 295
#define OB 296
#define CB 297
#define OC 298
#define CC 299
#define COMMA 300
#define PERIOD 301
#define IDENTIFIER 302
#define NULL 303
#define BOOLEAN 304
#define INTEGER 305
#define STRING 306
#define CHAR 307
#define UNRECOG_ERROR 308
#define UMINUS 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
