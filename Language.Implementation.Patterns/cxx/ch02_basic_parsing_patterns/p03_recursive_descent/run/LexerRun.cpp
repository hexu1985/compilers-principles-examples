#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Token.hpp"
#include "ListLexer.hpp"
#include "read_file.hpp"

int main(int argc, char* argv[]) {
    const char* file_path = "test.txt";

    if (argc == 2) {
        file_path = argv[1];
    }

    ListLexer lexer{read_file(file_path)};
    auto t = lexer.nextToken();
    while (t.type != Lexer::EOF_TYPE) {
        std::cout << "=> " << t.toString(lexer) << "\n";
        t = lexer.nextToken();
    }
}
