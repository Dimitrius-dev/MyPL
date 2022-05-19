#include "nodeAssignVar.h"
#include <iostream>
NodeAssignVar::NodeAssignVar(std::string name, const int& lineNum):
Node(EXP_OP_ASSIGN_VAR, lineNum), name(name) {}

void NodeAssignVar::action(const InterpreterArgs& args) const {
    args.variables->insert_or_assign(name, args.stack.top());

    std::cout<<args.stack.top()<<'\n';
    args.stack.pop();
}