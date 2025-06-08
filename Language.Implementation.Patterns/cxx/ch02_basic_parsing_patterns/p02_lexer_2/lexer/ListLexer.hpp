#pragma once

#include "Token.hpp"
#include "Lexer.hpp"

class ListLexer: public Lexer {
public:
    ListLexer(const std::string& input): Lexer(input) {}

    Token nextToken();

    Token NAME();

    void WS();

private:
    bool isLETTER() {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }
};
