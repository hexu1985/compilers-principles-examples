#include <iostream>
#include <antlr4-runtime.h>
#include "RowsLexer.h"
#include "RowsParser.h"

using namespace antlr4;

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <column_number>" << std::endl;
        return 1;
    }

    int col = std::stoi(argv[1]);

    ANTLRInputStream input(std::cin);
    RowsLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    RowsParser parser(&tokens, col);  // 传递列号参数

    parser.setBuildParseTree(false);  // 不构建语法树，节省时间
    parser.file();  // 开始解析

    return 0;
}
