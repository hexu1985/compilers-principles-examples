#pragma once

#include "Parser.hpp"
#include "BacktrackLexer.hpp"
#include <iostream>

class BacktrackParser : public Parser {
public:
    BacktrackParser(std::unique_ptr<Lexer> input): Parser(std::move(input)) {}

    /** stat : list EOF | assign EOF ; */
    void stat() {
        // attempt alternative 1: list EOF
        if ( speculate_stat_alt1() ) {
            list(); match(Lexer::EOF_TYPE);
        }
        // attempt alternative 2: assign EOF
        else if ( speculate_stat_alt2() ) {
            assign(); match(Lexer::EOF_TYPE);
        }
        // must be an error; neither matched; LT(1) is lookahead token 1
        else throw NoViableAltException("expecting stat found "+LT(1).toString());
    }

    bool speculate_stat_alt1() {
        bool success = true;
        mark(); // mark this spot in input so we can rewind
        try { list(); match(Lexer::EOF_TYPE); }
        catch (const RecognitionException& e) { 
            std::cout << "in speculate_stat_alt1: " << e.what() << std::endl;
            success = false; 
        }
        release(); // either way, rewind to where we were
        return success;
    }

    bool speculate_stat_alt2() {
        bool success = true;
        mark(); // mark this spot in input so we can rewind
        try { assign(); match(Lexer::EOF_TYPE); }
        catch (const RecognitionException& e) { 
            std::cout << "in speculate_stat_alt2: " << e.what() << std::endl;
            success = false; 
        }
        release(); // either way, rewind to where we were
        return success;
    }

    /** assign : list '=' list ; // parallel assignment */
    void assign() {
        list(); match(BacktrackLexer::EQUALS); list();
    }

    /** list : '[' elements ']' ; // match bracketed list */
    void list() {
        match(BacktrackLexer::LBRACK); elements(); match(BacktrackLexer::RBRACK);
    }
    
private:
    /** elements : element (',' element)* ; // match comma-separated list */
    void elements() {
        element(); while ( LA(1) == BacktrackLexer::COMMA ) { match(BacktrackLexer::COMMA); element(); }
    }

    /** element : name '=' NAME | NAME | list ; // assignment, name or list */
    void element() {
        if ( LA(1) == BacktrackLexer::NAME && LA(2) == BacktrackLexer::EQUALS ) {
            match(BacktrackLexer::NAME);
            match(BacktrackLexer::EQUALS);
            match(BacktrackLexer::NAME);
        }
        else if ( LA(1) == BacktrackLexer::NAME ) match(BacktrackLexer::NAME);
        else if ( LA(1) == BacktrackLexer::LBRACK ) list();
        else throw NoViableAltException("expecting name or list; found " + LT(1).toString());
    }
};

