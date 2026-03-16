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
    int p;               // index into input of current character
    int c;               // current character

public:
    Lexer(const std::string& input) : input(input), p(0) {
        if (input.empty())
            c = EOF;
        else
            c = static_cast<unsigned char>(input[0]); // prime lookahead
    }

    virtual ~Lexer() = default;

    /** Move one character; detect "end of file" */
    void consume() {
        ++p;
        if (p >= static_cast<int>(input.length()))
            c = EOF;
        else
            c = static_cast<unsigned char>(input[p]);
    }

    /** Ensure x is next character on the input stream */
    void match(char x) {
        if (c == x) {
            consume();
        } else {
            std::string msg = "expecting ";
            msg += x;
            msg += "; found ";
            if (c == EOF)
                msg += "EOF";
            else
                msg += static_cast<char>(c);
            throw std::runtime_error(msg);
        }
    }

    virtual std::unique_ptr<Token> nextToken() = 0;
    virtual std::string getTokenName(int tokenType) = 0;
};
