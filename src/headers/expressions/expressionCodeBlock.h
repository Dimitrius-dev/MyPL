#pragma once

#include "expression.h"

class ExpressionCodeBlock final: public Expression {
public:
    ExpressionCodeBlock(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};