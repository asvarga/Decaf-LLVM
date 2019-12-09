
#pragma once

#include <list>
#include "symbolTable.h"

using namespace llvm;
using namespace llvm::sys;


/// LLVM ///
static LLVMContext TheContext;
static IRBuilder<> Builder(TheContext);
static std::unique_ptr<Module> TheModule = make_unique<Module>("START", TheContext);
static std::map<std::string, Value *> NamedValues;

class CodeGenV : public Visitor {
    // Module * module;
    // StartA * start;
    // Function * mainFunction;
    //SymbolTable symbolTable;
    StartA *currStart;
    ClassA *currClass;
    MethodA *currMethod;
    SymbolTable *currSymTab;
    int nameCase;   // decaf-semantics.pdf: page 12
public:
    void LogErrorV(const char *s) {
        cout << "XXXX error: " << s << " XXXXXXXXXXXXXXXXXXXXXXX\n";
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
