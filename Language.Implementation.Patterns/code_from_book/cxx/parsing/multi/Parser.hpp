#pragma once

#include <string>
#include <memory>
#include <stdexcept>
#include "Token.hpp"
#include "Lexer.hpp"

class Parser {
protected:
    std::unique_ptr<Lexer> input;   // from where do we get tokens?
    std::vector<Token> lookahead;   // circular lookahead buffer
    int k;                          // how many lookahead symbols
    int p = 0;                      // circular index of next token position to fill

public:
    Parser(std::unique_ptr<Lexer> input_, int k_) : input(std::move(input_)), k(k_) {
        lookahead.resize(k);                // make lookahead buffer
        for (int i=1; i<=k; i++) consume(); // prime buffer with k lookahead
    }

    virtual ~Parser() = 0;

    void consume() {
        lookahead[p] = input->nextToken();  // fill next position with token
        p = (p+1) % k;                      // fill next position with token
    }

    Token LT(int i) {
        return lookahead[(p+i-1) % k];      // circular fetch
    }

    int LA(int i) {
        return LT(i).type;
    }

    void match(int x) {
        if ( LA(1) == x) consume();
        else {
            throw std::runtime_error("expecting " + input->getTokenName(x) +
                                     "; found " + LT(1).toString());
        }
    }
};

