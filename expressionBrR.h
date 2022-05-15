#pragma once

#include "expression.h"

class expressionBrR final: public Expression {
public:
    expressionBrR(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};