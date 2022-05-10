#ifndef LEXER
#define LEXER

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <regex>

#include "token.h"
#include "listOfTokens.h"

class Lexer
{
private:
	std::string path_;
	std::vector<Token> tokens_;
	ListOfTokens *listOfTokens_ = new ListOfTokens();

public:
	Lexer(std::string path);
	void read();
	int getTokenType(std::string line);

	void print();

	bool isNormChar(std::string line);
};

#endif