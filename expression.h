#pragma once

#include "interpreterArgs.h"

enum ExpressionType {
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

class Expression {
protected:
    const ExpressionType type;
    const int lineNum;

public:
    Expression(const ExpressionType& type, const int& lineNum);
    virtual ~Expression();

    ExpressionType getType() const;

    virtual void action(const InterpreterArgs& args) const = 0;

    bool isOperation() const;
};
