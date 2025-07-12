#pragma once

#include "Token.hpp"
#include "Lexer.hpp"

class ListLexer: public Lexer {
public:
    static constexpr int NAME = 2;
    static constexpr int COMMA = 3;
    static constexpr int LBRACK = 4;
    static constexpr int RBRACK = 5;

    const static std::vector<std::string> tokenNames;

    ListLexer(const std::string& input): Lexer(input) {}

    Token nextToken();

    Token NAME_();

    void WS();

    std::string getTokenName(int tokenType) const override;

private:
    bool isLETTER() {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }
};
