#pragma once

#include <list>
#include <map>
#include <stack>

#include "node.h"


class Interpreter final {
private:

    std::list<std::map<std::string, int>*> variablesGlobal;
    std::map<std::string, int>* variables;

    std::stack<int> stack;

public:
    Interpreter();
    Interpreter(
            const std::list<std::map<std::string, int>*>& variablesGlobal
            );

    ~Interpreter();

    void execute(const Node*);

    std::stack<int>& getStack();
};