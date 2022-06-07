#pragma once

#include "node.h"

#include <string>

class NodeLog final: public Node {
public:
    NodeLog(const int& lineNum);

    void action(InterpreterArgs* args) const override;

private:
    void writeLog(std::string value) const;
};