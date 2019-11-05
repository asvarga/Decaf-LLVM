#include "ast.h"
#include <bits/stdc++.h>
#include <string.h> // strdup
#include <stdio.h> // printf
#include <stdarg.h>
#include <string.h>
#include <vector>
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/Interval.h"
#include <llvm/IR/CFG.h>
#include "llvm/IR/BasicBlock.h"
#include <llvm/IR/Function.h>
#include <utility>
#include <llvm/IR/Value.h>



using namespace llvm;
using namespace std;


string newline(string str) {
    size_t index = 0;
    string search = "\\n";
    index = str.find(search, index);
    while (index != std::string::npos) {
        str.erase(index, search.length());
        str.insert(index, "\n");
        index += 1;
        index = str.find(search, index);
    }
    return str;
}


Construct::Construct() {
    this->Builder = new IRBuilder<>(Context);
    this->loops = new std::stack<loopInfo*>();
    errors = 0;
    this->TheModule = new Module("My Decaf Compiler", Context);
}

AllocaInst *Construct::CreateEntryBlockAlloca(Function *TheFunction, std::string VarName, std::string type) {
    IRBuilder<> Build(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
    AllocaInst *alloca_instruction = nullptr;
    if (type == "boolean")
    {
        alloca_instruction = Build.CreateAlloca(Type::getInt1Ty(this->Context), 0, VarName);
    }
    else if(type == "int")
    {
        alloca_instruction = Build.CreateAlloca(Type::getInt32Ty(this->Context), 0, VarName);
    }
    return alloca_instruction;
}

typedef struct type_func
{
    string a,b;
}type_func;

bool operator< ( type_func A, type_func B ) { return std::make_pair(A.a,A.b) < std::make_pair(B.a,B.b) ; }



map<type_func,int> var_map;



AST::AST(){}

int AST::accept(Visitor *vis)
{
	vis->visit(this);
}

Program::Program(Field_decls *fields,Method_decls *methods)
{
	this->fields=fields;
	this->methods=methods;
	this->Constructs = new Construct();
}

Value *Program::GenCode()
{
	Value *v;
	if(fields!=NULL)
	{
		v=fields->GenCode(this->Constructs);
		if(v==nullptr)
		{
			cerr<<"Invalid field Declarations"<<endl;
            Constructs->errors++;
    	    return nullptr;
		}
	}
	if(methods!=NULL)
	{
		v=methods->GenCode(this->Constructs);
		
		if(v==nullptr)
		{
			cerr<<"Invalid method Declarations"<<endl;
            Constructs->errors++;
	        return nullptr;
		}
	}
	return v;
}


raw_ostream &file_write() 
{
    FILE *fp=fopen("outfile","w");
    static raw_fd_ostream S(fileno(fp), true);
    return S;
}
void Program::GenCodeDump()
{
    if(Constructs->errors==0)     
	   cerr << "Generating LLVM IR Code\n";
    
    this->Constructs->TheModule->print(file_write(), nullptr);
}



void Field_decls::Push_back(Fields_decl* fields_decl)
{
	field_declaration_list.push_back(fields_decl);
}

Value *Field_decls::GenCode(Construct *Constructs)
{
	for(auto &i:field_declaration_list)
	{
		i->GenCode(Constructs);
	}
	Value *v=ConstantInt::get(Constructs->Context, APInt(32, 1));
	return v;
}


Fields_decl::Fields_decl(string data_type, Comma_sep_fields* comma_sep_field)
{
	this->data_type=data_type;
	this->var_declaration_list=comma_sep_field->getVarList();

    for(auto var:this->var_declaration_list)
    {
        if(data_type=="int")
        {
            type_func temp={var->getname(),"GLOBAL"};
            var_map[temp]=0;
        }
        if(data_type=="boolean")
        {   
            type_func temp={var->getname(),"GLOBAL"};
            var_map[temp]=1;
        }
    }

    
}

Value *Fields_decl::GenCode(Construct *Constructs)
{
	llvm::Type *ty = nullptr;
	if(data_type=="int")
	{
		ty = Type::getInt32Ty(Constructs->Context);
	}
	else if(data_type=="boolean")
	{
		ty = Type::getInt1Ty(Constructs->Context);
	}

	for(auto var: var_declaration_list)
	{
        Value *cur = Constructs->TheModule->getGlobalVariable(var->getname());
        if(cur!=nullptr)
        {
            Constructs->errors++;
            cout<<"var name "<< var->getname() <<" already declared"<<endl;
            continue;
        }
		if(var->isArray())
		{
			ArrayType *arrType = ArrayType::get(ty, var->getLength());
			GlobalVariable *gv = new GlobalVariable(*(Constructs->TheModule), arrType, false,
                                                    GlobalValue::ExternalLinkage, nullptr,
                                                    var->getname());
            gv->setInitializer(ConstantAggregateZero::get(arrType));
		}
		else 
		{
            GlobalVariable *gv = new GlobalVariable(*(Constructs->TheModule), ty, false,
                                                    GlobalValue::ExternalLinkage, nullptr,
                                                    var->getname());
            gv->setInitializer(Constant::getNullValue(ty));
        }
	}
	Value *v = ConstantInt::get(Constructs->Context, APInt(32, 1));
    return v;

}


void Comma_sep_fields::Push_back(Comma_sep_field *comma_sep_field)
{
	var_declaration_list.push_back(comma_sep_field);
}

vector <Comma_sep_field*> Comma_sep_fields::getVarList()
{
	return var_declaration_list;
}

Comma_sep_field::Comma_sep_field(string name, uint length)
{
	this->variable_type=var_type::array;
	this->name=name;
	this->length=length;
}

Comma_sep_field::Comma_sep_field(string name)
{
	this->variable_type=var_type::normal;
	this->name=name;
}

void Method_decls::Push_back(Method_decl* method_decl)
{
	method_decl_list.push_back(method_decl);
}

Value *Method_decls::GenCode(Construct *Constructs)
{
	Value *V = ConstantInt::get(Constructs->Context, APInt(32, 0));
	for(auto &i:method_decl_list)
	{
		V=i->GenCode(Constructs);
		if(V==nullptr)
			return V;
	}
	return V;
}


Method_decl::Method_decl(string method_type, string name,Type_plus_ids *type_plus_ids,Block *blck)
{
	this->method_type=method_type;
	this->name=name;
	this->type_plus_ids=type_plus_ids;
	this->blck=blck;
}

Function* Method_decl::GenCode(Construct *Constructs)
{
	vector<std::string> arg_names;
    vector<std::string> arg_types;
    vector<class Type_plus_id *> args;
    if(type_plus_ids!=NULL)
    {
    	args = type_plus_ids->getArgList();
    }

    std::vector<Type *> arguments;
    auto arg_size = args.size();
    for (auto &arg : args)
    {
        string argument_type = arg->getType();
        string argument_name = arg->getName();
        if(argument_type == "int") 
        {
            arguments.push_back(Type::getInt32Ty(Constructs->Context));
        } 
        else if(argument_type == "boolean")
        {
            arguments.push_back(Type::getInt1Ty(Constructs->Context));
        } 
        else
        {
            Constructs->errors++;
            cerr<<"Arguments can only be int or boolean"<<endl;
            return nullptr;
        }
        arg_types.emplace_back(argument_type);
        arg_names.emplace_back(argument_name);
    }

    Type *returnType;
    if (method_type == "int")
    {
        returnType = Type::getInt32Ty(Constructs->Context);
    } 
    else if (method_type == "boolean")
    {
        returnType = Type::getInt1Ty(Constructs->Context);
    } 
    else if (method_type == "void") 
    {
        returnType = Type::getVoidTy(Constructs->Context);
    } 
    else 
    {
        Constructs->errors++;
        cerr<<"Invalid Return Type for " + name + ". Return Type can only be int or boolean or bool"<<endl;
        return nullptr;
    }

    FunctionType *FT = llvm::FunctionType::get(returnType, arguments, false);
    Function *F = llvm::Function::Create(FT, Function::ExternalLinkage, name, Constructs->TheModule);

    unsigned Idx = 0;
    for (Function::arg_iterator I = F->arg_begin(); Idx != arg_size; ++I, ++Idx)
    {
        I->setName(arg_names[Idx]);
    }


    BasicBlock *BB = BasicBlock::Create(Constructs->Context, "entry", F);
    Constructs->Builder->SetInsertPoint(BB);
    

    unsigned Idx1 = 0;
    for (auto &Arg : F->args()) {
        AllocaInst *Alloca = Constructs->CreateEntryBlockAlloca(F, arg_names[Idx1], arg_types[Idx1]);
        Constructs->Builder->CreateStore(&Arg, Alloca);
        Constructs->NamedValues[arg_names[Idx1]] = Alloca;
        Idx1++;
    }

    Value *RetVal = blck->GenCode(Constructs);
    if(RetVal==nullptr)
    {
        if(method_type=="void")
            Constructs->Builder->CreateRetVoid();
        verifyFunction(*F);
        return F;
    }
    if(method_type=="int" && !RetVal->getType()->isIntegerTy(32))
    {
        cerr<<"Ret Type and Method type mismatch"<<endl;
        Constructs->errors++;
    }
    if(method_type=="boolean" && !RetVal->getType()->isIntegerTy(1))
    {
        cerr<<"Ret Type and Method type mismatch"<<endl;
        Constructs->errors++;
    }
    // if(method_type=="void" && (RetVal->getType()->isIntegerTy(32) || RetVal->getType()->isIntegerTy(1)))
    // {
    //     cerr<<"Ret Type and Method type mismatch"<<endl;
    //     Constructs->errors++;
    // }
    
    if (RetVal) {
        if(method_type=="void")
            Constructs->Builder->CreateRetVoid();
        verifyFunction(*F);
        return F;
    }

    F->eraseFromParent();
    return nullptr;


}



void Type_plus_ids::Push_back(Type_plus_id* type_plus_id)
{
	type_plus_id_list.push_back(type_plus_id);
}

std::vector<class Type_plus_id *> Type_plus_ids::getArgList() {
    return type_plus_id_list;
}



Type_plus_id::Type_plus_id(string type_name, string name)
{
	this->type_name=type_name;
	this->name=name;
}

Block::Block(Var_decls* var_decls,Statements* statements)
{
	this->var_decls=var_decls;
	this->statements=statements;
}

bool Block::has_return()
{
	return statements->has_return();
}
bool Block::has_break()
{
	return statements->has_break();
}
bool Block::has_continue()
{
	return statements->has_continue();
}

Value* Block::GenCode(Construct *Constructs)
{
	Value *V;
    map<std::string, llvm::AllocaInst *> in_func_vals;
    if(var_decls!=NULL)
    {
	    V = var_decls->GenCode(in_func_vals, Constructs);
	    if (V == nullptr) {
	        return V;
	    }
	}
	if(statements!=NULL)
	{
	    V=statements->GenCode(Constructs);
	    for (auto it = in_func_vals.begin(); it != in_func_vals.end(); it++) {
	        Constructs->NamedValues[it->first] = in_func_vals[it->first];
	    }
	}
    return V;


}


void Var_decls::Push_back(Var_decl* var_decl)
{
	this->decl_list.push_back(var_decl);
}

Value* Var_decls::GenCode(map<string, AllocaInst *> &in_func_values, Construct *Constructs)
{
	Value *v = ConstantInt::get(Constructs->Context, APInt(32, 1));
    for (auto &decl : decl_list)
    {
        v = decl->GenCode(in_func_values, Constructs);
        if (v == nullptr)
        {
            return nullptr;
        }
    }
    return v;
}



Var_decl::Var_decl(string type_name, IDSS* idss)
{
	this->type_name=type_name;
	this->var_list=idss->getVarList();
}

Value* Var_decl::GenCode(map<string, llvm::AllocaInst *> &Old_vals, Construct *Constructs)
{
	llvm::Function *TheFunction = Constructs->Builder->GetInsertBlock()->getParent();
    for (const auto &var : var_list)
    {
        Value *cur = Constructs->TheModule->getGlobalVariable(var);
        if(cur!=nullptr)
        {
            Constructs->errors++;
            cout<<"var name "<< var <<" already declared"<<endl;
            continue;
        }
        cur = Constructs->NamedValues[var];
        if(cur!=nullptr)
        {
            Constructs->errors++;
            cout<<"var name "<< var <<" already declared"<<endl;
            continue;
        }
        llvm::Value *initval = nullptr;
        llvm::AllocaInst *Alloca = nullptr;
        if (type_name == "int")
        {
            initval = ConstantInt::get(Constructs->Context, APInt(32, 0));
            Alloca = Constructs->CreateEntryBlockAlloca(TheFunction, var, "int");
        }
        else if (type_name == "boolean")
        {
            initval = ConstantInt::get(Constructs->Context, APInt(1, 0));
            Alloca = Constructs->CreateEntryBlockAlloca(TheFunction, var, "boolean");
        }

        Constructs->Builder->CreateStore(initval, Alloca);
        Old_vals[var] = Constructs->NamedValues[var];
        Constructs->NamedValues[var] = Alloca;
    }
    Value *v = ConstantInt::get(Constructs->Context, APInt(32, 1));
    return v;
}

void IDSS::Push_back(string name1)
{
	this->var_list.push_back(name1);
}
vector<string> IDSS::getVarList()
{
	return this->var_list;
}

IDS::IDS(string name)
{
	this->name=name;
}

void Statements::Push_back(Statement * statement)
{
	this->statement_list.push_back(statement);
}

Value *Statements::GenCode(Construct* Constructs)
{
	Value *v = ConstantInt::get(Constructs->Context, llvm::APInt(32, 1));
	for (auto &stmt : statement_list)
    {
        v = stmt->GenCode(Constructs);
    }
    return v;
}
bool Statements::has_return() {
    for (int i = 0; i < statement_list.size(); i++) {
        if (statement_list[i]->has_return()) {
            return true;
        }
    }
    return false;
}


bool Statements::has_continue() {
    for (int i = 0; i < statement_list.size(); i++) {
        if (statement_list[i]->has_continue()) {
            return true;
        }
    }
    return false;
}

bool Statements::has_break() {
    for (int i = 0; i < statement_list.size(); i++) {
        if (statement_list[i]->has_break()) {
            return true;
        }
    }
    return false;
}





Assignment::Assignment(Location* location, Assign_op* assign_op, Expr* expr)
{
	// cout<<"location->lit_type "<<location->expr_type<<" expr->expr_type "<<expr->lit_type<<endl;
	// if(location->lit_type!=expr->lit_type)
	// {
	// 	cout<<"location = expr, must have the same type"<<endl;
	// 	exit(0);
	// }
	this->location=location;
	this->assign_op=assign_op;
	this->expr=expr;
}

Value* Assignment::GenCode(Construct *Constructs)
{
	Value *cur = Constructs->NamedValues[location->name];

    if (cur == nullptr)
    {
        cur = Constructs->TheModule->getGlobalVariable(location->name);
    }
    if (cur == nullptr)
    {
        Constructs->errors++;
        cerr<<"Unknown Variable Name: " + location->name<<endl;
        Constructs->errors++;
        return nullptr;
    }

    Value *val = expr->GenCode(Constructs);
    if (expr->expr_type==0)
    {
        val = Constructs->Builder->CreateLoad(val);
    }

    Value *lhs = location->GenCode(Constructs);
    cur = Constructs->Builder->CreateLoad(lhs);

    if(cur->getType()!=val->getType())
    {
            cerr<<"Both should be of sametype"<<endl;
            return nullptr;
    }

    if (val == nullptr)
    {
        Constructs->errors++;
        cerr<<"Error in right hand side of the Assignment"<<endl;
        return nullptr;
    }
    if (assign_op->oper == "+=")
    {
        if(!lhs->getType()->isIntegerTy(32)||!val->getType()->isIntegerTy(32))
        {
            cerr<<"Both should be int"<<endl;
            return nullptr;
        }
        val = Constructs->Builder->CreateAdd(cur, val, "AddEqualToVal");
    } 
    else if (assign_op->oper == "-=") 
    {
        if(!lhs->getType()->isIntegerTy(32)||!val->getType()->isIntegerTy(32))
        {
            cerr<<"Both should be int"<<endl;
            return nullptr;
        }
        val = Constructs->Builder->CreateSub(cur, val, "SubEqualToVal");
    }
    return Constructs->Builder->CreateStore(val, lhs);


}


If_Else::If_Else(Expr*expr, Block* blck1, Block* blck2)
{
	this->expr=expr;
	// cout<<expr->lit_type<<endl;
	// if(expr->lit_type!=1)
	// {
	// 	cout<<"If condition should be boolean"<<endl;
	// 	exit(0);
	// }
	this->blck1=blck1;
	this->blck2=blck2;
}


Value* If_Else::GenCode(Construct *Constructs)
{
	Value *cond = expr->GenCode(Constructs);
    if (cond == nullptr)
    {
        Constructs->errors++;
        cerr<<"Invalid Expression in the IF"<<endl;
        return nullptr;
    }

    if(!cond->getType()->isIntegerTy(1))
    {
        cerr<<"if statement must have type boolean."<<endl;
        return nullptr;
    }

    Function *TheFunction = Constructs->Builder->GetInsertBlock()->getParent();
    BasicBlock *ifBlock = BasicBlock::Create(Constructs->Context, "if", TheFunction);
    BasicBlock *elseBlock = BasicBlock::Create(Constructs->Context, "else");
    BasicBlock *nextBlock = BasicBlock::Create(Constructs->Context, "ifcont");
    
    bool ret_if = blck1->has_return(), ret_else = false;
    bool break_if=blck1->has_break(), break_else = false;
    bool continue_if=blck1->has_continue(), continue_else = false;
    
    BasicBlock *otherBlock = elseBlock;

    if (blck2 == nullptr)
    {
        otherBlock = nextBlock;
    }

    Constructs->Builder->CreateCondBr(cond, ifBlock, otherBlock);
    Constructs->Builder->SetInsertPoint(ifBlock);


    Value *if_val = blck1->GenCode(Constructs);
    if (if_val == nullptr)
    {
        return nullptr;
    }

    if (!ret_if && !break_if && !continue_if)
    {
        Constructs->Builder->CreateBr(nextBlock);
    }

    ifBlock = Constructs->Builder->GetInsertBlock();


    Value *else_val = nullptr;

    if (blck2 != nullptr)
    {

        TheFunction->getBasicBlockList().push_back(elseBlock);
        Constructs->Builder->SetInsertPoint(elseBlock);
        else_val = blck2->GenCode(Constructs);
        if (else_val == nullptr)
        {
            return nullptr;
        }
        ret_else = blck2->has_return();
        continue_else = blck2->has_continue();
        break_else = blck2->has_break();
        if (!ret_else && !continue_else && !break_else)
        {
            Constructs->Builder->CreateBr(nextBlock);
        }
    }
    
    TheFunction->getBasicBlockList().push_back(nextBlock);
    Constructs->Builder->SetInsertPoint(nextBlock);
    if (ret_else && ret_if) {
        
        Type *retType = Constructs->Builder->GetInsertBlock()->getParent()->getReturnType();
        if (retType == Type::getVoidTy(Constructs->Context))
            Constructs->Builder->CreateRetVoid();
        else {
            Constructs->Builder->CreateRet(ConstantInt::get(Constructs->Context, APInt(32, 0)));
        }
    }
    Value *V = ConstantInt::get(Constructs->Context, APInt(32, 0));
    return V;
}

bool If_Else::has_return() {
    bool status = false;
    if (blck1 != nullptr) {
        status = status | blck1->has_return();
    }
    if (blck2 != nullptr) {
        status = status | blck2->has_return();
    }
    return status;
}


bool If_Else::has_continue() {
    bool status = false;
    if (blck1 != nullptr) {
        status = status | blck1->has_continue();
    }
    if (blck2 != nullptr) {
        status = status | blck2->has_continue();
    }
    return status;
}


bool If_Else::has_break() {
    bool status = false;
    if (blck1 != nullptr) {
        status = status | blck1->has_break();
    }
    if (blck2 != nullptr) {
        status = status | blck2->has_break();
    }
    return status;
}


Iff::Iff(Expr*expr, Block* blck1)
{
	this->expr=expr;
	// cout<<expr->lit_type<<endl;
	if(expr->lit_type!=1)
	{
		cout<<"If condition should be boolean"<<endl;
		exit(0);
	}
	this->blck1=blck1;
}

Fors::Fors(string name, Expr* expr1, Expr* expr2, Block* blck)
{
	this->name=name;
	this->expr1=expr1;
	this->expr2=expr2;
	this->blck=blck;
}

Value* Fors::GenCode(Construct *Constructs)
{
	Value *start = expr1->GenCode(Constructs);
    if (start == nullptr)
    {
        return nullptr;
    }
    if (expr1->expr_type==0) {
        start = Constructs->Builder->CreateLoad(start);
    }
   

    Function *TheFunction = Constructs->Builder->GetInsertBlock()->getParent();
    
    llvm::AllocaInst *Alloca = Constructs->CreateEntryBlockAlloca(TheFunction, name, string("int"));
    Constructs->Builder->CreateStore(start, Alloca);

    Value *step_val = ConstantInt::get(Constructs->Context, APInt(32, 1));
    BasicBlock *pre_header = Constructs->Builder->GetInsertBlock();
    BasicBlock *loop_body = BasicBlock::Create(Constructs->Context, "loop_body", TheFunction);
    BasicBlock *afterBB = BasicBlock::Create(Constructs->Context, "afterBB", TheFunction);
    Constructs->Builder->CreateBr(loop_body);
    Constructs->Builder->SetInsertPoint(loop_body);

    PHINode *Variable = Constructs->Builder->CreatePHI(Type::getInt32Ty(Constructs->Context), 2, name);
    Variable->addIncoming(start, pre_header);
    

    Value *cond = expr2->GenCode(Constructs);
    if (cond == nullptr)
    {
        Constructs->errors++;
        cerr<<"Invalid Condition"<<endl;
        return nullptr;
    }

    // Check if condition is a location
    if (expr2->expr_type==0) 
    {
        cond = Constructs->Builder->CreateLoad(cond);
    }

    if(!start->getType()->isIntegerTy(32) || !cond->getType()->isIntegerTy(32))
    {
        cerr<<"should be int"<<endl;
        Constructs->errors++;
        return nullptr;
    }

    Constructs->loops->push(new loopInfo(afterBB, loop_body, cond, name, Variable));
    llvm::AllocaInst *OldVal = Constructs->NamedValues[name];
    Constructs->NamedValues[name] = Alloca;
    

    if (blck->GenCode(Constructs) == nullptr) {
        return nullptr;
    }

    Value *cur = Constructs->Builder->CreateLoad(Alloca, name);
    Value *next_val = Constructs->Builder->CreateAdd(cur, step_val, "Next_Val");
    Constructs->Builder->CreateStore(next_val, Alloca);
    cond = Constructs->Builder->CreateICmpSLT(next_val, cond, "loop_condition");
    BasicBlock *loopEndBlock = Constructs->Builder->GetInsertBlock();
    Constructs->Builder->CreateCondBr(cond, loop_body, afterBB);
    Constructs->Builder->SetInsertPoint(afterBB);
    Variable->addIncoming(next_val, loopEndBlock);

    if (OldVal)
    {
        Constructs->NamedValues[name] = OldVal;
    } 
    else
    {
        Constructs->NamedValues.erase(name);
    }
    llvm::Value *V = ConstantInt::get(Constructs->Context, APInt(32, 1));
    return V;
}


Return::Return(Expr* expr)
{
	this->expr=expr;
}

Value *Return::GenCode(Construct *Constructs)
{
	llvm::Value *V = nullptr;
    if (expr != nullptr)
    {
        V = expr->GenCode(Constructs);
        if (expr->expr_type==0)
        {
            V = Constructs->Builder->CreateLoad(V);
        }
        Constructs->Builder->CreateRet(V);
        return V;
    }
    Constructs->Builder->CreateRetVoid();
    return V;
}


Value *Continue::GenCode(Construct *Constructs) 
{
	llvm::Value *V = llvm::ConstantInt::get(Constructs->Context, llvm::APInt(32, 1));
    if(Constructs->loops->empty())
    {
        cout<<"Continue should be inside For"<<endl;
        Constructs->errors++;
        return nullptr;
    }
    loopInfo *currentLoop = Constructs->loops->top();
    Expr *condition = nullptr;
    string var = currentLoop->getLoopVariable();
    AllocaInst *Alloca = Constructs->NamedValues[var];
    Value *step_val = ConstantInt::get(Constructs->Context, APInt(32, 1));
    Value *cur = Constructs->Builder->CreateLoad(Alloca, var);
    Value *next_val = Constructs->Builder->CreateAdd(cur, step_val, "Next_Val");
    Constructs->Builder->CreateStore(next_val, Alloca);
    llvm::Value *cond = Constructs->Builder->CreateICmpULE(next_val, currentLoop->getCondition(),
                                                                   "loop_condition");
    BasicBlock *loopEndBlock = Constructs->Builder->GetInsertBlock();
    Constructs->Builder->CreateCondBr(cond, currentLoop->getCheckBlock(), currentLoop->getAfterBlock());
    return V;
}

Value *Break::GenCode(Construct *Constructs) 
{
	llvm::Value *V = llvm::ConstantInt::get(Constructs->Context, llvm::APInt(32, 1));
    if(Constructs->loops->empty())
    {
        cout<<"Break should be inside for"<<endl;
        Constructs->errors++;
        return nullptr;
    }
    loopInfo *currentLoop = Constructs->loops->top();
    Constructs->Builder->CreateBr(currentLoop->getAfterBlock());
    return V;
}

Location::Location(string name)
{
	this->name=name;
 //    if(var_map[name]==0)
 //    {
 //        this->lit_type=1;
 //    }
 //    else
 //    {
	//    this->lit_type=0;
 //    }
    this->lit_type=0;
    type_func temp={name,"GLOBAL"};
    if(var_map[temp]==1)
        this->lit_type=1;
	this->expr_type=0;
	this->location_type=var_type::normal;
}

Location::Location(string name, Expr* expr)
{
	this->name=name;
	this->expr=expr;
	this->expr_type=0;
    // if(var_map[name]==0)
    // {
    //     this->lit_type=1;
    // }
    // else
    // {
    //    this->lit_type=0;
    // }
    this->lit_type=0;
    type_func temp={name,"GLOBAL"};
    if(var_map[temp]==1)
        this->lit_type=1;    
	this->location_type=var_type::array;
}


Value *Location::GenCode(Construct *Constructs)
{
	Value *V = Constructs->NamedValues[name];
	if (V == nullptr) 
	{
        V = Constructs->TheModule->getNamedGlobal(name);
    }
    if (V == nullptr) 
    {
        Constructs->errors++;
        cerr<<"Unknown Variable name " + name<<endl;
        return nullptr;
    }
    

    if (this->location_type == var_type::normal) {
        return V;
    }
    
    if (this->expr == nullptr)
    {
        cerr<<"Invalid array index"<<endl;
        return nullptr;
    }
    
    Value *index = expr->GenCode(Constructs);
    if (expr->expr_type == 0) 
    {
        index = Constructs->Builder->CreateLoad(index);
    }

    if (index == nullptr)
    {
        cerr<<"Invalid array index"<<endl;
    }
    
    vector<Value *> array_index;
    array_index.push_back(Constructs->Builder->getInt32(0));
    array_index.push_back(index);
    V = Constructs->Builder->CreateGEP(V, array_index, name + "_Index");
    return V;

}


void Expr_plus::Push_back(Expr* expr)
{
	this->expr_list.push_back(expr);
}


Assign_op::Assign_op(string oper)
{
    // cout<<"Assign_op"<<oper<<endl;
	this->oper=oper;
}

Binary_expr::Binary_expr(Expr* expr1, string oper, Expr* expr2)
{
	this->expr1=expr1;
	this->oper=oper;
	this->expr2=expr2;
	this->expr_type=3;

	// cout<<"Binary "<<expr1->lit_type<<" "<<expr2->lit_type<<" "<<oper<<endl;
	if(oper=="+" || oper=="-" || oper=="*" || oper=="/" || oper=="%")
	{
		
		this->lit_type=0;
	}
	else if(oper=="<" || oper==">"||oper==">="||oper=="<=")
	{
		
		this->lit_type=1;
	}

	else if(oper=="==" || oper=="!=")
	{
		// if(expr1->lit_type!=expr2->lit_type)
		// {
  //           cout<<expr1->lit_type<<" "<<expr2->lit_type<<endl;
		// 	cout<<"eq ops must have the same type"<<endl;
		// 	exit(0);
		// }
		this->lit_type=1;
	}

}


Value *Binary_expr::GenCode(Construct *Constructs)
{
	Value *left = expr1->GenCode(Constructs);
    Value *right = expr2->GenCode(Constructs);
    if (expr1->expr_type == 0) {
        left = Constructs->Builder->CreateLoad(left);
    }
    if (expr2->expr_type == 0) {
        right = Constructs->Builder->CreateLoad(right);
    }
    string opr=oper;
    if (left == 0) {
        Constructs->errors++;
        cerr<<"Error in left operand of " + opr<<endl;
        return nullptr;
    } else if (right == 0) {
        Constructs->errors++;
        cerr<<"Error in right operand of " + opr<<endl;
        return nullptr;
    }
    Value *v = nullptr;
    if (opr == "+") 
    {
        if(!left->getType()->isIntegerTy(32)||!right->getType()->isIntegerTy(32))
        {
            cerr<<"Both should be int"<<endl;
            return nullptr;
        }
        v = Constructs->Builder->CreateAdd(left, right, "addtmp");
    } 
    else if (opr == "-")
    {
        if(!left->getType()->isIntegerTy(32)||!right->getType()->isIntegerTy(32))
        {
            cerr<<"Both should be int"<<endl;
            return nullptr;
        }
        v = Constructs->Builder->CreateSub(left, right, "subtmp");
    } 
    else if (opr == "*") 
    {
        if(!left->getType()->isIntegerTy(32)||!right->getType()->isIntegerTy(32))
        {
            cerr<<"Both should be int"<<endl;
            return nullptr;
        }
        v = Constructs->Builder->CreateMul(left, right, "multmp");
    } 
    else if (opr == "/")
    {
        if(!left->getType()->isIntegerTy(32)||!right->getType()->isIntegerTy(32))
        {
            cerr<<"Both should be int"<<endl;
            return nullptr;
        }
        v = Constructs->Builder->CreateSDiv(left, right, "divtmp");
    } 
    else if (opr == "%")
    {
        if(!left->getType()->isIntegerTy(32)||!right->getType()->isIntegerTy(32))
        {
            cerr<<"Both should be int"<<endl;
            return nullptr;
        }
        v = Constructs->Builder->CreateSRem(left, right, "modtmp");
    } 
    else if (opr == "<")
    {
        if(!left->getType()->isIntegerTy(32)||!right->getType()->isIntegerTy(32))
        {
            cerr<<"Both should be int"<<endl;
            return nullptr;
        }
        v = Constructs->Builder->CreateICmpSLT(left, right, "ltcomparetmp");
    } 
    else if (opr == ">") 
    {
        if(!left->getType()->isIntegerTy(32)||!right->getType()->isIntegerTy(32))
        {
            cerr<<"Both should be int"<<endl;
            return nullptr;
        }
        v = Constructs->Builder->CreateICmpSGT(left, right, "gtcomparetmp");
    }
    else if (opr == "<=")
    {
        if(!left->getType()->isIntegerTy(32)||!right->getType()->isIntegerTy(32))
        {
            cerr<<"Both should be int"<<endl;
            return nullptr;
        }
        v = Constructs->Builder->CreateICmpSLE(left, right, "lecomparetmp");
    } 
    else if (opr == ">=")
    {
        if(!left->getType()->isIntegerTy(32)||!right->getType()->isIntegerTy(32))
        {
            cerr<<"Both should be int"<<endl;
            return nullptr;
        }
        v = Constructs->Builder->CreateICmpSGE(left, right, "gecomparetmp");
    }
    else if (opr == "==") 
    {
        if(left->getType()!=right->getType())
        {
            cerr<<"Both should be of same type"<<endl;
            return nullptr;
        }
        v = Constructs->Builder->CreateICmpEQ(left, right, "equalcomparetmp");
    } 
    else if (opr == "!=") 
    {
        if(left->getType()!=right->getType())
        {
            cerr<<"Both should be of same type"<<endl;
            return nullptr;
        }
        v = Constructs->Builder->CreateICmpNE(left, right, "notequalcomparetmp");
    } 
    else if (opr=="&&")
    {
        if(!left->getType()->isIntegerTy(1)||!right->getType()->isIntegerTy(1))
        {
            cerr<<"Both should be bool"<<endl;
            return nullptr;
        }
        v = Constructs->Builder->CreateAnd(left, right, "andtmp");
    }
    else if (opr=="||")
    {
        if(!left->getType()->isIntegerTy(1)||!right->getType()->isIntegerTy(1))
        {
            cerr<<"Both should be bool"<<endl;
            return nullptr;
        }
        v = Constructs->Builder->CreateOr(left, right, "ortmp");
    }
    return v;
}


Unary_expr::Unary_expr(string oper, Expr* expr1)
{
	this->oper=oper;
	this->expr1=expr1;
	this->expr_type=4;
	// if(oper=="!")
	// {
	// 	if(expr1->lit_type!=1)
	// 	{
	// 		cout<<"Unary expression should be boolen for !"<<endl;
	// 		exit(0);
	// 	}
	// 	else
	// 		this->lit_type=1;
	// }

	// if(oper=="-")
	// {
	// 	if(expr1->lit_type!=0)
	// 	{
	// 		cout<<"Unary expression should be int for -"<<endl;
	// 		exit(0);
	// 	}
	// 	else
	// 		this->lit_type=0;
	// }

}

Value *Unary_expr::GenCode(Construct *Constructs)
{
	Value *v = expr1->GenCode(Constructs);
    if (expr1->expr_type==0) {
        v = Constructs->Builder->CreateLoad(v);
    }
    /// Generate the code for operation based on the operator
    if (oper == "-") 
    {
        if(!v->getType()->isIntegerTy(32))
        {
            cerr<<"Should be int"<<endl;
            return nullptr;
        }
        return Constructs->Builder->CreateNeg(v, "negtmp");
    } 
    else if (oper == "!") 
    {
        if(!v->getType()->isIntegerTy(1))
        {
            cerr<<"Should be boolean"<<endl;
            return nullptr;
        }
        return Constructs->Builder->CreateNot(v, "nottmp");
    }
}



Bracket_expr::Bracket_expr(Expr *expr)
{
	this->expr=expr;
	this->expr_type=5;
	this->lit_type=expr->lit_type;
}

Value *Bracket_expr::GenCode(Construct *Constructs)
{
	return expr->GenCode(Constructs);
}



Func_call::Func_call(string name, Expr_plus* expr_plus)
{
	this->name=name;
	this->expr_plus=expr_plus;
	this->expr_type=1;
	this->lit_type=0;
}

Value* Func_call::GenCode(Construct *Constructs)
{
	Function *calle = Constructs->TheModule->getFunction(name);
    if (calle == nullptr) {
        Constructs->errors++;
        cerr<<"Unknown Function name" + name<<endl;
        return nullptr;
    }

    // for (auto& A : calle->getArgumentList()) { cout<<A.getType()<<endl; }


    vector<class Expr*> args_list;
    if( expr_plus!=NULL)
    	 args_list = expr_plus->expr_list;
    if (calle->arg_size() != args_list.size()) 
    {
        Constructs->errors++;
        cerr<<"Incorrect Number of Parameters Passed"<<endl;
        return nullptr;
    }
   

    vector<Value *> Args;
    FunctionType* FTY=calle->getFunctionType();
    for(int i=0;i<args_list.size();i++)
    {
        Value *argVal = args_list[i]->GenCode(Constructs);
        if (args_list[i]->expr_type == 0) {
            argVal = Constructs->Builder->CreateLoad(argVal);
        }
        if(argVal->getType() != FTY->getParamType(i))
        {
            cerr<<"Arguments type mismatch"<<endl;
            return nullptr;
        }
    }

    for (auto &arg : args_list) {
        Value *argVal = arg->GenCode(Constructs);
        if (arg->expr_type == 0) {
            argVal = Constructs->Builder->CreateLoad(argVal);
        }
        if (argVal == nullptr) {
            Constructs->errors++;
            cerr<<"Argument is not valid"<<endl;
            return nullptr;
        }
        Args.push_back(argVal);
    }
     

    Value *v = Constructs->Builder->CreateCall(calle, Args);
    return v;
}


Call_out::Call_out(string name, Callout_args_plus* callout_args_plus)
{
	this->name=name.substr(1, name.length() - 2);
	this->name=newline(this->name);
	this->callout_args_plus=callout_args_plus;
}

Value* Call_out::GenCode(Construct *Constructs)
{
	std::vector<llvm::Type *> argTypes;
    std::vector<Value *> Args;
    std::vector<class Callout_arg *> args_list;
    if(callout_args_plus!=NULL) 
    	args_list= callout_args_plus->callout_arg_list;
    

    for (auto &i : args_list) {
        Value *tmp = i->GenCode(Constructs);
        if (tmp == nullptr) {
            return nullptr;
        }
        Args.push_back(tmp);
        argTypes.push_back(tmp->getType());
    }
    

    llvm::ArrayRef<llvm::Type *> argsRef(argTypes);
    llvm::ArrayRef<llvm::Value *> funcargs(Args);
    llvm::FunctionType *FType = FunctionType::get(Type::getInt32Ty(Constructs->Context), argsRef, false);
    Constant *func = Constructs->TheModule->getOrInsertFunction(name, FType);
    if (!func) {
        cerr<<"Error in inbuilt function. Unknown Function name " + name<<endl;
        return nullptr;
    }
    Value *v = Constructs->Builder->CreateCall(func, funcargs);
    return v;
}



void Callout_args_plus::Push_back(Callout_arg* callout_arg)
{
	callout_arg_list.push_back(callout_arg);
}

Callout_arg::Callout_arg(Expr *expr)
{
	this->expr=expr;
}

Callout_arg::Callout_arg(string literal)
{
	this->literal=literal.substr(1, literal.length() - 2);
	this->literal=newline(this->literal);
    this->expr = NULL;
}

Value *Callout_arg::GenCode(Construct *Constructs)
{
	if (expr == nullptr && literal=="") {
        Constructs->errors++;
        cerr<<"Invalid Callout Arg"<<endl;
    }
    Value *v;
    if(expr != nullptr)
    {
        // cout<<expr<<" expr "<<endl;
    	v = expr->GenCode(Constructs);
    	if (expr->expr_type==0) {
    	    v = Constructs->Builder->CreateLoad(v);
    	}
    }
    else
    {
        // cout<<literal<<endl;
    	v = Constructs->Builder->CreateGlobalStringPtr(literal);
    }
    return v;
}




Int_literal::Int_literal(int var)
{
	this->var=var;
	this->lit_type=0;
	this->expr_type=2;
	// cout<<"Int_literal "<<this->lit_type<<endl;
 //    cout<<var<<endl;
}

Value* Int_literal::GenCode(Construct *Constructs)
{
	Value *v = ConstantInt::get(Constructs->Context, llvm::APInt(32, static_cast<uint64_t>(var)));
    return v;
}

Char_literal::Char_literal(string var)
{
	this->var=var;
	this->lit_type=2;
	this->expr_type=2;
	// cout<<"Char_literal "<<this->lit_type<<endl;
}

Bool_literal::Bool_literal(string var)
{
	this->var=var;
	this->lit_type=1;
	this->expr_type=2;
	// cout<<"Bool_literal "<<this->lit_type<<endl;
    // cout<<var<<endl
}

Value* Bool_literal::GenCode(Construct *Constructs)
{
	bool val;
    if (var == "true") val = true;
    else if (var == "false") val = false;
    else {
        Constructs->errors++;
        cerr<<"Invalid Boolean Literal " + var<<endl;
        return nullptr;
    }
    Value *v = ConstantInt::get(Constructs->Context, llvm::APInt(1, val));
    return v;
}