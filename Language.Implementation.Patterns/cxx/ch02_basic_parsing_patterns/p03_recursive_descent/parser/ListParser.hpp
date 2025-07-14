#pragma once

#include "lexer/Lexer.hpp"
#include "lexer/ListLexer.hpp"
#include "Parser.hpp"

class ListParser: public Parser {
public:
    ListParser(Lexer* input);

	void list(); 
	
	void elements(); 
	
	void element(); 
};
