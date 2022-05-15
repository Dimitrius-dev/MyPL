#pragma once

#include <string>

#include "expression.h"

class expressionAssignVar final: public Expression {
public:
    expressionAssignVar(std::string name, const int& lineNum);

    void action(const InterpreterArgs& args) const override;
private:
    std::string name;
};