#include <iostream>
#include <string>

#include "lexer.h"
#include "parser.h"
#include "interpreter.h"

#include "expressionCodeBlock.h"

int main(int argc, char* argv[])
{

	try
	{
		Lexer lexer;
		lexer.readFile("../example.dsl");//(std::string)argv[1]
		lexer.print();

        Node *app = new Node(new ExpressionCodeBlock(0));
		Parser parser(app);
        parser.addTokens(lexer.getTokens());
		Interpreter interpreter;
        interpreter.execute(app);

	}
	catch(std::string error)
	{
		std::cout<<"error code:"<<error<<'\n';
	}

}