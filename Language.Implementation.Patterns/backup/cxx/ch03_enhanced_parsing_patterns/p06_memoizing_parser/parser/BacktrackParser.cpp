#include "BacktrackParser.hpp"
#include "RecognitionException.hpp"
#include "NoViableAltException.hpp"
#include "MismatchedTokenException.hpp"
#include <iostream>

BacktrackParser::BacktrackParser(Lexer* input): Parser(input) {
}

/** clear all data out of memoization dictionaries */
void BacktrackParser::clearMemo() {
    list_memo.clear();
}

/** stat : list EOF | assign EOF */
void BacktrackParser::stat() {
    // attempt alternative 1: list EOF
    if (speculate_stat_alt1()) {
        list();
        match(Lexer::EOF_TYPE);
    }
    // attempt alternative 2: assign EOF
    else if (speculate_stat_alt2()) {
        std::cout << "predict alternative 2" << std::endl;
        assign();
        match(Lexer::EOF_TYPE);
    }
    // must be an error; neither matched
    else
        throw NoViableAltException("expecting stat found " + LT(1).toString(*input));
}

bool BacktrackParser::speculate_stat_alt1() {
    std::cout << "attempt alternative 1" << std::endl;
    bool success = true;
    mark(); // mark this spot so we can rewind
    try {
        list();
        match(Lexer::EOF_TYPE);
    }
    catch (const RecognitionException& e) {
        success = false;
    }

    release();  // either way, rewind to where we were
    return success;
}

bool BacktrackParser::speculate_stat_alt2() {
    bool success = true;
    mark(); // mark this spot in input so we can rewind
    try {
        assign();
        match(Lexer::EOF_TYPE);
    }
    catch (const RecognitionException& e) {
        success = false;
    }

    release();  // either way, rewind to where we were
    return success;
}

/** assign : list '=' list ; // parallel assignment */
void BacktrackParser::assign() {
    list();
    match(BacktrackLexer::EQUALS);
    list();
}

// match '[' elements ']'
void BacktrackParser::_list() {
    std::cout << "parse list rule at token index: " << index() << std::endl;
    match(BacktrackLexer::LBRACK);
    elements();
    match(BacktrackLexer::RBRACK);
}

/** list : '[' elements ']'; // match bracketed list */
void BacktrackParser::list() {
    bool failed = false;
    int startTokenIndex = index(); // get current token position
    if (isSpeculating() && alreadyParsedRule(list_memo))
        return;
    // must not have previously parsed list at tokenIndex; parse it
    try {
        _list();
    } catch (...) {
        failed = true;
        // succeed of fail, must record result if backtracking
        if (isSpeculating())
            memoize(list_memo, startTokenIndex, failed);
        throw;
    } 

    // succeed of fail, must record result if backtracking
    if (isSpeculating())
        memoize(list_memo, startTokenIndex, failed);
}

void BacktrackParser::elements() {
    element();
    while (LA(1) == BacktrackLexer::COMMA) {
        match(BacktrackLexer::COMMA);
        element();
    }
}

void BacktrackParser::element() {
    if (LA(1) == BacktrackLexer::NAME && LA(2) == BacktrackLexer::EQUALS) {
        match(BacktrackLexer::NAME);
        match(BacktrackLexer::EQUALS);
        match(BacktrackLexer::NAME);
    }
    else if (LA(1) == BacktrackLexer::NAME)
        match(BacktrackLexer::NAME);
    else if (LA(1) == BacktrackLexer::LBRACK)
        list();
    else 
        throw NoViableAltException("expecting element found " + LT(1).toString(*input));
}

