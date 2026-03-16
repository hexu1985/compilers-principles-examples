#include <iostream>
#include <string>
#include "ListLexer.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_string>" << std::endl;
        return 1;
    }

    ListLexer lexer(argv[1]);
    auto t = lexer.nextToken();
    while (t.type != Lexer::EOF_TYPE) {
        std::cout << t.toString() << std::endl;
        t = lexer.nextToken();
    }
    std::cout << t.toString() << std::endl;    //EOF

    return 0;
}
