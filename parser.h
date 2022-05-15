#ifndef PARSER
#define PARSER

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <regex>

#include "token.h"
#include "listOfTokens.h"

class Parser
{
private:
	Node* node;

public:
	Parser(Node* node);

	void addTokens(std::list<Token> tokens);
	void compare(std::list<Token> tokens);	
	bool checkLine(std::list<Token> tokens);

	void parseVarAssignment(std::list<Token> tokens);
	void parseIf(std::list<Token> tokens);
	void parseWhile(std::list<Token> tokens);
	void parsePrint(std::list<Token> tokens);
};

#endif