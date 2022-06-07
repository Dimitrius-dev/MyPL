#include "nodeLog.h"

//#include <string>
#include <fstream>
#include <ctime>

NodeLog::NodeLog(const int& lineNum):
Node(NODE_LOG, lineNum) {}


void NodeLog::action(InterpreterArgs* args) const {

    if (args->getStack().size() >= 1) {
        //std::cout<<args->getStack().top()<<'\n';
        this->writeLog(std::to_string(args->getStack().top()));
        //args.stack.pop();
    } else {
        throw std::string("there is no value on line: ") + std::to_string(lineNum);
    }
}

void NodeLog::writeLog(std::string value) const
{
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);

    std::ofstream file;
    file.open("out.log", std::ofstream::app);
    if(!file.is_open())
    {
        //throw std::string("file is not supported");
    } else
    {
        file<<asctime(timeinfo)<<" : "<<value<<'\n';
    }

    file.close();

}