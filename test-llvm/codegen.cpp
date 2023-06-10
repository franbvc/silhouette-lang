#include "codegen.hpp"
#include "node.hpp"
#include "parser-bison/parser.hpp"
#include <llvm-14/llvm/IR/InstrTypes.h>

using namespace std;

/* Compile the AST into a module */
void CodeGenContext::generateCode(NBlock &root) {
    std::cout << "Generating code...n";

    /* Create the top level interpreter function to call as entry */
    std::vector<llvm::Type *> argTypes;

    // main function as void
    // llvm::FunctionType *ftype = llvm::FunctionType::get(
    //     llvm::Type::getVoidTy(context), argTypes, false);

    // test main return int
    llvm::FunctionType *ftype = llvm::FunctionType::get(
        llvm::Type::getInt64Ty(context), argTypes, false);

    mainFunction = llvm::Function::Create(
        ftype, llvm::GlobalValue::InternalLinkage, "main", module);
    llvm::BasicBlock *bblock =
        llvm::BasicBlock::Create(context, "entry", mainFunction, nullptr);

    /* Push a new variable/block context */
    pushBlock(bblock);
    llvm::Value *mainRetVal =
        root.codeGen(*this); /* emit bytecode for the toplevel block */
    //llvm::ReturnInst::Create(context, mainRetVal, bblock);
    llvm::ReturnInst::Create(context, mainRetVal, this->currentBlock());
    popBlock();

    /* Print the bytecode in a human-readable format
       to see if our program compiled properly
     */
    std::cout << "Code is generated.n" << endl;
    llvm::legacy::PassManager pm;
    pm.add(createPrintModulePass(llvm::outs()));
    pm.run(*module);
}

/* Executes the AST by running the main function */
llvm::GenericValue CodeGenContext::runCode() {
    std::cout << "Running code...n" << endl;

    std::unique_ptr<llvm::ExecutionEngine> ee(
        llvm::EngineBuilder(std::unique_ptr<llvm::Module>(module)).create());

    vector<llvm::GenericValue> noargs;
    llvm::GenericValue v = ee->runFunction(mainFunction, noargs);

    std::cout << "Code was run.n" << endl;

    // Extract the integer value
    long long value = v.IntVal.getSExtValue();

    // Print the value
    std::cout << "Return value: " << value << std::endl;

    return v;
}

/* -- Code Generation -- */

llvm::Value *NInteger::codeGen(CodeGenContext &context) {
    std::cout << "Creating integer: " << value << std::endl;
    return llvm::ConstantInt::get(llvm::Type::getInt64Ty(context.context),
                                  value, true);
}

llvm::Value *NFloat::codeGen(CodeGenContext &context) {
    std::cout << "Creating float: " << value << std::endl;
    return llvm::ConstantFP::get(llvm::Type::getDoubleTy(context.context),
                                 value);
}

llvm::Value *NIdentifier::codeGen(CodeGenContext &context) {
    std::cout << "Creating identifier reference: " << name << std::endl;

    if (context.locals().find(name) == context.locals().end()) {
        std::cerr << "undeclared variable " << name << std::endl;
        return nullptr;
    }

    llvm::Value *variablePtr = context.locals()[name];

    llvm::Type *var_type = variablePtr->getType()->getPointerElementType();
    return new llvm::LoadInst(var_type, variablePtr, "", false,
                              context.currentBlock());
}

llvm::Value *NVariableDeclaration::codeGen(CodeGenContext &context) {
    std::cout << "Creating variable declaration " << type << " " << id.name
              << std::endl;

    llvm::Type *var_type = llvm::Type::getInt64Ty(context.context);
    auto *alloc =
        new llvm::AllocaInst(var_type, 0, id.name, context.currentBlock());

    context.locals()[id.name] = alloc;
    if (assignmentExpr != nullptr) {
        NAssignment assn(id, *assignmentExpr);
        assn.codeGen(context);
    }
    return alloc;
}

llvm::Value *NAssignment::codeGen(CodeGenContext &context) {
    std::cout << "Creating assignment for " << lhs.name << std::endl;
    if (context.locals().find(lhs.name) == context.locals().end()) {
        std::cerr << "undeclared variable " << lhs.name << std::endl;
        return nullptr;
    }

    llvm::Value* variableValue = context.locals()[lhs.name];
    if (!variableValue) {
        std::cerr << "Error accessing variable " << lhs.name << std::endl;
        return nullptr;
    }

    return new llvm::StoreInst(rhs.codeGen(context), context.locals()[lhs.name],
                               false, context.currentBlock());
}

