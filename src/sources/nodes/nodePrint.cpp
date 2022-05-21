#include "nodePrint.h"

#include <iostream>

NodePrint::NodePrint(const int& lineNum):
Node(EXP_OP_PRINT, lineNum) {}


void NodePrint::action(InterpreterArgs* args) const {

    if (args->getStack().size() >= 1) {
        std::cout<<args->getStack().top()<<'\n';
        //args.stack.pop();
    } else {
        throw std::string("there is no value");
    }
}