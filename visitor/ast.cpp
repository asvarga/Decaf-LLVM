
#include "ast.h"
#include <iostream> 
#include <vector>

using namespace std; 

/// Main ///

int main() { 
    vector<AST*> asts{
        new ClassA("Aaa"), 
        new ClassA("Bbb"), 
        new ClassA("Ccc")
    };
    ListA *list = new ListA(asts);
    StartA *start = new StartA(list);

    start->accept(*(new CounterV()));
    start->accept(*(new PrinterV()));
	return 0; 
} 

/// ASTs ///

void StartA::accept(Visitor& v) { 
    v.visit(this); 
    this->list->accept(v);
}
void ListA::accept(Visitor& v) { 
    v.visit(this); 
    // this->ast->accept(v);
    for (AST *a : this->asts) {
        a->accept(v);
    }
}
void ClassA::accept(Visitor& v) { 
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
    cout << "Visiting ClassA : " << a->getName() << "\n"; 
}

void CounterV::visit(StartA* a) { 
    cout << this->c++ << "\n"; 
}
void CounterV::visit(ListA* a) { 
    cout << this->c++ << "\n"; 
}
void CounterV::visit(ClassA* a) { 
    cout << this->c++ << "\n"; 
}
















