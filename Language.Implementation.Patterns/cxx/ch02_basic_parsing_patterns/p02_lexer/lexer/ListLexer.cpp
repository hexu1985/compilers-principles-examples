#include "ListLexer.hpp"
#include <sstream>

Token ListLexer::nextToken() {
    while (c != EOF_CHAR) {
        switch (c) {
        case ' ': case '\t': case '\n': case '\r': WS(); continue;
        case ',': consume(); return Token(Token::COMMA, ","); 
        case '[': consume(); return Token(Token::LBRACK, "["); 
        case ']': consume(); return Token(Token::RBRACK, "]"); 
        default:
            if (isLETTER()) return NAME();
            throw LexerError(std::string("invalid character: ") + c);
        }
    }
    return Token(Token::EOF_TYPE, "<EOF>");
}

Token ListLexer::NAME() {
    std::stringstream buf;
    do {
        buf << c;
        consume();
    } while (isLETTER());
    return Token(Token::NAME, buf.str());
}

void ListLexer::WS() {
    while (c == ' ' || c == '\t' || c == '\n' || c == '\r')
        consume();
}
