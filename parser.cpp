#include "parser.h"

Parser::Parser(std::vector<Token> tokens)
: tokens_(tokens)
{
}

void Parser::print()
{
	std::cout<<"-----Parser-----\n";
	for(auto i : tokens_) {
		std::cout<<"type:|"<<'\t'<<i.getType()<<'\t'<<"|value:|"<<i.getValue()<<"|\n";
	}
}

void Parser::read()
{
	
	if(tokens_[indexOfcurToken].getType() == "VAR"){	parseVar(); }
	else if(tokens_[indexOfcurToken].getType() == "WHILE"){ parseWhile(); }
	else if(tokens_[indexOfcurToken].getType() == "FOR"){	parseFor(); }
	else if(tokens_[indexOfcurToken].getType() == "PRINT"){ parsePrint(); }
	else if(tokens_[indexOfcurToken].getType() == "IF"){	parseIf(); }
	else{ throw std::string("waiting token ") + "VAR"; } 
}

void Parser::parseVar()
{

}

void Parser::parseWhile()
{

}

void Parser::parseFor()
{

}

void Parser::parsePrint()
{

}

void Parser::parseIf()
{

}

void Parser::expect(std::string type, bool isSeveral)
{
	if(tokens_[indexOfcurToken].getType() == type)
	{
		indexOfcurToken++;
	}
	else
	{
		if(!isSeveral)
		{
			throw std::string("expected token ") + type;
		}
	}
}