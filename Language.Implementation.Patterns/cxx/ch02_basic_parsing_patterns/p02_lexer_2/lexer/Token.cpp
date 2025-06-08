#include "Token.hpp"
#include <iostream>

const std::vector<std::string> Token::tokenNames = {"n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBRACK"};

std::string Token::toString() const {
    const std::string& tname = tokenNames[type];
    return "<'" + text + "'," + tname;
}

std::ostream& operator<<(std::ostream& os, const Token& t) {
    os << t.toString();
    return os;
}
