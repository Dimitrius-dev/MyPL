#include "expressionSmallerOrEq.h"

ExpressionSmallerOrEq::ExpressionSmallerOrEq(const int& lineNum):
Expression(EXP_OP_SMALLER_OR_EQUAL, lineNum) {}

void ExpressionSmallerOrEq::action(const InterpreterArgs& args) const {
    
	

    } else {
        throw std::string("function doesn't return any value") + lineNum;
    }
}