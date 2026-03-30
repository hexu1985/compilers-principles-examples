#pragma once

#include <string>
#include <memory>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include "Token.hpp"
#include "Lexer.hpp"
#include "RecognitionException.hpp"
#include "NoViableAltException.hpp"
#include "MismatchedTokenException.hpp"
#include "PreviousParseFailedException.hpp"

class Parser {
protected:
    std::unique_ptr<Lexer> input;   // from where do we get tokens?
    std::vector<int> markers;       // stack of index markers into lookahead buffer
    std::vector<Token> lookahead;   // dynamically-sized lookahead buffer
    int p = 0;                      // index of current lookahead token;
                                    // LT(1) returns lookahead[p]

public:
    static const int FAILED = -1;   // parsing failed on last attempt

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
            clearMemo();       // clear any rule_memo dictionaries
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

    /** Actual parser implements to clear any rule_memo dictionaries */
    virtual void clearMemo() = 0;

    int mark() {
        markers.push_back(p);
        return p;
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

    /** Have we parsed a particular rule before at this input position?
     *  If no memoization value, we've never parsed here before.
     *  If memoization value is FAILED, we parsed and failed before.
     *  If value >= 0, it is an index into the token buffer.  It indicates
     *  a previous successful parse.  This method has a side effect:
     *  it seeks ahead in the token buffer to avoid reparsing.
     */
    bool alreadyParsedRule(std::unordered_map<int, int>& memoization) {
        auto it = memoization.find(index());
        if (it == memoization.end()) return false;

        int memo = it->second;
        std::cout << "parsed list before at index " << index()
            << "; skip ahead to token index " << memo << ": "
            << lookahead[memo].text << std::endl;

        if (memo == FAILED) throw PreviousParseFailedException();
        // else skip ahead, pretending we parsed this rule ok
        seek(memo);
        return true;
    }

    /** While backtracking, record partial parsing results.
     *  If invoking rule method failed, record that fact.
     *  If it succeeded, record the token position we should skip to
     *  next time we attempt this rule for this input position.
     */
    void memoize(std::unordered_map<int, int>& memoization,
            int startTokenIndex, bool failed) {
        // record token just after last in rule if success
        int stopTokenIndex = failed ? FAILED : index();
        memoization[startTokenIndex] = stopTokenIndex;
    }

    int index() { return p; } // return current input position
};

