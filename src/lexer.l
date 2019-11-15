%{
#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <string.h>
// #include "y.tab.h"
#include "parser.tab.hpp"

#define YY_DECL extern "C" int yylex()

%}



    /* Macros */
WHITESPACE          ([ \t]+)
NEWLINE             (\r|\n|\r\n)
SINGLE_COMMENT      ("//"[^\r\n]*)
COMMENT             ("/*"[^*/]"*/")
IDENTIFIER          ([A-Za-z_][A-Za-z0-9_]*)
INTEGER             (0|([1-9][0-9]*))
BEG_STRING          (\"[^"\n]*)
STRING              ({BEG_STRING}\")
OPERATOR            ([-+/*%=.,;!<>()[\]{}:])
CHAR                "'"[^'\n\\]"'"
CHAR_SLASH          "'"\\[^nt]"'"


%%
    /* Key Words*/
"break"     { std::cout << "BREAK: " << yytext << "\n"; return BREAK; }
"class"     { std::cout << "CLASS: " << yytext << "\n"; return CLASS; }
"continue"  { std::cout << "CONTINUE: " << yytext << "\n"; return CONTINUE; }
"else"      { std::cout << "ELSE: " << yytext << "\n"; return ELSE; }
"extends"   { std::cout << "EXTENDS: " << yytext << "\n"; return EXTENDS; }
"if"        { std::cout << "IF: " << yytext << "\n"; return IF; }
"new"       { std::cout << "NEW: " << yytext << "\n"; return NEW; }
"null"      { std::cout << "NILL: " << yytext << "\n"; return NILL; }
"private"   { std::cout << "PRIVATE: " << yytext << "\n"; return PRIVATE; }
"protected" { std::cout << "PROTECTED: " << yytext << "\n"; return PROTECTED; }
"public"    { std::cout << "PUBLIC: " << yytext << "\n"; return PUBLIC; }
"return"    { std::cout << "RETURN: " << yytext << "\n"; return RETURN; }
"static"    { std::cout << "STATIC: " << yytext << "\n"; return STATIC; }
"super"     { std::cout << "SUPER: " << yytext << "\n"; return SUPER; }
"this"      { std::cout << "THIS: " << yytext << "\n"; return THIS; }
"while"     { std::cout << "WHILE: " << yytext << "\n"; return WHILE; }

    /* Forbidden Words*/
"abstract"      { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"byte"          { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"case"          { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"catch"         { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"const"         { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"default"       { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"do"            { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"double"        { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"final"         { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"finally"       { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"for"           { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"implements"    { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"import"        { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"instanceof"    { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"interface"     { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"long"          { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"native"        { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"goto"          { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"package"       { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"short"         { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"switch"        { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"synchronized"  { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"throw"         { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"throws"        { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"transient"     { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"try"           { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"volatile"      { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"byvalue"       { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"cast"          { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"generic"       { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"inner"         { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"none"          { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"operator"      { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"outer"         { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"rest"          { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"var"           { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"float"         { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"~"             { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"?"             { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
":"             { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"++"            { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"--"            { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"&"             { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"|"             { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"^"             { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"<<"            { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
">>"            { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
">>>"           { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"^=="           { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"%="            { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
"<<="           { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
">>="           { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }
">>>="          { std::cout << "FORBIDDEN: " << yytext << "\n"; return FORBIDDEN; }



    /* Comments */
{SINGLE_COMMENT}            { /* COMMENT */ }
{COMMENT}               { /* COMMENT */ ; }
{WHITESPACE}       /* pass */


    /* Operator and Separator */
"<="               { std::cout << "LEQ: " << yytext << "\n"; return LEQ; }
"<"                { std::cout << "LESS: " << yytext << "\n"; return LESS; }
">="               { std::cout << "GEQ: " << yytext << "\n"; return GEQ; }
">"                { std::cout << "GREATER: " << yytext << "\n"; return GREATER; }
"=="               { std::cout << "EQEQ: " << yytext << "\n"; return EQEQ; }
"="                { std::cout << "EQ: " << yytext << "\n"; return EQ; }
"!="               { std::cout << "NEQ: " << yytext << "\n"; return NEQ; }
"&&"               { std::cout << "LAND: " << yytext << "\n"; return LAND; }
"||"               { std::cout << "LOR: " << yytext << "\n"; return LOR; }
"+"                { std::cout << "PLUS: " << yytext << "\n"; return PLUS; }
"-"                { std::cout << "MINUS: " << yytext << "\n"; return MINUS; }
"*"                { std::cout << "TIMES: " << yytext << "\n"; return TIMES; }
"/"                { std::cout << "DIV: " << yytext << "\n"; return DIV; }
"%"                { std::cout << "MOD: " << yytext << "\n"; return MOD; }
"!"                { std::cout << "NOT: " << yytext << "\n"; return NOT; }
"("                { std::cout << "OP: " << yytext << "\n"; return OP; }
")"                { std::cout << "CP: " << yytext << "\n"; return CP; }
"["                { std::cout << "OB: " << yytext << "\n"; return OB; }
"]"                { std::cout << "CB: " << yytext << "\n"; return CB; }
"{"                { std::cout << "OC: " << yytext << "\n"; return OC; }
"}"                { std::cout << "CC: " << yytext << "\n"; return CC; }
","                { std::cout << "COMMA: " << yytext << "\n"; return COMMA; }
"."                { std::cout << "DOT: " << yytext << "\n"; return DOT; }
";"                { std::cout << "SEMICOLON: " << yytext << "\n"; return SEMICOLON; }


    /*Primitive Types*/
    /* 
    "void"          { yylval.value = strdup(yytext); std::cout << "TYPE_VOID: " << yytext << "\n"; return TYPE_VOID; }
    "int"           { yylval.value = strdup(yytext); std::cout << "TYPE_INT: " << yytext << "\n"; return TYPE_INT; }
    "boolean"       { yylval.value = strdup(yytext); std::cout << "TYPE_BOOL: " << yytext << "\n"; return TYPE_BOOL; }
    "char"          { yylval.value = strdup(yytext); std::cout << "TYPE_CHAR: " << yytext << "\n"; return TYPE_CHAR; } 
    */
"void"          { std::cout << "TYPE_VOID: " << yytext << "\n"; return TYPE_VOID; }
"int"           { std::cout << "TYPE_INT: " << yytext << "\n"; return TYPE_INT; }
"boolean"       { std::cout << "TYPE_BOOL: " << yytext << "\n"; return TYPE_BOOL; }
"char"          { std::cout << "TYPE_CHAR: " << yytext << "\n"; return TYPE_CHAR; }

    /* Literal Types */
    /*
    "true|false"        { yylval.boolConstant = strdup(yytext);std::cout << "BOOLEAN: " << yytext << "\n"; return BOOLEAN; }
    {IDENTIFIER}        { std::cout << "IDENTIFIER: " << yytext << "\n"; return IDENTIFIER; }
    {INTEGER}           { yylval.integerConstant = strdup(yytext);std::cout << "INTEGER: " << yytext << "\n"; return INTEGER; }
    {STRING}            { yylval.stringConstant = strdup(yytext);std::cout << "STRING: " << yytext << "\n"; return STRING; }
    {BEG_STRING}        { std::cout << "INCOMPL_STR: " << yytext << "\n"; return INCOMPL_STR; }
    {CHAR}              { yylval.charConstant = strdup(yytext); std::cout << "CHAR: " << yytext << "\n"; return CHAR; }
    {CHAR_SLASH}        { yylval.charConstant = yytext[1]; std::cout << "CHAR: " << yytext << "\n"; return CHAR; }
    */
"true|false"        { std::cout << "BOOLEAN: " << yytext << "\n"; 
                        yylval.b = (strcmp(yytext, "true")==0); return BOOLEAN; }
{IDENTIFIER}        { std::cout << "IDENTIFIER: " << yytext << "\n"; 
                        yylval.s = strdup(yytext); return IDENTIFIER; }
{INTEGER}           { std::cout << "INTEGER: " << yytext << "\n"; 
                        yylval.i = atoi(yytext); return INTEGER; }
{STRING}            { std::cout << "STRING: " << yytext << "\n"; 
                        yylval.s = strdup(yytext); return STRING; }
{BEG_STRING}        { std::cout << "STRING: " << yytext << "\n"; 
                        yylval.s = strdup(yytext); return STRING; }
{CHAR}              { std::cout << "CHAR: " << yytext << "\n"; 
                        yylval.c = yytext[0]; return STRING; }
{CHAR_SLASH}        { std::cout << "CHAR: " << yytext << "\n"; 
                        yylval.c = yytext[0]; return STRING; }


    /* Default rule (error) */
.                   { std::cout << "UNRECOG_ERROR: " << yytext << "\n"; return UNRECOG_ERROR; }

%%
