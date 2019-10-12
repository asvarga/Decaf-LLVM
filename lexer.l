%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>
%}

/* Macros */
WHITESPACE          ([ \t]+)
NEWLINE             (\r|\n|\r\n)
SINGLE_COMMENT      ("//"[^\r\n]*)
BEG_COMMENT         ("/*")
END_COMMENT         ("*/")
IDENTIFIER          ([A-Za-z_][A-Za-z0-9_]*)
INTEGER             (0|([1-9][0-9]*))
BEG_STRING          (\"[^"\n]*)
STRING              ({BEG_STRING}\")
OPERATOR            ([-+/*%=.,;!<>()[\]{}:])
CHAR                [^\\]| "\t"|"\n"
CHAR_SLASH          (\\[^nt])


%%
    /* Key Words*/
"break"     { return BREAK; }
"class"     { return CLASS;}
"continue"  { return CONTINUE; }
"else"      { return ELSE; }
"extends"   { return EXTENDS; }
"if"        { return IF; }
"new"       { return NEW; }
"private"   { return PRIVATE; }
"protected" { return PROTECTED;}
"public"    { return PUBLIC; }
"return"    { return RETURN; }
"static"    { return STATIC; }
"super"     { return SUPER; }
"this"      { return THIS; }
"while"     { return WHILE; }

    /* Forbidden Words*/
"abstract"      { return FORBIDDEN; }
"byte"          { return FORBIDDEN; }
"case"          { return FORBIDDEN; }
"catch"         { return FORBIDDEN; }
"const"         { return FORBIDDEN; }
"default"       { return FORBIDDEN; }
"do"            { return FORBIDDEN; }
"double"        { return FORBIDDEN; }
"final"         { return FORBIDDEN; }
"finally"       { return FORBIDDEN; }
"for"           { return FORBIDDEN; }
"implements"    { return FORBIDDEN; }
"import"        { return FORBIDDEN; }
"instanceof"    { return FORBIDDEN; }
"interface"     { return FORBIDDEN; }
"long"          { return FORBIDDEN; }
"native"        { return FORBIDDEN; }
"goto"          { return FORBIDDEN; }
"package"       { return FORBIDDEN; }
"short"         { return FORBIDDEN; }
"switch"        { return FORBIDDEN; }
"synchronized"  { return FORBIDDEN; }
"throw"         { return FORBIDDEN; }
"throws"        { return FORBIDDEN; }
"transient"     { return FORBIDDEN; }
"try"           { return FORBIDDEN; }
"volatile"      { return FORBIDDEN; }
"byvalue"       { return FORBIDDEN; }
"cast"          { return FORBIDDEN; }
"generic"       { return FORBIDDEN; }
"inner"         { return FORBIDDEN; }
"none"          { return FORBIDDEN; }
"operator"      { return FORBIDDEN; }
"outer"         { return FORBIDDEN; }
"rest"          { return FORBIDDEN; }
"var"           { return FORBIDDEN; }
"byte"          { return FORBIDDEN; }
"double"        { return FORBIDDEN; }
"float"         { return FORBIDDEN; }
"long"          { return FORBIDDEN; }
"short"         { return FORBIDDEN; }
"~"             { return FORBIDDEN; }
"?"             { return FORBIDDEN; }
":"             { return FORBIDDEN; }
"++"            { return FORBIDDEN; }
"--"            { return FORBIDDEN; }
"&"             { return FORBIDDEN; }
"|"             { return FORBIDDEN; }
"^"             { return FORBIDDEN; }
"<<"            { return FORBIDDEN; }
">>"            { return FORBIDDEN; }
">>>"           { return FORBIDDEN; }
"^=="           { return FORBIDDEN; }
"%="            { return FORBIDDEN; }
"<<="           { return FORBIDDEN; }
">>="           { return FORBIDDEN; }
">>>="          { return FORBIDDEN; }

    /* Comments */
{SINGLE_COMMENT}            { /* COMMENT */ }
{BEG_COMMENT}               { BEGIN(COMM); }
<COMM>{END_COMMENT}         { BEGIN(N); }
<COMM><<EOF>>               { RETURN UNENDED_COM;}


/* Operator and Separator */
"<="               { return LEQ; }
">="               { return GEQ; }
"=="               { return EQ; }
"!="               { return NEQ; }
"&&"               { return LAND; }
"||"               { return OR; }
"[]"               { return DIMS; }
"++"               { return INCR; }
"--"               { return DECR; }
{OPERATOR}         { return yytext[0]; }
{IDENTIFIER}       { return IDENTIFIER; }
"null"             { return NULL; }

    /*Primitive Types*/
"void"          { yylval.value = strdup(yytext);return VOID; }
"int"           { yylval.value = strdup(yytext); return TYPE; }
"boolean"       { yylval.value = strdup(yytext); return TYPE; }
"char"          { yylval.value = strdup(yytext); return TYPE; }

    /* Literal Types */
"true"|"false"      { yylval.boolConstant = strdup(yytext);return BOOLEAN; }
{INTEGER}           { yylval.integerConstant = strdup(yytext);return INTEGER;}
{STRING}            { yylval.stringConstant = strdup(yytext);return STRING; }
{BEG_STRING}        { return INCOMPL_STR;}
{CHAR}              { yylval.charConstant = strdup(yytext); return CHAR;}
{CHAR_SLASH}        { yylval.charConstant = strdup(yytext[1]); return CHAR;}

/* Default rule (error) */
.                   { return UNRECOG_ERROR;}

%%
