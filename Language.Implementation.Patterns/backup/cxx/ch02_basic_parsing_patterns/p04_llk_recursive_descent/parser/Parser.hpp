#pragma once

#include "lexer/Token.hpp"
#include "lexer/Lexer.hpp"

class ParserError: public std::logic_error {
public:
    ParserError(const std::string& what_arg): std::logic_error(what_arg) {}
};

class Parser {
public:
	Parser(Lexer* input, int k);
	
	void consume(); 

    Token LT(int i);

    int LA(int i);

	void match(int x); 
	
protected:
	Lexer* input;
    std::vector<Token> lookahead;
    int k;
    int p = 0;
};
