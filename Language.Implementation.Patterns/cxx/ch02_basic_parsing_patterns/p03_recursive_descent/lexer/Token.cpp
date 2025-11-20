#include "Token.hpp"
#include "Lexer.hpp"

std::string Token::toString(const Lexer& lexer) const {
    std::string tname = lexer.getTokenName(type);
    return "<'" + text + "'," + tname + ">";
}

