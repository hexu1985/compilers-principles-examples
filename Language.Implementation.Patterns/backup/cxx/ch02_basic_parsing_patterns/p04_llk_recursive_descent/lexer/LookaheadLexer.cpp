#include "LookaheadLexer.hpp"
#include <sstream>

const std::vector<std::string> LookaheadLexer::tokenNames = {"n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBRACK", "EQUALS"};

std::string LookaheadLexer::getTokenName(int tokenType) const {
    return tokenNames.at(tokenType);
}

Token LookaheadLexer::nextToken() {
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

Token LookaheadLexer::NAME_() {
    std::stringstream buf;
    do {
        buf << c;
        consume();
    } while (isLETTER());
    return Token(NAME, buf.str());
}

void LookaheadLexer::WS() {
    while (c == ' ' || c == '\t' || c == '\n' || c == '\r')
        consume();
}
