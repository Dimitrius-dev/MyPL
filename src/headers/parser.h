#ifndef PARSER
#define PARSER

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <regex>
#include "node.h"
#include "token.h"

class Parser {
private:
    Node *node;

public:
    Parser(Node *node);

    void addTokens(std::list<Token> tokens);

    void parseVarAssignment(std::list<Token> tokens);

    void parseIf(std::list<Token> tokens);

    void parseWhile(std::list<Token> tokens);

    void parseFor(std::list<Token> tokens);

    void parsePrint(std::list<Token> tokens);

    std::list<Expression*> parseOperations(std::list<Token> tokens);

    short operatorPriority(std::string type);

    std::list<Token> toPostfix(std::list<Token> tokens);

    Node* addNodeExpression(std::list<Expression*> expressions);

    void addTokensLine(std::list<Token> &tokens);
};
#endif