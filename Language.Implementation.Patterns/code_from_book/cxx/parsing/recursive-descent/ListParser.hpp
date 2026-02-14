#pragma once

#include "Parser.hpp"
#include "ListLexer.hpp"
#include <stdexcept>

class ListParser : public Parser {
public:
    ListParser(std::unique_ptr<Lexer> input): Parser(std::move(input)) {}
    
    /** list : '[' elements ']' ; // match bracketed list */
    void list() {
        match(ListLexer::LBRACK); elements(); match(ListLexer::RBRACK);
    }
    
private:
    /** elements : element (',' element)* ; */
    void elements() {
        element();
        while ( lookahead->type == ListLexer::COMMA ) {
            match(ListLexer::COMMA); element();
        }
    }
    
    /** element : name | list ; // element is name or nested list */
    void element() {
        if ( lookahead->type == ListLexer::NAME ) match(ListLexer::NAME);
        else if ( lookahead->type == ListLexer::LBRACK ) list();
        else throw std::runtime_error("expecting name or list; found " + lookahead->toString());
    }
};

