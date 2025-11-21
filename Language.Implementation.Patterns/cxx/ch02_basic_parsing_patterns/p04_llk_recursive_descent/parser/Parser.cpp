#include "Parser.hpp"

Parser::Parser(Lexer* input_, int k_): input(input_), k(k_) { 
    lookahead.resize(k);

    for (int i = 1; i <=k; i++)
        consume();
}
	
void Parser::consume() {
    lookahead[p] = input->nextToken();
    p = (p + 1) % p;
}

Token Parser::LT(int i) {
    return lookahead[(p + i - 1) % k];
}

int Parser::LA(int i) {
    return LT(i).type;
}

void Parser::match(int x) {
    if (LA(1) == x) consume();
    else throw ParserError("expecting " + input->getTokenName(x) +
            "; found " + LT(1).toString(*input));
}
