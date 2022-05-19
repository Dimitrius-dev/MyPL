#pragma once

#include <list>
//#include "expression.h"
#include "interpreterArgs.h"

enum NodeType {
    EXP_VAR,
    EXP_VAL,

    EXP_OP_MUL,
    EXP_OP_DIV,
    EXP_OP_SUM,
    EXP_OP_SUB,

    EXP_OP_SMALLER,
    EXP_OP_SMALLER_OR_EQUAL,
    EXP_OP_GREATER,
    EXP_OP_GREATER_OR_EQUAL,
    EXP_OP_EQUAL,
    EXP_OP_NOT_EQUAL,

    EXP_OP_ASSIGN_VAR,

    EXP_OP_PRINT,

    EXP_IF,

    EXP_LOOP_WHILE,
    EXP_LOOP_FOR,

    EXP_CODE_BLOCK
};

class Node {
protected:
    std::list<Node*> children;

public:
    Node(const NodeType type, const int lineNum);
    ~Node();

    NodeType getType();

    void addChildFront(Node *child);
    void addChildBack(Node *child);

    std::list<Node*> getChildren() const;

    //action
    //Expression(const ExpressionType& type, const int& lineNum);

    NodeType getType() const;
    virtual void action(const InterpreterArgs& args) const = 0;

    bool isOperation() const;

protected:
    const NodeType type;
    const int lineNum;

};