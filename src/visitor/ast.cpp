
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

void StartA::accept(Visitor& v) { 
    v.visit(this); 
    this->list->accept(v);
}
void ListA::accept(Visitor& v) { 
    v.visit(this); 
    for (AST *a : this->asts) { 
        a->accept(v); 
    }
}
void ClassA::accept(Visitor& v) { 
    v.visit(this); 
    this->members->accept(v);
}
void SuperA::accept(Visitor& v) { 
    v.visit(this);
    this->type->accept(v);
}
void MethodBodyA::accept(Visitor& v) { 
    v.visit(this);
    this->formalList->accept(v);
    this->statementList->accept(v);
}
void FieldDeclA::accept(Visitor& v) { 
    v.visit(this);
    this->fieldList->accept(v);
}
void FieldA::accept(Visitor& v) { 
    v.visit(this);
    this->initializer->accept(v);
}
void MethodA::accept(Visitor& v) { 
    v.visit(this);
    this->type->accept(v);
    this->methodbody->accept(v);
}
void ConstructorA::accept(Visitor& v) { 
    v.visit(this);
    this->type->accept(v);
    this->methodbody->accept(v);
}
void FormalA::accept(Visitor& v) { 
    v.visit(this);
    this->type->accept(v);
}
void DeclStatementA::accept(Visitor& v) { 
    v.visit(this);
    this->localList->accept(v);
}
void LocalA::accept(Visitor& v) { 
    v.visit(this);
    this->expression->accept(v);
}
void IfStatementA::accept(Visitor& v) { 
    v.visit(this);
    this->expression->accept(v);
    this->statement1->accept(v);
    this->statement2->accept(v);
}
void ExpressionStatementA::accept(Visitor& v) { 
    v.visit(this);
    this->expression->accept(v);
}
void WhileStatementA::accept(Visitor& v) { 
    v.visit(this);
    this->expression->accept(v);
    this->statement->accept(v);
}
void ReturnStatementA::accept(Visitor& v) { 
    v.visit(this);
    this->expression->accept(v);
}
void ContinueStatementA::accept(Visitor& v) { 
    v.visit(this);
}
void BreakStatementA::accept(Visitor& v) { 
    v.visit(this);
}
void BlockStatementA::accept(Visitor& v) { 
    v.visit(this);
    this->block->accept(v);
}
void BlockA::accept(Visitor& v) { 
    v.visit(this);
    this->statementList->accept(v);
}
void SuperStatementA::accept(Visitor& v) { 
    v.visit(this);
    this->call->accept(v);
}
void CallA::accept(Visitor& v) { 
    v.visit(this);
    this->name->accept(v);
    this->expressionList->accept(v);
}
void OpExpressionA::accept(Visitor& v) { 
    v.visit(this);
    this->expression1->accept(v);
    this->expression2->accept(v);
}
void NewArrayA::accept(Visitor& v) { 
    v.visit(this);
    this->type->accept(v);
    this->expressionList->accept(v);
}
void ArrayRefA::accept(Visitor& v) { 
    v.visit(this);
    this->expression1->accept(v);
    this->expression2->accept(v);
}

void PrimTypeA::accept(Visitor& v) { 
    v.visit(this);
}
void ExpressionA::accept(Visitor& v) { 
    v.visit(this);
}
void InitializerA::accept(Visitor& v) { 
    v.visit(this);
}
void StatementA::accept(Visitor& v) { 
    v.visit(this);
}
void NameA::accept(Visitor& v) { 
    v.visit(this);
}
void StrLitA::accept(Visitor& v) { 
    v.visit(this);
}

/// Visitors ///

