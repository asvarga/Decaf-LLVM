
#include <string>
#include <vector>

using namespace std;

/// Forward Declaration ///

class AST;
class StartA;
class ListA;
class ClassA;
class SuperA;
class MethodBodyA;
class FieldDeclA;
class FieldA;
class MethodA;
class ConstructorA;
class FormalA;
class DeclStatementA;
class LocalA;
class IfStatementA;
class ExpressionStatementA;
class WhileStatementA;
class ReturnStatementA;
class ContinueStatementA;
class BreakStatementA;
class BlockStatementA;
class BlockA;
class SuperStatementA;
class CallA;
class OpExpressionA;
class NewArrayA;
class ArrayRefA;

class TypeA;
class ExpressionA;
class InitializerA;
class StatementA;
class NameA;


class Visitor;
class PrinterV;
class CounterV;

/// ASTs ///

class AST {
public:
    virtual void accept(Visitor& v) = 0;
};

class StartA : public AST {
    ListA *list;
public: 
    StartA(ListA *l): list(l) {};
    ListA *getList() { return list; }
    virtual void accept(Visitor& v);
};
class ListA : public AST {
    vector<AST*> asts;
public: 
    ListA() {};
    ListA(vector<AST*> as) { asts = as; };
    virtual void accept(Visitor& v);
};
class ClassA : public AST {
    string name; 
public: 
    ClassA(string n = ""): name(n) {};
    string getName() { return name; }
    virtual void accept(Visitor& v);
};
class SuperA : public AST {
    TypeA *type; 
public: 
    SuperA(TypeA *t): type(t) {};
    TypeA *getType() { return type; };
    virtual void accept(Visitor& v);
};
class MethodBodyA : public AST {
    ListA *formalList;
    ListA *statementList; 
public: 
    MethodBodyA(ListA *fs, ListA *ss): formalList(fs), statementList(ss) {};
    ListA *getFormalList() { return formalList; };
    ListA *getStatementList() { return statementList; };
    virtual void accept(Visitor& v);
};
class FieldDeclA : public AST {
    ListA *fieldList; 
public: 
    FieldDeclA(ListA *fs): fieldList(fs) {};
    ListA *getFieldList() { return fieldList; };
    virtual void accept(Visitor& v);
};
class FieldA : public AST {
    InitializerA *initializer; 
public: 
    FieldA(InitializerA *i): initializer(i) {};
    InitializerA *getInitializer() { return initializer; };
    virtual void accept(Visitor& v);
};
class MethodA : public AST {
    TypeA *type;
    MethodBodyA *methodbody; 
public: 
    MethodA(TypeA *t, MethodBodyA *m): type(t), methodbody(m) {};
    TypeA *getType() { return type; };
    MethodBodyA *getMethodBody() { return methodbody; };
    virtual void accept(Visitor& v);
};
class ConstructorA : public AST {
    TypeA *type;
    MethodBodyA *methodbody; 
public: 
    ConstructorA(TypeA *t, MethodBodyA *m): type(t), methodbody(m) {};
    TypeA *getType() { return type; };
    MethodBodyA *getMethodBody() { return methodbody; };
    virtual void accept(Visitor& v);
};
class FormalA : public AST {
    TypeA *type; 
public: 
    FormalA(TypeA *t): type(t) {};
    TypeA *getType() { return type; };
    virtual void accept(Visitor& v);
};
class DeclStatementA : public AST {
    ListA *localList; 
public: 
    DeclStatementA(ListA *ls): localList(ls) {};
    ListA *getLocalList() { return localList; };
    virtual void accept(Visitor& v);
};
class LocalA : public AST {
    ExpressionA *expression; 
public: 
    LocalA(ExpressionA *e): expression(e) {};
    ExpressionA *getExpression() { return expression; };
    virtual void accept(Visitor& v);
};
class IfStatementA : public AST {
    ExpressionA *expression;
    StatementA *statement1;
    StatementA *statement2; 
public: 
    IfStatementA(ExpressionA *e, StatementA *s1, StatementA *s2): expression(e), statement1(s1), statement2(s2) {};
    ExpressionA *getExpression() { return expression; };
    StatementA *getStatement1() { return statement1; };
    StatementA *getStatement2() { return statement2; };
    virtual void accept(Visitor& v);
};
class ExpressionStatementA : public AST {
    ExpressionA *expression; 
public: 
    ExpressionStatementA(ExpressionA *e): expression(e) {};
    ExpressionA *getExpression() { return expression; };
    virtual void accept(Visitor& v);
};
class WhileStatementA : public AST {
    ExpressionA *expression;
    StatementA *statement; 
public: 
    WhileStatementA(ExpressionA *e, StatementA *s): expression(e), statement(s) {};
    ExpressionA *getExpression() { return expression; };
    StatementA *getStatement() { return statement; };
    virtual void accept(Visitor& v);
};
class ReturnStatementA : public AST {
    ExpressionA *expression; 
public: 
    ReturnStatementA(ExpressionA *e): expression(e) {};
    ExpressionA *getExpression() { return expression; };
    virtual void accept(Visitor& v);
};
class ContinueStatementA : public AST {
     
public: 
    ContinueStatementA() {};
    virtual void accept(Visitor& v);
};
class BreakStatementA : public AST {
     
public: 
    BreakStatementA() {};
    virtual void accept(Visitor& v);
};
class BlockStatementA : public AST {
    BlockA *block; 
public: 
    BlockStatementA(BlockA *b): block(b) {};
    BlockA *getBlock() { return block; };
    virtual void accept(Visitor& v);
};
class BlockA : public AST {
    ListA *statementList; 
public: 
    BlockA(ListA *ss): statementList(ss) {};
    ListA *getStatementList() { return statementList; };
    virtual void accept(Visitor& v);
};
class SuperStatementA : public AST {
    CallA *call; 
public: 
    SuperStatementA(CallA *c): call(c) {};
    CallA *getCall() { return call; };
    virtual void accept(Visitor& v);
};
class CallA : public AST {
    NameA *name;
    ListA *expressionList; 
public: 
    CallA(NameA *n, ListA *es): name(n), expressionList(es) {};
    NameA *getName() { return name; };
    ListA *getExpressionList() { return expressionList; };
    virtual void accept(Visitor& v);
};
class OpExpressionA : public AST {
    ExpressionA *expression1;
    ExpressionA *expression2; 
public: 
    OpExpressionA(ExpressionA *e1, ExpressionA *e2): expression1(e1), expression2(e2) {};
    ExpressionA *getExpression1() { return expression1; };
    ExpressionA *getExpression2() { return expression2; };
    virtual void accept(Visitor& v);
};
class NewArrayA : public AST {
    TypeA *type;
    ListA *expressionList; 
public: 
    NewArrayA(TypeA *t, ListA *es): type(t), expressionList(es) {};
    TypeA *getType() { return type; };
    ListA *getExpressionList() { return expressionList; };
    virtual void accept(Visitor& v);
};
class ArrayRefA : public AST {
    ExpressionA *expression1;
    ExpressionA *expression2; 
public: 
    ArrayRefA(ExpressionA *e1, ExpressionA *e2): expression1(e1), expression2(e2) {};
    ExpressionA *getExpression1() { return expression1; };
    ExpressionA *getExpression2() { return expression2; };
    virtual void accept(Visitor& v);
};

