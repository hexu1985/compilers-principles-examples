#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "GraphicsLexer.h"
#include "GraphicsParser.h"

using namespace antlr4;

int main(int argc, const char* argv[]) {
    std::ifstream stream;
    if (argc > 1) {
        stream.open(argv[1]);
        if (!stream.is_open()) {
            std::cerr << "Cannot open file: " << argv[1] << std::endl;
            return 1;
        }
    } else {
        // 从标准输入读取
        std::cin >> std::noskipws;
        std::istream& input = std::cin;
        // 需要把 std::istream 包装成 ANTLRInputStream
        // 这里简化处理：从 std::cin 读入全部内容
        std::string content((std::istreambuf_iterator<char>(std::cin)),
                             std::istreambuf_iterator<char>());
        stream = std::ifstream(); // dummy, 实际使用 ANTLRInputStream(content)
        // 更简单的方法：直接使用 ANTLRInputStream 构造函数
    }
    
    // 使用文件或字符串构造输入流
    ANTLRInputStream input(stream);  // 如果从文件
    // 或者 ANTLRInputStream input(content);  // 如果从 stdin
    
    GraphicsLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    GraphicsParser parser(&tokens);
    
    parser.file();  // 启动解析
    
    return 0;
}
