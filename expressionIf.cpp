#include "expressionIf.h"

ExpressionIf::ExpressionIf(const int& lineNum):
Expression(EXP_OP_IF, lineNum) {}

void ExpressionIf::action(const InterpreterArgs& args) const {
    
	

    } else {
        throw std::string("function doesn't return any value") + lineNum;
    }
}