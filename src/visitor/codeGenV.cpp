#include "codeGenV.h"

void CodeGenV::visit(StrLitA* a) {
    // indent(a->getDepth()); // cout << "StrLitA: " << a->getValue() << "\n";
    a->setReg(Builder.CreateGlobalStringPtr(StringRef(a->getValue())));
}
void CodeGenV::visit(CharLitA* a) {
    // indent(a->getDepth()); // cout << "CharLitA: " << a->getValue() << endl ;
    a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), a->getValue()));

}
void CodeGenV::visit(IntLitA* a) {
    // indent(a->getDepth()); // cout << "IntLitA: " << a->getValue() << "\n";
    a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), a->getValue()));
}

void CodeGenV::visit(BoolLitA* a) {
    // indent(a->getDepth()); // cout << "BoolLitA: " << a->getValue() << endl;
    a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), a->getValue()));
}

void CodeGenV::visit(NullLitA* a) {
    // indent(a->getDepth()); // cout << "NullLitA\n";
    a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), 0));
}

void CodeGenV::visit(NameA* a) {
    // indent(a->getDepth()); 
    // cout << "NameA: " << a->getName() << " (case " << a->getCase() << ")\n";
    string name = a->getName();
    switch(a->getCase()) {
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 5: break;
        case 6:
            // a->setReg(currSymTab->getGlobal(name));
            AllocaInst *alloca = currSymTab->getGlobal(name);
            // a->setReg()
            // a->setReg(Builder.CreateLoad(Type::getInt64Ty(TheContext), alloca, a->getName()));
            a->setReg(Builder.CreateLoad(alloca, a->getName()));
            break;
        // default:
        //     a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), 1234));    // TODO:
    }
}

void CodeGenV::visit(AssignmentA* a) {
    // indent(a->getDepth()); // cout << "AssignmentA\n";

    a->getLHS()->accept(*this);
    AllocaInst *alloca = currSymTab->getGlobal(a->getLHS()->getName());
    
    a->getRHS()->accept(*this);
    Value *reg = a->getRHS()->getReg();

    a->setReg(Builder.CreateStore(reg, alloca));
}

void CodeGenV::visit(TypeA* a) {
    // indent(a->getDepth()); // cout << "TypeA" << "\n";
}

void CodeGenV::visit(PrimTypeA* a) {
    // indent(a->getDepth()); // cout << "PrimTypeA: " << a->getName()->getName() << "\n";
    // a->getName()->accept(*this);
    string name = a->getName()->getName();
    if (name == "int") {
        // a->setIRType(Type::getInt64Ty(TheContext));
        a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), 0));
    } else if (name == "void") {
        // a->setIRType(Type::getVoidTy(TheContext));
    } else if (name == "char") {
        // a->setIRType(Type::getInt64Ty(TheContext));
        a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), 32));  // space
    } else {
        Print("type unimplemented: " + name);
    }
}

void CodeGenV::visit(ArrayTypeA* a) {
    // indent(a->getDepth()); // cout << "ArrayTypeA: dim " << a->getDim() << "\n";
    a->getType()->accept(*this);
    // TODO:
}

void CodeGenV::visit(ClassTypeA* a) {
    // indent(a->getDepth()); // cout << "ClassTypeA: " << a->getName()->getName() << "\n";
    // a->getName()->accept(*this);
    string name = a->getName()->getName();
    if (name == "string" or name == "String") {
        // a->setIRType(Type::getInt8PtrTy(TheContext));
        // a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), 0));
    } else {
        Print("type not found: " + name);
    }
}

void CodeGenV::visit(StatementA* a) {
    // indent(a->getDepth()); // cout << "StatementA\n";
}

void CodeGenV::visit(PrimaryExprA* a) {
    // indent(a->getDepth()); // cout << "PrimaryExprA\n";
}

void CodeGenV::visit(ExpressionA* a) {
    // indent(a->getDepth()); // cout << "ExpressionA\n";
}

