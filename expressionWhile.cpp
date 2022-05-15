#include "expressionWhile.h"

ExpressionWhile::ExpressionWhile(const int& lineNum):
Expression(EXP_LOOP_WHILE, lineNum) {}

void ExpressionWhile::action(const InterpreterArgs& args) const {
    
	

    } else {
        throw std::string("function doesn't return any value") + lineNum;
    }
}