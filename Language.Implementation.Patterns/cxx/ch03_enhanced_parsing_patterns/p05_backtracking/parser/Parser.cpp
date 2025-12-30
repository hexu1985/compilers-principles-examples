#include "Parser.hpp"
#include "RecognitionException.hpp"
#include "MismatchedTokenException.hpp"
#include <cassert>

Parser::Parser(Lexer* input_): input(input_) { 
    sync(1);    // prime lookahead
}
	
/** The same as in the fixed-lookahead parser except that we clear the lookahead buffer when
 *  we hit the end. */
void Parser::consume() {
    p++;
    // have we hit end of buffer when not backtracking?
    if (p == lookahead.size() && !isSpeculating()) {
        // if so, it's an opportunity to start filling at index 0 again
        p = 0;
        lookahead.clear();
    }
    sync(1); // get another to replace consumed token
}

/** Make sure we have i tokens from current position p (valid tokens from index p to p+i-1). */
void Parser::sync(int i) {
    if (p + i - 1 > static_cast<int>(lookahead.size()) - 1) {
        int n = (p + i - 1) - (static_cast<int>(lookahead.size()) - 1);
        fill(n);
    }
}

void Parser::fill(int n) {  // add n tokens
    for (int i = 1; i <= n; i++) {
        lookahead.push_back(input->nextToken());
    }
}

/** Lookahead token */
Token Parser::LT(int i) {
    sync(i);
    return lookahead[p + i - 1];
}

int Parser::LA(int i) {
    return LT(i).type;
}

void Parser::match(int x) {
    if (LA(1) == x) 
        consume();
    else {
        Token lt1 = LT(1);
        std::string msg = "expecting " + 
                        input->getTokenName(x) + 
                        " found " + lt1.toString(*input);
        throw MismatchedTokenException(msg);                        
    }
}

// marker management methods are simple because all they do is manage the markers stack:


/** Push current token index to stack */
int Parser::mark() {
    markers.push_back(p);
    return p;
}

/** Pop the token index of the stack.
 *  Rewind p to that position.
 *  Rewinding the input is kind of undoing the `consume` */
void Parser::release() {
    assert(!markers.empty());
    int marker = markers.back();
    markers.pop_back();
    seek(marker);
}

/** Rewind p to index */
void Parser::seek(int index) {
    p = index;
}

bool Parser::isSpeculating() {
    return !markers.empty();
}
