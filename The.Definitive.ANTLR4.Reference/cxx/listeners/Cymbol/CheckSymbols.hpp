#pragma once

#include "Symbol.hpp"

#include <antlr4-runtime.h>

class CheckSymbols {
public:
    static Symbol::Type getType(int tokenType); 

    static void error(antlr4::Token* t, const std::string& msg); 

    void process(int argc, char* argv[]); 
};

