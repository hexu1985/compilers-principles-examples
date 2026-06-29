#include "ListLexer.hpp"
#include <sstream>

const std::vector<std::string> ListLexer::tokenNames = {"n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBRACK"};

std::string ListLexer::getTokenName(int tokenType) const {
    return tokenNames.at(tokenType);
}

Token ListLexer::nextToken() {
    while (c != EOF) {
        switch (c) {
        case ' ': case '\t': case '\n': case '\r': WS(); continue;
        case ',': consume(); return Token(COMMA, ","); 
        case '[': consume(); return Token(LBRACK, "["); 
        case ']': consume(); return Token(RBRACK, "]"); 
        default:
            if (isLETTER()) return NAME_();
            throw LexerError(std::string("invalid character: ") + c);
        }
    }
    return Token(EOF_TYPE, "<EOF>");
}

Token ListLexer::NAME_() {
    std::stringstream buf;
    do {
        buf << c;
        consume();
    } while (isLETTER());
    return Token(NAME, buf.str());
}

void ListLexer::WS() {
    while (c == ' ' || c == '\t' || c == '\n' || c == '\r')
        consume();
}
