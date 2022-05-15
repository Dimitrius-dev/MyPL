#include "Interpreter.h"

Interpreter::Interpreter() {
    variables = new std::map<std::string, int>();
}

Interpreter::Interpreter(
        const std::list<std::map<std::string, int>*>& variablesGlobal
):
variablesGlobal(variablesGlobal) {
    variables = new std::map<std::string, int>();
}

Interpreter::~Interpreter() {
}

void Interpreter::execute(const Node* tree) {
    for (auto node: tree->getChildren()) {
        execute(node);
    }

    tree->getExpression()->action(InterpreterArgs(variablesGlobal, variables, stack));
}

std::stack<int>& Interpreter::getStack() {
    return stack;
}