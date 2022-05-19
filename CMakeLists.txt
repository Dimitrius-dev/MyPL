cmake_minimum_required(VERSION 3.22)
project(MyPL)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(src/headers)
include_directories(src/sources)
include_directories(src/headers/nodes)
include_directories(src/sources/nodes)

add_executable(
        MyPL

        src/sources/main.cpp

        src/headers/token.h
        src/sources/token.cpp

        src/headers/lexer.h
        src/sources/lexer.cpp

        src/headers/node.h
        src/sources/node.cpp

        src/headers/parser.h
        src/sources/parser.cpp

        src/headers/nodes/nodeCodeBlock.h
        src/sources/nodes/nodeCodeBlock.cpp

        src/headers/nodes/nodeAssignVar.h
        src/sources/nodes/nodeAssignVar.cpp

        src/headers/nodes/nodeVar.h
        src/sources/nodes/nodeVar.cpp

        src/headers/nodes/nodeVal.h
        src/sources/nodes/nodeVal.cpp

        src/headers/nodes/nodeSum.h
        src/sources/nodes/nodeSum.cpp

        src/headers/interpreterArgs.h
        src/sources/interpreterArgs.cpp

        src/headers/interpreter.h
        src/sources/interpreter.cpp
)
