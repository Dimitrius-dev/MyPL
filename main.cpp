#include <iostream>
#include <string>

#include "lexer.h"
#include "parser.h"

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		std::cout<<"enter the way\n";
		return 1;
	}

	try
	{
		Lexer lexer((std::string)argv[1]);
		lexer.read();		
		//lexer.print();
		Parser parser(lexer.getTokens());
		parser.print();
		parser.read();

	}
	catch(std::string error)
	{
		std::cout<<"error code:"<<error<<'\n';
	}

}