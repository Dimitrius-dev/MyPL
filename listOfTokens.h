#ifndef LISTOFTOKENS
#define LISTOFTOKENS

#include <vector>
#include <string>

#include "token.h"

class ListOfTokens
{
private:
	std::vector<Token> types_;

	std::string norm_ = "";
public:
	ListOfTokens();
	std::vector<Token> getTypes();
	std::string getNorm() const;
	Token getTokenByName(std::string name) const;
};

#endif