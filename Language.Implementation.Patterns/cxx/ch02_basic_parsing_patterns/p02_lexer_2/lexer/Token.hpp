#pragma once

#include <vector>
#include <string>
#include <iosfwd>

struct Token {
    enum {
        EOF_TYPE = 1,
        NAME = 2,
        COMMA = 3,
        LBRACK = 4,
        RBRACK = 5,
    };

    const static std::vector<std::string> tokenNames;

    Token(int type_, const std::string& text_): type(type_), text(text_) {}

    std::string toString() const;

    int type = 0;
    std::string text;
};

std::ostream& operator<<(std::ostream& os, const Token& t);
