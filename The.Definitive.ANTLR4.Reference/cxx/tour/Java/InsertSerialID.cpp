#include <iostream>
#include <fstream>
#include <memory>

#include "antlr4-runtime.h"
#include "JavaLexer.h"
#include "JavaParser.h"
#include "InsertSerialIDListener.h"   // 之前转换的监听器类

using namespace antlr4;
using namespace antlr4::tree;

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
    
    JavaLexer lexer(input.get());
    CommonTokenStream tokens(&lexer);
    JavaParser parser(&tokens);
    tree::ParseTree* tree = parser.compilationUnit();   // parse

    ParseTreeWalker walker;     // create standard walker
    InsertSerialIDListener extractor(&tokens);
    walker.walk(&extractor, tree);  // initiate walk of tree with listener

    // print back ALTERED stream
    std::cout << extractor.rewriter.getText() << std::endl;

    return 0;
}
