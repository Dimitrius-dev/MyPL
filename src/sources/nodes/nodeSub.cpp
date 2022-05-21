#include "nodeSub.h"

NodeSub::NodeSub(const int& lineNum):
Node(EXP_OP_SUM, lineNum) {}

void NodeSub::action(InterpreterArgs* args) const {
    if (args->getStack().size() >= 2) {
        auto arg2 = args->getStack().top();
        args->getStack().pop();
        auto arg1 = args->getStack().top();
        args->getStack().pop();

        args->getStack().push(arg1 - arg2);
    } else {
        throw std::string("function doesn't return any value");
    }
}