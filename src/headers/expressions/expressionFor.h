#pragma once

#include "expression.h"

class ExpressionFor final: public Expression {
public:
    ExpressionFor(Node* nodeCondition, Node* nodeAction, const int& lineNum);

    void action(const InterpreterArgs& args) const override;
private:
    Node* nodeCondition;
    Node* nodeAction;
};