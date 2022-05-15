#pragma once

#include "expression.h"

class ExpressionSmallerOrEq final: public Expression {
public:
    ExpressionSmallerOrEq(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};