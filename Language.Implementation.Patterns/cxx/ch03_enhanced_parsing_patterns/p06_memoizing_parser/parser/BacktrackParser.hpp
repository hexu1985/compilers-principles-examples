#pragma once

#include "lexer/Lexer.hpp"
#include "lexer/BacktrackLexer.hpp"
#include "Parser.hpp"

class BacktrackParser: public Parser {
public:
    BacktrackParser(Lexer* input);

    void clearMemo() override;

    void stat();

    bool speculate_stat_alt1();

    bool speculate_stat_alt2();

    void assign();

    void _list();
    void list();

    void elements();

    void element();

private:
	/**
	 * Map input position to FAILED or previous stop token index. null implies
	 * we've not parsed this rule at that index.
	 */
    std::map<int, int> list_memo;
};
