#include "listOfTokens.h"

ListOfTokens::ListOfTokens()
{
	norm_ = "[A-Za-z0-9\\.\\{\\}\\(\\)\\-\\+\\_\\=\\<\\>\\n]";
	
	types_.push_back(Token("VAR", "[a-z][A-Za-z0-9]*"));
	types_.push_back(Token("ASSIGN", "\\="));
	types_.push_back(Token("NUMBER", "[-]?[1-9]+[0-9]*"));
	types_.push_back(Token("OPERATION", "(\\+|\\-|\\/|\\*|\\=\\=)"));
	types_.push_back(Token("PRINT", "print"));
	types_.push_back(Token("LBR", "\\("));
	types_.push_back(Token("RBR", "\\)"));
	types_.push_back(Token("LFBR", "\\{"));
	types_.push_back(Token("RFBR", "\\}"));
	types_.push_back(Token("LQ", "\\<"));
	types_.push_back(Token("RQ", "\\>"));

	types_.push_back(Token("WHILE", "while"));
	types_.push_back(Token("FOR", "for"));
	types_.push_back(Token("IF", "if"));

	types_.push_back(Token("END", "\\n"));
}

std::vector<Token> ListOfTokens::getTypes()
{
	return types_;
}

std::string ListOfTokens::getNorm() const
{
	return norm_;	
}

Token ListOfTokens::getTokenByName(std::string name) const
{
	for (int i = 0; i < types_.size(); i++) {
    		if(types_[i].getType() == name)
		{
			return types_[i];
		}
	}
	return types_[types_.size() - 1];
}