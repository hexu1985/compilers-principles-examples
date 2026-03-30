#pragma once

#include "Parser.hpp"
#include "BacktrackLexer.hpp"
#include <iostream>
#include <unordered_map>

class BacktrackParser : public Parser {
public:
    BacktrackParser(std::unique_ptr<Lexer> input): Parser(std::move(input)) {}

    /** clear all data out of memoization dictionaries */
    void clearMemo() override {
        list_memo.clear();
    }

    /** stat : list EOF | assign EOF ; */
    void stat() {
        // attempt alternative 1: list EOF
        if ( speculate_stat_alt1() ) {
            list(); match(Lexer::EOF_TYPE);
        }
        // attempt alternative 2: assign EOF
        else if ( speculate_stat_alt2() ) {
            std::cout << "predict alternative 2" << std::endl;
            assign(); match(Lexer::EOF_TYPE);
        }
        // must be an error; neither matched
        else throw NoViableAltException("expecting stat found "+LT(1).toString());
    }

    bool speculate_stat_alt1() {
        std::cout << "attempt alternative 1" << std::endl;
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
        std::cout << "attempt alternative 2" << std::endl;
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

    // match '[' elements ']'
    void _list() {
        std::cout << "parse list rule at token index: " << index() << std::endl;
        match(BacktrackLexer::LBRACK);
        elements();
        match(BacktrackLexer::RBRACK);
    }

    /** list : '[' elements ']' ; // match bracketed list */
    void list() {
        bool failed = false;
        int startTokenIndex = index(); // get current token position
        if (isSpeculating() && alreadyParsedRule(list_memo)) return;
        // must not have previously parsed list at tokenIndex; parse it
        try {
            _list();
        } catch (const RecognitionException& re) {
            failed = true;
            if (isSpeculating()) memoize(list_memo, startTokenIndex, failed);
            throw; // rethrow
        }
        // succeed or fail, must record result if backtracking
        if (isSpeculating()) memoize(list_memo, startTokenIndex, failed);
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

    /** Map input position to FAILED or previous stop token index.
     *  null implies we've not parsed this rule at that index.
     */
    std::unordered_map<int, int> list_memo;
};

