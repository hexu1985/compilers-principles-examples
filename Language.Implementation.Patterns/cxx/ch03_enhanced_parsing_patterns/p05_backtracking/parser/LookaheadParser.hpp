#pragma once

#include "lexer/Lexer.hpp"
#include "lexer/LookaheadLexer.hpp"
#include "Parser.hpp"

class LookaheadParser: public Parser {
public:
    LookaheadParser(Lexer* input, int k);

	void list(); 
	
	void elements(); 
	
	void element(); 
};
