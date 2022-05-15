#pragma once

#include "expression.h"

class ExpressionWhile final: public Expression {
public:
    ExpressionWhile(const int& lineNum);

    void action(const InterpreterArgs& args) const override;
};