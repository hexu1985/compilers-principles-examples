#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <memory>

#include "antlr4-runtime.h"
#include "LExprLexer.h"
#include "LExprParser.h"
#include "LExprBaseListener.h"

using namespace antlr4;
using namespace antlr4::tree;

// ==================== 计算器类 ====================
class Evaluator : public LExprBaseListener {
public:
    std::stack<int> stack;

    // 处理乘法规则（标签为 Mult）
    void exitMult(LExprParser::MultContext* ctx) override {
        int right = stack.top(); stack.pop();
        int left = stack.top(); stack.pop();
        stack.push(left * right);
    }

    // 处理加法规则（标签为 Add）
    void exitAdd(LExprParser::AddContext* ctx) override {
        int right = stack.top(); stack.pop();
        int left = stack.top(); stack.pop();
        stack.push(left + right);
    }

    // 处理整数规则（标签为 Int）
    void exitInt(LExprParser::IntContext* ctx) override {
        stack.push(std::stoi(ctx->INT()->getText()));
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

    ParseTreeWalker walker;
    Evaluator eval;
    walker.walk(&eval, tree);
    std::cout << "stack result = " << eval.stack.top() << std::endl;

    return 0;
}
