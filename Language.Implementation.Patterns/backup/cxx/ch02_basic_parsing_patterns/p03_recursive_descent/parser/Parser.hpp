#pragma once

#include "lexer/Token.hpp"
#include "lexer/Lexer.hpp"

class ParserError: public std::logic_error {
public:
    ParserError(const std::string& what_arg): std::logic_error(what_arg) {}
};

class Parser {
public:
	Parser(Lexer* input);
	
	void match(int x); 
	
	void consume(); 

protected:
	Lexer* input;	 //from where do we get tokens?
	Token lookahead; // The current lookahead token
};
