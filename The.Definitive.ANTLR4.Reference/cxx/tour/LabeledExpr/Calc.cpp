#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "LabeledExprLexer.h"
#include "LabeledExprParser.h"
#include "EvalVisitor.h"

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
    LabeledExprLexer lexer(input.get());
    CommonTokenStream tokens(&lexer);
    LabeledExprParser parser(&tokens);
    tree::ParseTree* tree = parser.prog();
    EvalVisitor eval;
    eval.visit(tree);

    return 0;
}
