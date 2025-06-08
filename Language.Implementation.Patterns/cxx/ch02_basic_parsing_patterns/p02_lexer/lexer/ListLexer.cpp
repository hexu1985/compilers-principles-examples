#include "ListLexer.hpp"
#include <sstream>

const std::vector<std::string> ListLexer::tokenNames = {"n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBRACK"};

std::string ListLexer::getTokenName(int tokenType) const {
    return tokenNames.at(tokenType);
}

Token ListLexer::nextToken() {
    while (c != EOF_CHAR) {
        switch (c) {
        case ' ': case '\t': case '\n': case '\r': WS(); continue;
        case ',': consume(); return Token(T_TYPE_COMMA, ","); 
        case '[': consume(); return Token(T_TYPE_LBRACK, "["); 
        case ']': consume(); return Token(T_TYPE_RBRACK, "]"); 
        default:
            if (isLETTER()) return NAME();
            throw LexerError(std::string("invalid character: ") + c);
        }
    }
    return Token(T_TYPE_EOF, "<EOF>");
}

Token ListLexer::NAME() {
    std::stringstream buf;
    do {
        buf << c;
        consume();
    } while (isLETTER());
    return Token(T_TYPE_NAME, buf.str());
}

void ListLexer::WS() {
    while (c == ' ' || c == '\t' || c == '\n' || c == '\r')
        consume();
}
