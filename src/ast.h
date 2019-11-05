#include<bits/stdc++.h>
#include <map>
#include <string>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/IRBuilder.h>
#include "llvm/IR/Module.h"
#include <string>
#include <stack>

using namespace llvm;

using namespace std;

class loopInfo {
    BasicBlock *afterBB, *checkBB;
    llvm::Value *condition;
    std::string loopVariable;
    PHINode *phiVariable;
public:
    loopInfo(BasicBlock *afterBlock, BasicBlock *checkBlock, Value *cond, std::string var, PHINode *phiVar) {
        afterBB = afterBlock;
        checkBB = checkBlock;
        condition = cond;
        loopVariable = var;
        phiVariable = phiVar;
    }
    BasicBlock *getAfterBlock() { return afterBB; }
    BasicBlock *getCheckBlock() { return checkBB; }
    llvm::Value *getCondition() { return condition; }
    PHINode *getPHINode() { return phiVariable; }
    std::string getLoopVariable() { return loopVariable; }
};

class Construct {
public:
    LLVMContext Context;
    Module *TheModule;
    IRBuilder<> *Builder;
    std::map<std::string, llvm::AllocaInst *> NamedValues;
    int errors;
    std::stack<loopInfo *> *loops;
    Construct();
    AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, std::string VarName, std::string type);
};


class AST;
class Program;
class Field_decls;
class Fields_decl;
class Comma_sep_fields;
class Comma_sep_field;
class Method_decls;
class Method_decl;
class Type_plus_ids;
class Type_plus_id;
class Block;
class Var_decls;
class Var_decl;
class IDSS;
class IDS;
class Statements;
class Statement;
class Assignment;
class Method_call;
class If_Else;
class Iff;
class Fors;
class Return;
class Break;
class Continue;
class Assign_op;
class Func_call;
class Call_out;
class Callout_args_plus;
class Callout_arg;
class Location;
class Expr_plus;
class Expr;
class Literal;
class Int_literal;
class Bool_literal;
class Char_literal;
class Unary_expr;
class Binary_expr;
class Bracket_expr;


class Visitor
{
	public:
		virtual int visit(AST *vis){};
		virtual int visit(Program *vis){};
		virtual int visit(Field_decls *vis){};
		virtual int visit(Fields_decl *vis){};
		virtual int visit(Comma_sep_fields *vis){};
		virtual int visit(Comma_sep_field *vis){};
		virtual int visit(Method_decls *vis){};
		virtual int visit(Method_decl *vis){};
		virtual int visit(Type_plus_ids *vis){};
		virtual int visit(Type_plus_id *vis){};
		virtual int visit(Block *vis){};
		virtual int visit(Var_decls *vis){};
		virtual int visit(Var_decl *vis){};
		virtual int visit(IDSS *vis){};
		virtual int visit(IDS *vis){};
		virtual int visit(Statements *vis){};
		virtual int visit(Statement *vis){};
		virtual int visit(Assignment *vis){};
		virtual int visit(Method_call *vis){};
		virtual int visit(If_Else *vis){};
		virtual int visit(Iff *vis){};
		virtual int visit(Fors *vis){};
		virtual int visit(Return *vis){};
		virtual int visit(Break *vis){};
		virtual int visit(Continue *vis){};
		virtual int visit(Assign_op *vis){};
		virtual int visit(Func_call *vis){};
		virtual int visit(Call_out *vis){};
		virtual int visit(Callout_args_plus *vis){};
		virtual int visit(Callout_arg *vis){};
		virtual int visit(Location *vis){};
		virtual int visit(Expr_plus *vis){};
		virtual int visit(Expr *vis){};
		virtual int visit(Literal *vis){};
		virtual int visit(Int_literal *vis){};
		virtual int visit(Char_literal *vis){};
		virtual int visit(Bool_literal *vis){};
		virtual int visit(Unary_expr *vis){};
		virtual int visit(Binary_expr *vis){};
		virtual int visit(Bracket_expr *vis){};
};

enum var_type{
	normal=0,array=1
};

enum int_type
{
	booll=0,intt=1
};

class AST
{
	public:
		AST();
		virtual int accept(Visitor *v);
};

class Program:public AST
{
	public:
		class Field_decls *fields;
		class Method_decls *methods;
		Program(class Field_decls *, class Method_decls *);
		virtual Value *GenCode();
   		void GenCodeDump();
    	Construct *Constructs;

	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};


class Field_decls:public AST
{
	public:
		vector <class Fields_decl* > field_declaration_list;
		Field_decls() = default;
		void Push_back(class Fields_decl*);
		virtual Value *GenCode(Construct *Constructs);
	
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}

};

