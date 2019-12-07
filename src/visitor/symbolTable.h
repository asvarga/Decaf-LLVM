
#include <list>

using namespace std;
using namespace llvm;

/// SymbolTable ///
class Scope
{
public:
    BasicBlock* block;
    std::map<string, Value*> localSymbols;

    Scope(BasicBlock * b): block(b) {};

    bool hasSymbol(string name)
    {
        auto it = localSymbols.find(name);
        return localSymbols.end() != it;
    }

    Value* getValue(string name)
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

    void declareVar(string name, Value* value)
    {
        localSymbols.insert({name, value});
    }

    // just use declareVar and pass a 0
    // void declareVar(string name)
    // {
    //     localSymbols.insert({name, ConstantInt::get(Type::getInt64Ty(TheContext), 0)});
    // }

    void setValue(string name, Value* value)
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
};

class SymbolTable
{
private:
    list<Scope> scopes;

public:
    SymbolTable() {};

    // Set value of symbol in current scope.
    void setLocal(string name, Value* value)
    {
        this->scopes.front().setValue(name, value);
    }

    //Check if a symbol is in current scope
    bool isLocal(string name)
    {
        return this->scopes.front().hasSymbol(name);
    }

    // Get the value of symbol in current scope
    Value* getLocal(string name)
    {
        return this->scopes.front().getValue(name);

    }

    // Declare symbol in current scope
    void declareLocal(string name, Value* value) {
        if (!isLocal(name))
        {
            this->scopes.front().declareVar(name, value);
        }
        else
        {
            fprintf(stderr, "Variable %s already declared!\n", name.c_str());

        }
    }

    // Check if value is declared in any scope
    bool isGlobal(string name)
    {
        for(auto scope : scopes)
        {
            if (scope.hasSymbol(name))
            {
                return true;
            }
        }
        return false;
    }

    //returns value for the symbol closest to the current scope
    Value * getGlobal(std::string name)
    {
        for(auto scope : scopes)
        {
            if (scope.hasSymbol(name))
            {
                return scope.getValue(name);
            }
        }
        return nullptr;
    }

    void enterScope(BasicBlock* block) {
        this->scopes.push_front(Scope(block));
    }

    void leaveScope() {
        this->scopes.pop_front();
    }

    BasicBlock* topBlock() {

        return this->scopes.back().block;
    }

    BasicBlock* localBlock()
    {
        return this->scopes.front().block;
    }

};