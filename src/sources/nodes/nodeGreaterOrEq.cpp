#include "nodeGreaterOrEq.h"

NodeGreaterOrEq::NodeGreaterOrEq(const int& lineNum):
Node(EXP_OP_GREATER_OR_EQUAL, lineNum) {}

void NodeGreaterOrEq::action(InterpreterArgs* args) const {
    if (args->getStack().size() >= 2) {
        auto arg2 = args->getStack().top();
        args->getStack().pop();
        auto arg1 = args->getStack().top();
        args->getStack().pop();

        args->getStack().push( (arg1 >= arg2) ? 1 : 0 );

    } else {
        throw std::string("function doesn't return any value on line: ") + std::to_string(lineNum);
    }
}