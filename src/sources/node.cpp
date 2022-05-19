#include "node.h"


Node::Node(const NodeType type, const int lineNum):
lineNum(lineNum), type(type)
{}

Node::~Node() {
    for (auto child: children) {
        delete child;
    }
}

NodeType Node::getType() {
    return type;
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

bool Node::isOperation() const {
    return(type == EXP_OP_SUM ||
           type == EXP_OP_SUB ||
           type == EXP_OP_MUL ||
           type == EXP_OP_DIV ||
           type == EXP_OP_EQUAL ||
           type == EXP_OP_NOT_EQUAL ||
           type == EXP_OP_GREATER_OR_EQUAL ||
           type == EXP_OP_SMALLER_OR_EQUAL ||
           type == EXP_OP_SMALLER ||
           type == EXP_OP_GREATER
    );
}
