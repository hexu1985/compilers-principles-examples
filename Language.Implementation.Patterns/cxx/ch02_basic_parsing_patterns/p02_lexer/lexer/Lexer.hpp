#pragma once

#include <string>
#include <stdexcept>

#include "Token.hpp"

class LexerError: public std::logic_error {
public:
    LexerError(const std::string& what_arg): logic_error(what_arg) {}
};

class Lexer {
public:
    static const char EOF_CHAR = -1;

    Lexer(const std::string& input_): input(input_) {
        c = input.at(p);
    }

    virtual ~Lexer();
    void consume(); 
    void match(char x);

    virtual Token nextToken() = 0;

private:
    std::string input;
    int p = 0;

protected:
    char c;
};
