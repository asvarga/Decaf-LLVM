
#pragma once

#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/Optional.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Scalar/GVN.h>
#include <llvm/Transforms/Utils.h>


#include "symbolTable.h"

#include <string>
#include <deque>

using namespace std;
using namespace llvm;

/// Forward Declaration ///
class Visitor;
class ClassA;
class MethodA;
class FieldA;

/// ASTs ///

class AST {
    Value *reg;     // TODO: move somewhere more specific?
    BasicBlock *bb; // TODO: move somewhere more specific?
    Function *func; // TODO: move somewhere more specific?
    int depth = 0;
    AST *parent;
    int ind = -1;    // index if in list
public:
    AST() {};
    AST(Function *f): func(f) {};
    Value *getReg() { return reg; }
    void setReg(Value *r) { reg = r; }
    BasicBlock *getBB() { return bb; }
    void setBB(BasicBlock *b) { bb = b; }
    Function *getFunc() { return func; }
    void setFunc(Function *f) { func = f; }

    int getDepth() { return depth; }
    void setDepth(int d) { depth = d; }
    AST *getParent() { return parent; }
    void setParent(AST *p) { parent = p; }
    int getInd() { return ind; }
    void setInd(int i) { ind = i; }

    virtual void accept(Visitor& v) = 0;
};

class ExpressionA : public AST {
public:
    ExpressionA() {};
    virtual void accept(Visitor& v);
};

class LitA : public ExpressionA {};

class TypeA : public AST {
    Type *irtype;
public:
    TypeA(){};
    Type *getIRType() { return irtype; }
    void setIRType(Type *t) { irtype = t; }
    virtual void accept(Visitor& v);
};



class StrLitA : public LitA {
    string value;
public:
    StrLitA(string v) {
        value = v.substr(1, v.size()-2);
    };
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
    int nameCase;
public:
    NameA(string n, int nc): name(n), nameCase(nc){};
    string getName() { return name; };
    int getCase() { return nameCase; };
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
    std::map<string, ClassA*> classTable;
    MethodA *main;
public:
    StartA(): list(new ListA()) {}
    StartA(ListA *l): list(l) {};
    ListA *getList() { return list; }

    void addClass(string name, ClassA *clas) { classTable.insert({name, clas}); }
    bool hasClass(string name) { return classTable.end() != classTable.find(name); }
    ClassA *getClass(string name) {
        if (hasClass(name)) { return classTable[name]; } else {
            cout << "Class not in scope: " << name << endl;
            return nullptr;
        }
    }

    MethodA *getMain() { return main; }
    void setMain(MethodA *m) { main = m; }

    void addb(AST *a) { list->addb(a); }
    void addf(AST *a) { list->addf(a); }
    virtual void accept(Visitor& v);
};

class SuperA : public AST {
    string name;
public:
    SuperA(string n): name(n) {};
    string getName() { return name; };
    virtual void accept(Visitor& v);
};

class ClassA : public AST {
    string name;
    SuperA *superClass;
    // NOTE: Changed constructors so default is provided in Parser.ypp
    // We need to decide if the type of superClass is ClassA, SuperA TypeA or ClassTypeA
    ListA *members;
    std::map<string, MethodA*> methodTable;
    std::map<string, FieldA*> fieldTable;
public:
    //ClassA(string n): name(n), members(new ListA()) {};
    ClassA(string n, SuperA *sc): name(n), superClass(sc), members(new ListA()) {};
    //ClassA(string n, ListA *ms): name(n), members(ms) {};
    ClassA(string n, SuperA *sc, ListA *ms): name(n), superClass(sc), members(ms) {};
    string getName() { return name; };
    SuperA *getSuperClass() { return superClass; };
    ListA *getMembers() { return members; };

