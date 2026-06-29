#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Token.hpp"
#include "ListLexer.hpp"
#include "ListParser.hpp"
#include "read_file.hpp"

int main(int argc, char* argv[]) {
    const char* file_path = "test.txt";

    if (argc == 2) {
        file_path = argv[1];
    }

    ListLexer* lexer = new ListLexer(read_file(file_path));
    ListParser parser{lexer};
    parser.list();

    return 0;
}
