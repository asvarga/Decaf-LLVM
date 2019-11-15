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
"break"     { std::cout << "BREAK: " << BREAK << "\n"; return BREAK; }
"class"     { std::cout << "CLASS: " << CLASS << "\n"; return CLASS; }
"continue"  { std::cout << "CONTINUE: " << CONTINUE << "\n"; return CONTINUE; }
"else"      { std::cout << "ELSE: " << ELSE << "\n"; return ELSE; }
"extends"   { std::cout << "EXTENDS: " << EXTENDS << "\n"; return EXTENDS; }
"if"        { std::cout << "IF: " << IF << "\n"; return IF; }
"new"       { std::cout << "NEW: " << NEW << "\n"; return NEW; }
"null"      { std::cout << "NILL: " << NILL << "\n"; return NILL; }
"private"   { std::cout << "PRIVATE: " << PRIVATE << "\n"; return PRIVATE; }
"protected" { std::cout << "PROTECTED: " << PROTECTED << "\n"; return PROTECTED; }
"public"    { std::cout << "PUBLIC: " << PUBLIC << "\n"; return PUBLIC; }
"return"    { std::cout << "RETURN: " << RETURN << "\n"; return RETURN; }
"static"    { std::cout << "STATIC: " << STATIC << "\n"; return STATIC; }
"super"     { std::cout << "SUPER: " << SUPER << "\n"; return SUPER; }
"this"      { std::cout << "THIS: " << THIS << "\n"; return THIS; }
"while"     { std::cout << "WHILE: " << WHILE << "\n"; return WHILE; }

    /* Forbidden Words*/
