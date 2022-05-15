#include "node.h"

Node::Node(const Expression* expression):
        expression(expression) {}

Node::Node(const Expression* expression, const std::list<Node*>& children):
        expression(expression),
        children(children) {}

Node::~Node() {
    delete expression;
    for (auto child: children) {
        delete child;
    }
}

ExpressionType Node::getType() {
    return expression->getType();
}

void Node::addChildFront(Node* child) {
    children.push_front(child);
}

void Node::addChildBack(Node* child) {
    children.push_back(child);
}

std::list<Node *> Node::getChildren() const {
    return children;
}

const Expression* Node::getExpression() const {
    return expression;
}