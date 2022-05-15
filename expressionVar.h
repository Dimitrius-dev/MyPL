#pragma once

#include "expression.h"

class ExpressionVar final: public Expression {
public:
    ExpressionVar(std::string name, const int& lineNum);

    void action(const InterpreterArgs& args) const override;

private:

    bool callVariableFrom(std::map<std::string, int>* container, std::stack<int>& stack) const;
    std::string name;
};