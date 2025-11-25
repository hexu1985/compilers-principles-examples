#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Token.hpp"
#include "LookaheadLexer.hpp"
#include "LookaheadParser.hpp"
#include "read_file.hpp"

int main(int argc, char* argv[]) {
    const char* file_path = "test.txt";

    if (argc == 2) {
        file_path = argv[1];
    }

    LookaheadLexer* lexer = new LookaheadLexer(read_file(file_path));
    LookaheadParser parser{lexer, 2};
    parser.list();

    return 0;
}
