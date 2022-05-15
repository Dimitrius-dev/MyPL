#include "expressionVar.h"

#include <string>

ExpressionVar::ExpressionVar(std::string name, const int& lineNum)
: Expression(EXP_VAR, lineNum), name(name) {}

void ExpressionVar::action(const InterpreterArgs& args) const {
    if (!callVariableFrom(args.variables, args.stack)) {
       for (auto scope: args.variablesGlobal) {
            if (callVariableFrom(scope, args.stack)) {
                return;
            }
	    }
    }
    else
    {
	    return;
    }
    throw std::string("usage of undeclared var");
    
}

bool ExpressionVar::callVariableFrom(std::map<std::string, int>* container, std::stack<int>& stack) const {
    auto it = container->find(name);
    if (it != container->end()) {
        stack.push(it->second);
        return true;
    }
    return false;
}