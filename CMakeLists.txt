cmake_minimum_required(VERSION 3.22)
project(DSL)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/headers)
include_directories(src/sources)
include_directories(src/headers/expressions)
include_directories(src/sources/expressions)

add_executable(
        DSL

        src/sources/main.cpp

        src/headers/lexer.h
        src/sources/lexer.cpp

        src/headers/parser.h
        src/sources/parser.cpp


        src/headers/token.h
        src/sources/token.cpp

        src/headers/node.h
        src/sources/node.cpp

        src/headers/interpreterArgs.h
        src/sources/interpreterArgs.cpp

        src/headers/interpreter.h
        src/sources/interpreter.cpp

        src/headers/expressions/expression.h
        src/sources/expressions/expression.cpp

        src/headers/expressions/expressionAssignVar.h
        src/sources/expressions/expressionAssignVar.cpp

        src/headers/expressions/expressionDiv.h
        src/sources/expressions/expressionDiv.cpp

        src/headers/expressions/expressionEq.h
        src/sources/expressions/expressionEq.cpp

        src/headers/expressions/expressionFor.h
        src/sources/expressions/expressionFor.cpp

        src/headers/expressions/expressionGreater.h
        src/sources/expressions/expressionGreater.cpp

        src/headers/expressions/expressionGreaterOrEq.h
        src/sources/expressions/expressionGreaterOrEq.cpp

        src/headers/expressions/expressionIf.h
        src/sources/expressions/expressionIf.cpp

        src/headers/expressions/expressionMul.h
        src/sources/expressions/expressionMul.cpp

        src/headers/expressions/expressionNotEq.h
        src/sources/expressions/expressionNotEq.cpp

        src/headers/expressions/expressionPrint.h
        src/sources/expressions/expressionPrint.cpp

        src/headers/expressions/expressionSmaller.h
        src/sources/expressions/expressionSmaller.cpp

        src/headers/expressions/expressionSmallerOrEq.h
        src/sources/expressions/expressionSmallerOrEq.cpp

        src/headers/expressions/expressionSub.h
        src/sources/expressions/expressionSub.cpp

        src/headers/expressions/expressionSum.h
        src/sources/expressions/expressionSum.cpp

        src/headers/expressions/expressionVal.h
        src/sources/expressions/expressionVal.cpp

        src/headers/expressions/expressionVar.h
        src/sources/expressions/expressionVar.cpp

        src/headers/expressions/expressionWhile.h
        src/sources/expressions/expressionWhile.cpp
        src/headers/expressions/expressionCodeBlock.h src/sources/expressions/expressionCodeBlock.cpp)