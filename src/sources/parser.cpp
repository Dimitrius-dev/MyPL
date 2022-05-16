#include "parser.h"

#include "expression.h"
#include "expressionSum.h"
#include "expressionDiv.h"
#include "expressionSub.h"
#include "expressionMul.h"
#include "expressionVar.h"
#include "expressionVal.h"
#include "expressionPrint.h"
#include "expressionWhile.h"
#include "expressionFor.h"
#include "expressionIf.h"
#include "expressionCodeBlock.h"



#include "expressionAssignVar.h"
#include "expressionSmaller.h"
#include "expressionSmallerOrEq.h"
#include "expressionEq.h"
#include "expressionGreater.h"
#include "expressionGreaterOrEq.h"
#include <stack>
Parser::Parser(Node* node)
: node(node)
{
}

//в конце вызвает compare и передает конечные строки
//циклом разбиваю токены на строки токенов
// например if - становится одной единой строкой
void Parser::addTokens(std::list<Token> tokens)
{
    std::list<Token> tokenLine;

    int openedBrackets = 0;// (
    int openedBraces = 0;// {

    bool operation = false;
    bool end = false;
    for( auto token : tokens)
    {
        const auto type = token.getType();

        if (type == "END")
        {
            if (openedBraces == 0)
            {
                if (openedBrackets == 0)
                {
                    end = true;
                }
            }
            else
            {
                tokenLine.push_back(token);
            }
        }
        else
        {
            if( ( type == "VAR" || type == "FOR" || type == "WHILE" || type == "IF" || type == "PRINT" ) && !operation)
            {
                if (end)
                {
                    if (!tokenLine.empty())
                    {
                        addTokensLine(tokenLine);
                        tokenLine.clear();
                    }
                }
            }
            else if (type == "OPERATION") {
                operation = true;
            } else if (type == "LBR") {
                openedBrackets++;
            } else if (type == "RBR") {
                openedBrackets--;
            } else if (type == "LFBR") {
                openedBraces++;
            } else if (type == "RFBR") {
                openedBraces--;
            } else {
                operation = false;
            }

            end = false;
            tokenLine.push_back(token);
        }
    }

    if (!tokenLine.empty())
    {
        addTokensLine(tokenLine);
        tokenLine.clear();
    }
}

void Parser::addTokensLine(std::list<Token>& tokens) {
//    for (auto token : tokens )
//    {
//        std::cout<<token.getType()<<" ";
//    }
    //std::cout<<'\n';

    const auto & type = tokens.front().getType();

    if(type == "VAR")
    {
        parseVarAssignment(tokens);
    } else if(type == "FOR")
    {
        parseFor(tokens);
    } else if(type == "WHILE")
    {
        parseWhile(tokens);
    } else if(type == "IF")
    {
        parseIf(tokens);
    } else if(type == "PRINT")
    {
        parsePrint(tokens);
    }

}

void Parser::parseVarAssignment(std::list<Token> tokens)
{
    std::cout<<"----\n";
    for(auto token : tokens)
    {
        std::cout<<"type: "<<token.getType()<<" value: "<<token.getValue()<<'\n';
    }

    const auto & token = tokens.front();

    auto nodeChild = new Node(new ExpressionAssignVar(token.getValue(), token.getLine()));

    tokens.pop_front();
    tokens.pop_front();

    nodeChild->addChildBack(addNodeExpression(parseOperations(tokens)));
    node->addChildBack(nodeChild);

}

Node* Parser::addNodeExpression(std::list<Expression*> expressions)
{
    std::stack<Node*> st;

    for (const auto& exp: expressions) {
        Node* node = new Node(exp);
        if (node->getExpression()->isOperation()) {
            node->addChildFront(st.top());
            st.pop();
            node->addChildFront(st.top());
            st.pop();
        }
        st.push(node);
    }
    Node* result = st.top();
    st.pop();

    return result;

}

void Parser::parseFor(std::list<Token> tokens)
{

}

void Parser::parseIf(std::list<Token> tokens)
{

    tokens.pop_front();//remove if
    tokens.pop_front();//remove (

    std::list<Token> conditionTokens;
    int amount = 0;
    for (auto token : tokens)
    {
        if(token.getType() != "LFBR")//until token '{'
        {
            amount++;
            conditionTokens.push_back(token);
        }
        else
        {
            break;
        }
    }
    conditionTokens.pop_back();//remove last token ')'

    for(int i = 0; i < amount; i++)
    {
        tokens.pop_front();
    }

    tokens.pop_front();//remove token '{'
    tokens.pop_back();//remove token '}'

    auto nodeCondition = addNodeExpression(parseLogicOperations(conditionTokens));
    auto nodeBlock = new Node(new ExpressionCodeBlock(tokens.front().getLine()));

    Parser parser(nodeBlock);
    parser.addTokens(tokens);

    node->addChildBack(new Node(new ExpressionIf(nodeCondition, nodeBlock, tokens.front().getLine())));
}

