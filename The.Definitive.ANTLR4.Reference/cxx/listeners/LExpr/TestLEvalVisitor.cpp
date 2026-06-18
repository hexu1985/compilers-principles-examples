#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "antlr4-runtime.h"
#include "LExprLexer.h"
#include "LExprParser.h"
#include "LExprBaseVisitor.h"

using namespace antlr4;
using namespace antlr4::tree;

// ==================== Visitor 计算器 ====================
// 注意：C++ 中 Visitor 返回类型是 std::any，不是模板参数
class EvalVisitor : public LExprBaseVisitor {
public:
    // 处理乘法规则
    virtual std::any visitMult(LExprParser::MultContext* ctx) override {
        int left = std::any_cast<int>(visit(ctx->e(0)));
        int right = std::any_cast<int>(visit(ctx->e(1)));
        return std::any(left * right);
    }

    // 处理加法规则
    virtual std::any visitAdd(LExprParser::AddContext* ctx) override {
        int left = std::any_cast<int>(visit(ctx->e(0)));
        int right = std::any_cast<int>(visit(ctx->e(1)));
        return std::any(left + right);
    }

    // 处理整数规则
    virtual std::any visitInt(LExprParser::IntContext* ctx) override {
        std::string intText = ctx->INT()->getText();
        return std::any(std::stoi(intText));
    }
};

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
    LExprLexer lexer(input.get());
    CommonTokenStream tokens(&lexer);
    LExprParser parser(&tokens);
    parser.setBuildParseTree(true);  // 告诉 ANTLR 构建语法树
    ParseTree* tree = parser.s();    // 解析

    // 以文本形式显示语法树
    std::cout << tree->toStringTree(&parser) << std::endl;

    EvalVisitor evalVisitor;
    int result = std::any_cast<int>(evalVisitor.visit(tree));
    std::cout << "visitor result = " << result << std::endl;

    return 0;
}
