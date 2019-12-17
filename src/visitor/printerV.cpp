
#include "printerV.h"

void PrinterV::visit(StrLitA* a) {
    indent();
    cout << "StrLitA: " << a->getValue() << "\n";
    ++d;
    --d;
}
void PrinterV::visit(CharLitA* a) {
    indent();
    cout << "CharLitA: " << a->getValue() << endl ;
    ++d;
    --d;
}
void PrinterV::visit(IntLitA* a) {
    indent();
    cout << "IntLitA: " << a->getValue() << "\n";
    ++d;
    --d;
}

void PrinterV::visit(BoolLitA* a) {
    indent();
    cout << "BoolLitA: " << a->getValue() << endl;
    ++d;
    --d;
}

void PrinterV::visit(NullLitA* a) {
    indent();
    cout << "NullLitA\n";
    ++d;
    --d;
}

void PrinterV::visit(NameA* a) {
    indent();
    cout << "NameA: " << a->getName() << endl;
    ++d;
    --d;
}

void PrinterV::visit(TypeA* a) {
    indent();
    cout << "TypeA" << "\n";
    ++d;
    --d;
}

void PrinterV::visit(PrimTypeA* a) {
    indent();
    cout << "PrimTypeA" << "\n";
    ++d;
    a->getName()->accept(*this);
    --d;
}

void PrinterV::visit(ArrayTypeA* a) {
    indent();
    cout << "ArrayTypeA: dim " << a->getDim() << "\n";
    ++d;
    a->getType()->accept(*this);
    --d;
}

void PrinterV::visit(ClassTypeA* a) {
    indent();
    cout << "ClassTypeA: " << a->getName() << "\n";
    ++d;
    a->getName()->accept(*this);
    --d;
}

void PrinterV::visit(StatementA* a) {
    indent();
    cout << "StatementA\n";
    ++d;
    --d;
}

void PrinterV::visit(PrimaryExprA* a) {
    indent();
    cout << "PrimaryExprA\n";
    ++d;
    --d;
}

void PrinterV::visit(ExpressionA* a) {
    indent();
    cout << "ExpressionA\n";
    ++d;
    --d;
}

void PrinterV::visit(ListA* a) {
    indent();
    cout << "ListA\n";
    ++d;
    deque<AST *> asts = a->getASTs();
    for (AST *a2 : asts) {
        a2->accept(*this);
    }
    --d;
}
void PrinterV::visit(StartA* a) {
    indent();
    cout << "StartA\n";
    ++d;
    a->getList()->accept(*this);
    --d;
}

void PrinterV::visit(SuperA* a) {
    indent();
    cout << "SuperA: " << a->getName() <<  "\n";
    ++d;
    --d;
}

void PrinterV::visit(ClassA* a) {
    indent();
    cout << "ClassA: " << a->getName() << "\n" ;
    ++d;
    a->getSuperClass()->accept(*this);
    a->getMembers()->accept(*this);
    --d;
}

void PrinterV::visit(MethodBodyA* a) {
    indent();
    cout << "MethodBodyA\n";
    ++d;
    // a->getFormalList()->accept(*this); // repeated in MethodA
    a->getStatementList()->accept(*this);
    --d;
}

void PrinterV::visit(FieldDeclA* a) {
    indent();
    cout << "FieldDeclA\n";
    ++d;
    a->getFieldList()->accept(*this);
    --d;
}

void PrinterV::visit(VarDeclA* a) {
    indent();
    cout << "VarDeclA: " << a->getName() << endl;
    ++d;
    a->getExpression()->accept(*this);
    --d;
}

void PrinterV::visit(FieldA* a) {
    indent();
    cout << "FieldA\n";
    ++d;
    a->getModifers()->accept(*this);
    a->getType()->accept(*this);
    a->getVar()->accept(*this);
    --d;
}

void PrinterV::visit(ModifierA* a) {
    indent();
    cout << "ModifierA" << a->getModifier() << endl;
    ++d;
    --d;
}

void PrinterV::visit(MethodA* a) {
    indent();
    cout << "MethodA: " << a->getName() << endl;
    ++d;
    a->getModifiers()->accept(*this);
    a->getType()->accept(*this);
    a->getArgs()->accept(*this);
    a->getMethodBody()->accept(*this);
    --d;
}

void PrinterV::visit(ConstructorA* a) {
    indent();
    cout << "ConstructorA\n";
    ++d;
    a->getType()->accept(*this);
    a->getModifers()->accept(*this);
    a->getMethodBody()->accept(*this);
    --d;
}

void PrinterV::visit(FormalA* a) {
    indent();
    cout << "FormalA: " << a->getName() << "\n";
    ++d;
    a->getType()->accept(*this);
    --d;
}

void PrinterV::visit(DeclStatementA* a) {
    indent();
    cout << "DeclStatementA\n";
    ++d;
    a->getType()->accept(*this);
    a->getLocalList()->accept(*this);
    --d;
}

