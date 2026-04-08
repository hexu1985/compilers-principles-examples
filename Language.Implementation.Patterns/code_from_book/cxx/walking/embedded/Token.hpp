#pragma once

#include <string>

struct Token {
    static constexpr int INVALID_TOKEN_TYPE = 0;
    static constexpr int PLUS = 1;
    static constexpr int MULT = 2;
    static constexpr int DOT = 3;
    static constexpr int INT = 4;
    static constexpr int VEC = 5;
    static constexpr int ID = 6;
    static constexpr int ASSIGN = 7;
    static constexpr int PRINT = 8;
    static constexpr int STAT_LIST = 9;

    int type;
    std::string text;

    Token(int type, const std::string& text) : type(type), text(text) {}
    explicit Token(int type) : type(type), text() {}

    std::string toString() const {
        return text;
    }
};