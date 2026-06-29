#include "BacktrackLexer.hpp"
#include <sstream>

const std::vector<std::string> BacktrackLexer::tokenNames = {"n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBRACK", "EQUALS"};

std::string BacktrackLexer::getTokenName(int tokenType) const {
    return tokenNames.at(tokenType);
}

Token BacktrackLexer::nextToken() {
    while (c != EOF) {
        switch (c) {
        case ' ': case '\t': case '\n': case '\r': WS(); continue;
        case ',': consume(); return Token(COMMA, ","); 
        case '[': consume(); return Token(LBRACK, "["); 
        case ']': consume(); return Token(RBRACK, "]"); 
        case '=': consume(); return Token(EQUALS, "=");
        default:
            if (isLETTER()) return NAME_();
            throw LexerError(std::string("invalid character: ") + c);
        }
    }
    return Token(EOF_TYPE, "<EOF>");
}

Token BacktrackLexer::NAME_() {
    std::stringstream buf;
    do {
        buf << c;
        consume();
    } while (isLETTER());
    return Token(NAME, buf.str());
}

void BacktrackLexer::WS() {
    while (c == ' ' || c == '\t' || c == '\n' || c == '\r')
        consume();
}
