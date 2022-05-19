#pragma once

#include "expression.h"

class ExpressionWhile final: public Expression {
public:
    ExpressionWhile(Node* nodeCondition, Node* nodeAction, const int& lineNum);

    void action(const InterpreterArgs& args) const override;
private:
    Node* nodeCondition;
    Node* nodeAction;
};