#include <iostream>
#include <vector>
#include <llvm/Value.h>

class CodeGenContext;
class NStatement;
class NExpression;
class NVariableDeclaration;

typedef std::vector<NStatement *> StatementList;
typedef std::vector<NExpression *> ExpressionList;
typedef std::vector<NVariableDeclaration *> VariableList;
typedef std::vector<NArgDeclaration *> ArgTypeList;
typedef std::vector<NArgument *> ArgList;

class Node
{
public:
    virtual ~Node() {}
    virtual llvm::Value *codeGen(CodeGenContext &context) {}
};

class NExpression : public Node
{
};

class NStatement : public Node
{
};

class NInteger : public NExpression
{
public:
    long long value;
    NInteger(long long value) : value(value) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NFloat : public NExpression
{
public:
    double value;
    NFloat(double value) : value(value) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NString : public NExpression
{
public:
    std::string value;
    NString(const std::string &value) : value(value) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NIdentifier : public NExpression
{
public:
    std::string name;
    NIdentifier(const std::string &name) : name(name) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NMethodCall : public NExpression
{
public:
    const NIdentifier &id;
    ExpressionList arguments;
    NMethodCall(const NIdentifier &id, ExpressionList &arguments) : id(id), arguments(arguments) {}
    NMethodCall(const NIdentifier &id) : id(id) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NUnaryOperator : public NExpression
{
public:
    int op;
    NExpression &rhs;
    NUnaryOperator(int op, NExpression &rhs) : op(op), rhs(rhs) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NBinaryOperator : public NExpression
{
public:
    int op;
    NExpression &lhs;
    NExpression &rhs;
    NBinaryOperator(NExpression &lhs, int op, NExpression &rhs) : lhs(lhs), rhs(rhs), op(op) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NAssignment : public NExpression
{
public:
    NIdentifier &lhs;
    int op;
    NExpression &rhs;
    NAssignment(NIdentifier &lhs, NExpression &rhs) : lhs(lhs), rhs(rhs) {}
    NAssignment(NIdentifier &lhs, int op, NExpression &rhs) : lhs(lhs), rhs(rhs), op(op) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NBlock : public NExpression
{
public:
    StatementList statements;
    NBlock() {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NExpressionStatement : public NStatement
{
public:
    NExpression &expression;
    NExpressionStatement(NExpression &expression) : expression(expression) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NVariableDeclaration : public NStatement
{
public:
    const NIdentifier &type;
    NIdentifier &id;
    NExpression *assignmentExpr;
    NVariableDeclaration(const NIdentifier &type, NIdentifier &id) : type(type), id(id) {}
    NVariableDeclaration(const NIdentifier &type, NIdentifier &id, NExpression *assignmentExpr) : type(type), id(id), assignmentExpr(assignmentExpr) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NArgument : public NStatement
{
public:
    NIdentifier &id;
    NArgument(NIdentifier &id) : id(id) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NFunctionAssignment : public NExpression
{
public:
    const NIdentifier &id;
    ArgList arguments;
    NBlock &block;
    NFunctionAssignment(const NIdentifier &id, NBlock &block) : id(id), block(block) {}
    NFunctionAssignment(const NIdentifier &id, const ArgsList &arguments, NBlock &block) : id(id), arguments(arguments), block(block) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NArgDeclaration : public NStatement
{
public:
    const NIdentifier &type;
    NArgDeclaration(const NIdentifier &type) : type(type) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NFunctionDeclaration : public NStatement
{
public:
    const NIdentifier &id;
    ArgTypeList arguments;
    const NIdentifier &returnType;
    NFunctionDeclaration(const NIdentifier &id, const ArgTypeList &arguments,
                         const NIdentifier &returnType) : id(id), arguments(arguments), returnType(returnType) {}
    NFunctionDeclaration(const NIdentifier &id, const ArgTypeList &arguments) : id(id), arguments(arguments) {}
    NFunctionDeclaration(const NIdentifier &id, const NIdentifier &returnType) : id(id), returnType(returnType) {}
    NFunctionDeclaration(const NIdentifier &id) : id(id) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NResult : public NStatement
{
public:
    NExpression &expression;
    NResult(NExpression &expression) : expression(expression) {}
    NResult() {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NGuard : public NStatement
{
public:
    NExpression &condition;
    NResult &guardResult;
    NGuard(NExpression &condition, NResult &guardResult) : condition(condition), guardResult(guardResult) {}
    NGuard(NExpression &condition) : condition(condition) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NIfStatement : public NStatement
{
public:
    NExpression &condition;
    NBlock &trueBlock;
    NBlock &falseBlock;
    NIfStatement(NExpression &condition, NBlock &trueBlock, NBlock &falseBlock) : condition(condition), trueBlock(trueBlock), falseBlock(falseBlock) {}
    NIfStatement(NExpression &condition, NBlock &trueBlock) : condition(condition), trueBlock(trueBlock) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NWhileStatement : public NStatement
{
public:
    NExpression &condition;
    NBlock &block;
    NWhileStatement(NExpression &condition, NBlock &block) : condition(condition), block(block) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NPrintStatement : public NStatement
{
public:
    NExpression &expression;
    NPrintStatement(NExpression &expression) : expression(expression) {}
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NReadStatement : public NStatement
{
public:
    virtual llvm::Value *codeGen(CodeGenContext &context);
};

class NEmpty() : public NStatement
{
public:
    virtual llvm::Value *codeGen(CodeGenContext & context);
};