class TypeA : public AST {
public: 
    TypeA() {};
    virtual void accept(Visitor& v);
};
class ExpressionA : public AST {
public: 
    ExpressionA() {};
    virtual void accept(Visitor& v);
};
class InitializerA : public AST {
public: 
    InitializerA() {};
    virtual void accept(Visitor& v);
};
class StatementA : public AST {
public: 
    StatementA() {};
    virtual void accept(Visitor& v);
};
class NameA : public AST {
public: 
    NameA() {};
    virtual void accept(Visitor& v);
};

/// Visitors ///

class Visitor {
public:
    virtual void visit(StartA* a) = 0;
    virtual void visit(ListA* a) = 0;
    virtual void visit(ClassA* a) = 0;
    virtual void visit(SuperA* a) = 0;
    virtual void visit(MethodBodyA* a) = 0;
    virtual void visit(FieldDeclA* a) = 0;
    virtual void visit(FieldA* a) = 0;
    virtual void visit(MethodA* a) = 0;
    virtual void visit(ConstructorA* a) = 0;
    virtual void visit(FormalA* a) = 0;
    virtual void visit(DeclStatementA* a) = 0;
    virtual void visit(LocalA* a) = 0;
    virtual void visit(IfStatementA* a) = 0;
    virtual void visit(ExpressionStatementA* a) = 0;
    virtual void visit(WhileStatementA* a) = 0;
    virtual void visit(ReturnStatementA* a) = 0;
    virtual void visit(ContinueStatementA* a) = 0;
    virtual void visit(BreakStatementA* a) = 0;
    virtual void visit(BlockStatementA* a) = 0;
    virtual void visit(BlockA* a) = 0;
    virtual void visit(SuperStatementA* a) = 0;
    virtual void visit(CallA* a) = 0;
    virtual void visit(OpExpressionA* a) = 0;
    virtual void visit(NewArrayA* a) = 0;
    virtual void visit(ArrayRefA* a) = 0;

    virtual void visit(TypeA* a) = 0;
    virtual void visit(ExpressionA* a) = 0;
    virtual void visit(InitializerA* a) = 0;
    virtual void visit(StatementA* a) = 0;
    virtual void visit(NameA* a) = 0;
};

class PrinterV : public Visitor {
public: 
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

    virtual void visit(TypeA* a);
    virtual void visit(ExpressionA* a);
    virtual void visit(InitializerA* a);
    virtual void visit(StatementA* a);
    virtual void visit(NameA* a);
};

class CounterV : public Visitor {
    int c = 0;
public: 
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

    virtual void visit(TypeA* a);
    virtual void visit(ExpressionA* a);
    virtual void visit(InitializerA* a);
    virtual void visit(StatementA* a);
    virtual void visit(NameA* a);
};


