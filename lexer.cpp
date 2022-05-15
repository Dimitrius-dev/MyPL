#include "lexer.h"

#include <iostream>
#include <fstream>

Lexer::Lexer()
: lexems({
	{"VAR", std::regex("[a-z][A-Za-z0-9]*")},
	{"ASSIGN", std::regex("\\=")},
	{"NUMBER", std::regex("[-]?[1-9]+[0-9]*")},
	{"OPERATION", std::regex("(\\+|\\-|\\/|\\*")},
	{"PRINT", std::regex("print")},
	{"LBR", std::regex("\\(")},
	{"RBR", std::regex("\\)")},
	{"LFBR", std::regex("\\{")},
	{"RFBR", std::regex("\\}")},
	{"SM", std::regex("\\<")},
	{"GR", std::regex("\\>")},
	{"EQ", std::regex("\\=\\=")},
	{"WHILE", std::regex("while")},
	{"FOR", std::regex("for")}
	//{"END", std::regex("\\n")},
	
})

{
	// tokens.push_back(Token());
}

void Lexer::readFile(std::string path)
{
    std::ifstream file(path);

    if (!file.is_open()) {
        file.close();
        throw std::string("can't open file ") + path;
    }

    std::string line;
    for (int i = 0; getline(file, line); i++) {
        if (!line.empty()) {
            std::string oldStr;

            for (int startIndex = 0, endIndex = 1; endIndex <= line.size(); endIndex++) {
                if (startIndex < endIndex) {
                    std::string newStr = line.substr(startIndex, endIndex - startIndex);
                    if (newStr == " ") {
                        startIndex++;
                        continue;
                    } else if (!checkToken(newStr)) {
                        addToken(oldStr.empty() ? newStr : oldStr, i + 1);
                        endIndex--;
                        startIndex = endIndex;
                    } else if (endIndex == line.size()) {
                        addToken(newStr, i + 1);
                        tokens.push_back(Token("END", "\\n", i + 1));
                    }

                    oldStr = newStr;
                }
            }
        }
    }

    file.close();
}


bool Lexer::checkToken(std::string input)
{
	for(auto lexem : lexems)
	{
		if(std::regex_match(input, lexem.second))
		{
			return true;
		}
	}
	return false;
}

void Lexer::addToken(std::string input, int lineNum) {

	for(auto lexem : lexems)
	{
		if(std::regex_match(input, lexem.second))
		{
			tokens.push_back(Token(lexem.first, input, lineNum));
			return;
		}
	}

	throw std::string("lexem not found");

}

void Lexer::print()
{
	
	for(auto token : tokens) {
		std::cout<<"type:|"<<'\t'<<token.getType()<<'\t'<<"|value:|"<<token.getValue()<<"|\n";
	}
	
}

