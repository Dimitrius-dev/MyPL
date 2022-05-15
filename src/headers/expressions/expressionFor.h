#pragma once

#include "expression.h"

class ExpressionFor final: public Expression {
public:
    ExpressionFor(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};