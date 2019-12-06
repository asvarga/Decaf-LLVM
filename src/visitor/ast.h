
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
//
// class AST;
// class LitA;
// class TypeA;
//
// class StartA;
// class ListA;
// class ClassA;
// class SuperA;
// class MethodBodyA;
// class FieldDeclA;
// class FieldA;
// class MethodA;
// class ConstructorA;
// class FormalA;
// class DeclStatementA;
// class LocalA;
// class IfStatementA;
// class ExpressionStatementA;
// class WhileStatementA;
// class ReturnStatementA;
// class ContinueStatementA;
// class BreakStatementA;
// class BlockStatementA;
// class EmptyStatementA;
// class BlockA;
// class SuperStatementA;
// class CallA;
// class OpExpressionA;
// class NewArrayA;
// class ArrayRefA;
// class VarDeclA;
// class SuperStatementA;
// class PrimaryExprA;
// class DimensionA;
// class PrimTypeA;
// class ArrayTypeA;
// class ClassTypeA;
// class FieldlExprA
// class ExpressionA;
// class InitializerA;
// class StatementA;
// class NameA;
// class StrLitA;
// class BoolLitA;
// class IntLitA;
// class MethodCallExprA;
// class NewObjExprA;
// class ModifierA;
// class ThisExprA;
// class NonArrayPrimaryA;
// class NullLitA;

class Visitor;
class PrinterV;
class CounterV;



/// ASTs ///

class AST {
public:
    AST() {};
    virtual void accept(Visitor& v) = 0;
};

class ExpressionA : public AST {
public:
    ExpressionA() {};
    virtual void accept(Visitor& v);
};

class LitA : public ExpressionA {};

class TypeA : public AST {;
public:
    TypeA(){};
    virtual void accept(Visitor& v);
};



class StrLitA : public LitA {
    string value;
public:
    StrLitA(string v): value(v) {};
    string getValue() { return value; }
    virtual void accept(Visitor& v);
};

class CharLitA : public LitA {
    char value;
public:
    CharLitA(char v): value(v) {};
    char getValue() { return value; }
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
    bool getValue() { return value; }
    virtual void accept(Visitor& v);
};

class NullLitA : public LitA {
public:
    NullLitA() {};
    virtual void accept(Visitor& v);
};

class PrimaryExprA : public ExpressionA {
public:
    PrimaryExprA() {};
    virtual void accept(Visitor& v);
};

class NameA : public PrimaryExprA {
    string name;
public:
    NameA(string n): name(n){};
    string getName() { return name; }
    virtual void accept(Visitor& v);
};


class PrimTypeA : public TypeA {
    NameA *name;
public:
    PrimTypeA(NameA *n): name(n) { };
    NameA *getName() { return name; };
    virtual void accept(Visitor& v);
};

//Might need to change dim to be of type DimensionA
class ArrayTypeA : public TypeA {
    TypeA *type;
    int dim;
public:
    ArrayTypeA(TypeA *t, int d): type(t), dim(d) {};
    ArrayTypeA(TypeA *t): type(t), dim(1) {};
    TypeA *getType() { return type; };
    int getDim() { return dim; };
    virtual void accept(Visitor& v);
};

