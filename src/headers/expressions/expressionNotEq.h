#pragma once

#include "expression.h"

class ExpressionNotEq final: public Expression {
public:
    ExpressionNotEq(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};