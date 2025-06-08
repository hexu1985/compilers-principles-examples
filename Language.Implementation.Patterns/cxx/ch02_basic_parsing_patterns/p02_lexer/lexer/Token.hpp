#pragma once

#include <vector>
#include <string>
#include <iosfwd>

class Lexer;

struct Token {
    Token(int type_, const std::string& text_): type(type_), text(text_) {}

    std::string toString(const Lexer& lexer) const;

    int type = 0;
    std::string text;
};

