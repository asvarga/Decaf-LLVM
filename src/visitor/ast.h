
#include <string>
#include <deque>


using namespace std;

struct Null{};
union Value {
    int i;
    char c;
    string s;   // TODO: use char*?
    bool b;
    Null n;
};

/// Forward Declaration ///

class AST;
class LitA;
class TypeA;

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
class VarDeclA;
class ModifierA;

class PrimTypeA;
class ArrayTypeA;
class ClassTypeA;

class ExpressionA;
class InitializerA;
class StatementA;
class NameA;
class StrLitA;


class Visitor;
class PrinterV;
class CounterV;

/// ASTs ///

class AST {
public:
    virtual void accept(Visitor& v) = 0;
};
class ExpressionA : public AST {
public:
    ExpressionA() {};
    virtual void accept(Visitor& v);
};
class LitA : public ExpressionA {};
class TypeA : public AST {};


class NameA : public AST {
    string name;
public:
    NameA(string n): name(n){};
    virtual void accept(Visitor& v);
};


class StrLitA : public LitA {
    string value;
public:
    StrLitA(string v): value(v) {};
    string getValue() { return value; }
    virtual void accept(Visitor& v);
};
class IntLitA : public LitA {
    int value;
public:
    IntLitA(int v): value(v) {};
    int getValue() { return value; }
    virtual void accept(Visitor& v);
};

class BoolLitA : public LitA {
    bool value;
public:
    BoolLitA(bool v): value(v) {};
    int getValue() { return value; }
    virtual void accept(Visitor& v);
};

class NullLitA : public LitA {
public:
    virtual void accept(Visitor& v);
};

class PrimTypeA : public TypeA {
    string name;
public:
    PrimTypeA(string n): name(n) {};
    string getName() { return name; }
    virtual void accept(Visitor& v);
};
class ArrayTypeA : public TypeA {
    TypeA *type;
    int dim;
public:
    ArrayTypeA(TypeA *t, int d): type(t), dim(d) {};
    ArrayTypeA(TypeA *t): type(t), dim(1) {};
    TypeA *getType() { return type; }
    int getDim() { return dim; }
    virtual void accept(Visitor& v);
};
class ClassTypeA : public TypeA {
    string name;
public:
    ClassTypeA(string n): name(n) {};
    string getName() { return name; }
    virtual void accept(Visitor& v);
};
class StatementA : public AST {
public:
    StatementA() {};
    virtual void accept(Visitor& v);
};





class ListA : public AST {
    deque<AST*> asts;
public:
    ListA() {};
    ListA(deque<AST*> as): asts(as) {};
    deque<AST*> getASTs() { return asts; }
    void addb(AST *a) { asts.push_back(a); }
    void addf(AST *a) { asts.push_front(a); }
    virtual void accept(Visitor& v);
};
class StartA : public AST {
    ListA *list;
public:
    StartA(): list(new ListA()) {}
    StartA(ListA *l): list(l) {};
    ListA *getList() { return list; }
    void addb(AST *a) { list->addb(a); }
    void addf(AST *a) { list->addf(a); }
    virtual void accept(Visitor& v);
};
class ClassA : public AST {
    string name;
    SuperA *superClass;
    // NOTE: Changed constructors so default is provided in Parser.ypp
    // We need to decide if the type of superClass is ClassA, SuperA TypeA or ClassTypeA
    ListA *members;
public:
    //ClassA(string n): name(n), members(new ListA()) {};
    ClassA(string n, SuperA *sc): name(n), superClass(sc), members(new ListA()) {};
    //ClassA(string n, ListA *ms): name(n), members(ms) {};
    ClassA(string n, SuperA *sc, ListA *ms): name(n), superClass(sc), members(ms) {};
    string getName() { return name; }
    SuperA *getSuperClass() { return superClass; }
    ListA *getMembers() { return members; }
    virtual void accept(Visitor& v);
};