void CodeGenV::visit(ListA* a) {
    // indent(a->getDepth()); // cout << "ListA\n";
    deque<AST *> asts = a->getASTs();
    for (AST *a2 : asts) {
        a2->accept(*this);
    }
}
void CodeGenV::visit(StartA* a) {
    // indent(a->getDepth()); // cout << "StartA\n";
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
    // indent(a->getDepth()); // cout << "SuperA\n";
}

void CodeGenV::visit(ClassA* a) {
    // indent(a->getDepth()); // cout << "ClassA\n" ;

    currClass = a;

    a->getSuperClass()->accept(*this);
    a->getMembers()->accept(*this);
}

void CodeGenV::visit(MethodBodyA* a) {
    // indent(a->getDepth()); // cout << "MethodBodyA\n";
    // a->getFormalList()->accept(*this); // repeated in MethodA
    a->getStatementList()->accept(*this);
}

void CodeGenV::visit(FieldDeclA* a) {
    // indent(a->getDepth()); // cout << "FieldDeclA\n";
    a->getFieldList()->accept(*this);
}

void CodeGenV::visit(VarDeclA* a) {
    // indent(a->getDepth()); // cout << "VarDeclA: " << a->getName() << "\n";
    // a->getName()->accept(*this);
    a->getExpression()->accept(*this);
    Value *reg = a->getExpression()->getReg();

    AllocaInst *alloca = Builder.CreateAlloca(currType, 0, a->getName());
    if (reg != nullptr) {
        Builder.CreateStore(reg, alloca);
    }

    // do this after visiting expression
    currSymTab->declareLocal(a->getName(), alloca);
}

void CodeGenV::visit(FieldA* a) {
    // indent(a->getDepth()); // cout << "FieldA\n";
    a->getModifers()->accept(*this);
    a->getType()->accept(*this);
    a->getVar()->accept(*this);
}

void CodeGenV::visit(ModifierA* a) {
    // indent(a->getDepth()); // cout << "ModifierA: " << a->getModifier() << endl;
}

void CodeGenV::visit(MethodA* a) {
    // indent(a->getDepth()); // cout << "MethodA\n";
    currMethod = a;
    currSymTab = a->getSymbolTable();
    currSymTab->enterScope();
    
    a->getModifiers()->accept(*this);
    a->getType()->accept(*this);
    

    // // return type
    // a->getType()->accept(*this);
    // Type *returnType = a->getType()->getIRType();
    // // arg types
    // std::vector<Type*> argTypes;
    // currArgTypes = argTypes;    
    // a->getArgs()->accept(*this);    // populates currArgTypes
    // FunctionType *FT = FunctionType::get(returnType, currArgTypes, false);
    // // make TheFunction
    // string fname = a->getClass()->getName() + "." + a->getName();   // avoid name collision across classes
    // Function *TheFunction = Function::Create(FT, Function::ExternalLinkage, fname, TheModule.get());   
    // a->setFunc(TheFunction);

    // a's Function is built by Pass1V 
    Function *TheFunction = a->getFunc();
    BasicBlock *BB = BasicBlock::Create(TheContext, "entry", TheFunction);
    Builder.SetInsertPoint(BB);

    // TODO: this is bad
    for (auto &Arg : TheFunction->args()) {
        a->addArgVal(&Arg);
    }

    a->getArgs()->accept(*this);

    // for (AST *arg : a->getArgs()->getASTs()) {
    //     // cout << arg->getReg() << endl;
    // }

    // std::vector<AST*> args = a->getArgs()->getASTs();

    

    // // call IO$getInt()
    // std::vector<Value *> getIntArgsV;
    // currSymTab->declareLocal("i", Builder.CreateCall(GetIntFunction, getIntArgsV, "calltmp"));
    // // square result
    // currSymTab->declareLocal("i2", Builder.CreateMul(currSymTab->getLocal("i"),
    //                                                  currSymTab->getLocal("i"),
    //                                                  "multmp"));
    // // call IO$putInt(i2)
    // std::vector<Value *> putIntArgsV(1, currSymTab->getLocal("i2"));
    // Builder.CreateCall(PutIntFunction, putIntArgsV, "calltmp");
    // // call IO$putChar('\n')
    // std::vector<Value *> putCharArgsV(1, ConstantInt::get(Type::getInt8Ty(TheContext), '\n'));
    // Builder.CreateCall(PutCharFunction, putCharArgsV, "calltmp");

    // build method
    a->getMethodBody()->accept(*this);

    // TODO: segfaults if multiple/no returns
    Builder.CreateRet(nullptr); // c++ nullptr = llvm void

    currSymTab->leaveScope();

    verifyFunction(*TheFunction);
    TheFPM->run(*TheFunction);   // TODO: uncomment for optimizations
}

