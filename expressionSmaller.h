#pragma once

#include "expression.h"

class ExpressionSmaller final: public Expression {
public:
    ExpressionSmaller(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};