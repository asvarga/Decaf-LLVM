
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

void PrimTypeA::accept(Visitor& v) { v.visit(this); }
void ArrayTypeA::accept(Visitor& v) { v.visit(this); }
void ClassTypeA::accept(Visitor& v) { v.visit(this); }

void ExpressionA::accept(Visitor& v) { v.visit(this); }
void InitializerA::accept(Visitor& v) { v.visit(this); }
void StatementA::accept(Visitor& v) { v.visit(this); }
void NameA::accept(Visitor& v) { v.visit(this); }
void StrLitA::accept(Visitor& v) { v.visit(this); }

/// Visitors ///

void PrinterV::visit(StartA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "StartA\n"; 
    this->d++;
    a->getList()->accept(*this);
    this->d--;
}
void PrinterV::visit(ListA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "ListA\n"; 
    this->d++;
    deque<AST *> asts = a->getASTs();
    for (AST *a2 : asts) { 
        a2->accept(*this); 
    }
    this->d--;
}
void PrinterV::visit(ClassA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "ClassA: " << a->getName() << "\n"; 
    this->d++;
    a->getMembers()->accept(*this);
    this->d--;
}
void PrinterV::visit(SuperA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "SuperA\n"; 
    this->d++;
    a->getType()->accept(*this);
    this->d--;
}
void PrinterV::visit(MethodBodyA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "MethodBodyA\n"; 
    this->d++;
    a->getFormalList()->accept(*this);
    a->getStatementList()->accept(*this);
    this->d--;
}
void PrinterV::visit(FieldDeclA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "FieldDeclA\n"; 
    this->d++;
    a->getFieldList()->accept(*this);
    this->d--;
}
void PrinterV::visit(FieldA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "FieldA\n"; 
    this->d++;
    a->getInitializer()->accept(*this);
    this->d--;
}
void PrinterV::visit(MethodA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "MethodA: " << a->getName() << "\n"; 
    this->d++;
    a->getModifiers()->accept(*this);
    a->getType()->accept(*this);
    a->getArgs()->accept(*this);
    a->getMethodBody()->accept(*this);
    this->d--;
}
void PrinterV::visit(ConstructorA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "ConstructorA\n"; 
    this->d++;
    a->getType()->accept(*this);
    a->getMethodBody()->accept(*this);
    this->d--;
}
void PrinterV::visit(FormalA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "FormalA: " << a->getName() << "\n"; 
    this->d++;
    a->getType()->accept(*this);
    this->d--;
}
void PrinterV::visit(DeclStatementA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "DeclStatementA\n"; 
    this->d++;
    a->getLocalList()->accept(*this);
    this->d--;
}
void PrinterV::visit(LocalA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "LocalA\n"; 
    this->d++;
    a->getExpression()->accept(*this);
    this->d--;
}
void PrinterV::visit(IfStatementA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "IfStatementA\n"; 
    this->d++;
    a->getExpression()->accept(*this);
    a->getStatement1()->accept(*this);
    a->getStatement2()->accept(*this);
    this->d--;
}
void PrinterV::visit(ExpressionStatementA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "ExpressionStatementA\n"; 
    this->d++;
    a->getExpression()->accept(*this);
    this->d--;
}
void PrinterV::visit(WhileStatementA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "WhileStatementA\n"; 
    this->d++;
    a->getExpression()->accept(*this);
    a->getStatement()->accept(*this);
    this->d--;
}
void PrinterV::visit(ReturnStatementA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "ReturnStatementA\n"; 
    this->d++;
    a->getExpression()->accept(*this);
    this->d--;
}
void PrinterV::visit(ContinueStatementA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "ContinueStatementA\n"; 
    this->d++;
    this->d--;
}
void PrinterV::visit(BreakStatementA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "BreakStatementA\n"; 
    this->d++;
    this->d--;
}
void PrinterV::visit(BlockStatementA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "BlockStatementA\n"; 
    this->d++;
    a->getBlock()->accept(*this);
    this->d--;
}
void PrinterV::visit(BlockA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "BlockA\n"; 
    this->d++;
    a->getStatementList()->accept(*this);
    this->d--;
}
void PrinterV::visit(SuperStatementA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "SuperStatementA\n"; 
    this->d++;
    a->getCall()->accept(*this);
    this->d--;
}
void PrinterV::visit(CallA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "CallA: " << a->getName() << "\n"; 
    this->d++;
    a->getExpressionList()->accept(*this);
    this->d--;
}
void PrinterV::visit(OpExpressionA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "OpExpressionA\n"; 
    this->d++;
    a->getExpression1()->accept(*this);
    a->getExpression2()->accept(*this);
    this->d--;
}
void PrinterV::visit(NewArrayA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "NewArrayA\n"; 
    this->d++;
    a->getType()->accept(*this);
    a->getExpressionList()->accept(*this);
    this->d--;
}
void PrinterV::visit(ArrayRefA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "ArrayRefA\n"; 
    this->d++;
    a->getExpression1()->accept(*this);
    a->getExpression2()->accept(*this);
    this->d--;
}

void PrinterV::visit(PrimTypeA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "PrimTypeA: " << a->getName() << "\n"; 
    this->d++;
    this->d--;
}
void PrinterV::visit(ArrayTypeA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "ArrayTypeA: " << a->getType();
    int c = a->getDim();
    for (int i=0; i<c; i++) { cout << "[]"; } 
    cout << "\n"; 
    this->d++;
    this->d--;
}
void PrinterV::visit(ClassTypeA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "ClassTypeA: " << a->getName() << "\n"; 
    this->d++;
    this->d--;
}

void PrinterV::visit(ExpressionA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "ExpressionA\n"; 
    this->d++;
    this->d--;
}
void PrinterV::visit(InitializerA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "InitializerA\n"; 
    this->d++;
    this->d--;
}
void PrinterV::visit(StatementA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "StatementA\n"; 
    this->d++;
    this->d--;
}
void PrinterV::visit(NameA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "NameA\n"; 
    this->d++;
    this->d--;
}
void PrinterV::visit(StrLitA* a) { 
    int d = this->d; for (int i=0; i<d; i++) { cout << "  "; }
    cout << "StrLitA: " << a->getValue() << "\n"; 
    this->d++;
    this->d--;
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













