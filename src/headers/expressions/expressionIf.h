#pragma once

#include "expression.h"

class ExpressionIf final: public Expression {
public:
    ExpressionIf(Node* nodeCondition, Node* nodeAction, const int& lineNum);

    void action(const InterpreterArgs& args) const override;
private:
    Node* nodeCondition;
    Node* nodeAction;
};