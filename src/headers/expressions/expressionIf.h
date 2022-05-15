#pragma once

#include "expression.h"

class ExpressionIf final: public Expression {
public:
    ExpressionIf(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};