void CodeGenV::visit(ConstructorA* a) {
    // indent(a->getDepth()); // cout << "ConstructorA\n";
    a->getType()->accept(*this);
    a->getModifers()->accept(*this);
    a->getMethodBody()->accept(*this);
}

void CodeGenV::visit(FormalA* a) {
    // indent(a->getDepth()); 
    // if (a->getInd() >= 0) { // cout << a->getInd() << ". "; }
    // cout << "FormalA: " << a->getName() << "\n";

    int ind = a->getInd();
    Value *reg = currMethod->getArgVal(ind);
    reg->setName(a->getName());

    a->getType()->accept(*this);
    AllocaInst *alloca = Builder.CreateAlloca(a->getType()->getIRType(), 0, "a_"+a->getName());
    Builder.CreateStore(reg, alloca);

    currSymTab->declareLocal(a->getName(), alloca);
}

void CodeGenV::visit(DeclStatementA* a) {
    // indent(a->getDepth()); // cout << "DeclStatementA\n";
    a->getType()->accept(*this);
    currType = a->getType()->getIRType();
    a->getLocalList()->accept(*this);
}

void CodeGenV::visit(LocalA* a) {
    // indent(a->getDepth()); // cout << "LocalA\n";
    a->getExpression()->accept(*this);
}

void CodeGenV::visit(IfStatementA* a) {
    // indent(a->getDepth()); // cout << "IfStatementA\n";

    // Emit cond value.
    a->getExpression()->accept(*this);
    Value* CondV = a->getExpression()->getReg();
    if (CondV->getType() == Type::getInt64Ty(TheContext)) {
        CondV = Builder.CreateICmpNE(CondV, ConstantInt::get(Type::getInt64Ty(TheContext), 0), "ifcond");
    }
    // current function
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    // Create blocks for the then and else cases.  Insert the 'then' block at the
    // end of the function.
    BasicBlock *ThenBB = BasicBlock::Create(TheContext, "then", TheFunction);
    BasicBlock *ElseBB = BasicBlock::Create(TheContext, "else");
    BasicBlock *MergeBB = BasicBlock::Create(TheContext, "ifcont");
    Builder.CreateCondBr(CondV, ThenBB, ElseBB);

    // Emit then value.
    Builder.SetInsertPoint(ThenBB);
    a->getStatement1()->accept(*this);
    // Value *ThenV = a->getStatement1()->getReg();
    Builder.CreateBr(MergeBB);
    // Codegen of 'Then' can change the current block, update ThenBB for the PHI.
    ThenBB = Builder.GetInsertBlock();
    
    // Emit else block.
    TheFunction->getBasicBlockList().push_back(ElseBB);
    Builder.SetInsertPoint(ElseBB);
    a->getStatement2()->accept(*this);
    // Value *ElseV = a->getStatement2()->getReg();
    Builder.CreateBr(MergeBB);
    // codegen of 'Else' can change the current block, update ElseBB for the PHI.
    ElseBB = Builder.GetInsertBlock();

    // Emit merge block.
    TheFunction->getBasicBlockList().push_back(MergeBB);
    Builder.SetInsertPoint(MergeBB);
    // PHINode *PN = Builder.CreatePHI(Type::getInt64Ty(TheContext), 2, "iftmp");
    // PN->addIncoming(ThenV, ThenBB);
    // PN->addIncoming(ElseV, ElseBB);
    // a->setReg(PN);
}
void CodeGenV::visit(ExpressionStatementA* a) {
    // indent(a->getDepth()); // cout << "ExpressionStatementA\n";
    a->getExpression()->accept(*this);
}