void Parser::parseWhile(std::list<Token> tokens)
{

}

void Parser::parsePrint(std::list<Token> tokens)
{
    tokens.pop_front();
    tokens.pop_front();
    tokens.pop_back();

    auto nodeChild = new Node(new ExpressionPrint(tokens.front().getLine()));

    nodeChild->addChildBack(addNodeExpression(parseOperations(tokens)));
    node->addChildBack(nodeChild);

}

std::list<Expression *> Parser::parseOperations(std::list<Token> tokens) {
    std::list<Expression*> expressions;
    for(auto token: toPostfix(tokens))
    {
        auto type = token.getType();
        if(type == "OPERATION") {
            auto op = token.getValue();
            if (op == "+") {
                expressions.push_back(new ExpressionSum(token.getLine()));
            } else if (op == "-") {
                expressions.push_back(new ExpressionSub(token.getLine()));
            } else if (op == "*") {
                expressions.push_back(new ExpressionMul(token.getLine()));
            } else if (op == "/") {
                expressions.push_back(new ExpressionDiv(token.getLine()));
            }
        } else if(type == "NUMBER")
        {
            expressions.push_back(new ExpressionVal(std::stoi(token.getValue()), token.getLine()));
        }
        else if(type == "VAR")
        {
            expressions.push_back(new ExpressionVar(token.getValue(), token.getLine()));
        }

    }


    return expressions;
}

std::list<Expression *> Parser::parseLogicOperations(std::list<Token> tokens) {
    std::list<Expression*> expressions;
    for(auto token: toLogicPostfix(tokens))
    {
        auto type = token.getType();
        if(type == "LOG_OPERATION") {
            auto op = token.getValue();
            if (op == "<") {
                expressions.push_back(new ExpressionSmaller(token.getLine()));
            } else if (op == "<=") {
                expressions.push_back(new ExpressionSmallerOrEq(token.getLine()));
            } else if (op == "==") {
                expressions.push_back(new ExpressionEq(token.getLine()));
            } else if (op == ">") {
                expressions.push_back(new ExpressionGreater(token.getLine()));
            } else if (op == ">=") {
                expressions.push_back(new ExpressionGreaterOrEq(token.getLine()));
            }
        } else if(type == "NUMBER")
        {
            expressions.push_back(new ExpressionVal(std::stoi(token.getValue()), token.getLine()));
        }
        else if(type == "VAR")
        {
            expressions.push_back(new ExpressionVar(token.getValue(), token.getLine()));
        }

    }


    return expressions;
}

std::list<Token> Parser::toPostfix(std::list<Token> tokens) {
    std::list<Token> postfix;
    std::stack<Token> operators;

    for (const auto &token: tokens) {
        const auto& type = token.getType();

        if (type == "LBR") {
            operators.push(token);
        } else if (type == "RBR") {
            while (operators.top().getType() != "LBR") {
                postfix.push_back(operators.top());
                operators.pop();
            }

            operators.pop();
        } else if (type == "OPERATION") {
            while (!operators.empty() && operatorPriority(token.getValue()) >= operatorPriority(operators.top().getValue())) {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
        } else {
            postfix.push_back(token);
        }
    }

    while (!operators.empty()) {
        postfix.push_back(operators.top());
        operators.pop();
    }

    return postfix;
}

std::list<Token> Parser::toLogicPostfix(std::list<Token> tokens) {
    std::list<Token> postfix;
    std::stack<Token> operators;

    for (const auto &token: tokens) {
        const auto& type = token.getType();

        if (type == "LBR") {
            operators.push(token);
        } else if (type == "RBR") {
            while (operators.top().getType() != "LBR") {
                postfix.push_back(operators.top());
                operators.pop();
            }

            operators.pop();
        } else if (type == "LOG_OPERATION") {
            while (!operators.empty() && operatorLogicPriority(token.getValue()) >= operatorLogicPriority(operators.top().getValue())) {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
        } else {
            postfix.push_back(token);
        }
    }

    while (!operators.empty()) {
        postfix.push_back(operators.top());
        operators.pop();
    }

    return postfix;
}

short Parser::operatorPriority(std::string type) {
    if (type == "*" || type == "/") {
        return 1;
    } else if (type == "+" || type == "-") {
        return 2;
    } else
    {
        return 3;
    }
}

short Parser::operatorLogicPriority(std::string type) {
    if (type == ">" || type == ">=" || type == "<" || type == "<=") {
        return 1;
    } else if (type == "==") {
        return 2;
    } else
    {
        return 4;
    }
}