class ClassTypeA : public TypeA {
    NameA *name;
public:
    ClassTypeA(NameA* n): name(n) {};
    NameA* getName() { return name; }
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

class SuperA : public AST {
    NameA *name;
public:
    SuperA(NameA *n): name(n) {};
    NameA *getName() { return name; };
    virtual void accept(Visitor& v);
};

class ClassA : public AST {
    NameA *name;
    SuperA *superClass;
    // NOTE: Changed constructors so default is provided in Parser.ypp
    // We need to decide if the type of superClass is ClassA, SuperA TypeA or ClassTypeA
    ListA *members;
public:
    //ClassA(string n): name(n), members(new ListA()) {};
    ClassA(NameA *n, SuperA *sc): name(n), superClass(sc), members(new ListA()) {};
    //ClassA(string n, ListA *ms): name(n), members(ms) {};
    ClassA(NameA *n, SuperA *sc, ListA *ms): name(n), superClass(sc), members(ms) {};
    NameA *getName() { return name; };
    SuperA *getSuperClass() { return superClass; };
    ListA *getMembers() { return members; };
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


class VarDeclA : public AST {
    NameA *name;
    ExpressionA *expression;
public:
    VarDeclA(NameA *n): name(n), expression(0) {};
    VarDeclA(NameA *n, ExpressionA *e): name(n), expression(e) {};
    NameA *getName() { return name; }
    ExpressionA *getExpression() { return expression; };
    virtual void accept(Visitor& v);
};

class FieldA : public AST {
    ListA *modifiers;
    TypeA *type;
    VarDeclA *var;
public:
    FieldA(ListA *ms, TypeA *t, VarDeclA *v): modifiers(ms), type(t), var(v) {};
    ListA *getModifers() { return modifiers; };
    TypeA *getType() { return type; };
    VarDeclA *getVar() { return var; };
    virtual void accept(Visitor& v);
};

class ModifierA : public AST {
    string modifier;
public:
    ModifierA(string m): modifier(m) {};
    string getModifier() { return modifier; };
    virtual void accept(Visitor& v);
};

class MethodA : public AST {
    ListA *modifiers;
    TypeA *type;
    NameA *name;
    ListA *args;
    MethodBodyA *methodbody;
public:
    MethodA(ListA* ms, TypeA *t, NameA *n, ListA *as, MethodBodyA *m):
        modifiers(ms), type(t), name(n), args(as), methodbody(m) {};
    MethodA(TypeA *t, NameA *n, ListA *as, MethodBodyA *m):
        modifiers(new ListA()), type(t), name(n), args(as), methodbody(m) {
            modifiers = new ListA();
            modifiers->addb(new ModifierA("public")); // Correct?:
        };
    NameA *getName() { return name; }
    ListA *getModifiers() { return modifiers; }
    TypeA *getType() { return type; };
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
    ListA *getModifers() { return modifiers; }
    MethodBodyA *getMethodBody() { return methodbody; };
    virtual void accept(Visitor& v);
};

class FormalA : public AST {
    TypeA *type;
    NameA *varDecl;
public:
    FormalA(TypeA *t, NameA *v): type(t), varDecl(v) {};
    TypeA *getType() { return type; };
    NameA *getVarDecl() { return varDecl; }
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

class IfStatementA : public StatementA {
    ExpressionA *expression;
    StatementA *statement1;
    StatementA *statement2;
public:
    IfStatementA(ExpressionA *e, StatementA *s1): expression(e), statement1(s1), statement2(0) {};
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

class WhileStatementA : public StatementA {
    ExpressionA *expression;
    StatementA *statement;
public:
    WhileStatementA(ExpressionA *e, StatementA *s): expression(e), statement(s) {};
    ExpressionA *getExpression() { return expression; };
    StatementA *getStatement() { return statement; };
    virtual void accept(Visitor& v);
};

class ReturnStatementA : public StatementA {
    ExpressionA *expression;
public:
    ReturnStatementA(ExpressionA *e): expression(e) {};
    ExpressionA *getExpression() { return expression; };
    virtual void accept(Visitor& v);
};
class ContinueStatementA : public StatementA {

public:
    ContinueStatementA() {};
    virtual void accept(Visitor& v);
};
class BreakStatementA : public StatementA {

public:
    BreakStatementA() {};
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

class BlockStatementA : public StatementA {
    BlockA *block;
public:
    BlockStatementA(BlockA *b): block(b) {};
    BlockA *getBlock() { return block; };
    virtual void accept(Visitor& v);
};

class EmptyStatementA : public StatementA {

public:
    EmptyStatementA() {};
    virtual void accept(Visitor& v);
};

class NewArrayA : public AST {
    TypeA *type;
    ListA *dimList;
public:
    NewArrayA(TypeA *t, ListA *d): type(t), dimList(d) {};
    TypeA *getType() { return type; };
    ListA *getDimList() { return dimList; };
    virtual void accept(Visitor& v);
};

class DimensionA : public AST {
    ExpressionA *dim;
public:
    DimensionA(ExpressionA *d): dim(d) {};
    ExpressionA *getDim() { return dim; };
    virtual void accept(Visitor& v);
};


class ArrayRefA : public ExpressionA {
    NameA *name;
    ExpressionA *expression;
    DimensionA *dim;
public:
    ArrayRefA(ExpressionA *e, DimensionA *d): expression(e), dim(d) {};
    ArrayRefA(NameA* n, ExpressionA *e): name(n), expression(e) {};
    NameA *getName() { return name; }
    ExpressionA *getExpression() { return expression; };
    DimensionA *getDim() { return dim; };
    virtual void accept(Visitor& v);
};

class PrimaryArrayA : public PrimaryExprA {
    NewArrayA *array;
public:
    PrimaryArrayA(NewArrayA *a): array(a) {};
    NewArrayA* getArray() { return array; };
    virtual void accept(Visitor& v);
};


class NonArrayPrimaryA : public PrimaryExprA {
    ExpressionA* expression;
public:
    NonArrayPrimaryA(ExpressionA* e): expression(e) {};
    ExpressionA* getExpression() { return expression; };
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

class SuperStatementA : public StatementA {
    ListA *args;
public:
    SuperStatementA(ListA *a): args(a) {};
    ListA *getArgs() { return args; };
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
        op(o), arity(1), expression1(e1), expression2(0) {};
    string getOp() { return op; }
    int getArity() { return arity; }
    ExpressionA *getExpression1() { return expression1; };
    ExpressionA *getExpression2() { return expression2; };
    virtual void accept(Visitor& v);
};

class ThisExprA : public ExpressionA {
public:
    ThisExprA() {};
    virtual void accept(Visitor& v);
};


class NewObjExprA: public ExpressionA{
    NameA *name;
    ListA *expressions;
public:
    NewObjExprA(NameA *n, ListA *es): name(n), expressions(es) {};
    NameA *getName() { return name; };
    ListA *getExpressionList() { return expressions; }
    virtual void accept(Visitor& v);
};

class ThisCallExprA: public ExpressionA{
    NameA *name;
    ListA *args;
public:
    ThisCallExprA(NameA *n, ListA *as): name(n), args(as) {};
    NameA *getName() { return name; };
    ListA *getArgs() { return args; };
    virtual void accept(Visitor& v);
};

class MethodCallExprA: public ExpressionA{
    PrimaryExprA *type;
    NameA *name;
    ListA *args;
public:
    MethodCallExprA(PrimaryExprA* t, NameA* n, ListA *as): type(t), name(n), args(as) {};
    PrimaryExprA *getType() { return type; }
    NameA *getName() { return name; };
    ListA *getArgs() { return args; };
    virtual void accept(Visitor& v);
};

class SuperCallExprA: public ExpressionA{
    NameA *name;
    ListA *args;
public:
    SuperCallExprA(NameA *t, ListA *as): name(t), args(as) {};
    NameA *getName() { return name; };
    ListA *getArgs() { return args; };
    virtual void accept(Visitor& v);
};

class FieldExprA: public ExpressionA{
    PrimaryExprA *type;
    NameA *name;
public:
    FieldExprA(PrimaryExprA *t, NameA *i): type(t), name(i) {};
    PrimaryExprA *getType() { return type; };
    NameA *getName() { return name; };
    virtual void accept(Visitor& v);
};

class SuperFieldExprA: public ExpressionA{
    NameA *name;
public:
    SuperFieldExprA(NameA *n): name(n) {};
    NameA *getName() { return name; };
    virtual void accept(Visitor& v);
};

class InitializerA : public AST {
public:
    InitializerA() {};
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