"abstract"      { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"byte"          { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"case"          { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"catch"         { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"const"         { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"default"       { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"do"            { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"double"        { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"final"         { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"finally"       { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"for"           { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"implements"    { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"import"        { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"instanceof"    { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"interface"     { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"long"          { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"native"        { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"goto"          { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"package"       { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"short"         { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"switch"        { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"synchronized"  { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"throw"         { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"throws"        { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"transient"     { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"try"           { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"volatile"      { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"byvalue"       { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"cast"          { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"generic"       { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"inner"         { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"none"          { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"operator"      { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"outer"         { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"rest"          { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"var"           { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"float"         { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"~"             { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"?"             { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
":"             { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"++"            { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"--"            { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"&"             { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"|"             { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"^"             { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"<<"            { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
">>"            { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
">>>"           { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"^=="           { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"%="            { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
"<<="           { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
">>="           { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }
">>>="          { std::cout << "FORBIDDEN: " << FORBIDDEN << "\n"; return FORBIDDEN; }



    /* Comments */
{SINGLE_COMMENT}            { /* COMMENT */ }
{COMMENT}               { /* COMMENT */ ; }
{WHITESPACE}       /* { std::cout << "WHITESPACE\n"; } */


    /* Operator and Separator */
"<="               { std::cout << "LEQ: " << LEQ << "\n"; return LEQ; }
"<"                { std::cout << "LESS: " << LESS << "\n"; return LESS; }
">="               { std::cout << "GEQ: " << GEQ << "\n"; return GEQ; }
">"                { std::cout << "GREATER: " << GREATER << "\n"; return GREATER; }
"=="               { std::cout << "EQEQ: " << EQEQ << "\n"; return EQEQ; }
"="                { std::cout << "EQ: " << EQ << "\n"; return EQ; }
"!="               { std::cout << "NEQ: " << NEQ << "\n"; return NEQ; }
"&&"               { std::cout << "LAND: " << LAND << "\n"; return LAND; }
"||"               { std::cout << "LOR: " << LOR << "\n"; return LOR; }
"+"                { std::cout << "ADD: " << ADD << "\n"; return ADD; }
"-"                { std::cout << "SUBS: " << SUBS << "\n"; return SUBS; }
"*"                { std::cout << "TIMES: " << TIMES << "\n"; return TIMES; }
"/"                { std::cout << "DIV: " << DIV << "\n"; return DIV; }
"%"                { std::cout << "MOD: " << MOD << "\n"; return MOD; }
"!"                { std::cout << "NOT: " << NOT << "\n"; return NOT; }
"("                { std::cout << "OP: " << OP << "\n"; return OP; }
")"                { std::cout << "CP: " << CP << "\n"; return CP; }
"["                { std::cout << "OB: " << OB << "\n"; return OB; }
"]"                { std::cout << "CB: " << CB << "\n"; return CB; }
"{"                { std::cout << "OC: " << OC << "\n"; return OC; }
"}"                { std::cout << "CC: " << CC << "\n"; return CC; }
","                { std::cout << "COMMA: " << COMMA << "\n"; return COMMA; }
"."                { std::cout << "DOT: " << DOT << "\n"; return DOT; }


    /*Primitive Types*/
    /* 
    "void"          { yylval.value = strdup(yytext); std::cout << "TYPE_VOID: " << TYPE_VOID << "\n"; return TYPE_VOID; }
    "int"           { yylval.value = strdup(yytext); std::cout << "TYPE_INT: " << TYPE_INT << "\n"; return TYPE_INT; }
    "boolean"       { yylval.value = strdup(yytext); std::cout << "TYPE_BOOL: " << TYPE_BOOL << "\n"; return TYPE_BOOL; }
    "char"          { yylval.value = strdup(yytext); std::cout << "TYPE_CHAR: " << TYPE_CHAR << "\n"; return TYPE_CHAR; } 
    */
"void"          { std::cout << "TYPE_VOID: " << TYPE_VOID << "\n"; return TYPE_VOID; }
"int"           { std::cout << "TYPE_INT: " << TYPE_INT << "\n"; return TYPE_INT; }
"boolean"       { std::cout << "TYPE_BOOL: " << TYPE_BOOL << "\n"; return TYPE_BOOL; }
"char"          { std::cout << "TYPE_CHAR: " << TYPE_CHAR << "\n"; return TYPE_CHAR; }

    /* Literal Types */
    /*
    "true|false"        { yylval.boolConstant = strdup(yytext);std::cout << "BOOLEAN: " << BOOLEAN << "\n"; return BOOLEAN; }
    {IDENTIFIER}        { std::cout << "IDENTIFIER: " << IDENTIFIER << "\n"; return IDENTIFIER; }
    {INTEGER}           { yylval.integerConstant = strdup(yytext);std::cout << "INTEGER: " << INTEGER << "\n"; return INTEGER; }
    {STRING}            { yylval.stringConstant = strdup(yytext);std::cout << "STRING: " << STRING << "\n"; return STRING; }
    {BEG_STRING}        { std::cout << "INCOMPL_STR: " << INCOMPL_STR << "\n"; return INCOMPL_STR; }
    {CHAR}              { yylval.charConstant = strdup(yytext); std::cout << "CHAR: " << CHAR << "\n"; return CHAR; }
    {CHAR_SLASH}        { yylval.charConstant = yytext[1]; std::cout << "CHAR: " << CHAR << "\n"; return CHAR; }
    */
"true|false"        { std::cout << "BOOLEAN: " << BOOLEAN << "\n"; return BOOLEAN; }
{IDENTIFIER}        { std::cout << "IDENTIFIER: " << IDENTIFIER << "\n"; return IDENTIFIER; }
{INTEGER}           { std::cout << "INTEGER: " << INTEGER << "\n"; return INTEGER; }
{STRING}            { std::cout << "STRING: " << STRING << "\n"; return STRING; }
{BEG_STRING}        { std::cout << "STRING: " << STRING << "\n"; return STRING; }
{CHAR}              { std::cout << "CHAR: " << CHAR << "\n"; return CHAR; }
{CHAR_SLASH}        { std::cout << "CHAR: " << CHAR << "\n"; return CHAR; }


    /* Default rule (error) */
.                   { std::cout << "UNRECOG_ERROR: " << UNRECOG_ERROR << "\n"; return UNRECOG_ERROR; }

%%
