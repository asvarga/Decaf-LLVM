
#pragma once

#include <list>

using namespace std;
using namespace llvm;

/// SymbolTable ///
class Scope
{
public:
    BasicBlock* block;
    std::map<string, Value*> localSymbols;

    Scope() {}; // TODO: remove
    Scope(BasicBlock * b): block(b) {};

    bool hasSymbol(string name);
    Value* getValue(string name);
    void declareVar(string name, Value* value);

    // just use declareVar and pass a 0
    // void declareVar(string name)
    // {
    //     localSymbols.insert({name, ConstantInt::get(Type::getInt64Ty(TheContext), 0)});
    // }

    void setValue(string name, Value* value);
};

class SymbolTable
{
private:
    list<Scope *> scopes;

public:
    SymbolTable() {};

    // Set value of symbol in current scope.
    void setLocal(string name, Value* value);

    //Check if a symbol is in current scope
    bool isLocal(string name);

    // Get the value of symbol in current scope
    Value* getLocal(string name);

    // Declare symbol in current scope
    void declareLocal(string name, Value* value);

    // Check if value is declared in any scope
    bool isGlobal(string name);

    //returns value for the symbol closest to the current scope
    Value * getGlobal(std::string name);

    void enterScope(BasicBlock* block);

    void leaveScope();

    BasicBlock* topBlock();

    BasicBlock* localBlock();

};