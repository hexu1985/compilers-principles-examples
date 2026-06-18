#include <iostream>
#include <fstream>
#include <sstream>

#include "antlr4-runtime.h"
#include "ExprLexer.h"
#include "ExprParser.h"
#include "ExprBaseListener.h"

using namespace antlr4;
using namespace antlr4::tree;

// ------------------------------------------------------------
// 1. LeafListener: 只打印叶子节点
// ------------------------------------------------------------
class LeafListener : public ExprBaseListener {
public:
    void visitTerminal(antlr4::tree::TerminalNode* node) override {
        std::cout << node->getText();
    }
};

// ------------------------------------------------------------
// 2. Printer: 带括号的表达式输出 (1+2*3 => (1+(2*3)))
// ------------------------------------------------------------
class Printer : public ExprBaseListener {
public:
    void enterE(ExprParser::EContext* ctx) override {
        if (ctx->children.size() > 1) {
            std::cout << "(";
        }
    }

    void exitE(ExprParser::EContext* ctx) override {
        if (ctx->children.size() > 1) {
            std::cout << ")";
        }
    }

    void visitTerminal(antlr4::tree::TerminalNode* node) override {
        std::cout << node->getText();
    }
};

std::unique_ptr<ANTLRFileStream> makeANTLRFileStream(const std::string& fileName) {
    auto input = std::make_unique<ANTLRFileStream>();
    input->loadFromFile(fileName);
    return input;
}

// ------------------------------------------------------------
// 主函数
// ------------------------------------------------------------
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

    // 词法分析和语法分析
    ExprLexer lexer(input.get());
    CommonTokenStream tokens(&lexer);
    ExprParser parser(&tokens);
    parser.setBuildParseTree(true);

    // 解析得到语法树
    ParseTree* tree = parser.s();

    // 打印语法树（LISP 风格）
    std::cout << tree->toStringTree(&parser) << std::endl;

    // 使用 LeafListener 遍历
    ParseTreeWalker walker;
    LeafListener leafListener;
    walker.walk(&leafListener, tree);
    std::cout << std::endl;

    // 使用 Printer 遍历
    Printer printer;
    walker.walk(&printer, tree);
    std::cout << std::endl;

    return 0;
}
