#pragma once

#include "expression.h"

class expressionWhile final: public Expression {
public:
    expressionWhile(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};