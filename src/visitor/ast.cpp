
#include "ast.h"
#include <iostream>
#include <vector>

using namespace std;

/// Main ///

// int main() {
//     vector<AST*> asts{
//         new ClassA("Aaa"),
//         new ClassA("Bbb"),
//         new ClassA("Ccc")
//     };
//     ListA *list = new ListA(asts);
//     StartA *start = new StartA(list);

//     start->accept(*(new CounterV()));
//     start->accept(*(new PrinterV()));
// 	return 0;
// }

/// ASTs ///

void StartA::accept(Visitor& v) { v.visit(this); }
void ListA::accept(Visitor& v) { v.visit(this); }
void ClassA::accept(Visitor& v) { v.visit(this); }
void SuperA::accept(Visitor& v) { v.visit(this); }
void MethodBodyA::accept(Visitor& v) { v.visit(this); }
void FieldDeclA::accept(Visitor& v) { v.visit(this); }
void FieldA::accept(Visitor& v) { v.visit(this); }
void MethodA::accept(Visitor& v) { v.visit(this); }
void ConstructorA::accept(Visitor& v) { v.visit(this); }
void FormalA::accept(Visitor& v) { v.visit(this); }
void DeclStatementA::accept(Visitor& v) { v.visit(this); }
void LocalA::accept(Visitor& v) { v.visit(this); }
void IfStatementA::accept(Visitor& v) { v.visit(this); }
void ExpressionStatementA::accept(Visitor& v) { v.visit(this); }
void WhileStatementA::accept(Visitor& v) { v.visit(this); }
void ReturnStatementA::accept(Visitor& v) { v.visit(this); }
void ContinueStatementA::accept(Visitor& v) { v.visit(this); }
void BreakStatementA::accept(Visitor& v) { v.visit(this); }
void BlockStatementA::accept(Visitor& v) { v.visit(this); }
void BlockA::accept(Visitor& v) { v.visit(this); }
void SuperStatementA::accept(Visitor& v) { v.visit(this); }
void CallA::accept(Visitor& v) { v.visit(this); }
void OpExpressionA::accept(Visitor& v) { v.visit(this); }
void NewArrayA::accept(Visitor& v) { v.visit(this); }
void ArrayRefA::accept(Visitor& v) { v.visit(this); }
void VarDeclA::accept(Visitor& v) { v.visit(this); }

void PrimTypeA::accept(Visitor& v) { v.visit(this); }
void ArrayTypeA::accept(Visitor& v) { v.visit(this); }
void ClassTypeA::accept(Visitor& v) { v.visit(this); }

void ExpressionA::accept(Visitor& v) { v.visit(this); }
void InitializerA::accept(Visitor& v) { v.visit(this); }
void StatementA::accept(Visitor& v) { v.visit(this); }
void NameA::accept(Visitor& v) { v.visit(this); }
void StrLitA::accept(Visitor& v) { v.visit(this); }
void IntLitA::accept(Visitor& v) { v.visit(this); }

void DimensionA::accept(Visitor& v) { v.visit(this); }
void FieldExprA::accept(Visitor& v) { v.visit(this); }
void NewObjExprA::accept(Visitor& v) { v.visit(this); }
void PrimaryArrayA::accept(Visitor& v) { v.visit(this); }
void ThisCallExprA::accept(Visitor& v) { v.visit(this); }
void SuperCallExprA::accept(Visitor& v) { v.visit(this); }
void EmptyStatementA::accept(Visitor& v) { v.visit(this); }
void MethodCallExprA::accept(Visitor& v) { v.visit(this); }
void SuperFieldExprA::accept(Visitor& v) { v.visit(this); }
void NonArrayPrimaryA::accept(Visitor& v) { v.visit(this); }
void BoolLitA::accept(Visitor& v) { v.visit(this); }
void CharLitA::accept(Visitor& v) { v.visit(this); }
void NullLitA::accept(Visitor& v) { v.visit(this); }
void ModifierA::accept(Visitor& v) { v.visit(this); }
void ThisExprA::accept(Visitor& v) { v.visit(this); }

/// Visitors ///

