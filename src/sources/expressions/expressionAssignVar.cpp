#include "expressionAssignVar.h"

ExpressionAssignVar::ExpressionAssignVar(std::string name, const int& lineNum):
Expression(EXP_OP_ASSIGN_VAR, lineNum), name(name) {}

void ExpressionAssignVar::action(const InterpreterArgs& args) const {
    args.variables->insert_or_assign(name, args.stack.top());
    args.stack.pop();
}