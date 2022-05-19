
#include "nodeCodeBlock.h"

NodeCodeBlock::NodeCodeBlock(const int& lineNum):
Node(EXP_CODE_BLOCK, lineNum)
{}

void NodeCodeBlock::action(const InterpreterArgs &args) const {
}
