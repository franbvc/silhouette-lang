#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/Interpreter.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/Pass.h>
#include <llvm/Support/raw_ostream.h>
#include <map>
#include <stack>

class NBlock;

class CodeGenBlock {
  public:
    llvm::BasicBlock *block{};
    std::map<std::string, llvm::Value*> locals;
};

class CodeGenContext {
    std::stack<CodeGenBlock *> blocks;
    llvm::Function *mainFunction;

  public:
    llvm::LLVMContext context;
    llvm::Module *module;
    CodeGenContext()
        : context(), module(new llvm::Module("main", context)),
          mainFunction(nullptr) {}

    void generateCode(NBlock &root);
    llvm::GenericValue runCode();
    std::map<std::string, llvm::Value *> &locals() { return blocks.top()->locals; }
    llvm::BasicBlock *currentBlock() { return blocks.top()->block; }
    void pushBlock(llvm::BasicBlock *block) {
        auto *topBlock = new CodeGenBlock();
        topBlock->block = block;
        blocks.push(topBlock);
    }

    void pushBlockGlobal(llvm::BasicBlock *block) {
        auto *topBlock = new CodeGenBlock();
        topBlock->block = block;
        // Copy the locals from the current block to the new block
        topBlock->locals = blocks.top()->locals;
        blocks.push(topBlock);
    }

    void popBlock() {
        CodeGenBlock *top = blocks.top();
        blocks.pop();
        // Preserve the locals if there is a previous block
        if (!blocks.empty()) {
            CodeGenBlock *previous = blocks.top();
            previous->locals = top->locals;
        }
        delete top;
    }
};
