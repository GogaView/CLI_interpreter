cmake_minimum_required(VERSION 3.14)
project(CLI_interpreter)

set(CMAKE_CXX_STANDARD 11)

add_executable(Protei main.cpp ValueCalc.h AddCalc.h AddCalc.cpp SignValue.cpp SignValue.h StringValue.cpp StringValue.h SubCalc.cpp SubCalc.h cast_helpers.cpp cast_helpers.h MultiCalc.cpp MultiCalc.h FunctionCalc.h ConcatCalc.cpp ConcatCalc.h parser_exception.h FunctionCalculator.cpp FunctionCalculator.h)