#pragma once

#include <list>
#include <map>
#include <stack>

class Node;

struct InterpreterArgs {
    std::list<std::map<std::string, int>*>& variablesGlobal;
    std::map<std::string, int>* variables;

    std::stack<int>& stack;

    InterpreterArgs(
            std::list<std::map<std::string, int>*>& variablesGlobal,
            std::map<std::string, int>* variables,
            std::stack<int>& stack
    );
};