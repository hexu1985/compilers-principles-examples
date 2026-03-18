#include "BacktrackLexer.hpp"
#include "BacktrackParser.hpp"

int main(int argc, char* argv[]) {
    auto lexer = std::make_unique<BacktrackLexer>(argv[1]);  // parse arg
    BacktrackParser parser(std::move(lexer));
    parser.stat();  // begin parsing at rule stat

    return 0;
}
