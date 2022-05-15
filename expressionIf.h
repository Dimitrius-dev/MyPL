#pragma once

#include "expression.h"

class expressionIf final: public Expression {
public:
    expressionIf(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};