#include "Lexer.hpp"

Lexer::~Lexer() {}

void Lexer::consume() {
    p++;
    if (p >= input.length()) c = EOF_CHAR;
    else c = input.at(p);
}

void Lexer::match(char x) {
    if (c == x) consume();
    else throw LexerError(std::string("expecting ") + x + "; found " + c);
}
