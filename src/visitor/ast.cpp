
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

void TypeA::accept(Visitor& v) { v.visit(this); }
void PrimTypeA::accept(Visitor& v) { v.visit(this); }
void ArrayTypeA::accept(Visitor& v) { v.visit(this); }
void ClassTypeA::accept(Visitor& v) { v.visit(this); }

void PrimaryExprA::accept(Visitor& v) { v.visit(this); }
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