class SuperA : public AST {
    ClassTypeA *type;
public:
    SuperA(ClassTypeA *t): type(t) {};
    ClassTypeA *getType() { return type; };
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
// Is this one necessary?
class FieldDeclA : public AST {
    ListA *fieldList;
public:
    FieldDeclA(ListA *fs): fieldList(fs) {};
    ListA *getFieldList() { return fieldList; };
    virtual void accept(Visitor& v);
};

class FieldA : public AST {
    ListA *modifiers;
    TypeA *type;
    ListA *vars;
public:
    FieldA(ListA *ms, TypeA *t, ListA *vs): modifiers(ms), type(t), vars(vs) {};
    ListA *getModifers() { return modifiers; };
    TypeA *getType() { return type; };
    ListA *getVars() { return vars; };
    virtual void accept(Visitor& v);
};

class ModifierA : public AST {
    string *modifier;
public:
    ModifierA(string m) {};
    string *getModifier() { return modifier; };
    virtual void accept(Visitor& v);
};

class MethodA : public AST {
    ListA *modifiers;
    TypeA *type;
    string name;
    ListA *args;
    MethodBodyA *methodbody;
public:
    MethodA(ListA* ms, TypeA *t, string n, ListA *as, MethodBodyA *m):
        modifiers(ms), type(t), name(n), args(as), methodbody(m) {};
    MethodA(TypeA *t, string n, ListA *as, MethodBodyA *m):
        modifiers(new ListA()), type(t), name(n), args(as), methodbody(m) {
            modifiers = new ListA();
            modifiers->addb(new ModifierA("public")); // Correct?:
        };
    ListA *getModifiers() { return modifiers; }
    TypeA *getType() { return type; };
    string getName() { return name; }
    ListA *getArgs() { return args; }
    MethodBodyA *getMethodBody() { return methodbody; };
    virtual void accept(Visitor& v);
};

class ConstructorA : public AST {
    TypeA *type;
    ListA *modifiers;
    MethodBodyA *methodbody;
public:
    ConstructorA(TypeA *t, ListA *modifiers, MethodBodyA *m): type(t), methodbody(m) {};
    ConstructorA(TypeA *t, MethodBodyA *m): type(t), methodbody(m) {
        modifiers = new ListA();
        modifiers->addb(new ModifierA("public")); // Correct?:
    };
    TypeA *getType() { return type; };
    MethodBodyA *getMethodBody() { return methodbody; };
    virtual void accept(Visitor& v);
};

class FormalA : public AST {
    TypeA *type;
    string name;
public:
    FormalA(TypeA *t, string n): type(t), name(n) {};
    TypeA *getType() { return type; };
    string getName() { return name; }
    virtual void accept(Visitor& v);
};
class DeclStatementA : public StatementA {
    TypeA *type;
    ListA *localList;
public:
    DeclStatementA(TypeA *t, ListA *ls): type(t), localList(ls) {};
    TypeA *getType() { return type; };
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
    IfStatementA(ExpressionA *e, StatementA *s1): expression(e), statement1(s1) {};
    IfStatementA(ExpressionA *e, StatementA *s1, StatementA *s2): expression(e), statement1(s1), statement2(s2) {};
    ExpressionA *getExpression() { return expression; };
    StatementA *getStatement1() { return statement1; };
    StatementA *getStatement2() { return statement2; };
    virtual void accept(Visitor& v);
};
class ExpressionStatementA : public StatementA {
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
    BlockA(): statementList(new ListA()) {};
    BlockA(ListA *ss): statementList(ss) {};
    ListA *getStatementList() { return statementList; };
    virtual void accept(Visitor& v);
};
class EmptyStatementA : public AST {
public:
    EmptyStatementA() {};
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
class OpExpressionA : public ExpressionA {
    string op;
    int arity;
    ExpressionA *expression1;
    ExpressionA *expression2;
public:
    OpExpressionA(string o, ExpressionA *e1, ExpressionA *e2):
        op(o), arity(2), expression1(e1), expression2(e2) {};
    OpExpressionA(string o, ExpressionA *e1):
        op(o), arity(1), expression1(e1) {};
    string getOp() { return op; }
    int getArity() { return arity; }
    ExpressionA *getExpression1() { return expression1; };
    ExpressionA *getExpression2() { return expression2; };
    virtual void accept(Visitor& v);
};
class NewArrayA : public AST {
    NameA *name;
    TypeA *type;
    ListA *expressions;
public:
    NewArrayA(NameA *n, TypeA *t, ListA *d): name(n), type(t), expressions(d) {};
    NameA *getName() { return name; };
    TypeA *getType() { return type; };
    ListA *getExpressions() { return expressions; };
    virtual void accept(Visitor& v);
};
class ArrayRefA : public AST {
    NameA *name;
    ExpressionA *expression1;
    ExpressionA *expression2;
public:
    ArrayRefA(ExpressionA *e1, ExpressionA *e2): expression1(e1), expression2(e2) {};
    ArrayRefA(NameA *n, ExpressionA *e): name(n), expression1(e) {};
    ExpressionA *getExpression1() { return expression1; };
    ExpressionA *getExpression2() { return expression2; };
    virtual void accept(Visitor& v);
};
class VarDeclA : public AST {
    string name;
    ExpressionA *expression;
public:
    VarDeclA(string n): name(n) {};
    VarDeclA(string n, ExpressionA *e): name(n), expression(e) {};
    string getName() { return name; }
    ExpressionA *getExpression() { return expression; };
    virtual void accept(Visitor& v);
};
class ThisExpr : public AST {
public:
    ThisExpr() {};
    virtual void accept(Visitor& v);
};


class NewObjExprA: public AST {
    NameA *name;
    ListA *args;
public:
    NewObjExprA(NameA *n, ListA *as): name(n), args(as) {};
    virtual void accept(Visitor& v);
};

class ThisCallExprA: public AST {
    NameA *name;
    ListA *args;
public:
    ThisCallExprA(NameA *n, ListA *as): name(n), args(as) {};
    virtual void accept(Visitor& v);
};

class MethodCallExprA: public AST {
    TypeA *type;
    NameA *name;
    ListA *args;
public:
    MethodCallExprA(TypeA *t, NameA *n, ListA *as): type(t), name(n), args(as) {};
    virtual void accept(Visitor& v);
};

class SuperCallExprA: public AST {
    NameA *name;
    ListA *args;
public:
    SuperCallExprA(NameA *t, ListA *as): name(t), args(as) {};
    virtual void accept(Visitor& v);
};

class FieldExprA: public AST {
    TypeA *type;
    NameA *name;
public:
    FieldExprA(TypeA *t, NameA *n): type(t), name(n) {};
    TypeA *getType() { return type; }
    NameA *getName() { return name; }
    virtual void accept(Visitor& v);
};

class SuperFieldExprA: public FieldExprA {
    // NameA *name;
public:
    SuperFieldExprA(NameA *n): name(n) {};
    virtual void accept(Visitor& v);
};

class InitializerA : public AST {
public:
    InitializerA() {};
    virtual void accept(Visitor& v);
};

class DimensionA : public AST {
    int dim;
public:
    DimensionA(int d): dim(d) {};
    int getDim() { return dim; }
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
    virtual void visit(VarDeclA* a) = 0;

