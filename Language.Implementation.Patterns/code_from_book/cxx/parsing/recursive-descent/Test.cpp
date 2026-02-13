#include <iostream>
#include <string>
#include "ListLexer.hpp"   // 包含 ListLexer 及相关的 Token, Lexer 定义

int main(int argc, char* argv[]) {
    // 检查命令行参数
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_string>" << std::endl;
        return 1;
    }

    // 创建词法分析器
    ListLexer lexer(argv[1]);

    // 获取第一个 Token
    Token* t = lexer.nextToken();

    // 循环处理直到 EOF
    while (t->type != Lexer::EOF_TYPE) {
        std::cout << t->toString() << std::endl;
        delete t;               // 释放已处理的 Token 内存
        t = lexer.nextToken();
    }

    // 输出 EOF Token
    std::cout << t->toString() << std::endl;
    delete t;                   // 释放最后一个 Token

    return 0;
}