class Fields_decl:public AST
{
	public:
		string data_type;
		vector <Comma_sep_field*> var_declaration_list;
		Fields_decl(string,Comma_sep_fields*);
		virtual Value* GenCode(Construct *Constructs) ;

	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Comma_sep_fields:public AST
{
	public:
		vector <class Comma_sep_field*> var_declaration_list;
		Comma_sep_fields() = default;
		void Push_back(Comma_sep_field*);
		vector <Comma_sep_field* > getVarList();
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Comma_sep_field:public AST
{
	public:
		int_type type;
		var_type variable_type;
		string name;
		uint length;
		Comma_sep_field(string,uint);
		explicit Comma_sep_field(string);
		bool isArray()
		{
			return variable_type==var_type::array;
		}
		uint getLength()
		{
			return length;
		}

		string getname()
		{
			return name;
		}

	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Method_decls:public AST
{
	public:
		vector <class Method_decl* > method_decl_list;
		Method_decls()=default;
		void Push_back(class Method_decl*);
		virtual Value *GenCode(Construct *Constructs);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Method_decl:public AST
{
	public:
		string method_type;
		string name;
		class Type_plus_ids *type_plus_ids;
		class Block *blck;
		Method_decl(string,string,Type_plus_ids*,Block*);
		virtual Function *GenCode(Construct *Constructs);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Type_plus_ids:public AST
{
	public:
		vector <class Type_plus_id* >type_plus_id_list;
		Type_plus_ids()=default;
		void Push_back(class Type_plus_id*);
		std::vector<class Type_plus_id *> getArgList();
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Type_plus_id:public AST
{
	public:
		string type_name;
		string name;
		Type_plus_id(string,string);

		string getType()
		{
			return type_name;
		}

		string getName()
		{
			return name;
		}
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Statement:public AST
{
	public:
		Statement()=default;
		virtual bool has_return() { return false; }
		virtual bool has_break() { return false; }
		virtual bool has_continue() { return false; }
		virtual Value *GenCode(Construct *Constructs){};
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Expr:public AST
{
	public:
		int expr_type;
		int lit_type;
		Expr() = default;
		virtual Value *GenCode(Construct *Constructs) {};
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};


class Block:public Statement
{
	public:
		class Var_decls* var_decls;
		class Statements* statements;
		Block(Var_decls*, Statements*);
		bool has_return() ;
		bool has_break() ;
		bool has_continue() ;
    	virtual Value *GenCode(Construct *Constructs);

	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Var_decls:public AST
{
	public:
		vector <class Var_decl*> decl_list;
		Var_decls()=default;
		void Push_back(class Var_decl*);
		virtual Value *GenCode(std::map<std::string, llvm::AllocaInst *> &, Construct *);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Var_decl:public AST
{
	public:
		string type_name;
		vector <string >var_list;
		Var_decl(string,IDSS*);
		virtual Value *GenCode(std::map<std::string, llvm::AllocaInst *> &, Construct *);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class IDSS:public AST
{
	public:
		vector <string >var_list;
		IDSS()=default;
		void Push_back(string);
		vector <string> getVarList();
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class IDS:public AST
{
	public:
		string name;
		IDS(string);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Statements:public AST
{
	public:
		vector <class Statement*> statement_list;
		Statements()=default;
		void Push_back(Statement*);
		bool has_return();
		bool has_break();
		bool has_continue();
		virtual Value *GenCode(Construct *Constructs);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Assignment:public Statement
{
	public:
		class Location* location;
		class Assign_op* assign_op;
		class Expr* expr;
		Assignment(Location*,Assign_op*,Expr*);
		virtual Value *GenCode(Construct *Constructs);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Method_call:public Statement, public Expr
{
	public:
		Method_call()=default;
		virtual Value *GenCode(Construct *Constructs){};
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class If_Else:public Statement
{
	public:
		Expr* expr;
		Block* blck1;
		Block* blck2;
		If_Else(Expr*,Block*,Block*);
		virtual Value *GenCode(Construct *Constructs);
		bool has_return();
		bool has_break();
		bool has_continue();
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Iff:public Statement
{
	public:
		Expr* expr;
		Block* blck1;
		Iff(Expr*,Block*);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Fors:public Statement
{
	public:
		string name;
		Expr* expr1;
		Expr* expr2;
		Block* blck;
		Fors(string,Expr*,Expr*,Block*);
		virtual Value *GenCode(Construct *Constructs);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Return:public Statement
{
	public:
		Expr* expr;
		Return(Expr*);
		virtual Value *GenCode(Construct *Constructs);
		virtual bool has_return(){return true;}
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Break:public Statement
{
	public:
		Break()=default;
		virtual Value *GenCode(Construct *Constructs);
		virtual bool has_break(){return true;}
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Continue:public Statement
{
	public:
		Continue()=default;
		virtual Value *GenCode(Construct *Constructs);
		virtual bool has_continue(){return true;}
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Location:public Expr
{
	public:
		string name;
		Expr* expr;
		var_type location_type;
		Location(string,Expr*);
		explicit Location(string);
		virtual Value *GenCode(Construct *Constructs);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Assign_op:public AST
{
	public:
		string oper;
		Assign_op(string);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};


class Binary_expr:public Expr
{
	public:
		Expr* expr1;
		string oper;
		Expr* expr2;
		Binary_expr(Expr*,string,Expr*);
		virtual Value *GenCode(Construct *Constructs);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Unary_expr:public Expr
{
	public:
		string oper;
		Expr* expr1;
		Unary_expr(string,Expr*);
		virtual Value *GenCode(Construct *Constructs);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Bracket_expr:public Expr
{
	public:
		Expr* expr;
		Bracket_expr(Expr*);
		virtual Value *GenCode(Construct *Constructs);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};



class Func_call:public Method_call
{
	public:
		string name;
		Expr_plus* expr_plus;
		Func_call(string, Expr_plus*);
		virtual Value *GenCode(Construct *Constructs);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Call_out:public Method_call
{
	public:
		string name;
		Callout_args_plus* callout_args_plus;
		Call_out(string,Callout_args_plus*);
		virtual Value *GenCode(Construct *Constructs);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Callout_args_plus:public AST
{
	public:
		vector<class Callout_arg* > callout_arg_list;
		Callout_args_plus()=default;
		void Push_back(Callout_arg*);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Callout_arg:public AST
{
	public:
		Expr* expr;
		string literal;
		Callout_arg(class Expr*);
		Callout_arg(string);
		virtual Value *GenCode(Construct *Constructs);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Literal:public Expr
{
	public:
		Literal()=default;
		virtual Value *GenCode(Construct *Constructs){};
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Expr_plus:public AST
{
	public:
		vector <Expr*> expr_list;
		Expr_plus()=default;
		void Push_back(Expr*);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Int_literal:public Literal
{
	public:
		int var;
		Int_literal(int);
		virtual Value *GenCode(Construct *Constructs);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Char_literal:public Literal
{
	public:
		string var;
		Char_literal(string);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};

class Bool_literal:public Literal
{
	public:
		string var;
		Bool_literal(string);
		virtual Value *GenCode(Construct *Constructs);
	virtual int accept(Visitor *v)
	{
		v->visit(this);
	}
};


class DFS:public Visitor
{
	public:
		int visit(Program *vis)
		{
			cout<<"Program Started"<<endl;
			if(vis->fields)
				vis->fields->accept(this);
			if(vis->methods)
				vis->methods->accept(this);
		}
		int visit(Field_decls *vis)
		{
			cout<<"Field_decls"<<endl;
			for(int i=0;i<vis->field_declaration_list.size();i++)
				vis->field_declaration_list[i]->accept(this);
		}
		int visit(Fields_decl *vis)
		{
			cout<<"Fields_decl"<<endl;
			cout<<"data_type --> "<<vis->data_type<<endl;
			for(int i=0;i<vis->var_declaration_list.size();i++)
				vis->var_declaration_list[i]->accept(this);
		}

		int visit(Comma_sep_field *vis)
		{
			cout<<"comma_sep_Variables"<<endl;
			if(vis->variable_type==1)
			{
				cout<<"Variable is Array"<<endl;
				cout<<"var name is "<<vis->name<<endl;
				cout<<"Length is "<<vis->length<<endl;
			}
			else
			{
				cout<<"Variable not array"<<endl;
				cout<<"var name is "<<vis->name<<endl;
			}
		}

		int visit(Method_decls *vis)
		{
			cout<<"Method_decls"<<endl;
			for(int i=0;i<vis->method_decl_list.size();i++)
				vis->method_decl_list[i]->accept(this);
		}
		
		int visit(Method_decl *vis)
		{
			cout<<"Method_decl"<<endl;
			cout<<"Type name is " << vis->method_type<<endl;
			cout<<"Name is " << vis->name<<endl;
			if(vis->type_plus_ids)
				vis->type_plus_ids->accept(this);
			vis->blck->accept(this);
		}		

		int visit(Type_plus_ids *vis)
		{
			cout<<"Type_plus_ids"<<endl;
			for(int i=0;i<vis->type_plus_id_list.size();i++)
				vis->type_plus_id_list[i]->accept(this);
		}

		int visit(Type_plus_id *vis)
		{
			cout<<"Type name is "<<vis->type_name<<endl;
			cout<<"name is "<<vis->name<<endl;
		}

		int visit(Block *vis)
		{
			cout<<"Block"<<endl;
			if(vis->var_decls)
				vis->var_decls->accept(this);
			if(vis->statements)
				vis->statements->accept(this);
		}

		int visit(Var_decls *vis)
		{
			cout<<"Var_decls"<<endl;
			for(int i=0;i<vis->decl_list.size();i++)
				vis->decl_list[i]->accept(this);
		}

		int visit(Var_decl *vis)
		{
			cout<<"Var_decl"<<endl;
			cout<<"Var type is "<<vis->type_name<<endl;
			for(int i=0;i<vis->var_list.size();i++)
				cout<<vis->var_list[i]<<endl;
			// for(int i=0;i<vis->var_list.size();i++)
			// 	vis->var_list[i]->accept(this);
		}

		int visit(IDS *vis)
		{
			cout<<"IDS"<<endl;
			cout<<"Name is "<<vis->name<<endl;
		}

		int visit(Statements *vis)
		{
			cout<<"Statements"<<endl;
			for(int i=0;i<vis->statement_list.size();i++)
				vis->statement_list[i]->accept(this);
		}

		int visit(Statement *vis)
		{
			cout<<"Statement"<<endl;
		}

		int visit(Assignment *vis)
		{
			cout<<"Assignment"<<endl;
			vis->location->accept(this);
			vis->assign_op->accept(this);
			vis->expr->accept(this);
		}

		int visit(Method_call *vis)
		{
			cout<<"Method_call"<<endl;
		}

		int visit(If_Else *vis)
		{
			cout<<"If_Else"<<endl;
			vis->expr->accept(this);
			vis->blck1->accept(this);
			vis->blck2->accept(this);
		}
		
		int visit(Iff *vis)
		{
			cout<<"Iff"<<endl;
			vis->expr->accept(this);
			vis->blck1->accept(this);
		}

		int visit(Fors *vis)
		{
			cout<<"Fors"<<endl;
			cout<<"Name is "<<vis->name<<endl;
			vis->expr1->accept(this);
			vis->expr2->accept(this);
			vis->blck->accept(this);
		}

		int visit(Return *vis)
		{
			cout<<"Return"<<endl;
			if(vis->expr)
				vis->expr->accept(this);
		}

		int visit(Break *vis)
		{
			cout<<"Break"<<endl;
		}

		int visit(Continue *vis)
		{
			cout<<"Continue"<<endl;
		}

		int visit(Location *vis)
		{
			cout<<"Location"<<endl;
			cout<<"Name is "<< vis->name<<endl;
			if(vis->expr)
				vis->expr->accept(this);
		}

		int visit(Assign_op *vis)
		{
			cout<<"Assign_op"<<endl;
			cout<<"operation name is "<<vis->oper<<endl;
		}

		int visit(Binary_expr *vis)
		{
			cout<<"Binary_expr"<<endl;
			cout<<"operation is "<<vis->oper<<endl;
			vis->expr1->accept(this);
			vis->expr2->accept(this);
		}

		int visit(Unary_expr *vis)
		{
			cout<<"Unary_expr"<<endl;
			cout<<"Operation is "<<vis->oper;
			vis->expr1->accept(this);
		}

		int visit(Bracket_expr *vis)
		{
			cout<<"Bracket_expr"<<endl;
			vis->expr->accept(this);
		}

		int visit(Func_call *vis)
		{
			cout<<"Func_call"<<endl;
			cout<<"Name is "<<vis->name;
			if(vis->expr_plus!=NULL)
				vis->expr_plus->accept(this);
		}

		int visit(Call_out *vis)
		{
			cout<<"Call_out"<<endl;
			cout<<"Name is "<<vis->name<<endl;
			vis->callout_args_plus->accept(this);
		}

		int visit(Callout_args_plus *vis)
		{
			cout<<"Callout_args_plus"<<endl;
			for(int i=0;i<vis->callout_arg_list.size();i++)
				vis->callout_arg_list[i]->accept(this);
		}

		int visit(Callout_arg *vis)
		{
			cout<<"Callout_arg"<<endl;
		}

		int visit(Expr_plus *vis)
		{
			cout<<"Expr_plus"<<endl;
			for(int i=0;i<vis->expr_list.size();i++)
				vis->expr_list[i]->accept(this);
		}

		int visit(Expr *vis)
		{
			cout<<"Entered Expr node"<<endl;
		}

		int visit(Literal *vis)
		{
			cout<<"Entered Literal Node"<<endl;
		}

		int visit(Int_literal *vis)
		{
			cout<<"Int_literal is "<<vis->var<<endl;
		}

		int visit(Char_literal *vis)
		{
			cout<<"Char_literal is "<<vis->var<<endl;
		}

		int visit(Bool_literal *vis)
		{
			cout<<"Bool_literal is "<<vis->var<<endl;
		}



};

