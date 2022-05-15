#include "expressionBrL.h"

ExpressionBrL::ExpressionBrL(const int& lineNum):
Expression(EXP_BRACKET_L, lineNum) {}

void ExpressionBrL::action(const InterpreterArgs& args) const {
    
	

    } else {
        throw std::string("function doesn't return any value") + lineNum;
    }
}