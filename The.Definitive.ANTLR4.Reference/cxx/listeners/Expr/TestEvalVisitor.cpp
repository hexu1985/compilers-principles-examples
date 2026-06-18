#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

#include "antlr4-runtime.h"
#include "ExprLexer.h"
#include "ExprParser.h"
#include "ExprBaseVisitor.h"

using namespace antlr4;
using namespace antlr4::tree;

// ------------------------------------------------------------
// EvalVisitor: 继承自 ExprBaseVisitor
// ------------------------------------------------------------
class EvalVisitor : public ExprBaseVisitor {
public:
    // 访问 E 规则（对应 ExprParser::EContext）
    std::any visitE(ExprParser::EContext* ctx) override {
        // 操作符节点有 3 个子节点：左操作数、操作符、右操作数
        if (ctx->children.size() == 3) {
            int left = std::any_cast<int>(visit(ctx->e(0)));
            int right = std::any_cast<int>(visit(ctx->e(1)));

            if (ctx->op->getType() == ExprParser::MULT) {
                return std::any(left * right);
            } else {
                return std::any(left + right);  // ADD
            }
        }
        
        // 如果是 INT 叶子节点，由 visitTerminal 处理
        return visitChildren(ctx);
    }

    // 访问终结符节点（INT）
    std::any visitTerminal(antlr4::tree::TerminalNode* node) override {
        Token* symbol = node->getSymbol();
        if (symbol->getType() == ExprParser::INT) {
            return std::any(std::stoi(symbol->getText()));
        }
        return 0;
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

    // 1. 词法分析和语法分析
    std::unique_ptr<ANTLRInputStream> input;
    if (!inputFile.empty()) {
        input = makeANTLRFileStream(inputFile);
    } else {
        input = std::make_unique<ANTLRInputStream>(std::cin);
    }
    ExprLexer lexer(input.get());
    CommonTokenStream tokens(&lexer);
    ExprParser parser(&tokens);
    parser.setBuildParseTree(true);

    // 2. 解析得到语法树
    ParseTree* tree = parser.s();

    // 3. 打印语法树（LISP 风格）
    std::cout << tree->toStringTree(&parser) << std::endl;

    // 4. Visitor 计算
    EvalVisitor evalVisitor;
    int result = std::any_cast<int>(evalVisitor.visit(tree));
    std::cout << "visitor result = " << result << std::endl;

    return 0;
}
