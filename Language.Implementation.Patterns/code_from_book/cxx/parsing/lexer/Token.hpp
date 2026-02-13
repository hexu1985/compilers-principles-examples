#pragma once

#include <string>

class Token {
public:
    int type;
    std::string text;

    Token(int type, const std::string& text) : type(type), text(text) {}

    std::string toString() const; 
};
