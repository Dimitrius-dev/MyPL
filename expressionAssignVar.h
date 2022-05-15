#pragma once

#include <string>

#include "expression.h"

class ExpressionAssignVar final: public Expression {
public:
    ExpressionAssignVar(std::string name, const int& lineNum);

    void action(const InterpreterArgs& args) const override;
private:
    std::string name;
};