    virtual void visit(TypeA *a) = 0;
    virtual void visit(PrimTypeA* a) = 0;
    virtual void visit(ArrayTypeA* a) = 0;
    virtual void visit(ClassTypeA* a) = 0;

    virtual void visit(PrimaryExprA* a) = 0;
    virtual void visit(ExpressionA* a) = 0;
    virtual void visit(InitializerA* a) = 0;
    virtual void visit(StatementA* a) = 0;
    virtual void visit(NameA* a) = 0;
    virtual void visit(StrLitA* a) = 0;
    virtual void visit(IntLitA* a) = 0;

    virtual void visit(DimensionA* a) = 0;
    virtual void visit(FieldExprA* a) = 0;
    virtual void visit(NewObjExprA* a) = 0;
    virtual void visit(PrimaryArrayA* a) = 0;
    virtual void visit(ThisCallExprA* a) = 0;
    virtual void visit(SuperCallExprA* a) = 0;
    virtual void visit(EmptyStatementA* a) = 0;
    virtual void visit(MethodCallExprA* a) = 0;
    virtual void visit(SuperFieldExprA* a) = 0;
    virtual void visit(NonArrayPrimaryA* a) = 0;
    virtual void visit(BoolLitA* a) = 0;
    virtual void visit(CharLitA* a) = 0;
    virtual void visit(NullLitA* a) = 0;
    virtual void visit(ModifierA* a) = 0;
    virtual void visit(ThisExprA* a) = 0;
    
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