void PrinterV::visit(LocalA* a) {
    indent();
    cout << "LocalA\n";
    ++d;
    a->getExpression()->accept(*this);
    --d;
}

void PrinterV::visit(IfStatementA* a) {
    indent();
    cout << "IfStatementA\n";
    ++d;
    a->getExpression()->accept(*this);
    a->getStatement1()->accept(*this);
    if (a->getStatement2() != nullptr) {
        a->getStatement2()->accept(*this);
    }
    --d;
}
void PrinterV::visit(ExpressionStatementA* a) {
    indent();
    cout << "ExpressionStatementA\n";
    ++d;
    a->getExpression()->accept(*this);
    --d;
}

void PrinterV::visit(WhileStatementA* a) {
    indent();
    cout << "WhileStatementA\n";
    ++d;
    a->getExpression()->accept(*this);
    a->getStatement()->accept(*this);
    --d;
}

void PrinterV::visit(ReturnStatementA* a) {
    indent();
    cout << "ReturnStatementA\n";
    ++d;
    a->getExpression()->accept(*this);
    --d;
}
void PrinterV::visit(ContinueStatementA* a) {
    indent();
    cout << "ContinueStatementA\n";
    ++d;
    --d;
}
void PrinterV::visit(BreakStatementA* a) {
    indent();
    cout << "BreakStatementA\n";
    ++d;
    --d;
}

void PrinterV::visit(BlockA* a) {
    indent();
    cout << "BlockA\n";
    ++d;
    a->getStatementList()->accept(*this);
    --d;
}

void PrinterV::visit(BlockStatementA* a) {
    indent();
    cout << "BlockStatementA\n";
    ++d;
    a->getBlock()->accept(*this);
    --d;
}

void PrinterV::visit(EmptyStatementA* a) {
    indent();
    cout << "EmptyStatementA\n";
    ++d;
    --d;
}

void PrinterV::visit(NewArrayA* a) {
    indent();
    cout << "NewArrayA\n";
    ++d;
    a->getType()->accept(*this);
    a->getDimList()->accept(*this);
    --d;
}

void PrinterV::visit(DimensionA* a) {
    indent();
    cout << "DimensionA" << a->getDim() << endl;
    ++d;
    --d;
}

void PrinterV::visit(ArrayRefA* a) {
    indent();
    cout << "ArrayRefA\n";
    ++d;
    a->getName()->accept(*this);
    a->getExpression()->accept(*this);
    a->getDim()->accept(*this);
    --d;
}

void PrinterV::visit(PrimaryArrayA* a) {
    indent();
    cout << "PrimaryArrayA\n";
    ++d;
    a->getArray()->accept(*this);
    --d;
}

void PrinterV::visit(NonArrayPrimaryA* a) {
    indent();
    cout << "NonArrayPrimaryA\n";
    ++d;
    a->getExpression()->accept(*this);
    --d;
}

void PrinterV::visit(CallA* a) {
    indent();
    cout << "CallA: " << a->getName() << "\n";
    ++d;
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
    --d;
}

void PrinterV::visit(SuperStatementA* a) {
    indent();
    cout << "SuperStatementA\n";
    ++d;
    a->getArgs()->accept(*this);
    --d;
}

void PrinterV::visit(OpExpressionA* a) {
    indent();
    cout << "OpExpressionA: " << a->getOp() << " (" << a->getArity() << ")\n";
    ++d;
    a->getExpression1()->accept(*this);
    a->getExpression2()->accept(*this);
    --d;
}

void PrinterV::visit(ThisExprA* a) {
    indent();
    cout << "ThisExprA\n";
    ++d;
    --d;
}

void PrinterV::visit(NewObjExprA* a) {
    indent();
    cout << "NewObjExprA\n";
    ++d;
    a->getName()->accept(*this);
    a->getExpressionList()->accept(*this);
    --d;
}

void PrinterV::visit(ThisCallExprA* a) {
    indent();
    cout << "ThisCallExprA\n";
    ++d;
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
    --d;
}

void PrinterV::visit(MethodCallExprA* a) {
    indent();
    cout << "MethodCallExprA\n";
    ++d;
    a->getType()->accept(*this);
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
    --d;
}

void PrinterV::visit(SuperCallExprA* a) {
    indent();
    cout << "SuperCallExprA\n";
    ++d;
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
    --d;
}

void PrinterV::visit(FieldExprA* a) {
    indent();
    cout << "FieldExprA\n";
    ++d;
    a->getType()->accept(*this);
    a->getName()->accept(*this);
    --d;
}

void PrinterV::visit(SuperFieldExprA* a) {
    indent();
    cout << "SuperFieldExprA\n";
    ++d;
    a->getName()->accept(*this);
    --d;
}

void PrinterV::visit(InitializerA* a) {
    indent();
    cout << "InitializerA\n";
    ++d;
    --d;
}

void PrinterV::visit(AssignmentA* a) {
    indent();
    cout << "AssignmentA\n";
    ++d;
    a->getLHS()->accept(*this);
    a->getRHS()->accept(*this);
    --d;
}
