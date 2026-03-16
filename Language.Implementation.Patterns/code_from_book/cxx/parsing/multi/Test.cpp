#include "LookaheadLexer.hpp"
#include "LookaheadParser.hpp"

int main(int argc, char* argv[]) {
    auto lexer = std::make_unique<LookaheadLexer>(argv[1]);  // parse command-line arg
    LookaheadParser parser(std::move(lexer), 2);
    parser.list();  // begin parsing at rule list

    return 0;
}
