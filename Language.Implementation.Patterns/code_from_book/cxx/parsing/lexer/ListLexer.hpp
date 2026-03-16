#pragma once

#include "Lexer.hpp"

#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>

class ListLexer : public Lexer {
public:
    static const int NAME = 2;
    static const int COMMA = 3;
    static const int LBRACK = 4;
    static const int RBRACK = 5;

    static const char* tokenNames[];

    ListLexer(const std::string& input) : Lexer(input) {}

    std::string getTokenName(int x) override {
        return tokenNames[x];
    }

    bool isLETTER() const {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    Token nextToken() override {
        while (c != EOF) {
            switch (c) {
                case ' ': case '\t': case '\n': case '\r': WS(); continue;
                case ',': consume(); return Token{COMMA, ","};
                case '[': consume(); return Token{LBRACK, "["};
                case ']': consume(); return Token{RBRACK, "]"};
                default:
                    if (isLETTER()) return NAME_();
                    throw std::runtime_error(std::string("invalid character: ") + static_cast<char>(c));
            }
        }
        return Token{EOF_TYPE, "<EOF>"};
    }

    /** NAME : ('a'..'z'|'A'..'Z')+; // NAME is sequence of >=1 letter */
    Token NAME_() {
        std::string buf;
        do { buf.push_back(static_cast<char>(c)); consume(); } while (isLETTER());
        return Token{NAME, buf};
    }

    /** WS : (' '|'\t'|'\n'|'\r')* ; // ignore any whitespace */
    void WS() {
        while (c == ' ' || c == '\t' || c == '\n' || c == '\r') consume();
    }
};
