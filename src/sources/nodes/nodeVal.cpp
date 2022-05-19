#include "nodeVal.h"

NodeVal::NodeVal(int val, const int& lineNum):
Node(EXP_VAL, lineNum), val(val) {}

void NodeVal::action(const InterpreterArgs& args) const {
	args.stack.push(val); 
}