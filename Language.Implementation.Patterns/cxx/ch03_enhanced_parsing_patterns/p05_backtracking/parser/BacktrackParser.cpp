#include "BacktrackParser.hpp"
#include "RecognitionException.hpp"
#include "NoViableAltException.hpp"

BacktrackParser::BacktrackParser(Lexer* input): Parser(input) {
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
        assign();
        match(Lexer::EOF_TYPE);
    }
    else
        throw NoViableAltException("expecting stat found " + LT(1).toString(*input));
}

bool BacktrackParser::speculate_stat_alt1() {
    bool success = true;
    mark(); // mark this spot so we can rewind
    try {
        list();
        match(Lexer::EOF_TYPE);
    }
    catch (const RecognitionException& e) {
        success = false;
    }

    release();
    return success;
}

bool BacktrackParser::speculate_stat_alt2() {
    bool success = true;
    mark(); // mark this spot so we can rewind
    try {
        assign();
        match(Lexer::EOF_TYPE);
    }
    catch (RecognitionException e) {
        success = false;
    }

    release();
    return success;
}


