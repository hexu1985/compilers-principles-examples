#include <iostream>
#include "antlr4-runtime.h"
#include "ArrayInitLexer.h"
#include "ArrayInitParser.h"
#include "ShortToUnicodeString.h"   // 之前的监听器类

int main() {
    // 创建从标准输入读取的 CharStream
    antlr4::ANTLRInputStream input(std::cin);

    // 创建词法分析器
    ArrayInitLexer lexer(&input);

    // 创建令牌流
    antlr4::CommonTokenStream tokens(&lexer);

    // 创建语法分析器
    ArrayInitParser parser(&tokens);

    // 开始解析，起始规则为 init
    antlr4::tree::ParseTree *tree = parser.init();

    // 创建通用的语法树遍历器
    antlr4::tree::ParseTreeWalker walker;

    // 遍历树，触发监听器回调
    ShortToUnicodeString listener;
    walker.walk(&listener, tree);

    // 输出换行
    std::cout << std::endl;

    return 0;
}
