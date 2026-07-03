#include <iostream>
#include <string>
#include <memory>

#include "antlr4-runtime.h"
#include "VecMathLexer.h"
#include "VecMathParser.h"
#include "VecMathBaseListener.h"

using namespace antlr4;
using namespace antlr4::tree;

class PrinterListener : public VecMathBaseListener {
private:
    void print(const std::string& s) {
        std::cout << s;
    }

public:
    // ===== 处理 Assign 标签 (# Assign) =====
    void enterAssign(VecMathParser::AssignContext* ctx) override {
        print(ctx->ID()->getText() + " = ");
    }

    void exitAssign(VecMathParser::AssignContext* ctx) override {
        print("\n");
    }

    // ===== 处理 Print 标签 (# Print) =====
    void enterPrint(VecMathParser::PrintContext* ctx) override {
        print("print ");
    }

    void exitPrint(VecMathParser::PrintContext* ctx) override {
        print("\n");
    }

    // ===== 处理 Int 标签 (# Int) =====
    void enterInt(VecMathParser::IntContext* ctx) override {
        print(ctx->INT()->getText());
    }

    // ===== 处理 Id 标签 (# Id) =====
    void enterId(VecMathParser::IdContext* ctx) override {
        print(ctx->ID()->getText());
    }

    // ===== 处理 Vector 标签 (# Vector) =====
    void enterVector(VecMathParser::VectorContext* ctx) override {
        print("[");
    }

    void exitVector(VecMathParser::VectorContext* ctx) override {
        print("]");
    }

    // 如果语法中 op=('*'|'.') 生成了独立的 Context，使用下面的方法
    // 否则通过 visitTerminal 处理
    void visitTerminal(antlr4::tree::TerminalNode* node) override {
        std::string text = node->getText();

        // 处理操作符
        if (text == "*" || text == "." || text == "+") {
            print(text);
        }
        // 处理逗号
        else if (text == ",") {
            print(", ");
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
    VecMathLexer lexer(input.get());
    CommonTokenStream tokens(&lexer);
    VecMathParser parser(&tokens);
    parser.setBuildParseTree(true);  // 告诉 ANTLR 构建语法树
    ParseTree* tree = parser.prog();    // 解析

    // 以文本形式显示语法树
//    std::cout << tree->toStringTree(&parser) << std::endl;

    ParseTreeWalker walker;

    PrinterListener listener;
    walker.walk(&listener, tree);
    std::cout << std::endl;

    return 0;
}

