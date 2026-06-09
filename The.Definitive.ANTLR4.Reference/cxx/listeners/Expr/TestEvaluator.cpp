#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <memory>
#include <unordered_map>

#include "antlr4-runtime.h"
#include "ExprLexer.h"
#include "ExprParser.h"
#include "ExprBaseListener.h"

using namespace antlr4;
using namespace antlr4::tree;

// ==================== 方法1：使用栈的计算器 ====================
class Evaluator : public ExprBaseListener {
public:
    std::stack<int> stack;

    void exitE(ExprParser::EContext* ctx) override {
        if (ctx->children.size() == 3) {  // 操作符有3个子节点
            int right = stack.top(); stack.pop();
            int left = stack.top(); stack.pop();
            
            if (ctx->op->getType() == ExprParser::MULT) {
                stack.push(left * right);
            } else {
                stack.push(left + right);  // 必须是加法
            }
        }
    }

    void visitTerminal(TerminalNode* node) override {
        Token* symbol = node->getSymbol();
        if (symbol->getType() == ExprParser::INT) {
            stack.push(std::stoi(symbol->getText()));
        }
    }
};

// ==================== 方法2：使用 ParseTreeProperty 的计算器 ====================
class EvaluatorWithProps : public ExprBaseListener {
public:
    ParseTreeProperty<int> values;

    void exitS(ExprParser::SContext* ctx) override {
        values.put(ctx, values.get(ctx->children.at(0)));
    }

    void exitE(ExprParser::EContext* ctx) override {
        if (ctx->children.size() == 3) {  // 操作符有3个子节点
            int left = values.get(ctx->e(0));
            int right = values.get(ctx->e(1));
            
            if (ctx->op->getType() == ExprParser::MULT) {
                values.put(ctx, left * right);
            } else {
                values.put(ctx, left + right);  // 必须是加法
            }
        } else {
            // 整数叶子节点
            values.put(ctx, values.get(ctx->children.at(0)));
        }
    }

    void visitTerminal(TerminalNode* node) override {
        Token* symbol = node->getSymbol();
        if (symbol->getType() == ExprParser::INT) {
            values.put(node, std::stoi(symbol->getText()));
        }
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
    ExprLexer lexer(input.get());
    CommonTokenStream tokens(&lexer);
    ExprParser parser(&tokens);
    parser.setBuildParseTree(true);  // 告诉 ANTLR 构建语法树
    ParseTree* tree = parser.s();    // 解析

    // 以文本形式显示语法树
    std::cout << tree->toStringTree(&parser) << std::endl;

    ParseTreeWalker walker;

    // 使用栈方式计算
    Evaluator eval;
    walker.walk(&eval, tree);
    int result = eval.stack.top(); eval.stack.pop();
    std::cout << "result = " << result << std::endl;

    // 使用 ParseTreeProperty 方式计算
    EvaluatorWithProps eval2;
    walker.walk(&eval2, tree);
    std::cout << "result with tree props = " << eval2.values.get(tree) << std::endl;

    return 0;
}
