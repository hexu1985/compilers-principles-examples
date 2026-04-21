#include <iostream>
#include "antlr4-runtime.h"
#include "ArrayInitLexer.h"
#include "ArrayInitParser.h"

using namespace antlr4;

int main() {
    // create a CharStream that reads from standard input
    ANTLRInputStream input(std::cin);

    // create a lexer that feeds off of input CharStream
    ArrayInitLexer lexer(&input);

    // create a buffer of tokens pulled from the lexer
    CommonTokenStream tokens(&lexer);

    // create a parser that feeds off the tokens buffer
    ArrayInitParser parser(&tokens);

    tree::ParseTree *tree = parser.init();  // begin parsing at init rule
    std::cout << tree->toStringTree(&parser) << std::endl;  // print LISP-style tree

    return 0;
}
