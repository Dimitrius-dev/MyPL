#ifndef LEXER
#define LEXER


#include <list>
#include <string>
#include <regex>

#include "token.h"

class Lexer
{
private:
	std::list<Token> tokens;
	std::map<std::string, std::regex> lexems;

public:
	Lexer();
	void readFile(std::string path);
	bool checkToken(std::string input);	
	void addToken(std::string input, int lineNum);
	
	void print();
};

#endif