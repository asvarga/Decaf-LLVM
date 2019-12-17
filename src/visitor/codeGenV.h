
#pragma once

#include <list>
#include "symbolTable.h"
// #include "../decaf_runtime.h"

using namespace llvm;
using namespace llvm::sys;


/// LLVM ///
static LLVMContext TheContext;
static IRBuilder<> Builder(TheContext);
static std::unique_ptr<Module> TheModule = make_unique<Module>("START", TheContext);
// static std::map<std::string, Value *> NamedValues;
static std::unique_ptr<legacy::FunctionPassManager> TheFPM;

/// extern ///
Function *PutCharFunction;
Function *PutIntFunction;
Function *PutStringFunction;
Function *PeekFunction;
Function *GetCharFunction;
Function *GetIntFunction;
Function *GetLineFunction;

class CodeGenV : public Visitor {
    // Module * module;
    // StartA * start;
    // Function * mainFunction;
    //SymbolTable symbolTable;
    StartA *currStart;
    ClassA *currClass;
    MethodA *currMethod;
    SymbolTable *currSymTab;
    std::vector<Type*> currArgTypes;
    Type *currType;
    int nameCase;   // decaf-semantics.pdf: page 12
    // std::vector<CallA*> currCalls; // for handling nested calls
public:
    CodeGenV() {
        // TODO: declare rest of externs
        // TODO: put in IO class

        // putChar external declaration
        Type *putCharReturnType = Type::getVoidTy(TheContext);
        std::vector<Type*> putCharArgTypes(1, Type::getInt8Ty(TheContext));
        FunctionType *putCharFT = FunctionType::get(putCharReturnType, putCharArgTypes, false);
        PutCharFunction = Function::Create(putCharFT, Function::ExternalLinkage, "IO$putChar", TheModule.get()); 

        // putInt external declaration
        Type *putIntReturnType = Type::getVoidTy(TheContext);
        std::vector<Type*> putIntArgTypes(1, Type::getInt64Ty(TheContext));
        FunctionType *putIntFT = FunctionType::get(putIntReturnType, putIntArgTypes, false);
        PutIntFunction = Function::Create(putIntFT, Function::ExternalLinkage, "IO$putInt", TheModule.get()); 

        // putString external declaration
        Type *putStringReturnType = Type::getVoidTy(TheContext);
        std::vector<Type*> putStringArgTypes(1, Type::getInt8PtrTy(TheContext));    // char*
        FunctionType *putStringFT = FunctionType::get(putStringReturnType, putStringArgTypes, false);
        PutStringFunction = Function::Create(putStringFT, Function::ExternalLinkage, "IO$putString", TheModule.get()); 

        // peek external declaration
        Type *peekReturnType = Type::getInt8Ty(TheContext);
        std::vector<Type*> peekArgTypes;
        FunctionType *peekFT = FunctionType::get(peekReturnType, peekArgTypes, false);
        PeekFunction = Function::Create(peekFT, Function::ExternalLinkage, "IO$peek", TheModule.get()); 

        // getChar external declaration
        Type *getCharReturnType = Type::getInt8Ty(TheContext);
        std::vector<Type*> getCharArgTypes;
        FunctionType *getCharFT = FunctionType::get(getCharReturnType, getCharArgTypes, false);
        GetCharFunction = Function::Create(getCharFT, Function::ExternalLinkage, "IO$getChar", TheModule.get()); 

        // getInt external declaration
        Type *getIntReturnType = Type::getInt64Ty(TheContext);
        std::vector<Type*> getIntArgTypes;
        FunctionType *getIntFT = FunctionType::get(getIntReturnType, getIntArgTypes, false);
        GetIntFunction = Function::Create(getIntFT, Function::ExternalLinkage, "IO$getInt", TheModule.get()); 

        // getLine external declaration
        Type *getLineReturnType = Type::getInt8PtrTy(TheContext);    //char*
        std::vector<Type*> getLineArgTypes;
        FunctionType *getLineFT = FunctionType::get(getLineReturnType, getLineArgTypes, false);
        GetLineFunction = Function::Create(getLineFT, Function::ExternalLinkage, "IO$getLine", TheModule.get()); 

    }
    void LogErrorV(const char *s) {
        cout << "XXXX error: " << s << " XXXXXXXXXXXXXXXXXXXXXXX\n";
    }
    void Print(string s) {
        cout << s << endl;
    }
    void indent(int d) {
        for (int i=0; i<d; i++) { cout << "| "; }
    }
    virtual void visit(StartA* a);
    virtual void visit(ListA* a);
    virtual void visit(ClassA* a);
    virtual void visit(SuperA* a);
    virtual void visit(MethodBodyA* a);
    virtual void visit(FieldDeclA* a);
    virtual void visit(FieldA* a);
    virtual void visit(MethodA* a);
    virtual void visit(ConstructorA* a);
    virtual void visit(FormalA* a);
    virtual void visit(DeclStatementA* a);
    virtual void visit(LocalA* a);
    virtual void visit(IfStatementA* a);
    virtual void visit(ExpressionStatementA* a);
    virtual void visit(WhileStatementA* a);
    virtual void visit(ReturnStatementA* a);
    virtual void visit(ContinueStatementA* a);
    virtual void visit(BreakStatementA* a);
    virtual void visit(BlockStatementA* a);
    virtual void visit(BlockA* a);
    virtual void visit(SuperStatementA* a);
    virtual void visit(CallA* a);
    virtual void visit(OpExpressionA* a);
    virtual void visit(NewArrayA* a);
    virtual void visit(ArrayRefA* a);
    virtual void visit(VarDeclA* a);

    virtual void visit(TypeA *a);
    virtual void visit(PrimTypeA* a);
    virtual void visit(ArrayTypeA* a);
    virtual void visit(ClassTypeA* a);

    virtual void visit(PrimaryExprA* a);
    virtual void visit(ExpressionA* a);
    virtual void visit(InitializerA* a);
    virtual void visit(StatementA* a);
    virtual void visit(NameA* a);
    virtual void visit(StrLitA* a);
    virtual void visit(IntLitA* a);

    virtual void visit(DimensionA* a);
    virtual void visit(FieldExprA* a);
    virtual void visit(NewObjExprA* a);
    virtual void visit(PrimaryArrayA* a);
    virtual void visit(ThisCallExprA* a);
    virtual void visit(SuperCallExprA* a);
    virtual void visit(EmptyStatementA* a);
    virtual void visit(MethodCallExprA* a);
    virtual void visit(SuperFieldExprA* a);
    virtual void visit(NonArrayPrimaryA* a);
    virtual void visit(BoolLitA* a);
    virtual void visit(CharLitA* a);
    virtual void visit(NullLitA* a);
    virtual void visit(ModifierA* a);
    virtual void visit(ThisExprA* a);
};
