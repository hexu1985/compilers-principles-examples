#pragma once

#include <memory>
#include <string>
#include <stdexcept>

#include "Token.hpp"

class Lexer {
public:
#ifndef EOF
    static const int EOF = -1;      // represent end of file char
#endif
    static const int EOF_TYPE = 1;  // represent EOF token type

protected:
    std::string input;   // input string
    size_t i = 0;        // index into input of current character
    int c;               // current character

public:
    Lexer(const std::string& input_) : input(input_) {
        c = input.at(i); // prime lookahead
    }

    virtual ~Lexer() = default;

    /** Move one character; detect "end of file" */
    void consume() {
        advance(); WS();
    }

    /** Move one character; detect "end of file" */
    void advance() {
        i++;
        if ( i>= input.length() ) c = EOF;
        else c = input.at(i);
    }

    /** Ensure x is next character on the input stream */
    void match(char x) {
        if (c == x) consume();
        else {
            throw std::runtime_error(std::string("expecting")+x+"; found "+static_cast<char>(c));
        }
    }

    virtual std::unique_ptr<Token> nextToken() = 0;
    virtual void WS() = 0;
    virtual std::string getTokenName(int x) = 0;
};
