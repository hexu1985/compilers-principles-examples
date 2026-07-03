#include <iostream>
#include <string>
#include <memory>

#include "antlr4-runtime.h"
#include "VecMathLexer.h"
#include "VecMathParser.h"
#include "VecMathBaseVisitor.h"

using namespace antlr4;
using namespace antlr4::tree;

class PrinterVisitor : public VecMathBaseVisitor {
private:
    void print(const std::string& s) {
        std::cout << s;
    }

public:
    virtual std::any visitProg(VecMathParser::ProgContext* ctx) override {
        return visitChildren(ctx);
    }

    // 处理 Assign 标签
    virtual std::any visitAssign(VecMathParser::AssignContext* ctx) override {
        print(ctx->ID()->getText() + "=");
        visit(ctx->expr());
        std::cout << std::endl;
        return nullptr;
    }

    // 处理 Print 标签
    virtual std::any visitPrint(VecMathParser::PrintContext* ctx) override {
        print("print ");
        visit(ctx->expr());
        std::cout << std::endl;
        return nullptr;
    }

    // 处理表达式（通过检查子节点来处理操作符）
    virtual std::any visitExpr(VecMathParser::ExprContext* ctx) override {
        // children 包含 multExpr 和可能的 '+' 操作符
        for (size_t i = 0; i < ctx->children.size(); i++) {
            std::string text = ctx->children[i]->getText();
            if (text == "+") {
                print("+");
            } else {
                visit(ctx->children[i]);
            }
        }
        return nullptr;
    }

    // 处理乘法表达式
    virtual std::any visitMultExpr(VecMathParser::MultExprContext* ctx) override {
        // children 包含 primary 和可能的 '*' 或 '.' 操作符
        for (size_t i = 0; i < ctx->children.size(); i++) {
            std::string text = ctx->children[i]->getText();
            if (text == "*" || text == ".") {
                print(text);
            } else {
                visit(ctx->children[i]);
            }
        }
        return nullptr;
    }

    // 处理 Int 标签
    virtual std::any visitInt(VecMathParser::IntContext* ctx) override {
        print(ctx->INT()->getText());
        return nullptr;
    }

    // 处理 Id 标签
    virtual std::any visitId(VecMathParser::IdContext* ctx) override {
        print(ctx->ID()->getText());
        return nullptr;
    }

    // 处理 Vector 标签
    virtual std::any visitVector(VecMathParser::VectorContext* ctx) override {
        print("[");
        auto exprs = ctx->expr();
        for (size_t i = 0; i < exprs.size(); i++) {
            if (i > 0) print(",");
            visit(exprs[i]);
        }
        print("]");
        return nullptr;
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
    VecMathLexer lexer(input.get());
    CommonTokenStream tokens(&lexer);
    VecMathParser parser(&tokens);
    parser.setBuildParseTree(true);  // 告诉 ANTLR 构建语法树
    ParseTree* tree = parser.prog();    // 解析

    // 以文本形式显示语法树
    //std::cout << tree->toStringTree(&parser) << std::endl;

    PrinterVisitor printerVisitor;
    printerVisitor.visit(tree);

    return 0;
}

