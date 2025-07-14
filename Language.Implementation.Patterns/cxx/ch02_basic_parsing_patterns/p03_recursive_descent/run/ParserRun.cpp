#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Token.hpp"
#include "ListLexer.hpp"
#include "ListParser.hpp"

int main(int argc, char* argv[]) {
    std::string file_path = "test.txt";

    if (argc == 2) {
        file_path = argv[1];
    }

    std::ifstream ifile{file_path};
    if (!ifile) {
        std::cerr << "open file \"" << file_path << "\" failed\n";
        return 1;
    }
    std::stringstream buf;
    buf << ifile.rdbuf();

    ListLexer* lexer = new ListLexer(buf.str());
    ListParser parser{lexer};
    parser.list();

    return 0;
}
