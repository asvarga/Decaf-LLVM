#include "codeGenV.h"

void CodeGenV::visit(StrLitA* a) {
    indent(a->getDepth()); cout << "StrLitA: " << a->getValue() << "\n";
}
void CodeGenV::visit(CharLitA* a) {
    indent(a->getDepth()); cout << "CharLitA: " << a->getValue() << endl ;
    a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), a->getValue()));

}
void CodeGenV::visit(IntLitA* a) {
    indent(a->getDepth()); cout << "IntLitA: " << a->getValue() << "\n";
    a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), a->getValue()));
}

void CodeGenV::visit(BoolLitA* a) {
    indent(a->getDepth()); cout << "BoolLitA: " << a->getValue() << endl;
    a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), a->getValue()));
}

void CodeGenV::visit(NullLitA* a) {
    indent(a->getDepth()); cout << "NullLitA\n";
    a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), 0));
}

void CodeGenV::visit(NameA* a) {
    indent(a->getDepth()); cout << "NameA: " << a->getName() << endl;
    string name = a->getName();
    switch(nameCase) {
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 5: break;
        case 6:
            a->setReg(currSymTab->getGlobal(name));
            break;
        default:
            a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), 1234));    // TODO:
    }
}

void CodeGenV::visit(TypeA* a) {
    indent(a->getDepth()); cout << "TypeA" << "\n";
}

void CodeGenV::visit(PrimTypeA* a) {
    indent(a->getDepth()); cout << "PrimTypeA" << "\n";
    // a->getName()->accept(*this);
    string name = a->getName()->getName();
    if (name == "int") {
        a->setIRType(Type::getInt64Ty(TheContext));
    } else if (name == "void") {
        a->setIRType(Type::getVoidTy(TheContext));
    } else {
        Print("type unimplemented: " + name);
    }
}

void CodeGenV::visit(ArrayTypeA* a) {
    indent(a->getDepth()); cout << "ArrayTypeA: dim " << a->getDim() << "\n";
    a->getType()->accept(*this);
}

void CodeGenV::visit(ClassTypeA* a) {
    indent(a->getDepth()); cout << "ClassTypeA: " << a->getName() << "\n";
    a->getName()->accept(*this);
}

void CodeGenV::visit(StatementA* a) {
    indent(a->getDepth()); cout << "StatementA\n";
}

void CodeGenV::visit(PrimaryExprA* a) {
    indent(a->getDepth()); cout << "PrimaryExprA\n";
}

void CodeGenV::visit(ExpressionA* a) {
    indent(a->getDepth()); cout << "ExpressionA\n";
}

void CodeGenV::visit(ListA* a) {
    indent(a->getDepth()); cout << "ListA\n";
    deque<AST *> asts = a->getASTs();
    for (AST *a2 : asts) {
        a2->accept(*this);
    }
}
void CodeGenV::visit(StartA* a) {
    indent(a->getDepth()); cout << "StartA\n";
    currStart = a;

    // build IO object
    ClassA *IO = new ClassA("IO", new SuperA("Object"));
    a->addClass("IO", IO);
    IO->addMethod("putChar", new MethodA(PutCharFunction));
    IO->addMethod("putInt", new MethodA(PutIntFunction));
    IO->addMethod("putString", new MethodA(PutStringFunction));
    IO->addMethod("peek", new MethodA(PeekFunction));
    IO->addMethod("getChar", new MethodA(GetCharFunction));
    IO->addMethod("getInt", new MethodA(GetIntFunction));
    IO->addMethod("getLine", new MethodA(GetLineFunction));

    a->getList()->accept(*this);

    // build _Decaf$Main in global scope which just calls the unique main method
    Type *mainReturnType = Type::getVoidTy(TheContext);
    std::vector<Type*> mainArgTypes;
    FunctionType *mainFT = FunctionType::get(mainReturnType, mainArgTypes, false);

    Function *MainFunction = Function::Create(mainFT, Function::ExternalLinkage, "_$DecafMain", TheModule.get()); 

    BasicBlock *BB = BasicBlock::Create(TheContext, "entry", MainFunction);
    Builder.SetInsertPoint(BB);

    std::vector<Value *> ArgsV; // no args
    Builder.CreateCall(a->getMain()->getFunc(), ArgsV, "calltmp");  // call main
    Builder.CreateRet(nullptr); // c++ nullptr = llvm void
    verifyFunction(*MainFunction);

}

