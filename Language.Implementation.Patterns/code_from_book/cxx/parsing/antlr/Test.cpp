#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "GraphicsLexer.h"
#include "GraphicsParser.h"

using namespace antlr4;

int main(int argc, const char* argv[]) {
    std::ifstream stream;
    std::unique_ptr<ANTLRInputStream> input;  // 如果从文件
    if (argc > 1) {
        stream.open(argv[1]);
        if (!stream.is_open()) {
            std::cerr << "Cannot open file: " << argv[1] << std::endl;
            return 1;
        }
        input = std::make_unique<ANTLRInputStream>(stream);
    } else {
        // 从标准输入读取
        input = std::make_unique<ANTLRInputStream>(std::cin);
    }
    
    // 使用文件或字符串构造输入流
    //ANTLRInputStream input(stream);  // 如果从文件
    // 或者 ANTLRInputStream input(content);  // 如果从 stdin
    
    GraphicsLexer lexer(input.get());
    CommonTokenStream tokens(&lexer);
    GraphicsParser parser(&tokens);
    
    parser.file();  // 启动解析
    
    return 0;
}
