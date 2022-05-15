#include "expressionEq.h"

ExpressionNotEq::ExpressionNotEq(const int& lineNum):
Expression(EXP_OP_NOT_EQUAL, lineNum) {}

void ExpressionNotEq::action(const InterpreterArgs& args) const {
}