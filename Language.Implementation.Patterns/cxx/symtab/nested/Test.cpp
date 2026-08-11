#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

#include "antlr4-runtime.h"
#include "CymbolLexer.h"
#include "CymbolParser.h"
#include "DefRefPhase.h"

#include "SymbolTable.hpp"
#include "VariableSymbol.hpp"


std::unique_ptr<ANTLRFileStream> makeANTLRFileStream(const std::string& fileName) {
    auto input = std::make_unique<ANTLRFileStream>();
    input->loadFromFile(fileName);
    return input;
}

int main(int argc, char* argv[]) {
    std::string inputFile;
    if (argc > 1) {
        inputFile = argv[1];
    }

    std::unique_ptr<ANTLRInputStream> input;
    if (!inputFile.empty()) {
        input = makeANTLRFileStream(inputFile);
    } else {
        input = std::make_unique<ANTLRInputStream>(std::cin);
    }

    CymbolLexer lexer(input.get());
    CommonTokenStream tokens(&lexer);
    CymbolParser parser(&tokens);

    parser.setBuildParseTree(true);
    tree::ParseTree* tree = parser.compilationUnit();

    // 显示树结构（文本形式）
    // std::cout << tree->toStringTree(&parser) << std::endl;

    // 遍历解析树
    tree::ParseTreeWalker walker;
    SymbolTable symtab;
    DefRefPhase defRef{&symtab};
    walker.walk(&listener, tree);

    std::cout << "globals: " << globals.toString() << std::endl;

    return 0;
}
