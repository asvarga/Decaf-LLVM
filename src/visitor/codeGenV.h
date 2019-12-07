
#include <list>

using namespace llvm;

/// LLVM ///
static LLVMContext TheContext;
static IRBuilder<> Builder(TheContext);
static std::unique_ptr<Module> TheModule;
static std::map<std::string, Value *> NamedValues;


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

    void declareVar(string name)
    {
        localSymbols.insert({name, ConstantInt::get(Type::getInt64Ty(TheContext), 0)});
    }

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




class CodeGenV : public Visitor {
    // Module * module;
    // StartA * start;
    // Function * mainFunction;
    //SymbolTable symbolTable;
public:
    void LogErrorV(const char *s) {
        cout << "XXXX error: " << s << " XXXXXXXXXXXXXXXXXXXXXXX\n";
    }
    void indent(int d) {
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