llvm::Value *NBinaryOperator::codeGen(CodeGenContext &context) {
    std::cout << "Creating binary operation " << op << std::endl;
    llvm::Instruction::BinaryOps instr;
    llvm::CmpInst::Predicate cmpInstr;

    switch (op) {
    case TPLUS:
        instr = llvm::Instruction::Add;
        goto math;
    case TMINUS:
        instr = llvm::Instruction::Sub;
        goto math;
    case TMUL:
        instr = llvm::Instruction::Mul;
        goto math;
    case TDIV:
        instr = llvm::Instruction::SDiv;
        goto math;
    case TCEQ:
        cmpInstr = llvm::CmpInst::ICMP_EQ;
        goto cmp;
    case TCNE:
        cmpInstr = llvm::CmpInst::ICMP_NE;
        goto cmp;
    case TCGT:
        cmpInstr = llvm::CmpInst::ICMP_SGT;
        goto cmp;
    case TCGE:
        cmpInstr = llvm::CmpInst::ICMP_SGE;
        goto cmp;
    case TCLT:
        cmpInstr = llvm::CmpInst::ICMP_SLT;
        goto cmp;
    case TCLE:
        cmpInstr = llvm::CmpInst::ICMP_SLE;
        goto cmp;
    case TAND:
        return llvm::BinaryOperator::CreateAnd(
            lhs.codeGen(context), rhs.codeGen(context), "", context.currentBlock());
    case TOR:
        return llvm::BinaryOperator::CreateOr(
            lhs.codeGen(context), rhs.codeGen(context), "", context.currentBlock());
    }

    return nullptr;
math:
    return llvm::BinaryOperator::Create(instr, lhs.codeGen(context),
                                        rhs.codeGen(context), "",
                                        context.currentBlock());

cmp:
    return llvm::ICmpInst::Create(llvm::Instruction::OtherOps::ICmp, cmpInstr,
                                  lhs.codeGen(context), rhs.codeGen(context),
                                  "", context.currentBlock());
}

llvm::Value *NUnaryOperator::codeGen(CodeGenContext &context) {
    std::cout << "Creating unary operation " << op << std::endl;
    llvm::Value *R = rhs.codeGen(context);

    switch (op) {
    case TPLUS:
        return R;

    case TMINUS: {
        return llvm::BinaryOperator::CreateNeg(R, "", context.currentBlock());
    }

    case TNOT: {
        return llvm::BinaryOperator::CreateNot(R, "", context.currentBlock());
    }
    }

    return nullptr;
}

llvm::Value *NBlock::codeGen(CodeGenContext &context) {
    StatementList::const_iterator it;
    llvm::Value *last = nullptr;
    for (it = statements.begin(); it != statements.end(); ++it) {
        std::cout << "Generating code for " << typeid(**it).name() << std::endl;
        last = (**it).codeGen(context);
    }
    std::cout << "Creating block" << std::endl;
    return last;
}

llvm::Value *NExpressionStatement::codeGen(CodeGenContext &context) {
    std::cout << "Generating code for " << typeid(expression).name()
              << std::endl;

    return expression.codeGen(context);
}

llvm::Value *NIfStatement::codeGen(CodeGenContext &context) {
    llvm::Value *condV = condition.codeGen(context);
    if (!condV)
        return nullptr;

    llvm::Type *boolType = llvm::Type::getInt1Ty(context.context);
    llvm::Value *zero = llvm::ConstantInt::getFalse(boolType);

    llvm::Function *currFunc = context.currentBlock()->getParent();

    llvm::BasicBlock *thenBB =
        llvm::BasicBlock::Create(context.context, "then", currFunc);
    llvm::BasicBlock *elseBB =
        llvm::BasicBlock::Create(context.context, "else");
    llvm::BasicBlock *mergeBB =
        llvm::BasicBlock::Create(context.context, "exitIf");

    llvm::CmpInst::Predicate predNe = llvm::CmpInst::ICMP_NE;
    llvm::Value *condInstr =
        llvm::ICmpInst::Create(llvm::Instruction::OtherOps::ICmp, predNe, condV,
                               zero, "", context.currentBlock());

    llvm::BranchInst::Create(thenBB, elseBB, condInstr, context.currentBlock());
    cout << "Created Branch Inst" << endl;

    // Set the current block to the "then" block
    context.pushBlockGlobal(thenBB);

    // Emit bytecode for "then" block
    llvm::Value *thenV = trueBlock.codeGen(context);
    if (!thenV)
        return nullptr;

    llvm::BranchInst::Create(mergeBB, thenBB);

    context.popBlock();
    cout << "Created Branch Then" << endl;

    // Set the current block to the "else" block
    currFunc->getBasicBlockList().push_back(elseBB);
    context.pushBlockGlobal(elseBB);


    // Emit bytecode for "else" block
    llvm::Value *elseV = falseBlock.codeGen(context);
    if (!elseV)
        return nullptr;

    llvm::BranchInst::Create(mergeBB, elseBB);
    context.popBlock();
    cout << "Created Branch Else" << endl;

    // Set the current block to the "merge" block
    currFunc->getBasicBlockList().push_back(mergeBB);
    context.pushBlockGlobal(mergeBB);


    unsigned reservedValues = 2;
    llvm::PHINode* PN = llvm::PHINode::Create(elseV->getType(), reservedValues, "");
    PN->addIncoming(thenV, thenBB);
    PN->addIncoming(elseV, elseBB);

    context.currentBlock()->getInstList().push_back(PN);

    return PN;
}