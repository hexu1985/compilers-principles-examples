#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "ExprLexer.h"
#include "ExprParser.h"

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

#if 0
    std::unique_ptr<std::istream> inputStream;
    if (!inputFile.empty()) {
        // Read from file
        inputStream = std::make_unique<std::ifstream>(inputFile);
        if (!inputStream->good()) {
            std::cerr << "Could not open file: " << inputFile << std::endl;
            return 1;
        }
    } else {
        // Read from stdin
        inputStream = std::make_unique<std::istream>(std::cin.rdbuf());
    }

    ANTLRInputStream input(*inputStream);
    ExprLexer lexer(&input);
#else
    std::unique_ptr<ANTLRInputStream> input;
    if (!inputFile.empty()) {
        input = makeANTLRFileStream(inputFile);
    } else {
        input = std::make_unique<ANTLRInputStream>(std::cin);
    }

    ExprLexer lexer(input.get());
#endif

    CommonTokenStream tokens(&lexer);
    ExprParser parser(&tokens);
    tree::ParseTree* tree = parser.prog();  // parse; start at prog
    std::cout << tree->toStringTree(&parser) << std::endl;  // print tree as text <label id="code.tour.main.7"/>

    return 0;
}
