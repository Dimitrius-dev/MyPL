#include "expressionFor.h"

ExpressionFor::ExpressionFor(const int& lineNum):
Expression(EXP_LOOP_FOR, lineNum) {}

void ExpressionFor::action(const InterpreterArgs& args) const {
}