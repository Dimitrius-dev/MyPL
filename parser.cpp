#include "parser.h"

#include "expression.h"

Parser::Parser(std::vector<Token> tokens)
: tokens_(tokens)
{
}

//в конце вызвает compare и передает конечные строки
//циклом разбиваю токены на строки токенов
// например if - становится одной единой строкой
void addTokens(std::list<Token> tokens)
{
	
}

// метод должен понимать в какой парсер передавать строку
// вначале if, передаем в parseIf, вначале var ->  
void compare(std::list<Token> tokens)
{

}

// пока нет необходимости	
bool checkLine(std::list<Token> tokens)
{
}


void parseVarAssignment(std::list<Token> tokens)
{
	Expression *expression = new ExpressionAssignVar(tokens.front.name, /*номер строки (положить в токен)*/ );  
}

void parseIf(std::list<Token> tokens)
{
}

void parseWhile(std::list<Token> tokens)
{
}

void parsePrint(std::list<Token> tokens)
{
}
