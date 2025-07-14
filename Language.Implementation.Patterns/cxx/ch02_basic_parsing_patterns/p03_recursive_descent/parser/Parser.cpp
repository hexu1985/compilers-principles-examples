#include "Parser.hpp"

Parser::Parser(Lexer* input_): input(input_) { 
    consume();
}
	
/** if lookahead token type matches x, consume & return else error */
void Parser::match(int x) {
    if ( lookahead.type == x) consume();
    else throw ParserError("expecting " + input->getTokenName(x) +
            "; found " + lookahead.toString(*input));
}
	
void Parser::consume() {
    lookahead = input->nextToken();
}
