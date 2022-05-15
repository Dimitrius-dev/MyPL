#pragma once

#include "expression.h"

class ExpressionGreater final: public Expression {
public:
    ExpressionGreater(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};