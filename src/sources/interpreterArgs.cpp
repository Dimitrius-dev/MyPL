#include "interpreterArgs.h"

InterpreterArgs::InterpreterArgs(
        std::list<std::map<std::string, int>*>& variablesGlobal,
        std::map<std::string, int>* variables,
        std::stack<int>& stack
):
        variablesGlobal(variablesGlobal),
        stack(stack)
{
    this->variables = variables;
}