void CodeGenV::visit(SuperA* a) {
    indent(a->getDepth()); cout << "SuperA\n";
}

void CodeGenV::visit(ClassA* a) {
    indent(a->getDepth()); cout << "ClassA\n" ;

    currClass = a;

    a->getSuperClass()->accept(*this);
    a->getMembers()->accept(*this);
}

void CodeGenV::visit(MethodBodyA* a) {
    indent(a->getDepth()); cout << "MethodBodyA\n";
    // a->getFormalList()->accept(*this); // repeated in MethodA
    a->getStatementList()->accept(*this);
}

void CodeGenV::visit(FieldDeclA* a) {
    indent(a->getDepth()); cout << "FieldDeclA\n";
    a->getFieldList()->accept(*this);
}

void CodeGenV::visit(VarDeclA* a) {
    indent(a->getDepth()); cout << "VarDeclA: " << a->getName() << "\n";
    // a->getName()->accept(*this);
    a->getExpression()->accept(*this);
    Value *reg = a->getExpression()->getReg();
    //= ConstantInt::get(Type::getInt64Ty(TheContext), 0);
    currSymTab->declareLocal(a->getName(), reg);
}

void CodeGenV::visit(FieldA* a) {
    indent(a->getDepth()); cout << "FieldA\n";
    a->getModifers()->accept(*this);
    a->getType()->accept(*this);
    a->getVar()->accept(*this);
}

void CodeGenV::visit(ModifierA* a) {
    indent(a->getDepth()); cout << "ModifierA: " << a->getModifier() << endl;
}

void CodeGenV::visit(MethodA* a) {
    indent(a->getDepth()); cout << "MethodA\n";
    currMethod = a;
    currSymTab = a->getSymbolTable();
    
    a->getModifiers()->accept(*this);

    a->getType()->accept(*this);
    Type *returnType = a->getType()->getIRType();

    std::vector<Type*> argTypes;
    currArgTypes = argTypes;    
    a->getArgs()->accept(*this);    // populates currArgTypes
    FunctionType *FT = FunctionType::get(returnType, currArgTypes, false);

    string fname = a->getClass()->getName() + "." + a->getName();   // avoid name collision across classes
    Function *TheFunction = Function::Create(FT, Function::ExternalLinkage, fname, TheModule.get());   
    a->setFunc(TheFunction);
    BasicBlock *BB = BasicBlock::Create(TheContext, "entry", TheFunction);
    Builder.SetInsertPoint(BB);
    currSymTab->enterScope(BB);

    // TODO: replace this hard-coded code with generated code   
    // call IO$getInt()
    std::vector<Value *> getIntArgsV;
    currSymTab->declareLocal("i", Builder.CreateCall(GetIntFunction, getIntArgsV, "calltmp"));
    // square result
    currSymTab->declareLocal("i2", Builder.CreateMul(currSymTab->getLocal("i"),
                                                     currSymTab->getLocal("i"),
                                                     "multmp"));
    // call IO$putInt(i2)
    std::vector<Value *> putIntArgsV(1, currSymTab->getLocal("i2"));
    Builder.CreateCall(PutIntFunction, putIntArgsV, "calltmp");
    // call IO$putChar('\n')
    std::vector<Value *> putCharArgsV(1, ConstantInt::get(Type::getInt8Ty(TheContext), '\n'));
    Builder.CreateCall(PutCharFunction, putCharArgsV, "calltmp");
    // return void
    Builder.CreateRet(nullptr); // c++ nullptr = llvm void

    a->getMethodBody()->accept(*this);

    verifyFunction(*TheFunction);
}

