#include "expressionFor.h"
#include "interpreter.h"

ExpressionFor::ExpressionFor(Node* nodeCondition, Node* nodeAction, const int& lineNum):
        Expression(EXP_LOOP_FOR, lineNum), nodeCondition(nodeCondition), nodeAction(nodeAction) {}

void ExpressionFor::action(const InterpreterArgs& args) const {

}