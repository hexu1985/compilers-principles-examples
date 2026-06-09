#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <unordered_map>

#include "antlr4-runtime.h"
#include "LExprLexer.h"
#include "LExprParser.h"
#include "LExprBaseListener.h"

using namespace antlr4;
using namespace antlr4::tree;

// ==================== 使用 ParseTreeProperty 的计算器 ====================
class EvaluatorWithProps : public LExprBaseListener {
public:
    /** maps nodes to integers with Map<ParseTree,Integer> */
    ParseTreeProperty<int> values;

    /** Need to pass e's value out of rule s : e ; */
    void exitS(LExprParser::SContext* ctx) override {
        setValue(ctx, getValue(ctx->e()));  // like: int s() { return e(); }
    }

    void exitMult(LExprParser::MultContext* ctx) override {
        int left = getValue(ctx->e(0));   // e '*' e   # Mult
        int right = getValue(ctx->e(1));
        setValue(ctx, left * right);
    }

    void exitAdd(LExprParser::AddContext* ctx) override {
        int left = getValue(ctx->e(0));   // e '+' e   # Add
        int right = getValue(ctx->e(1));
        setValue(ctx, left + right);
    }

    void exitInt(LExprParser::IntContext* ctx) override {
        std::string intText = ctx->INT()->getText();  // INT   # Int
        setValue(ctx, std::stoi(intText));
    }

    void setValue(ParseTree* node, int value) { 
        values.put(node, value); 
    }
    
    int getValue(ParseTree* node) { 
        return values.get(node); 
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
    EvaluatorWithProps evalProp;
    walker.walk(&evalProp, tree);
    std::cout << "properties result = " << evalProp.getValue(tree) << std::endl;

    return 0;
}
