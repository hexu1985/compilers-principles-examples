#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Token.hpp"
#include "BacktrackLexer.hpp"
#include "BacktrackParser.hpp"
#include "read_file.hpp"

int main(int argc, char* argv[]) {
    const char* file_path = "test.txt";

    if (argc == 2) {
        file_path = argv[1];
    }

    BacktrackLexer* lexer = new BacktrackLexer(read_file(file_path));
    BacktrackParser parser{lexer};
    parser.stat();

    return 0;
}
