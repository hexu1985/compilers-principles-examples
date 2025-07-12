#pragma once

#include <cstdio>
#include <string>
#include <stdexcept>

#include "Token.hpp"

class LexerError: public std::logic_error {
public:
    LexerError(const std::string& what_arg): std::logic_error(what_arg) {}
};

class Lexer {
public:

#ifndef EOF
    static constexpr char EOF = -1;
#endif
    static constexpr int EOF_TYPE = 1;

    Lexer(const std::string& input_): input(input_) {
        c = input.at(p);
    }

    virtual ~Lexer();
    void consume(); 
    void match(char x);

    virtual Token nextToken() = 0;
    virtual std::string getTokenName(int tokenType) const = 0;

private:
    std::string input;
    int p = 0;

protected:
    char c;
};
