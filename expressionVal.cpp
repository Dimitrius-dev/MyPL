#include "expressionVal.h"

ExpressionVal::ExpressionVal(int val, const int& lineNum):
Expression(EXP_VAL, lineNum), val(val) {}

void ExpressionVal::action(const InterpreterArgs& args) const {
	args.stack.push(val); 
}