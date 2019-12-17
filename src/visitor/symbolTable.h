
#pragma once

#include <list>

using namespace std;
using namespace llvm;

/// SymbolTable ///
class Scope
{
public:
    BasicBlock* block;      // FIXME: why is this needed?
    std::map<string, AllocaInst*> localSymbols;

    Scope() {}; // TODO: remove
    Scope(BasicBlock * b): block(b) {};

    bool hasSymbol(string name);
    AllocaInst* getValue(string name);
    void declareVar(string name, AllocaInst* value);

    // just use declareVar and pass a 0
    // void declareVar(string name)
    // {
    //     localSymbols.insert({name, ConstantInt::get(Type::getInt64Ty(TheContext), 0)});
    // }

    void setValue(string name, AllocaInst* value);

    void Print(string s) {
        cout << s << endl;
    }
};

class SymbolTable
{
private:
    list<Scope *> scopes;

public:
    SymbolTable() {};

    // Set value of symbol in current scope.
    void setLocal(string name, AllocaInst* value);

    //Check if a symbol is in current scope
    bool isLocal(string name);

    // Get the value of symbol in current scope
    AllocaInst* getLocal(string name);

    // Declare symbol in current scope
    void declareLocal(string name, AllocaInst* value);

    // Check if value is declared in any scope
    bool isGlobal(string name);

    //returns value for the symbol closest to the current scope
    AllocaInst* getGlobal(std::string name);

    void enterScope(BasicBlock* block);
    void enterScope();

    void leaveScope();

    BasicBlock* topBlock();

    BasicBlock* localBlock();

    void Print(string s) {
        cout << s << endl;
    }

};