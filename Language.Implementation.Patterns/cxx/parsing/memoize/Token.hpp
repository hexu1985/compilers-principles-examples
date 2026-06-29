#pragma once

#include <string>

class Token {
public:
    int type;
    std::string text;

    Token(): type(0) {}
    Token(int type_, const std::string& text_) : type(type_), text(text_) {}

    std::string toString() const; 
};
