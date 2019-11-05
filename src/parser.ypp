%{
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" void yyerror(char *s);
extern "C" int yywrap(void){return 1;};



%}


%token BREAK
%token CLASS
%token CONTINUE
%token ELSE
%token EXTENDS
%token IF
%token NEW
%token PRIVATE
%token PROTECTED
%token PUBLIC
%token RETURN
%token STATIC
%token SUPER
%token TYPE_VOID
%token TYPE_INT
%token TYPE_BOOL
%token TYPE_CHAR
%token THIS
%token WHILE
%token FORBIDDEN
%token UNENDED_COM
%token LEQ
%token LESS
%token GREATER
%token EQEQ
%token GEQ
%token EQ
%token NEQ
%token LAND
%token LOR
%token ADD
%token SUBS
%token MULT
%token DIV
%token MOD
%token NEG
%token OP
%token CP
%token OB
%token CB
%token OC
%token CC
%token COMMA
%token PERIOD
%token IDENTIFIER
%token NILL
%token BOOLEAN
%token INTEGER
%token STRING
%token CHAR
%token UNRECOG_ERROR

%left ADD SUBS MULT DIV MOD
%right EQ
%left LOR LAND
%left LESS GREATER LEQ GEQ
%left EQEQ NEQ
%right NEG
%precedence UMINUS

%%

start :  CLASS IDENTIFIER superzeroorone OC memberzeroormore CC
    |   CLASS IDENTIFIER superzeroorone OC memberzeroormore CC start
    ;

superzeroorone :
    |   super_nt
    ;

memberzeroormore :
    |   EXTENDS memberzeroormore
    ;

super_nt :  EXTENDS IDENTIFIER
    ;

member : field
    |   method
    |   ctor
    ;

field : modiferzeroormore type var_declarator_list
    ;

modiferzeroormore :
    |   modifier modiferzeroormore
    ;

method : modiferzeroormore type var_declarator_list
    ;

ctor :   modiferzeroormore IDENTIFIER formal_args block
    ;

modifier : STATIC
    |   PUBLIC
    |   PRIVATE
    |   PROTECTED
    ;

formal_arg_list_zero_or_one :
    |   formal_arg_list
    ;

formal_args : OP formal_arg_list_zero_or_one CP
    ;

formal_arg_list :   formal_arg
    |   formal_arg COMMA formal_arg_list
    ;

formal_arg : type var_declarator_id
    ;

type :   primitive_type
    |   IDENTIFIER
    |   type OB CB
    ;

primitive_type : TYPE_BOOL
    |   TYPE_CHAR
    |   TYPE_INT
    |   TYPE_VOID
    ;

var_declarator_list : var_declarator COMMA var_declarator_list
    |   var_declarator
    ;

var_declarator : var_declarator_id
    |   var_declarator_id EQ expression
    ;

var_declarator_id :  IDENTIFIER
    |   var_declarator_id OB CB
    ;

block : OC statement_zero_or_more CC
    ;

statement_zero_or_more :
    |statement statement_zero_or_more
    ;

expression :
    |   expression
    ;

statement :
    |   type var_declarator_list
    |   IF OP expression CP statement
    |   IF OP expression CP statement ELSE statement
    |   expression
    |   WHILE OP expression CP statement
    |   RETURN OP expression CP
    |   CONTINUE;
    |   BREAK;
    |   SUPER actual_args
    |   block
    ;

expression :
    |   expression binary_op expression
    |   unary_op expression
    |   primary
    ;

binary_op : EQ
    |   LOR
    |   LAND
    |   EQEQ
    |   NEQ
    |   LESS
    |   GREATER
    |   LEQ
    |   GEQ
    |   ADD
    |   SUBS
    |   MULT
    |   DIV
    |   MOD
    ;

unary_op : ADD
    |   SUBS
    |   NEG
    ;

 primary :
    |   new_array_expr
    |   non_new_array_expr
    |   IDENTIFIER
    ;

dimension_one_or_more : dimension_one_or_more
    |   dimension dimension_one_or_more
    ;

new_array_expr : NEW IDENTIFIER dimension_one_or_more
    |   NEW primitive_type dimension_one_or_more
    ;

dimension : OB expression CB
    ;

non_new_array_expr : litteral
    |   THIS
    |   OP expression CP
    |   NEW IDENTIFIER actual_args
    |   IDENTIFIER actual_args
    |   primary PERIOD IDENTIFIER actual_args
    |   SUPER PERIOD IDENTIFIER actual_args
    |   array_expr
    |   field_expr
    ;

field_expr : primary PERIOD IDENTIFIER
    |   SUPER PERIOD IDENTIFIER
    ;

array_expr : IDENTIFIER dimension
    |   non_new_array_expr dimension
    ;

litteral :   NILL
    |   BOOLEAN
    |   INTEGER
    |   CHAR
    |   STRING
    ;

actual_args : OP expr_list_zero_more CP
    ;

expr_list_zero_more :
    |   expr_list
    ;

expr_list :  expression
    |   expression COMMA expr_list
    ;

%%

void yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}
