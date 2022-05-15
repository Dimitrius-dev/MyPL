#pragma once

#include "expression.h"

class ExpressionSum final: public Expression {
public:
    ExpressionSum(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};