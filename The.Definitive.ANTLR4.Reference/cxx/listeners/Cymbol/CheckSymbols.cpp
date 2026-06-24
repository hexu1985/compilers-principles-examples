#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "CheckSymbols.hpp"
#include "DefPhase.hpp"
#include "RefPhase.hpp"

#include <antlr4-runtime.h>
#include "CymbolLexer.h"
#include "CymbolParser.h"

using namespace antlr4;

Symbol::Type CheckSymbols::getType(int tokenType) {
    switch (tokenType) {
        case CymbolParser::K_VOID:   return Symbol::Type::tVOID;
        case CymbolParser::K_INT:    return Symbol::Type::tINT;
        case CymbolParser::K_FLOAT:  return Symbol::Type::tFLOAT;
        default:                     return Symbol::Type::tINVALID;
    }
}

void CheckSymbols::error(antlr4::Token* t, const std::string& msg) {
    std::cerr << "line " << t->getLine() 
        << ":" << t->getCharPositionInLine() 
        << " " << msg << std::endl;
}

void CheckSymbols::process(int argc, char* argv[]) {
    std::string inputFile;
    if (argc > 1) {
        inputFile = argv[1];
    }

    std::ifstream fileStream;
    std::istream* inputStream = &std::cin;

    if (!inputFile.empty()) {
        fileStream.open(inputFile);
        if (!fileStream.is_open()) {
            std::cerr << "Error: Could not open file " << inputFile << std::endl;
            return;
        }
        inputStream = &fileStream;
    }

    antlr4::ANTLRInputStream input(*inputStream);
    CymbolLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    CymbolParser parser(&tokens);
    parser.setBuildParseTree(true);
    auto tree = parser.file();

    tree::ParseTreeWalker walker;
    DefPhase def;
    walker.walk(&def, tree);

    RefPhase ref(def.globals, def.scopes);
    walker.walk(&ref, tree);
}

void CheckSymbols::main(int argc, char* argv[]) {
    CheckSymbols checker;
    checker.process(argc, argv);
}

int main(int argc, char* argv[]) {
    CheckSymbols::main(argc, argv);
    return 0;
}
