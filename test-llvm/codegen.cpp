#include "codegen.hpp"
#include "node.hpp"
#include "parser-bison/parser.hpp"
#include <llvm-14/llvm/IR/InstrTypes.h>
#include <llvm-14/llvm/IR/IRBuilder.h>

using namespace std;

static std::unique_ptr<llvm::IRBuilder<>> Builder;

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

    Builder = std::make_unique<llvm::IRBuilder<>>(context);

    mainFunction = llvm::Function::Create(
        ftype, llvm::GlobalValue::InternalLinkage, "main", module);
    llvm::BasicBlock *bblock =
        llvm::BasicBlock::Create(context, "entry", mainFunction, nullptr);

    /* Push a new variable/block context */
    pushBlock(bblock);
    llvm::Value *mainRetVal =
        root.codeGen(*this); /* emit bytecode for the toplevel block */
    llvm::ReturnInst::Create(context, mainRetVal, bblock);
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

llvm::Value *NBinaryOperator::codeGen(CodeGenContext &context) {
    std::cout << "Creating binary operation " << op << std::endl;
    llvm::Instruction::BinaryOps instr;
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
    }

    return nullptr;
math:
    return llvm::BinaryOperator::Create(instr, lhs.codeGen(context),
                                        rhs.codeGen(context), "",
                                        context.currentBlock());
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
