#include <iostream>
#include <llvm/IR/Value.h>
#include <utility>
#include <vector>

class CodeGenContext;
class NStatement;
class NExpression;
class NVariableDeclaration;

typedef std::vector<NStatement *> StatementList;
typedef std::vector<NExpression *> ExpressionList;
typedef std::vector<NVariableDeclaration *> VariableList;

class Node {
  public:
    virtual ~Node() {}
    virtual llvm::Value *codeGen(CodeGenContext &context) { return nullptr; }
};

class NExpression : public Node {};
class NStatement : public Node {};

class NBlock : public NExpression {
  public:
    StatementList statements;

    NBlock() = default;

    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NInteger : public NExpression {
  public:
    long long value;

    explicit NInteger(long long value) : value(value) {}

    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NFloat : public NExpression {
  public:
    double value;

    explicit NFloat(double value) : value(value) {}

    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NIdentifier : public NExpression {
  public:
    std::string name;
    NIdentifier(const std::string &name) : name(name) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NVariableDeclaration : public NStatement {
  public:
    const int type;
    NIdentifier &id;
    NExpression *assignmentExpr;

    NVariableDeclaration(NIdentifier &id, const int type)
        : id(id), type(type) {}

    NVariableDeclaration(NIdentifier &id, const int type,
                         NExpression *assignmentExpr)
        : id(id), type(type), assignmentExpr(assignmentExpr) {}

    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NAssignment : public NStatement {
  public:
    int op;
    NIdentifier &lhs;
    NExpression &rhs;

    NAssignment(NIdentifier &lhs, NExpression &rhs) : lhs(lhs), rhs(rhs) {}
    NAssignment(NIdentifier &lhs, int op, NExpression &rhs)
        : lhs(lhs), rhs(rhs), op(op) {}

    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NBinaryOperator : public NExpression {
  public:
    int op;
    NExpression &lhs;
    NExpression &rhs;

    NBinaryOperator(NExpression &lhs, int op, NExpression &rhs)
        : lhs(lhs), rhs(rhs), op(op) {}

    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NUnaryOperator : public NExpression {
  public:
    int op;
    NExpression &rhs;

    NUnaryOperator(int op, NExpression &rhs) : op(op), rhs(rhs) {}

    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NExpressionStatement : public NStatement {
  public:
    NExpression &expression;

    explicit NExpressionStatement(NExpression &expression)
        : expression(expression) {}

    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NIfStatement : public NStatement {
  public:
    NExpression &condition;
    NBlock &trueBlock;
    NBlock &falseBlock;

    NIfStatement(NExpression &condition, NBlock &trueBlock, NBlock &falseBlock)
        : condition(condition), trueBlock(trueBlock), falseBlock(falseBlock) {}
    // NIfStatement(NExpression &condition, NBlock &trueBlock) :
    // condition(condition), trueBlock(trueBlock) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NFunctionDeclaration : public NStatement {
  public:
    const NIdentifier &id;
    VariableList arguments;
    NBlock &block;

    NFunctionDeclaration(const NIdentifier &id, const VariableList &arguments,
                         NBlock &block)
        : id(id), arguments(arguments), block(block) {}

    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NMethodCall : public NExpression {
  public:
    const NIdentifier &id;
    ExpressionList arguments;

    NMethodCall(const NIdentifier &id, ExpressionList &arguments)
        : id(id), arguments(arguments) {}
    NMethodCall(const NIdentifier &id) : id(id) {}

    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NResult : public NStatement {
  public:
    NExpression &expression;
    NResult(NExpression &expression) : expression(expression) {}

    virtual llvm::Value *codeGen(CodeGenContext &context);
};