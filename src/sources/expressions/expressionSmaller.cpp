#include "expressionSmaller.h"

ExpressionSmaller::ExpressionSmaller(const int& lineNum):
Expression(EXP_OP_SMALLER, lineNum) {}

void ExpressionSmaller::action(const InterpreterArgs& args) const {
}