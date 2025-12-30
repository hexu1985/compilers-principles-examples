#pragma once

#include "lexer/Token.hpp"
#include "lexer/Lexer.hpp"

class Parser {
public:
	Parser(Lexer* input);
	
	void consume(); 

    void sync(int i);

    void fill(int n);

    Token LT(int i);

    int LA(int i);

	void match(int x); 

    int mark();

    void release();
	
    void seek(int index);

    bool isSpeculating();

protected:
	Lexer* input;
    std::vector<int> markers;       // stack of index markers into lookahead buffer
    std::vector<Token> lookahead;   // dynamically-sized lookahead buffer
    int p = 0;  // index of current token in lookahead buffer
                // LT(1) returns lookahead[p] 
};
