#pragma once

#include "expression.h"

class ExpressionDiv final: public Expression {
public:
    ExpressionDiv(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};