
#include "expressionCodeBlock.h"

ExpressionCodeBlock::ExpressionCodeBlock(const int& lineNum):
Expression(EXP_CODE_BLOCK, lineNum)
{}

void ExpressionCodeBlock::action(const InterpreterArgs &args) const {
}
