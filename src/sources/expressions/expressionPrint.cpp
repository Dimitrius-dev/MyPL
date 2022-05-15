#include "expressionPrint.h"

#include <iostream>

ExpressionPrint::ExpressionPrint(const int& lineNum):
Expression(EXP_OP_ASSIGN_VAR, lineNum) {}

void ExpressionPrint::action(const InterpreterArgs& args) const {
    
    std::cout<<args.stack.top()<<'\n';
    args.stack.pop();

}