void CodeGenV::visit(WhileStatementA* a) {
    // indent(a->getDepth()); // cout << "WhileStatementA\n";
    // a->getExpression()->accept(*this);
    // a->getStatement()->accept(*this);

    // Emit cond value.
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock *CondBB = BasicBlock::Create(TheContext, "cond", TheFunction);
    Builder.CreateBr(CondBB);
    Builder.SetInsertPoint(CondBB);
    a->getExpression()->accept(*this);
    Value* CondV = a->getExpression()->getReg();
    if (CondV->getType() == Type::getInt64Ty(TheContext)) {
        CondV = Builder.CreateICmpNE(CondV, ConstantInt::get(Type::getInt64Ty(TheContext), 0), "ifcond");
    }
    
    // Create blocks for the then and else cases.  Insert the 'then' block at the
    // end of the function.
    BasicBlock *ThenBB = BasicBlock::Create(TheContext, "then", TheFunction);
    BasicBlock *ElseBB = BasicBlock::Create(TheContext, "whilecont");
    Builder.CreateCondBr(CondV, ThenBB, ElseBB);

    // Emit then value.
    Builder.SetInsertPoint(ThenBB);
    a->getStatement()->accept(*this);
    Builder.CreateBr(CondBB);
    // Codegen of 'Then' can change the current block, update ThenBB for the PHI.
    ThenBB = Builder.GetInsertBlock();
    
    // Emit else block.
    TheFunction->getBasicBlockList().push_back(ElseBB);
    Builder.SetInsertPoint(ElseBB);

    
}

void CodeGenV::visit(ReturnStatementA* a) {
    // indent(a->getDepth()); // cout << "ReturnStatementA\n";
    a->getExpression()->accept(*this);
    Builder.CreateRet(a->getExpression()->getReg());
}
void CodeGenV::visit(ContinueStatementA* a) {
    // indent(a->getDepth()); // cout << "ContinueStatementA\n";
}
void CodeGenV::visit(BreakStatementA* a) {
    // indent(a->getDepth()); // cout << "BreakStatementA\n";
}

void CodeGenV::visit(BlockA* a) {
    // indent(a->getDepth()); // cout << "BlockA\n";
    currSymTab->enterScope();
    a->getStatementList()->accept(*this);
    currSymTab->leaveScope();
}

void CodeGenV::visit(BlockStatementA* a) {
    // indent(a->getDepth()); // cout << "BlockStatementA\n";
    a->getBlock()->accept(*this);
}

void CodeGenV::visit(EmptyStatementA* a) {
    // indent(a->getDepth()); // cout << "EmptyStatementA\n";
}

void CodeGenV::visit(NewArrayA* a) {
    // indent(a->getDepth()); // cout << "NewArrayA\n";
    a->getType()->accept(*this);
    a->getDimList()->accept(*this);
}

void CodeGenV::visit(DimensionA* a) {
    // indent(a->getDepth()); // cout << "DimensionA" << a->getDim() << endl;
}

void CodeGenV::visit(ArrayRefA* a) {
    // indent(a->getDepth()); // cout << "ArrayRefA\n";
    a->getName()->accept(*this);
    a->getExpression()->accept(*this);
    a->getDim()->accept(*this);
}

void CodeGenV::visit(PrimaryArrayA* a) {
    // indent(a->getDepth()); // cout << "PrimaryArrayA\n";
    a->getArray()->accept(*this);
}

void CodeGenV::visit(NonArrayPrimaryA* a) {
    // indent(a->getDepth()); // cout << "NonArrayPrimaryA\n";
    a->getExpression()->accept(*this);
    a->setReg(a->getExpression()->getReg());
}

void CodeGenV::visit(CallA* a) {
    // indent(a->getDepth()); // cout << "CallA: " << a->getName() << "\n";
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
}

void CodeGenV::visit(SuperStatementA* a) {
    // indent(a->getDepth()); // cout << "SuperStatementA\n";
    a->getArgs()->accept(*this);
}

