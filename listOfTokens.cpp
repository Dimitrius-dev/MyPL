#include "listOfTokens.h"

ListOfTokens::ListOfTokens()
{
	norm_ = "[A-Za-z0-9\\.\\{\\}\\(\\)\\-\\+\\_\\=\\<\\>]";
	
	types_.push_back(Token("VAR", "[a-z][A-Za-z0-9]*"));
	types_.push_back(Token("ASSIGN", "\\="));
	types_.push_back(Token("NUMBER", "[-]?[1-9]+[0-9]*"));
	types_.push_back(Token("OPERATION", "(\\+|\\-|\\/|\\*)"));
	types_.push_back(Token("PRINT", "\\<\\<"));
	types_.push_back(Token("LBR", "\\("));
	types_.push_back(Token("RBR", "\\)"));
	types_.push_back(Token("LFBR", "\\{"));
	types_.push_back(Token("RFBR", "\\}"));
	types_.push_back(Token("LQ", "\\<"));
	types_.push_back(Token("RQ", "\\>"));
}

std::vector<Token> ListOfTokens::getTypes()
{
	return types_;
}

std::string ListOfTokens::getNorm() const
{
	return norm_;	
}