void PrinterV::visit(StartA* a) { 
    cout << "Visiting StartA\n"; 
}
void PrinterV::visit(ListA* a) { 
    cout << "Visiting ListA\n"; 
}
void PrinterV::visit(ClassA* a) { 
    cout << "Visiting ClassA: " << a->getName() << "\n"; 
}
void PrinterV::visit(SuperA* a) { 
    cout << "Visiting SuperA\n"; 
}
void PrinterV::visit(MethodBodyA* a) { 
    cout << "Visiting MethodBodyA\n"; 
}
void PrinterV::visit(FieldDeclA* a) { 
    cout << "Visiting FieldDeclA\n"; 
}
void PrinterV::visit(FieldA* a) { 
    cout << "Visiting FieldA\n"; 
}
void PrinterV::visit(MethodA* a) { 
    cout << "Visiting MethodA: " << a->getName() << "\n"; 
}
void PrinterV::visit(ConstructorA* a) { 
    cout << "Visiting ConstructorA\n"; 
}
void PrinterV::visit(FormalA* a) { 
    cout << "Visiting FormalA\n"; 
}
void PrinterV::visit(DeclStatementA* a) { 
    cout << "Visiting DeclStatementA\n"; 
}
void PrinterV::visit(LocalA* a) { 
    cout << "Visiting LocalA\n"; 
}
void PrinterV::visit(IfStatementA* a) { 
    cout << "Visiting IfStatementA\n"; 
}
void PrinterV::visit(ExpressionStatementA* a) { 
    cout << "Visiting ExpressionStatementA\n"; 
}
void PrinterV::visit(WhileStatementA* a) { 
    cout << "Visiting WhileStatementA\n"; 
}
void PrinterV::visit(ReturnStatementA* a) { 
    cout << "Visiting ReturnStatementA\n"; 
}
void PrinterV::visit(ContinueStatementA* a) { 
    cout << "Visiting ContinueStatementA\n"; 
}
void PrinterV::visit(BreakStatementA* a) { 
    cout << "Visiting BreakStatementA\n"; 
}
void PrinterV::visit(BlockStatementA* a) { 
    cout << "Visiting BlockStatementA\n"; 
}
void PrinterV::visit(BlockA* a) { 
    cout << "Visiting BlockA\n"; 
}
void PrinterV::visit(SuperStatementA* a) { 
    cout << "Visiting SuperStatementA\n"; 
}
void PrinterV::visit(CallA* a) { 
    cout << "Visiting CallA\n"; 
}
void PrinterV::visit(OpExpressionA* a) { 
    cout << "Visiting OpExpressionA\n"; 
}
void PrinterV::visit(NewArrayA* a) { 
    cout << "Visiting NewArrayA\n"; 
}
void PrinterV::visit(ArrayRefA* a) { 
    cout << "Visiting ArrayRefA\n"; 
}

void PrinterV::visit(PrimTypeA* a) { 
    cout << "Visiting PrimTypeA\n"; 
}
void PrinterV::visit(ExpressionA* a) { 
    cout << "Visiting ExpressionA\n"; 
}
void PrinterV::visit(InitializerA* a) { 
    cout << "Visiting InitializerA\n"; 
}
void PrinterV::visit(StatementA* a) { 
    cout << "Visiting StatementA\n"; 
}
void PrinterV::visit(NameA* a) { 
    cout << "Visiting NameA\n"; 
}
void PrinterV::visit(StrLitA* a) { 
    cout << "Visiting StrLitA: " << a->getValue() << "\n"; 
}




void CounterV::visit(StartA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(ListA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(ClassA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(SuperA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(MethodBodyA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(FieldDeclA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(FieldA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(MethodA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(ConstructorA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(FormalA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(DeclStatementA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(LocalA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(IfStatementA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(ExpressionStatementA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(WhileStatementA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(ReturnStatementA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(ContinueStatementA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(BreakStatementA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(BlockStatementA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(BlockA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(SuperStatementA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(CallA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(OpExpressionA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(NewArrayA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(ArrayRefA* a) { cout << this->c++ << "\n"; }

void CounterV::visit(PrimTypeA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(ExpressionA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(InitializerA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(StatementA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(NameA* a) { cout << this->c++ << "\n"; }
void CounterV::visit(StrLitA* a) { cout << this->c++ << "\n"; }