void CodeGenV::visit(ConstructorA* a) {
    indent(a->getDepth()); cout << "ConstructorA\n";
    a->getType()->accept(*this);
    a->getModifers()->accept(*this);
    a->getMethodBody()->accept(*this);
}

void CodeGenV::visit(FormalA* a) {
    indent(a->getDepth()); cout << "FormalA: " << a->getName() << "\n";
    a->getType()->accept(*this);
    currArgTypes.push_back(a->getType()->getIRType());
}

void CodeGenV::visit(DeclStatementA* a) {
    indent(a->getDepth()); cout << "DeclStatementA\n";
    a->getType()->accept(*this);
    a->getLocalList()->accept(*this);
}

void CodeGenV::visit(LocalA* a) {
    indent(a->getDepth()); cout << "LocalA\n";
    a->getExpression()->accept(*this);
}

void CodeGenV::visit(IfStatementA* a) {
    indent(a->getDepth()); cout << "IfStatementA\n";
    a->getExpression()->accept(*this);
    a->getStatement1()->accept(*this);
    a->getStatement2()->accept(*this);
}
void CodeGenV::visit(ExpressionStatementA* a) {
    indent(a->getDepth()); cout << "ExpressionStatementA\n";
    a->getExpression()->accept(*this);
}

void CodeGenV::visit(WhileStatementA* a) {
    indent(a->getDepth()); cout << "WhileStatementA\n";
    a->getExpression()->accept(*this);
    a->getStatement()->accept(*this);
}

void CodeGenV::visit(ReturnStatementA* a) {
    indent(a->getDepth()); cout << "ReturnStatementA\n";
    a->getExpression()->accept(*this);
}
void CodeGenV::visit(ContinueStatementA* a) {
    indent(a->getDepth()); cout << "ContinueStatementA\n";
}
void CodeGenV::visit(BreakStatementA* a) {
    indent(a->getDepth()); cout << "BreakStatementA\n";
}

void CodeGenV::visit(BlockA* a) {
    indent(a->getDepth()); cout << "BlockA\n";
    a->getStatementList()->accept(*this);
}

void CodeGenV::visit(BlockStatementA* a) {
    indent(a->getDepth()); cout << "BlockStatementA\n";
    a->getBlock()->accept(*this);
}

void CodeGenV::visit(EmptyStatementA* a) {
    indent(a->getDepth()); cout << "EmptyStatementA\n";
}

void CodeGenV::visit(NewArrayA* a) {
    indent(a->getDepth()); cout << "NewArrayA\n";
    a->getType()->accept(*this);
    a->getDimList()->accept(*this);
}

void CodeGenV::visit(DimensionA* a) {
    indent(a->getDepth()); cout << "DimensionA" << a->getDim() << endl;
}

void CodeGenV::visit(ArrayRefA* a) {
    indent(a->getDepth()); cout << "ArrayRefA\n";
    a->getName()->accept(*this);
    a->getExpression()->accept(*this);
    a->getDim()->accept(*this);
}

void CodeGenV::visit(PrimaryArrayA* a) {
    indent(a->getDepth()); cout << "PrimaryArrayA\n";
    a->getArray()->accept(*this);
}

void CodeGenV::visit(NonArrayPrimaryA* a) {
    indent(a->getDepth()); cout << "NonArrayPrimaryA\n";
    a->getExpression()->accept(*this);
    a->setReg(a->getExpression()->getReg());
}

void CodeGenV::visit(CallA* a) {
    indent(a->getDepth()); cout << "CallA: " << a->getName() << "\n";
    a->getName()->accept(*this);
    a->getExpressionList()->accept(*this);
}

void CodeGenV::visit(SuperStatementA* a) {
    indent(a->getDepth()); cout << "SuperStatementA\n";
    a->getArgs()->accept(*this);
}

