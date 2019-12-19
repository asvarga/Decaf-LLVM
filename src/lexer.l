%{
#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <string.h>
// #include "y.tab.h"
#include "parser.tab.hpp"

#define YY_DECL extern "C" int yylex()

using namespace std;

void rep(string &s, string sold, string snew) {
	size_t i = s.find(sold);
	while(i != string::npos) {
		s.replace(i, 2, snew);
		i = s.find(sold, i++);
	}
}
char *escape(char *c) {
    string s(c);
    rep(s, "\\n", "\n");
    rep(s, "\\t", "\t");
    rep(s, "\\\"", "\"");
    rep(s, "\\\\", "\\");
    c = new char[s.length()+1];
    strcpy(c, s.c_str());
    return c;
}

%}



    /* Macros */
WHITESPACE          ([ \t]+)
NEWLINE             (\r|\n|\r\n)
SINGLE_COMMENT      ("//"[^\r\n]*)
COMMENT             ("/*"[^*/]"*/")
HASHBANG            ("#!"[^\r\n]*)
IDENTIFIER          ([A-Za-z_][A-Za-z0-9_]*)
INTEGER             (0|([1-9][0-9]*))
STRING_ESC          (\\(\\nt\"))              # \ followed by \ or r or n or "
STRING_CHR          ([^\"\\])                 # anything but " or \
STRING              (\"(\\[\\nt\"]|[^\"\\])*\")
OPERATOR            ([-+/*%=.,;!<>()[\]{}:])
CHAR                "'"[^'\n\\]"'"
CHAR_SLASH          "'"\\[^nt]"'"


%%
    /* Key Words*/
"break"     { // std::cout << "BREAK: " << yytext << "\n";
                yylval.s = strdup(yytext); return BREAK; }
"class"     { // std::cout << "CLASS: " << yytext << "\n";
                yylval.s = strdup(yytext); return CLASS; }
"continue"  { // std::cout << "CONTINUE: " << yytext << "\n";
                yylval.s = strdup(yytext); return CONTINUE; }
"else"      { // std::cout << "ELSE: " << yytext << "\n";
                yylval.s = strdup(yytext); return ELSE; }
"extends"   { // std::cout << "EXTENDS: " << yytext << "\n";
                yylval.s = strdup(yytext); return EXTENDS; }
"if"        { // std::cout << "IF: " << yytext << "\n";
                yylval.s = strdup(yytext); return IF; }
"new"       { // std::cout << "NEW: " << yytext << "\n";
                yylval.s = strdup(yytext); return NEW; }
"null"      { // std::cout << "NILL: " << yytext << "\n";
                yylval.s = strdup(yytext); return NILL; }
"private"   { // std::cout << "PRIVATE: " << yytext << "\n";
                yylval.s = strdup(yytext); return PRIVATE; }
"protected" { // std::cout << "PROTECTED: " << yytext << "\n";
                yylval.s = strdup(yytext); return PROTECTED; }
"public"    { // std::cout << "PUBLIC: " << yytext << "\n";
                yylval.s = strdup(yytext); return PUBLIC; }
"return"    { // std::cout << "RETURN: " << yytext << "\n";
                yylval.s = strdup(yytext); return RETURN; }
"static"    { // std::cout << "STATIC: " << yytext << "\n";
                yylval.s = strdup(yytext); return STATIC; }
"super"     { // std::cout << "SUPER: " << yytext << "\n";
                yylval.s = strdup(yytext); return SUPER; }
"this"      { // std::cout << "THIS: " << yytext << "\n";
                yylval.s = strdup(yytext); return THIS; }
"while"     { // std::cout << "WHILE: " << yytext << "\n";
                yylval.s = strdup(yytext); return WHILE; }

    /* Forbidden Words*/
"abstract"      { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"byte"          { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"case"          { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"catch"         { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"const"         { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"default"       { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"do"            { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"double"        { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"final"         { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"finally"       { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"for"           { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"implements"    { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"import"        { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"instanceof"    { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"interface"     { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"long"          { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"native"        { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"goto"          { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"package"       { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"short"         { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"switch"        { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"synchronized"  { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"throw"         { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"throws"        { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"transient"     { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"try"           { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"volatile"      { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"byvalue"       { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"cast"          { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"generic"       { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"inner"         { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"none"          { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"operator"      { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"outer"         { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"rest"          { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"var"           { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"float"         { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"~"             { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"?"             { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
":"             { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"++"            { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"--"            { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"&"             { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"|"             { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"^"             { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"<<"            { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
">>"            { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
">>>"           { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"^=="           { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"%="            { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
"<<="           { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
">>="           { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }
">>>="          { // std::cout << "FORBIDDEN: " << yytext << "\n";
                    return FORBIDDEN; }



    /* Comments */
{SINGLE_COMMENT}            { /* COMMENT */ }
{COMMENT}               { /* COMMENT */ ; }
{HASHBANG}               { /* COMMENT */ ; }
{WHITESPACE}       { /* pass */ }
{NEWLINE}       { /* pass */ }


    /* Operator and Separator */
"<="               { // std::cout << "LEQ: " << yytext << "\n";
                        yylval.s = strdup(yytext);return LEQ; }
"<"                { // std::cout << "LESS: " << yytext << "\n";
                        yylval.s = strdup(yytext);return LESS; }
">="               { // std::cout << "GEQ: " << yytext << "\n";
                        yylval.s = strdup(yytext);return GEQ; }
">"                { // std::cout << "GREATER: " << yytext << "\n";
                        yylval.s = strdup(yytext);return GREATER; }
"=="               { // std::cout << "EQEQ: " << yytext << "\n";
                        yylval.s = strdup(yytext);return EQEQ; }
"="                { // std::cout << "EQ: " << yytext << "\n";
                        yylval.s = strdup(yytext);return EQ; }
"!="               { // std::cout << "NEQ: " << yytext << "\n";
                        yylval.s = strdup(yytext);return NEQ; }
"&&"               { // std::cout << "LAND: " << yytext << "\n";
                        yylval.s = strdup(yytext);return LAND; }
"||"               { // std::cout << "LOR: " << yytext << "\n";
                        yylval.s = strdup(yytext);return LOR; }
"+"                { // std::cout << "PLUS: " << yytext << "\n";
                        yylval.s = strdup(yytext);return PLUS; }
"-"                { // std::cout << "MINUS: " << yytext << "\n";
                        yylval.s = strdup(yytext);return MINUS; }
"*"                { // std::cout << "TIMES: " << yytext << "\n";
                        yylval.s = strdup(yytext);return TIMES; }
"/"                { // std::cout << "DIV: " << yytext << "\n";
                        yylval.s = strdup(yytext);return DIV; }
"%"                { // std::cout << "MOD: " << yytext << "\n";
                        yylval.s = strdup(yytext);return MOD; }
"!"                { // std::cout << "NOT: " << yytext << "\n";
                        yylval.s = strdup(yytext);return NOT; }
"("                { // std::cout << "OP: " << yytext << "\n";
                        yylval.s = strdup(yytext);return OP; }
")"                { // std::cout << "CP: " << yytext << "\n";
                        yylval.s = strdup(yytext);return CP; }
"["                { // std::cout << "OB: " << yytext << "\n";
                        yylval.s = strdup(yytext);return OB; }
"]"                { // std::cout << "CB: " << yytext << "\n";
                        yylval.s = strdup(yytext);return CB; }
"{"                { // std::cout << "OC: " << yytext << "\n";
                        yylval.s = strdup(yytext);return OC; }
"}"                { // std::cout << "CC: " << yytext << "\n";
                        yylval.s = strdup(yytext);return CC; }
","                { // std::cout << "COMMA: " << yytext << "\n";
                        yylval.s = strdup(yytext);return COMMA; }
"."                { // std::cout << "DOT: " << yytext << "\n";
                        yylval.s = strdup(yytext);return DOT; }
";"                { // std::cout << "SEMICOLON: " << yytext << "\n";
                        yylval.s = strdup(yytext);return SEMICOLON; }


    /*Primitive Types*/
"void"          { // std::cout << "TYPE_VOID: " << yytext << "\n";
                    yylval.s = strdup(yytext); return TYPE_VOID; }
"int"           { // std::cout << "TYPE_INT: " << yytext << "\n";
                    yylval.s = strdup(yytext); return TYPE_INT; }
"boolean"       { // std::cout << "TYPE_BOOL: " << yytext << "\n";
                    yylval.s = strdup(yytext); return TYPE_BOOL; }
"char"          { // std::cout << "TYPE_CHAR: " << yytext << "\n";
                    yylval.s = strdup(yytext); return TYPE_CHAR; }

    /* Literal Types */
"true|false"        { // std::cout << "BOOLEAN: " << yytext << "\n";
                        yylval.b = (strcmp(yytext, "true")==0); return BOOLEAN; }
{IDENTIFIER}        { // std::cout << "IDENTIFIER: " << yytext << "\n";
                        yylval.s = strdup(yytext); return IDENTIFIER; }
{INTEGER}           { // std::cout << "INTEGER: " << yytext << "\n";
                        yylval.i = atoi(yytext); return INTEGER; }
{STRING}            { // std::cout << "STRING: " << yytext << "\n";
                        yylval.s = escape(yytext); return STRING; }
{CHAR}              { // std::cout << "CHAR: " << yytext << "\n";
                        yylval.c = yytext[1]; return CHAR; }
"'\\n'"             { // std::cout << "CHAR: " << yytext << "\n";
                        yylval.c = '\n'; return CHAR; }
"'\\t'"             { // std::cout << "CHAR: " << yytext << "\n";
                        yylval.c = '\t'; return CHAR; }


    /* Default rule (error) */
.                   { // std::cout << "UNRECOG_ERROR: " << yytext << "\n";
                        return UNRECOG_ERROR; }

%%
