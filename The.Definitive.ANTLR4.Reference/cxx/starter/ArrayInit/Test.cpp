#include <iostream>
#include "antlr4-runtime.h"
#include "ArrayInitLexer.h"
#include "ArrayInitParser.h"

using namespace antlr4;

int main() {
    // 创建一个从标准输入读取的 CharStream
    ANTLRInputStream input(std::cin);

    // 创建词法分析器，使用该 CharStream
    ArrayInitLexer lexer(&input);

    // 创建令牌流，从词法分析器获取令牌
    CommonTokenStream tokens(&lexer);

    // 创建语法分析器，使用令牌流
    ArrayInitParser parser(&tokens);

    // 开始解析，起始规则为 init
    tree::ParseTree *tree = parser.init();

    // 以 LISP 风格打印语法树
    std::cout << tree->toStringTree(&parser) << std::endl;

    return 0;
}
