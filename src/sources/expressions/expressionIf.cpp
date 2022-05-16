#include "expressionIf.h"
#include "interpreter.h"

ExpressionIf::ExpressionIf(Node* nodeCondition, Node* nodeAction, const int& lineNum):
Expression(EXP_IF, lineNum), nodeCondition(nodeCondition), nodeAction(nodeAction) {}

void ExpressionIf::action(const InterpreterArgs& args) const {
    args.variablesGlobal.push_front(args.variables);

    Interpreter interpreterCondition(args.variablesGlobal);

    interpreterCondition.execute(nodeCondition);
    if(interpreterCondition.getStack().top() != 0)
    {
        Interpreter interpreterAction(args.variablesGlobal);
        interpreterAction.execute(nodeAction);
    }

    args.variablesGlobal.pop_front();
}