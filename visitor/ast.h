
#include <string>
#include <vector>

using namespace std;

/// Forward Declaration ///

class AST;
class StartA;
class ListA;
class ClassA;

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

/// Visitors ///

class Visitor {
public:
    virtual void visit(StartA* a) = 0;
    virtual void visit(ListA* a) = 0;
    virtual void visit(ClassA* a) = 0;
};

class PrinterV : public Visitor {
public: 
    virtual void visit(StartA* a);
    virtual void visit(ListA* a);
    virtual void visit(ClassA* a);
};
class CounterV : public Visitor {
    int c = 0;
public: 
    virtual void visit(StartA* a);
    virtual void visit(ListA* a);
    virtual void visit(ClassA* a);
};


