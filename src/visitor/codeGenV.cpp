
#include "codeGenV.h"

void CodeGenV::visit(StrLitA* a) {
    cout << "StrLitA: " << a->getValue() << "\n";
}
void CodeGenV::visit(CharLitA* a) {
    cout << "CharLitA: " << a->getValue() << endl ;
}
void CodeGenV::visit(IntLitA* a) {
    cout << "IntLitA: " << a->getValue() << "\n";
}

void CodeGenV::visit(BoolLitA* a) {
    cout << "BoolLitA: " << a->getValue() << endl;
}

void CodeGenV::visit(NullLitA* a) {
    cout << "NullLitA\n";
}

void CodeGenV::visit(NameA* a) {
    cout << "NameA" << a->getName() << endl;
}

void CodeGenV::visit(TypeA* a) {
    cout << "TypeA" << "\n";
}

void CodeGenV::visit(PrimTypeA* a) {
    cout << "PrimTypeA" << "\n";
    a->getName()->accept(*this);
}

void CodeGenV::visit(ArrayTypeA* a) {
    cout << "ArrayTypeA: dim " << a->getDim() << "\n";
    a->getType()->accept(*this);
}

void CodeGenV::visit(ClassTypeA* a) {
    cout << "ClassTypeA: " << a->getName() << "\n";
    a->getName()->accept(*this);
}

void CodeGenV::visit(StatementA* a) {
    cout << "StatementA\n";
}

void CodeGenV::visit(PrimaryExprA* a) {
    cout << "PrimaryExprA\n";
}

void CodeGenV::visit(ExpressionA* a) {
    cout << "ExpressionA\n";
}

void CodeGenV::visit(ListA* a) {
    cout << "ListA\n";
    deque<AST *> asts = a->getASTs();
    for (AST *a2 : asts) {
        a2->accept(*this);
    }
}
void CodeGenV::visit(StartA* a) {
    cout << "StartA\n";
    a->getList()->accept(*this);
}

void CodeGenV::visit(SuperA* a) {
    cout << "SuperA\n";
    a->getName()->accept(*this);
}

void CodeGenV::visit(ClassA* a) {
    cout << "ClassA\n" ;
    a->getName()->accept(*this);
    a->getSuperClass()->accept(*this);
    a->getMembers()->accept(*this);
}

void CodeGenV::visit(MethodBodyA* a) {
    cout << "MethodBodyA\n";
    // a->getFormalList()->accept(*this); // repeated in MethodA
    a->getStatementList()->accept(*this);
}

void CodeGenV::visit(FieldDeclA* a) {
    cout << "FieldDeclA\n";
    a->getFieldList()->accept(*this);
}

void CodeGenV::visit(VarDeclA* a) {
    cout << "VarDeclA\n";
    a->getName()->accept(*this);
    a->getExpression()->accept(*this);
}

void CodeGenV::visit(FieldA* a) {
    cout << "FieldA\n";
    a->getModifers()->accept(*this);
    a->getType()->accept(*this);
    a->getVar()->accept(*this);
}

void CodeGenV::visit(ModifierA* a) {
    cout << "ModifierA" << a->getModifier() << endl;
}

void CodeGenV::visit(MethodA* a) {
    cout << "MethodA\n";
    a->getName()->accept(*this);
    a->getModifiers()->accept(*this);
    a->getType()->accept(*this);
    a->getArgs()->accept(*this);
    a->getMethodBody()->accept(*this);
}

void CodeGenV::visit(ConstructorA* a) {
    cout << "ConstructorA\n";
    a->getType()->accept(*this);
    a->getModifers()->accept(*this);
    a->getMethodBody()->accept(*this);
}

void CodeGenV::visit(FormalA* a) {
    cout << "FormalA\n";
    a->getType()->accept(*this);
    a->getVarDecl()->accept(*this);
}

void CodeGenV::visit(DeclStatementA* a) {
    cout << "DeclStatementA\n";
    a->getType()->accept(*this);
    a->getLocalList()->accept(*this);
}

