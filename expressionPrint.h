#pragma once

#include "expression.h"

class ExpressionPrint final: public Expression {
public:
    ExpressionPrint(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};