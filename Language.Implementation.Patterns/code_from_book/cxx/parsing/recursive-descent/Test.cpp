#include "ListLexer.hpp"
#include "ListParser.hpp"

int main(int argc, char* argv[]) {
    auto lexer = std::make_unique<ListLexer>(argv[1]);  // parse command-line arg
    ListParser parser(std::move(lexer));
    parser.list();  // begin parsing at rule list

    return 0;
}
