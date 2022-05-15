#pragma once

#include "expression.h"

class ExpressionSub final: public Expression {
public:
    ExpressionSub(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};