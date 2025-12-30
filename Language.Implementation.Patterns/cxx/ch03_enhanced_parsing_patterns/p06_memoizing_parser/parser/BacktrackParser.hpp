#pragma once

#include "lexer/Lexer.hpp"
#include "lexer/BacktrackLexer.hpp"
#include "Parser.hpp"

class BacktrackParser: public Parser {
public:
    BacktrackParser(Lexer* input);

    void stat();

    bool speculate_stat_alt1();

    bool speculate_stat_alt2();

    void assign();

    void list();

    void elements();

    void element();
};
