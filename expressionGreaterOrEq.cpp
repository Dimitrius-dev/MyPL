#include "expressionGreaterOrEq.h"

ExpressionGreater::ExpressionGreater(const int& lineNum):
Expression(EXP_OP_GREATER_OR_EQUAL, lineNum) {}

void ExpressionGreater::action(const InterpreterArgs& args) const {
}