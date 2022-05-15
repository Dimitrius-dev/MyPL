#pragma once

#include "expression.h"

class expressionBrL final: public Expression {
public:
    expressionBrL(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};