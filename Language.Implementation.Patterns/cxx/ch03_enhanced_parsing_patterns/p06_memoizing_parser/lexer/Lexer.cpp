#include "Lexer.hpp"

Lexer::~Lexer() {}

void Lexer::consume() {
    i++;
    if (i >= input.length()) c = EOF;
    else c = input.at(i);
}

void Lexer::match(char x) {
    if (c == x) consume();
    else throw LexerError(std::string("expecting ") + x + "; found " + c);
}
