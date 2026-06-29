#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "GraphicsLexer.h"
#include "GraphicsParser.h"

using namespace antlr4;

std::unique_ptr<ANTLRFileStream> makeANTLRFileStream(const std::string& fileName) {
    auto input = std::make_unique<ANTLRFileStream>();
    input->loadFromFile(fileName);
    return input;
}

int main(int argc, const char* argv[]) {
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

    GraphicsLexer lexer(input.get());
    CommonTokenStream tokens(&lexer);
    GraphicsParser parser(&tokens);
    
    parser.file();  // 启动解析
    
    return 0;
}