    virtual void visit(PrimTypeA* a) = 0;
    virtual void visit(ArrayTypeA* a) = 0;
    virtual void visit(ClassTypeA* a) = 0;

    virtual void visit(ExpressionA* a) = 0;
    virtual void visit(InitializerA* a) = 0;
    virtual void visit(StatementA* a) = 0;
    virtual void visit(NameA* a) = 0;
    virtual void visit(StrLitA* a) = 0;
    virtual void visit(IntLitA* a) = 0;
};

class PrinterV : public Visitor {
    int d = 0;
public:
    void indent() {
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

    virtual void visit(PrimTypeA* a);
    virtual void visit(ArrayTypeA* a);
    virtual void visit(ClassTypeA* a);

    virtual void visit(ExpressionA* a);
    virtual void visit(InitializerA* a);
    virtual void visit(StatementA* a);
    virtual void visit(NameA* a);
    virtual void visit(StrLitA* a);
    virtual void visit(IntLitA* a);
};

// class CounterV : public Visitor {
//     int c = 0;
// public:
//     virtual void visit(StartA* a);
//     virtual void visit(ListA* a);
//     virtual void visit(ClassA* a);
//     virtual void visit(SuperA* a);
//     virtual void visit(MethodBodyA* a);
//     virtual void visit(FieldDeclA* a);
//     virtual void visit(FieldA* a);
//     virtual void visit(MethodA* a);
//     virtual void visit(ConstructorA* a);
//     virtual void visit(FormalA* a);
//     virtual void visit(DeclStatementA* a);
//     virtual void visit(LocalA* a);
//     virtual void visit(IfStatementA* a);
//     virtual void visit(ExpressionStatementA* a);
//     virtual void visit(WhileStatementA* a);
//     virtual void visit(ReturnStatementA* a);
//     virtual void visit(ContinueStatementA* a);
//     virtual void visit(BreakStatementA* a);
//     virtual void visit(BlockStatementA* a);
//     virtual void visit(BlockA* a);
//     virtual void visit(SuperStatementA* a);
//     virtual void visit(CallA* a);
//     virtual void visit(OpExpressionA* a);
//     virtual void visit(NewArrayA* a);
//     virtual void visit(ArrayRefA* a);

//     virtual void visit(PrimTypeA* a);
//     virtual void visit(ArrayTypeA* a);
//     virtual void visit(ClassTypeA* a);

//     virtual void visit(ExpressionA* a);
//     virtual void visit(InitializerA* a);
//     virtual void visit(StatementA* a);
//     virtual void visit(NameA* a);
//     virtual void visit(StrLitA* a);
// };
