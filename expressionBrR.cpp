#include "expressionBrR.h"

ExpressionBrR::ExpressionBrR(const int& lineNum):
Expression(EXP_BRACKET_R, lineNum) {}

void ExpressionBrR:action(const InterpreterArgs& args) const {
    
	

    } else {
        throw std::string("function doesn't return any value") + lineNum;
    }
}