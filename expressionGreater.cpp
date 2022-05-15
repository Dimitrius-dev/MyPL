#include "expressionGreater.h"

ExpressionGreater::ExpressionGreater(const int& lineNum):
Expression(EXP_OP_GREATER, lineNum) {}

void ExpressionGreater::action(const InterpreterArgs& args) const {
    
	

    } else {
        throw std::string("function doesn't return any value") + lineNum;
    }
}