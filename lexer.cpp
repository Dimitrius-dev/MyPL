#include "lexer.h"

Lexer::Lexer(std::string path)
: path_(path)
{
	// tokens.push_back(Token());
}

void Lexer::read()
{
	std::ifstream fin;
    	fin.open(path_);
	if (!fin.is_open())
	{
		throw "file does nor exist";
	}
	char ch;
	int id = -2, idS = -2;
	std::string buf = "", bufF = "";
	while(fin.get(ch))
	{
		if((ch == 32)||(ch == '\n')){ continue; } //space char 
		
		if(!isNormChar(std::string(1, ch))){ throw std::string("unidentified char[ ") + ch + " ]"; }

		buf += ch;
		//std::cout<<"buf:"<<buf<<'\n';
		if(id = getTokenType(buf) != -1) {
			idS = id;
			continue;
		}

		if( !buf.empty() )
		{
			//std::cout<<"buf1:\n";
			Token token = listOfTokens_->getTypes()[idS];
			token.setValue(buf.substr(0, buf.length()-1));
			tokens_.push_back(token);

			buf = ch;
		}		
	}

	if(idS = getTokenType(buf) != -1)
	{
		Token token = listOfTokens_->getTypes()[idS];
		token.setValue(buf);
		tokens_.push_back(token);
	}
}

int Lexer::getTokenType(std::string line) {
	for (int i = 0; i < listOfTokens_->getTypes().size(); i++) {
    		std::regex r(listOfTokens_->getTypes()[i].getRegexLine());
		if(std::regex_match(line.data(), r))
		{
			return i;
		}
	}
	return -1;

}

bool Lexer::isNormChar(std::string line)
{
	std::regex r(listOfTokens_->getNorm());
	return std::regex_match(line.data(), r);
}

void Lexer::print()
{
	
	for(auto i : tokens_) {
		std::cout<<"type:|"<<'\t'<<i.getType()<<'\t'<<"|value:|"<<i.getValue()<<"|\n";
	}
	
}