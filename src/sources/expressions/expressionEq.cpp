#include "expressionEq.h"

ExpressionEq::ExpressionEq(const int& lineNum):
Expression(EXP_OP_EQUAL, lineNum) {}

void ExpressionEq::action(const InterpreterArgs& args) const {
    if (args.stack.size() >= 2) {
        auto arg2 = args.stack.top();
        args.stack.pop();
        auto arg1 = args.stack.top();
        args.stack.pop();

        if(arg1 == arg2)
        {
            args.stack.push(1);
        } else
        {
            args.stack.push(0);
        }


    } else
    {
        throw std::string("function doesn't return any value");
    }
}