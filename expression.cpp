#include "expression.h"

Expression::Expression(const ExpressionType& type, const int& lineNum)
: type(type), lineNum(lineNum)
{
}

ExpressionType Expression::getType() const
{
	return type;
}

bool Expression::isOperation() const
{
	return(type == EXP_OP_SUM ||
            type == EXP_OP_SUB ||
            type == EXP_OP_MUL ||
            type == EXP_OP_DIV ||
            type == EXP_OP_EQUAL ||
            type == EXP_OP_NOT_EQUAL ||
            type == EXP_OP_GREATER_OR_EQUAL ||
            type == EXP_OP_SMALLER_OR_EQUAL ||
            type == EXP_OP_SMALLER ||
            type == EXP_OP_GREATER
	);
}