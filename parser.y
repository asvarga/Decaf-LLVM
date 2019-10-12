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
%token IDENTIFIER
%token NULL
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

start :  class IDENTIFIER superzeroorone OC member* CC
    |   class IDENTIFIER superzeroorone OC member* CC start
    ;

superzeroorone :
    |   SUPER
    ;

member* :
    |   EXTENDS member*
    ;

SUPER :  EXTENDS IDENTIFIER
    ;

member : field
    |   method
    |   ctor
    ;

modifier* :
    |   modifier modifier*
    ;

method : modifier* type var_declarator_list
    ;

ctor :   modifier* IDENTIFIER formal_args block
    ;

modifier : static
    |   PUBLIC
    |   PRIVATE
    |   PROTECTED
    ;

formal_arg_list? :
    |   formal_arg_list
    ;

formal_args : ( formal_arg_list? )
    ;

formal_arg_list :   formal_arg
    |   formal_arg , formal_arg_list
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

var_declarator_list : var_declarator, var_declarator_list
    |   var_declarator
    ;

var_declarator : var_declarator_id
    |   var_declarator_id = expression
    ;

var_declarator_id :  IDENTIFIER
    |   var_declarator_id[]
    ;

block : OC statement* CC
    ;

statement* :
    |statement statement*
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

dimension+ : dimension+
    |   dimension dimension+
    ;

new_array_expr : NEW IDENTIFIER dimension+
    |   new primitive_type dimension+
    ;

dimension : OB expression CB
    ;

non_new_array_expr : litteral
    |   THIS
    |   OP expression CP
    |   NEW IDENTIFIER actual_args
    |   IDENTIFIER actual_args
    |   primary . IDENTIFIER actual_args
    |   SUPER . IDENTIFIER actual_args
    |   array_expr
    |   field_expr
    ;

field_expr : primary . IDENTIFIER
    |   SUPER . IDENTIFIER
    ;

array_expr : IDENTIFIER dimension
    |   non_new_array_expr dimension
    ;

litteral :   NULL
    |   BOOLEAN
    |   INTEGER
    |   CHAR
    |   STRING
    ;

actual_args : OP expr_list? CP
    ;

expr_list? :
    |expr_list
    ;

expr_list :  expression
    |   expression , expr_list
    ;

%%

void yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}
