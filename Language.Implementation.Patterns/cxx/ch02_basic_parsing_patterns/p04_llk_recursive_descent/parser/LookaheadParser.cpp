#include "LookaheadParser.hpp"

LookaheadParser::LookaheadParser(Lexer* input, int k): Parser(input, k) {
}

/** list : '[' elements ']' ; // match bracketed list */
void LookaheadParser::list() {
    match(LookaheadLexer::LBRACK); 
    elements(); 
    match(LookaheadLexer::RBRACK);
}

/** elements : element (',' element)* ; */
void LookaheadParser::elements() {
    element();
    while ( LA(1) == LookaheadLexer::COMMA ) {
        match(LookaheadLexer::COMMA);
        element();
    }
}

/** element : name | list ; // element is name or nested list */
void LookaheadParser::element() {
    if (LA(1) == LookaheadLexer::NAME &&
        LA(2) == LookaheadLexer::EQUALS) {
        match(LookaheadLexer::NAME);
        match(LookaheadLexer::EQUALS);
        match(LookaheadLexer::NAME);
    } else if ( LA(1) == LookaheadLexer::NAME ) match(LookaheadLexer::NAME);
    else if ( lookahead.type == LookaheadLexer::LBRACK ) list();
    else throw ParserError("expecting name or list; found " + lookahead.toString(*input));
}