void PrinterV::visit(StartA* a) {
    indent();
    cout << "StartA\n";
    ++d;
    a->getList()->accept(*this);
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
void PrinterV::visit(ClassA* a) {
    indent();
    cout << "ClassA: " << a->getName()->getName() << "\n";
    ++d;
    a->getMembers()->accept(*this);
    --d;
}
void PrinterV::visit(SuperA* a) {
    indent();
    cout << "SuperA\n";
    ++d;
    a->getType()->accept(*this);
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
void PrinterV::visit(FieldA* a) {
    indent();
    cout << "FieldA\n";
    ++d;
    a->getModifers()->accept(*this);
    a->getType()->accept(*this);
    a->getVar()->accept(*this);
    --d;
}
void PrinterV::visit(MethodA* a) {
    indent();
    cout << "MethodA: " << a->getName() << "\n";
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
    a->getStatement2()->accept(*this);
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
void PrinterV::visit(BlockStatementA* a) {
    indent();
    cout << "BlockStatementA\n";
    ++d;
    a->getBlock()->accept(*this);
    --d;
}
void PrinterV::visit(BlockA* a) {
    indent();
    cout << "BlockA\n";
    ++d;
    a->getStatementList()->accept(*this);
    --d;
}
void PrinterV::visit(SuperStatementA* a) {
    indent();
    cout << "SuperStatementA\n";
    ++d;
    a->getArgs()->accept(*this);
    --d;
}
void PrinterV::visit(CallA* a) {
    indent();
    cout << "CallA: " << a->getName() << "\n";
    ++d;
    a->getExpressionList()->accept(*this);
    --d;
}
void PrinterV::visit(OpExpressionA* a) {
    indent();
    cout << "OpExpressionA: " << a->getOp() << "(" << a->getArity() << ")\n";
    ++d;
    a->getExpression1()->accept(*this);
    a->getExpression2()->accept(*this);
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
void PrinterV::visit(ArrayRefA* a) {
    indent();
    cout << "ArrayRefA\n";
    ++d;
    a->getExpression()->accept(*this);
    --d;
}

void PrinterV::visit(PrimTypeA* a) {
    indent();
    cout << "PrimTypeA: " << a->getName()->getName() << "\n";
    ++d;
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
    --d;
}
void PrinterV::visit(VarDeclA* a) {
    indent();
    cout << "VarDeclA: " << a->getName() << "\n";
    ++d;
    a->getExpression()->accept(*this);
    --d;
}

void PrinterV::visit(ExpressionA* a) {
    indent();
    cout << "ExpressionA\n";
    ++d;
    --d;
}
void PrinterV::visit(InitializerA* a) {
    indent();
    cout << "InitializerA\n";
    ++d;
    --d;
}
void PrinterV::visit(StatementA* a) {
    indent();
    cout << "StatementA\n";
    ++d;
    --d;
}
void PrinterV::visit(NameA* a) {
    indent();
    cout << "NameA\n";
    ++d;
    --d;
}
void PrinterV::visit(StrLitA* a) {
    indent();
    cout << "StrLitA: " << a->getValue() << "\n";
    ++d;
    --d;
}
void PrinterV::visit(IntLitA* a) {
    indent();
    cout << "IntLitA: " << a->getValue() << "\n";
    ++d;
    --d;
}



void PrinterV::visit(DimensionA* a) {
    indent();
    cout << "DimensionA\n";
    ++d;
    --d;
}
void PrinterV::visit(FieldExprA* a) {
    indent();
    cout << "FieldExprA\n";
    ++d;
    --d;
}
void PrinterV::visit(NewObjExprA* a) {
    indent();
    cout << "NewObjExprA\n";
    ++d;
    --d;
}
void PrinterV::visit(PrimaryArrayA* a) {
    indent();
    cout << "PrimaryArrayA\n";
    ++d;
    --d;
}
void PrinterV::visit(ThisCallExprA* a) {
    indent();
    cout << "ThisCallExprA\n";
    ++d;
    --d;
}
void PrinterV::visit(SuperCallExprA* a) {
    indent();
    cout << "SuperCallExprA\n";
    ++d;
    --d;
}
void PrinterV::visit(EmptyStatementA* a) {
    indent();
    cout << "EmptyStatementA\n";
    ++d;
    --d;
}
void PrinterV::visit(MethodCallExprA* a) {
    indent();
    cout << "MethodCallExprA\n";
    ++d;
    --d;
}
void PrinterV::visit(SuperFieldExprA* a) {
    indent();
    cout << "SuperFieldExprA\n";
    ++d;
    --d;
}
void PrinterV::visit(NonArrayPrimaryA* a) {
    indent();
    cout << "NonArrayPrimaryA\n";
    ++d;
    --d;
}
void PrinterV::visit(BoolLitA* a) {
    indent();
    cout << "BoolLitA\n";
    ++d;
    --d;
}
void PrinterV::visit(CharLitA* a) {
    indent();
    cout << "CharLitA\n";
    ++d;
    --d;
}
void PrinterV::visit(NullLitA* a) {
    indent();
    cout << "NullLitA\n";
    ++d;
    --d;
}
void PrinterV::visit(ModifierA* a) {
    indent();
    cout << "ModifierA\n";
    ++d;
    --d;
}
void PrinterV::visit(ThisExprA* a) {
    indent();
    cout << "ThisExprA\n";
    ++d;
    --d;
}



// void CounterV::visit(StartA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(ListA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(ClassA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(SuperA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(MethodBodyA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(FieldDeclA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(FieldA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(MethodA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(ConstructorA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(FormalA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(DeclStatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(LocalA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(IfStatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(ExpressionStatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(WhileStatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(ReturnStatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(ContinueStatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(BreakStatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(BlockStatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(BlockA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(SuperStatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(CallA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(OpExpressionA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(NewArrayA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(ArrayRefA* a) { cout << this->c++ << "\n"; }

// void CounterV::visit(PrimTypeA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(ArrayTypeA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(ClassTypeA* a) { cout << this->c++ << "\n"; }

// void CounterV::visit(ExpressionA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(InitializerA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(StatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(NameA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(StrLitA* a) { cout << this->c++ << "\n"; }
