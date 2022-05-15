#include "expressionGreaterOrEq.h"

ExpressionGreaterOrEq::ExpressionGreaterOrEq(const int& lineNum):
Expression(EXP_OP_GREATER_OR_EQUAL, lineNum) {}

void ExpressionGreaterOrEq::action(const InterpreterArgs& args) const {
}