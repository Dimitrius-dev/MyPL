#pragma once

#include "expression.h"

class ExpressionVal final: public Expression {
public:
    ExpressionVal(int val, const int& lineNum);

    void action(const InterpreterArgs& args) const override;
private:
    int val;
};