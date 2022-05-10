#include "token.h"

Token::Token(std::string type, std::string regexLine)
: type_(type), regexLine_(regexLine)
{

}

std::string Token::getType() const
{
	return type_;
}

std::string Token::getRegexLine() const
{
	return regexLine_;
}

std::string Token::getValue() const
{
	return value_;
}

void Token::setValue(std::string value)
{
	value_ = value;
}

Token& Token::operator=(const Token& from)
{
	type_ = from.getType();
	regexLine_ = from.getRegexLine();
	value_ = from.getValue();
	return *this;
}