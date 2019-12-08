
#include "symbolTable.h"


bool Scope::hasSymbol(string name)
{
    auto it = localSymbols.find(name);
    return localSymbols.end() != it;
}
Value* Scope::getValue(string name)
{
    if (hasSymbol(name))
    {
        return localSymbols[name];
    }
    else
    {
        cout << "Variable not in scope" << endl;
        return nullptr;
    }
}
void Scope::declareVar(string name, Value* value)
{
    localSymbols.insert({name, value});
}
// just use declareVar and pass a 0
// void declareVar(string name)
// {
//     localSymbols.insert({name, ConstantInt::get(Type::getInt64Ty(TheContext), 0)});
// }
void Scope::setValue(string name, Value* value)
{
    if (hasSymbol(name))
    {
        localSymbols[name] = value;
    }
    else
    {
        fprintf(stderr, "Variable %s not in scope.\n", name.c_str());
    }
}





// Set value of symbol in current scope.
void SymbolTable::setLocal(string name, Value* value)
{
    this->scopes.front()->setValue(name, value);
}
//Check if a symbol is in current scope
bool SymbolTable::isLocal(string name)
{
    return this->scopes.front()->hasSymbol(name);
}
// Get the value of symbol in current scope
Value* SymbolTable::getLocal(string name)
{
    return this->scopes.front()->getValue(name);
}
// Declare symbol in current scope
void SymbolTable::declareLocal(string name, Value* value) {
    if (!isLocal(name))
    {
        this->scopes.front()->declareVar(name, value);
    }
    else
    {
        fprintf(stderr, "Variable %s already declared!\n", name.c_str());
    }
}
// Check if value is declared in any scope
bool SymbolTable::isGlobal(string name)
{
    for(auto scope : scopes)
    {
        if (scope->hasSymbol(name))
        {
            return true;
        }
    }
    return false;
}
//returns value for the symbol closest to the current scope
Value * SymbolTable::getGlobal(std::string name)
{
    for(auto scope : scopes)
    {
        if (scope->hasSymbol(name))
        {
            return scope->getValue(name);
        }
    }
    return nullptr;
}
void SymbolTable::enterScope(BasicBlock* block) {
    this->scopes.push_front(new Scope(block));
}
void SymbolTable::leaveScope() {
    this->scopes.pop_front();
}
BasicBlock* SymbolTable::topBlock() {

    return this->scopes.back()->block;
}
BasicBlock* SymbolTable::localBlock()
{
    return this->scopes.front()->block;
}

