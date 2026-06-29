#include "BacktrackLexer.hpp"
#include <sstream>

const std::vector<std::string> BacktrackLexer::tokenNames = {"n/a", "<EOF>", "NAME", ",", "[", "]", "="};

std::string BacktrackLexer::getTokenName(int tokenType) const {
    return tokenNames.at(tokenType);
}

Token BacktrackLexer::nextToken() {
    while (c != EOF) {
        switch (c) {
        case ' ':
        case '\t':
        case '\n':
        case '\r': 
            WS(); 
            continue;
        case ',': 
            consume(); 
            return Token(COMMA, ","); 
        case '[': 
            consume(); 
            return Token(LBRACK, "["); 
        case ']': 
            consume(); 
            return Token(RBRACK, "]"); 
        case '=': 
            consume(); 
            return Token(EQUALS, "=");
        default:
            if (isLETTER()) 
                return name();
            throw LexerError(std::string("invalid character: ") + c);
        }
    }
    return Token(EOF_TYPE, "<EOF>");
}

Token BacktrackLexer::name() {
    std::stringstream buf;
    while (isLETTER()) {
        buf << c;
        LETTER();
    }
    return Token(NAME, buf.str());
}

/** LETTER : 'a'..'z'|'A'..'Z'; // define what a letter is (\w) */
void BacktrackLexer::LETTER() {
    if (isLETTER())
        consume();
    else
        throw LexerError(std::string("expecting LETTER; found ") + c);
}

void BacktrackLexer::WS() {
    while (c == ' ' || c == '\t' || c == '\n' || c == '\r')
        advance();
}