void CodeGenV::visit(OpExpressionA* a) {
    indent(a->getDepth()); cout << "OpExpressionA: " << a->getOp() << " (" << a->getArity() << ")\n";
    nameCase = 6;
    ExpressionA *e1 = a->getExpression1();
    ExpressionA *e2 = a->getExpression2();

    if (a->getArity() == 2)
    {
        e1->accept(*this);
        Value *L = e1->getReg();
        e2->accept(*this);
        Value *R = e2->getReg();

        string op = a->getOp();

        if (!L || !R)
        {
            LogErrorV("Missing operand for binary operator");
        }
        else if ( op == "+")
        {
            a->setReg(Builder.CreateFAdd(L, R, "addtmp"));
        }
        else if (op == "-")
        {
            a->setReg(Builder.CreateFSub(L, R, "subtmp"));
        }
        else if (op == "*")
        {
            a->setReg(Builder.CreateFMul(L, R, "multmp"));
        }
        else if (op == "/")
        {
            a->setReg(Builder.CreateFDiv(L, R, "divtmp"));
        }
        else if (op == "%")
        {
            a->setReg(Builder.CreateSRem(L, R, "modtmp"));
        }
        else if (op == ">")
        {
            a->setReg(Builder.CreateFCmpUGT(L, R, "gcmptmp"));
        }
        else if (op == ">=")
        {
            a->setReg(Builder.CreateFCmpUGE(L, R, "geqcmptmp"));
        }
        else if (op == "<")
        {
            a->setReg(Builder.CreateFCmpULT(L, R, "lcmptmp"));
        }
        else if (op == "<=")
        {
            a->setReg(Builder.CreateFCmpULE(L, R, "leqcmptmp"));
        }
        else if (op == "!=")
        {
            a->setReg(Builder.CreateICmpNE(L, R, "neqcmptmp"));
        }
        else if (op == "==")
        {
            a->setReg(Builder.CreateICmpEQ(L, R, "neqcmptmp"));
        }
        else if (op == "&&")
        {
            a->setReg(Builder.CreateAnd(L, R, "landtmp"));
        }
        else if (op == "||")
        {
            a->setReg(Builder.CreateOr(L, R, "landtmp"));
        }

        else
        {
            LogErrorV("invalid binary operator");
        }

    }
    else
    {
        e1->accept(*this);
        Value *E = e1->getReg();
        string op = a->getOp();
        if ( op == "-" )
        {
            a->setReg(Builder.CreateNeg(E, "neg"));
        }
        else if (op == "!")
        {
            a->setReg(Builder.CreateNot(E, "not"));
        }
        else
        {
            LogErrorV("invalid unary operator");
        }
    }
    nameCase = 0; // TODO: remove when all cases implemented
}

void CodeGenV::visit(ThisExprA* a) {
    indent(a->getDepth()); cout << "ThisExprA\n";
}

void CodeGenV::visit(NewObjExprA* a) {
    indent(a->getDepth()); cout << "NewObjExprA\n";
    a->getName()->accept(*this);
    a->getExpressionList()->accept(*this);
}

void CodeGenV::visit(ThisCallExprA* a) {
    indent(a->getDepth()); cout << "ThisCallExprA\n";
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
}

void CodeGenV::visit(MethodCallExprA* a) {
    indent(a->getDepth()); cout << "MethodCallExprA\n";
    a->getType()->accept(*this);
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
}

void CodeGenV::visit(SuperCallExprA* a) {
    indent(a->getDepth()); cout << "SuperCallExprA\n";
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
}

void CodeGenV::visit(FieldExprA* a) {
    indent(a->getDepth()); cout << "FieldExprA\n";
    a->getType()->accept(*this);
    a->getName()->accept(*this);
}

void CodeGenV::visit(SuperFieldExprA* a) {
    indent(a->getDepth()); cout << "SuperFieldExprA\n";
    a->getName()->accept(*this);
}

void CodeGenV::visit(InitializerA* a) {
    indent(a->getDepth()); cout << "InitializerA\n";
}
