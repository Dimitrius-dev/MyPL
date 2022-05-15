#pragma once

#include "expression.h"

class ExpressionEq final: public Expression {
public:
    ExpressionEq(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};