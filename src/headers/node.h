#pragma once

#include <list>
#include "expression.h"

class Node final {
private:
    const Expression* expression;
    std::list<Node*> children;

public:
    explicit Node(const Expression*);
    Node(const Expression*, const std::list<Node*>&);
    ~Node();

    ExpressionType getType();
    const Expression* getExpression() const;

    void addChildFront(Node *child);
    void addChildBack(Node *child);

    std::list<Node*> getChildren() const;
};