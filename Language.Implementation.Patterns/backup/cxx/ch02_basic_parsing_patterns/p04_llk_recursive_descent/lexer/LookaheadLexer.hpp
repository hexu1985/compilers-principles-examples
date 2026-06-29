#pragma once

#include "Token.hpp"
#include "Lexer.hpp"

class LookaheadLexer: public Lexer {
public:
    static constexpr int NAME = 2;
    static constexpr int COMMA = 3;
    static constexpr int LBRACK = 4;
    static constexpr int RBRACK = 5;
    static constexpr int EQUALS = 6;

    const static std::vector<std::string> tokenNames;

    LookaheadLexer(const std::string& input): Lexer(input) {}

    Token nextToken() override;

    Token NAME_();

    void WS();

    std::string getTokenName(int tokenType) const override;

private:
    bool isLETTER() {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }
};