void CodeGenV::visit(LocalA* a) {
    cout << "LocalA\n";
    a->getExpression()->accept(*this);
}

void CodeGenV::visit(IfStatementA* a) {
    cout << "IfStatementA\n";
    a->getExpression()->accept(*this);
    a->getStatement1()->accept(*this);
    a->getStatement2()->accept(*this);
}
void CodeGenV::visit(ExpressionStatementA* a) {
    cout << "ExpressionStatementA\n";
    a->getExpression()->accept(*this);
}

void CodeGenV::visit(WhileStatementA* a) {
    cout << "WhileStatementA\n";
    a->getExpression()->accept(*this);
    a->getStatement()->accept(*this);
}

void CodeGenV::visit(ReturnStatementA* a) {
    cout << "ReturnStatementA\n";
    a->getExpression()->accept(*this);
}
void CodeGenV::visit(ContinueStatementA* a) {
    cout << "ContinueStatementA\n";
}
void CodeGenV::visit(BreakStatementA* a) {
    cout << "BreakStatementA\n";
}

void CodeGenV::visit(BlockA* a) {
    cout << "BlockA\n";
    a->getStatementList()->accept(*this);
}

void CodeGenV::visit(BlockStatementA* a) {
    cout << "BlockStatementA\n";
    a->getBlock()->accept(*this);
}

void CodeGenV::visit(EmptyStatementA* a) {
    cout << "EmptyStatementA\n";
}

void CodeGenV::visit(NewArrayA* a) {
    cout << "NewArrayA\n";
    a->getType()->accept(*this);
    a->getDimList()->accept(*this);
}

void CodeGenV::visit(DimensionA* a) {
    cout << "DimensionA" << a->getDim() << endl;
}

void CodeGenV::visit(ArrayRefA* a) {
    cout << "ArrayRefA\n";
    a->getName()->accept(*this);
    a->getExpression()->accept(*this);
    a->getDim()->accept(*this);
}

void CodeGenV::visit(PrimaryArrayA* a) {
    cout << "PrimaryArrayA\n";
    a->getArray()->accept(*this);
}

void CodeGenV::visit(NonArrayPrimaryA* a) {
    cout << "NonArrayPrimaryA\n";
    a->getExpression()->accept(*this);
}

void CodeGenV::visit(CallA* a) {
    cout << "CallA: " << a->getName() << "\n";
    a->getName()->accept(*this);
    a->getExpressionList()->accept(*this);
}

void CodeGenV::visit(SuperStatementA* a) {
    cout << "SuperStatementA\n";
    a->getArgs()->accept(*this);
}

void CodeGenV::visit(OpExpressionA* a) {
    cout << "OpExpressionA: " << a->getOp() << " (" << a->getArity() << ")\n";
    a->getExpression1()->accept(*this);
    a->getExpression2()->accept(*this);
}

void CodeGenV::visit(ThisExprA* a) {
    cout << "ThisExprA\n";
}

void CodeGenV::visit(NewObjExprA* a) {
    cout << "NewObjExprA\n";
    a->getName()->accept(*this);
    a->getExpressionList()->accept(*this);
}

void CodeGenV::visit(ThisCallExprA* a) {
    cout << "ThisCallExprA\n";
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
}

void CodeGenV::visit(MethodCallExprA* a) {
    cout << "MethodCallExprA\n";
    a->getType()->accept(*this);
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
}

void CodeGenV::visit(SuperCallExprA* a) {
    cout << "SuperCallExprA\n";
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
}

void CodeGenV::visit(FieldExprA* a) {
    cout << "FieldExprA\n";
    a->getType()->accept(*this);
    a->getName()->accept(*this);
}

void CodeGenV::visit(SuperFieldExprA* a) {
    cout << "SuperFieldExprA\n";
    a->getName()->accept(*this);
}

void CodeGenV::visit(InitializerA* a) {
    cout << "InitializerA\n";
}
