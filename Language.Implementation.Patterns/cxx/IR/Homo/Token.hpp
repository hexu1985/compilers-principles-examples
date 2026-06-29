#pragma once

#include <string>

class Token {
public:
    static const int INVALID_TOKEN_TYPE = 0;
    static const int PLUS = 1;
    static const int INT = 2;

    int type;
    std::string text;

    Token(int type, const std::string& text) : type(type), text(text) {}
    explicit Token(int type) : type(type) {}

    std::string toString() const {
        return text;
    }
};
