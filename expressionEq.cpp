#include "expressionEq.h"

ExpressionEq::ExpressionEq(const int& lineNum):
Expression(EXP_OP_EQUAL, lineNum) {}

void ExpressionEq::action(const InterpreterArgs& args) const {
    
	

    } else {
        throw std::string("function doesn't return any value") + lineNum;
    }
}