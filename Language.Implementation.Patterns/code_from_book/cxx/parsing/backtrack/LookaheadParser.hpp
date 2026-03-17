#pragma once

#include "Parser.hpp"
#include "LookaheadLexer.hpp"
#include <stdexcept>

class LookaheadParser : public Parser {
public:
    LookaheadParser(std::unique_ptr<Lexer> input, int k): Parser(std::move(input), k) {}
    
    /** list : '[' elements ']' ; // match bracketed list */
    void list() {
        match(LookaheadLexer::LBRACK); elements(); match(LookaheadLexer::RBRACK);
    }
    
private:
    /** elements : element (',' element)* ; // match comma-separated list */
    void elements() {
        element(); while ( LA(1) == LookaheadLexer::COMMA ) { match(LookaheadLexer::COMMA); element(); }
    }
    
    /** element : NAME '=' NAME | NAME | list ; assignment, NAME or list */
    void element() {
        if ( LA(1) == LookaheadLexer::NAME && LA(2) == LookaheadLexer::EQUALS ) {
            match(LookaheadLexer::NAME);
            match(LookaheadLexer::EQUALS);
            match(LookaheadLexer::NAME);
        }
        else if ( LA(1) == LookaheadLexer::NAME ) match(LookaheadLexer::NAME);
        else if ( LA(1) == LookaheadLexer::LBRACK ) list();
        else throw std::runtime_error("expecting name or list; found " + LT(1).toString());
    }
};

