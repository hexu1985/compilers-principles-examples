#include "ListParser.hpp"

ListParser::ListParser(Lexer* input): Parser(input) {
}

/** list : '[' elements ']' ; // match bracketed list */
void ListParser::list() {
    match(ListLexer::LBRACK); elements(); match(ListLexer::RBRACK);
}

/** elements : element (',' element)* ; */
void ListParser::elements() {
    element();
    while ( lookahead.type == ListLexer::COMMA ) {
        match(ListLexer::COMMA); element();
    }
}

/** element : name | list ; // element is name or nested list */
void ListParser::element() {
    if ( lookahead.type == ListLexer::NAME ) match(ListLexer::NAME);
    else if ( lookahead.type == ListLexer::LBRACK ) list();
    else throw ParserError("expecting name or list; found " + lookahead.toString(*input));
}
