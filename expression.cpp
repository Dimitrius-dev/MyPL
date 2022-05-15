#include "expression.h"

Expression::Expression(const ExpressionType& type, const int& lineNum)
: type(type), lineNum(lineNum)
{
}

~Expression::Expression()
{
}

ExpressionType Expression::getType() const
{
	return type;
}

bool Expression::isOperation() const
{
	return(type == EXP_OP_SUM ||
            type == EXP_OP_SUBTRACTION ||
            type == EXP_OP_MULTIPLICATION ||
            type == EXP_OP_DIVISION ||
            type == EXP_OP_EQUAL ||
            type == EXP_OP_NOT_EQUAL ||
            type == EXP_OP_GREATER_OR_EQUAL ||
            type == EXP_OP_SMALLER_OR_EQUAL ||
            type == EXP_OP_SMALLER ||
            type == EXP_OP_GREATER
	);
}