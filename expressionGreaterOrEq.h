#pragma once

#include "expression.h"

class ExpressionGreaterOrEq final: public Expression {
public:
    ExpressionGreaterOrEq(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};