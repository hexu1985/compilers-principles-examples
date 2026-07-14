#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "antlr4-runtime.h"
#include "VecMathLexer.h"
#include "VecMathParser.h"
#include "VecMathBaseVisitor.h"
#include "SimplifyRewriter.hpp"

using namespace antlr4;
using namespace antlr4::tree;

std::unique_ptr<ANTLRFileStream> makeANTLRFileStream(const std::string& fileName) {
    auto input = std::make_unique<ANTLRFileStream>();
    input->loadFromFile(fileName);
    return input;
}

// ==================== 主函数 ====================
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
    VecMathLexer lexer(input.get());
    CommonTokenStream tokens(&lexer);
    VecMathParser parser(&tokens);
    parser.setBuildParseTree(true);  // 告诉 ANTLR 构建语法树
    ParseTree* tree = parser.prog();    // 解析

    // 以文本形式显示语法树
    std::cout << "Original tree: " << tree->toStringTree(&parser) << std::endl;

    SimplifyRewriter visitor;
    visitor.visit(tree);

    return 0;
}

