#ifndef TOKEN
#define TOKEN

#include "string"

class Token
{
public:
	Token(std::string type, std::string regexLine);

	std::string getType() const;
	std::string getRegexLine() const;
	std::string getValue() const;

	void setValue(std::string value);

	Token& operator=(const Token& from);

private:
	std::string type_ = "";
	std::string regexLine_ = "";
	std::string value_ = "";
};

#endif