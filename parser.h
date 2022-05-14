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
	std::vector<Token> tokens_;
	int indexOfcurToken = 0;

	void parseVar();
	void parseWhile();
	void parseFor();
	void parsePrint();
	void parseIf();

	void expect(std::string type, bool isSeveral);

public:
	Parser(std::vector<Token> tokens);
	void print();

	void read();


};

#endif