#include "codegen.hpp"
#include "node.hpp"
#include <iostream>

using namespace std;

extern int yyparse();
extern NBlock *programBlock;

// To compile:
// clang++ ./parser-bison/parser.cpp codegen.cpp main.cpp
// ./tokenizer-flex/tokens.cpp -o parser -lLLVM -L/usr/lib/llvm-14/lib

int main(int argc, char **argv) {
    std::cout << "Running yyparse..." << std::endl;
    yyparse();
    std::cout << "Ran yyparse!" << std::endl;
    std::cout << programBlock << std::endl;

    /* Print Type os statements in programBlock*/
    //for (auto stmt : programBlock->statements)
    //    std::cout << typeid(*stmt).name() << std::endl;

    CodeGenContext context;
    context.generateCode(*programBlock);
    context.runCode();

    return 0;
}
