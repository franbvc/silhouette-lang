#include "codegen.hpp"
#include "node.hpp"
#include <iostream>

using namespace std;

extern int yyparse();
extern NBlock *programBlock;

// To compile:
// `clang++ ./parser-bison/parser.cpp codegen.cpp main.cpp
// ./tokenizer-flex/tokens.cpp -o parser -lLLVM -L/usr/lib/llvm-14/lib`
// To compile with CMAKE:
// `cmake --build ./build`

int main(int argc, char **argv) {
  std::cout << "Running yyparse..." << std::endl;
  yyparse();
  std::cout << "Ran yyparse!" << std::endl;
  std::cout << programBlock << std::endl;

  //std::cout << "Statements in program block:" << std::endl;
  ///* Print Type os statements in programBlock*/
  //for (auto stmt : programBlock->statements) {
  //    if (typeid(*stmt) == typeid(NFunctionDeclaration)) {
  //        auto functionDecl = dynamic_cast<NFunctionDeclaration*>(stmt);
  //        for (auto & arg : functionDecl->arguments) {
  //            std::cout << "    " << arg->id.name << std::endl;
  //        }

  //    } else {
  //        std::cout << typeid(*stmt).name() << std::endl;

  //    }
  //}


  std::cout << "End Statements" << std::endl << std::endl;

  CodeGenContext context;
  context.generateCode(*programBlock);
  context.runCode();

  return 0;
}
