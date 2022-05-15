#include "expressionSub.h"

ExpressionSub::ExpressionSub(const int& lineNum):
Expression(EXP_OP_SUB, lineNum) {}

void ExpressionSub::action(const InterpreterArgs& args) const {
    if (args.stack.size() >= 2) {
        auto arg2 = args.stack.top();
        args.stack.pop();
        auto arg1 = args.stack.top();
        args.stack.pop();
        args.stack.push(arg1 - arg2);

    } else {
        throw std::string("function doesn't return any value") + lineNum;
    }
}