void CodeGenV::visit(OpExpressionA* a) {
    // indent(a->getDepth()); 
    // cout << "OpExpressionA: " << a->getOp() << " (arity " << a->getArity() << ")\n";
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

        // TODO: support all types
        if (!L || !R)
        {
            LogErrorV("Missing operand for binary operator");
        }
        else if ( op == "+")
        {
            a->setReg(Builder.CreateAdd(L, R, "addtmp"));
        }
        else if (op == "-")
        {
            a->setReg(Builder.CreateSub(L, R, "subtmp"));
        }
        else if (op == "*")
        {
            a->setReg(Builder.CreateMul(L, R, "multmp"));
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
            a->setReg(Builder.CreateICmpUGT(L, R, "gcmptmp"));
        }
        else if (op == ">=")
        {
            a->setReg(Builder.CreateICmpUGE(L, R, "geqcmptmp"));
        }
        else if (op == "<")
        {
            a->setReg(Builder.CreateICmpULT(L, R, "lcmptmp"));
        }
        else if (op == "<=")
        {
            a->setReg(Builder.CreateICmpULE(L, R, "leqcmptmp"));
        }
        else if (op == "!=")
        {
            a->setReg(Builder.CreateICmpNE(L, R, "neqcmptmp"));
        }
        else if (op == "==")
        {
            a->setReg(Builder.CreateICmpEQ(L, R, "eqcmptmp"));
        }
        else if (op == "&&")
        {
            a->setReg(Builder.CreateAnd(L, R, "landtmp"));
        }
        else if (op == "||")
        {
            a->setReg(Builder.CreateOr(L, R, "lortmp"));
        }
        else if (op == "=")
        {
            LogErrorV("Variable mutation is unimplemented");
        //     // a->setReg(Builder.CreateOr(L, R, "lortmp"));
        //     // // cout << L << endl;
        //     // // cout << R << endl;
        //     // FIXME: partial hack:
        //     // currSymTab->setLocal(e1->getName()->getName(), R);
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
    // indent(a->getDepth()); // cout << "ThisExprA\n";
}

void CodeGenV::visit(NewObjExprA* a) {
    // indent(a->getDepth()); // cout << "NewObjExprA\n";
    a->getName()->accept(*this);
    a->getExpressionList()->accept(*this);
}

void CodeGenV::visit(ThisCallExprA* a) {
    // indent(a->getDepth()); // cout << "ThisCallExprA\n";

    a->getName()->accept(*this);
    MethodA *m = currClass->getMethod(a->getName()->getName());
    Function *f = m->getFunc();
    if (f == nullptr) { LogErrorV("Function undefined"); }

    a->getArgs()->accept(*this);
    std::vector<Value *> callArgs;
    for (AST *arg : a->getArgs()->getASTs()) {
        callArgs.push_back(arg->getReg());
    }
    a->setReg(Builder.CreateCall(f, callArgs, "calltmp"));
}

void CodeGenV::visit(MethodCallExprA* a) {
    // indent(a->getDepth()); 
    // cout << "MethodCallExprA: " << a->getSubject()->getName() << "." << a->getName()->getName() << endl;
    // a->getName()->accept(*this);

    // a->getSubject()->accept(*this);
    ClassA *c = currStart->getClass(a->getSubject()->getName());
    if (c == nullptr) { LogErrorV("Class undefined"); }
    MethodA *m = c->getMethod(a->getName()->getName());
    Function *f = m->getFunc();
    if (f == nullptr) { LogErrorV("Function undefined"); }

    a->getArgs()->accept(*this);
    std::vector<Value *> callArgs;
    for (AST *arg : a->getArgs()->getASTs()) {
        callArgs.push_back(arg->getReg());
    }
    a->setReg(Builder.CreateCall(f, callArgs, "calltmp"));
}

void CodeGenV::visit(SuperCallExprA* a) {
    // indent(a->getDepth()); // cout << "SuperCallExprA\n";
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
}

void CodeGenV::visit(FieldExprA* a) {
    // indent(a->getDepth()); // cout << "FieldExprA\n";
    a->getType()->accept(*this);
    a->getName()->accept(*this);
}

void CodeGenV::visit(SuperFieldExprA* a) {
    // indent(a->getDepth()); // cout << "SuperFieldExprA\n";
    a->getName()->accept(*this);
}

void CodeGenV::visit(InitializerA* a) {
    // indent(a->getDepth()); // cout << "InitializerA\n";
}