    void addMethod(string name, MethodA *method) { methodTable.insert({name, method}); }
    bool hasMethod(string name) { return methodTable.end() != methodTable.find(name); }
    MethodA *getMethod(string name) {
        if (hasMethod(name)) { return methodTable[name]; } else {
            cout << "Method not in scope: " << name << endl;
            return nullptr;
        }
    }
    void addField(string name, FieldA *field) { fieldTable.insert({name, field}); }
    bool hasField(string name) { return fieldTable.end() != fieldTable.find(name); }
    FieldA *getField(string name) {
        if (hasField(name)) { return fieldTable[name]; } else {
            cout << "Field not in scope: " << name << endl;
            return nullptr;
        }
    }

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
    string name;
    ExpressionA *expression;
public:
    VarDeclA(string n): name(n), expression(0) {};
    VarDeclA(string n, ExpressionA *e): name(n), expression(e) {};
    string getName() { return name; }
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
    string name;
    ListA *args;
    MethodBodyA *methodbody;
    SymbolTable *symbolTable;
    ClassA *clas;
    std::vector<Value *> argVals;
public:
    MethodA(ListA* ms, TypeA *t, string n, ListA *as, MethodBodyA *m):
        modifiers(ms), type(t), name(n), args(as), methodbody(m) {
            symbolTable = new SymbolTable();
        };
    MethodA(TypeA *t, string n, ListA *as, MethodBodyA *m):
        modifiers(new ListA()), type(t), name(n), args(as), methodbody(m) {
            modifiers = new ListA();
            modifiers->addb(new ModifierA("public")); // Correct?:
            symbolTable = new SymbolTable();
        };
    MethodA(Function *f): AST(f) {}; // use for externs
    string getName() { return name; }
    ListA *getModifiers() { return modifiers; }
    TypeA *getType() { return type; };
    ListA *getArgs() { return args; }
    MethodBodyA *getMethodBody() { return methodbody; };
    SymbolTable *getSymbolTable() { return symbolTable; };
    Value *lookup(string name) { return symbolTable->getGlobal(name); }
    void setClass(ClassA *c) { clas = c; }
    ClassA *getClass() { return clas; };
    void addArgVal(Value *val) { argVals.push_back(val); }
    Value *getArgVal(int ind) { return argVals[ind]; }
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

class EmptyStatementA : public StatementA {
public:
    EmptyStatementA() {};
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
    BlockStatementA(): block(new BlockA()) {};
    BlockStatementA(BlockA *b): block(b) {};
    BlockA *getBlock() { return block; };
    virtual void accept(Visitor& v);
};

class IfStatementA : public StatementA {
    ExpressionA *expression;
    StatementA *statement1;
    StatementA *statement2;
public:
    IfStatementA(ExpressionA *e, StatementA *s1, StatementA *s2): expression(e), statement1(s1), statement2(s2) {};
    IfStatementA(ExpressionA *e, StatementA *s1): IfStatementA(e, s1, new EmptyStatementA()) {};
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

class CallA : public ExpressionA {
    NameA *name;
    ListA *args;
    // std::vector<Value *> callArgs;
public:
    CallA(NameA *n, ListA *es): name(n), args(es) {};
    NameA *getName() { return name; };
    ListA *getArgs() { return args; };
    // std::vector<Value *> getCallArgs() { return callArgs; };
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

class ThisCallExprA: public CallA {
    // NameA *name;
    // ListA *args;
public:
    ThisCallExprA(NameA *n, ListA *as): CallA(n, as) {};
    // NameA *getName() { return name; };
    // ListA *getArgs() { return args; };
    virtual void accept(Visitor& v);
};

class MethodCallExprA: public CallA {
    PrimaryExprA *type;
    // NameA *name;
    // ListA *args;
public:
    MethodCallExprA(PrimaryExprA* t, NameA* n, ListA *as): type(t), CallA(n, as) {};
    PrimaryExprA *getType() { return type; }
    // NameA *getName() { return name; };
    // ListA *getArgs() { return args; };
    virtual void accept(Visitor& v);
};

class SuperCallExprA: public CallA {
    // NameA *name;
    // ListA *args;
public:
    SuperCallExprA(NameA *n, ListA *as): CallA(n, as) {};
    // NameA *getName() { return name; };
    // ListA *getArgs() { return args; };
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
