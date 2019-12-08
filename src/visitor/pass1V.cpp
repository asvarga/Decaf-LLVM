
#include "pass1V.h"

void Pass1V::visit(StrLitA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    --d;
}
void Pass1V::visit(CharLitA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    --d;
}
void Pass1V::visit(IntLitA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    --d;
}

void Pass1V::visit(BoolLitA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    --d;
}

void Pass1V::visit(NullLitA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    --d;
}

void Pass1V::visit(NameA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    --d;
}

void Pass1V::visit(TypeA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    --d;
}

void Pass1V::visit(PrimTypeA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getName()->accept(*this);
    --d;
}

void Pass1V::visit(ArrayTypeA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getType()->accept(*this);
    --d;
}

void Pass1V::visit(ClassTypeA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getName()->accept(*this);
    --d;
}

void Pass1V::visit(StatementA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    --d;
}

void Pass1V::visit(PrimaryExprA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    --d;
}

void Pass1V::visit(ExpressionA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    --d;
}

void Pass1V::visit(ListA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    deque<AST *> asts = a->getASTs();
    for (AST *a2 : asts) {
        a2->accept(*this);
    }
    --d;
}
void Pass1V::visit(StartA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    this->currStart = a;
    ++d;
    a->getList()->accept(*this);
    --d;
}

void Pass1V::visit(SuperA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getName()->accept(*this);
    --d;
}

void Pass1V::visit(ClassA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);

    this->currClass = a;
    this->currStart->addClass(a->getName()->getName(), a); 

    ++d;
    a->getName()->accept(*this);
    a->getSuperClass()->accept(*this);
    a->getMembers()->accept(*this);
    --d;
}

void Pass1V::visit(MethodBodyA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    // a->getFormalList()->accept(*this); // repeated in MethodA
    a->getStatementList()->accept(*this);
    --d;
}

void Pass1V::visit(FieldDeclA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getFieldList()->accept(*this);
    --d;
}

void Pass1V::visit(VarDeclA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getName()->accept(*this);
    a->getExpression()->accept(*this);
    --d;
}

void Pass1V::visit(FieldA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getModifers()->accept(*this);
    a->getType()->accept(*this);
    a->getVar()->accept(*this);
    --d;
}

void Pass1V::visit(ModifierA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    --d;
}

void Pass1V::visit(MethodA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);

    this->currMethod = a;
    this->currClass->addMethod(a->getName()->getName(), a); 
    a->setClass(currClass);
    if (a->getName()->getName() == "main") {
        // cout << "FOUND!" << "\n";
        currStart->setMain(a);
    }

    ++d;
    a->getName()->accept(*this);
    a->getModifiers()->accept(*this);
    a->getType()->accept(*this);
    a->getArgs()->accept(*this);
    a->getMethodBody()->accept(*this);
    --d;
}

void Pass1V::visit(ConstructorA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getType()->accept(*this);
    a->getModifers()->accept(*this);
    a->getMethodBody()->accept(*this);
    --d;
}

void Pass1V::visit(FormalA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getType()->accept(*this);
    a->getVarDecl()->accept(*this);
    --d;
}

void Pass1V::visit(DeclStatementA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getType()->accept(*this);
    a->getLocalList()->accept(*this);
    --d;
}

void Pass1V::visit(LocalA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getExpression()->accept(*this);
    --d;
}

void Pass1V::visit(IfStatementA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getExpression()->accept(*this);
    a->getStatement1()->accept(*this);
    a->getStatement2()->accept(*this);
    --d;
}
void Pass1V::visit(ExpressionStatementA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getExpression()->accept(*this);
    --d;
}

void Pass1V::visit(WhileStatementA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getExpression()->accept(*this);
    a->getStatement()->accept(*this);
    --d;
}

void Pass1V::visit(ReturnStatementA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getExpression()->accept(*this);
    --d;
}
void Pass1V::visit(ContinueStatementA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    --d;
}
void Pass1V::visit(BreakStatementA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    --d;
}

void Pass1V::visit(BlockA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getStatementList()->accept(*this);
    --d;
}

void Pass1V::visit(BlockStatementA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getBlock()->accept(*this);
    --d;
}

void Pass1V::visit(EmptyStatementA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    --d;
}

void Pass1V::visit(NewArrayA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getType()->accept(*this);
    a->getDimList()->accept(*this);
    --d;
}

void Pass1V::visit(DimensionA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    --d;
}

void Pass1V::visit(ArrayRefA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getName()->accept(*this);
    a->getExpression()->accept(*this);
    a->getDim()->accept(*this);
    --d;
}

void Pass1V::visit(PrimaryArrayA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getArray()->accept(*this);
    --d;
}

void Pass1V::visit(NonArrayPrimaryA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getExpression()->accept(*this);
    --d;
}

void Pass1V::visit(CallA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getName()->accept(*this);
    a->getExpressionList()->accept(*this);
    --d;
}

void Pass1V::visit(SuperStatementA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getArgs()->accept(*this);
    --d;
}

void Pass1V::visit(OpExpressionA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getExpression1()->accept(*this);
    a->getExpression2()->accept(*this);
    --d;
}

void Pass1V::visit(ThisExprA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    --d;
}

void Pass1V::visit(NewObjExprA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getName()->accept(*this);
    a->getExpressionList()->accept(*this);
    --d;
}

void Pass1V::visit(ThisCallExprA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
    --d;
}

void Pass1V::visit(MethodCallExprA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getType()->accept(*this);
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
    --d;
}

void Pass1V::visit(SuperCallExprA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
    --d;
}

void Pass1V::visit(FieldExprA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getType()->accept(*this);
    a->getName()->accept(*this);
    --d;
}

void Pass1V::visit(SuperFieldExprA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    a->getName()->accept(*this);
    --d;
}

void Pass1V::visit(InitializerA* a) {
    a->setParent(parent);
    parent = a;
    a->setDepth(d);
    ++d;
    --d;
}
