#include "expressionWhile.h"
#include "interpreter.h"

ExpressionWhile::ExpressionWhile(Node* nodeCondition, Node* nodeAction, const int& lineNum):
        Expression(EXP_LOOP_WHILE, lineNum), nodeCondition(nodeCondition), nodeAction(nodeAction) {}

void ExpressionWhile::action(const InterpreterArgs& args) const {
    args.variablesGlobal.push_front(args.variables);

    Interpreter interpreterCondition(args.variablesGlobal);

    while(true) {
        interpreterCondition.execute(nodeCondition);

        if (interpreterCondition.getStack().top() != 0) {
            Interpreter interpreterAction(args.variablesGlobal);
            interpreterAction.execute(nodeAction);
        } else
        {
            break;
        }
    }

    args.variablesGlobal.pop_front();
}