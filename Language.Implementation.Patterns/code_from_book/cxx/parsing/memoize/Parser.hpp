#pragma once

#include <string>
#include <memory>
#include <stdexcept>
#include <vector>
#include <cassert>
#include "Token.hpp"
#include "Lexer.hpp"
#include "RecognitionException.hpp"
#include "NoViableAltException.hpp"
#include "MismatchedTokenException.hpp"

class Parser {
protected:
    std::unique_ptr<Lexer> input;   // from where do we get tokens?
    std::vector<int> markers;       // stack of index markers into lookahead buffer
    std::vector<Token> lookahead;   // dynamically-sized lookahead buffer
    int p = 0;                      // index of current lookahead token;
                                    // LT(1) returns lookahead[p]

public:
    Parser(std::unique_ptr<Lexer> input_) : input(std::move(input_)) {
        sync(1);    // prime buffer with at least 1 token
    }

    virtual ~Parser() = 0;

    void consume() {
        p++;
        // have we hit end of buffer when not backtracking?
        if ( p==lookahead.size() && !isSpeculating() ) {
            // if so, it's an opportunity to start filling at index 0 again
            p = 0;
            lookahead.clear(); // size goes to 0, but retains memory
        }
        sync(1); // get another to replace consumed token
    }

    /** Make sure we have i tokens from current position p */
    void sync(int i) {
        if ( p+i-1 > (static_cast<int>(lookahead.size())-1) ) {       // out of tokens?
            int n = (p+i-1) - (static_cast<int>(lookahead.size())-1); // get n tokens
            fill(n);            
        }
    }

    void fill(int n) { // add n tokens
        for (int i=1; i<=n; i++) { lookahead.push_back(input->nextToken()); }
    }

    Token LT(int i) {
        sync(i); return lookahead.at(p+i-1);
    }

    int LA(int i) {
        return LT(i).type;
    }

    void match(int x) {
        if ( LA(1) == x ) consume();
        else {
            throw MismatchedTokenException("expecting " + input->getTokenName(x) +
                                     "; found " + LT(1).toString());
        }
    }

    int mark() {
        markers.push_back(p); return p;
    }

    void release() {
        assert(!markers.empty());
        int marker = markers.back();
        markers.pop_back();
        seek(marker);
    }

    void seek(int index) {
        p = index;
    }

    bool isSpeculating() {
        return markers.size() > 0;
    }
};

