#pragma once

#include "expression.h"

class ExpressionMul final: public Expression {
public:
    ExpressionMul(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};