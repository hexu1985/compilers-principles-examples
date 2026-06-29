#include "Lexer.hpp"

Lexer::~Lexer() {}

/** Move to next non-whitespace character */
void Lexer::consume() {
    advance();
}

/** Move one character; detect "end of file" */
void Lexer::advance() {
    i++;
    if (i >= input.length()) 
        c = EOF;
    else 
        c = input.at(i);
}

/** Ensure x is next character on the input stream */
void Lexer::match(char x) {
    if (c == x) 
        consume();
    else 
        throw LexerError(std::string("expecting ") + x + "; found " + c);
}
