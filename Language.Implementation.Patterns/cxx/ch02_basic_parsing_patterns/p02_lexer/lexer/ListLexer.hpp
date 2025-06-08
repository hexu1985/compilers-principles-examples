#pragma once

#include "Token.hpp"
#include "Lexer.hpp"

class ListLexer: public Lexer {
public:
    enum {
        T_TYPE_EOF = 1,
        T_TYPE_NAME = 2,
        T_TYPE_COMMA = 3,
        T_TYPE_LBRACK = 4,
        T_TYPE_RBRACK = 5,
    };

    const static std::vector<std::string> tokenNames;

    ListLexer(const std::string& input): Lexer(input) {}

    Token nextToken();

    Token NAME();

    void WS();

    std::string getTokenName(int tokenType) const override;

private:
    bool isLETTER() {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }
};