    virtual void visit(TypeA *a);
    virtual void visit(PrimTypeA* a);
    virtual void visit(ArrayTypeA* a);
    virtual void visit(ClassTypeA* a);

    virtual void visit(PrimaryExprA* a);
    virtual void visit(ExpressionA* a);
    virtual void visit(InitializerA* a);
    virtual void visit(StatementA* a);
    virtual void visit(NameA* a);
    virtual void visit(StrLitA* a);
    virtual void visit(IntLitA* a);

    virtual void visit(DimensionA* a);
    virtual void visit(FieldExprA* a);
    virtual void visit(NewObjExprA* a);
    virtual void visit(PrimaryArrayA* a);
    virtual void visit(ThisCallExprA* a);
    virtual void visit(SuperCallExprA* a);
    virtual void visit(EmptyStatementA* a);
    virtual void visit(MethodCallExprA* a);
    virtual void visit(SuperFieldExprA* a);
    virtual void visit(NonArrayPrimaryA* a);
    virtual void visit(BoolLitA* a);
    virtual void visit(CharLitA* a);
    virtual void visit(NullLitA* a);
    virtual void visit(ModifierA* a);
    virtual void visit(ThisExprA* a);
};

class CodeGenV : public Visitor {
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
    virtual void visit(VarDeclA* a);

    virtual void visit(TypeA *a);
    virtual void visit(PrimTypeA* a);
    virtual void visit(ArrayTypeA* a);
    virtual void visit(ClassTypeA* a);

    virtual void visit(PrimaryExprA* a);
    virtual void visit(ExpressionA* a);
    virtual void visit(InitializerA* a);
    virtual void visit(StatementA* a);
    virtual void visit(NameA* a);
    virtual void visit(StrLitA* a);
    virtual void visit(IntLitA* a);

    virtual void visit(DimensionA* a);
    virtual void visit(FieldExprA* a);
    virtual void visit(NewObjExprA* a);
    virtual void visit(PrimaryArrayA* a);
    virtual void visit(ThisCallExprA* a);
    virtual void visit(SuperCallExprA* a);
    virtual void visit(EmptyStatementA* a);
    virtual void visit(MethodCallExprA* a);
    virtual void visit(SuperFieldExprA* a);
    virtual void visit(NonArrayPrimaryA* a);
    virtual void visit(BoolLitA* a);
    virtual void visit(CharLitA* a);
    virtual void visit(NullLitA* a);
    virtual void visit(ModifierA* a);
    virtual void visit(ThisExprA* a);
};
