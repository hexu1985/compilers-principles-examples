#include <iostream>
#include "antlr4-runtime.h"
#include "ArrayInitLexer.h"
#include "ArrayInitParser.h"
#include "ShortToUnicodeString.h"   // 之前的监听器类

int main() {
    // create a CharStream that reads from standard input
    antlr4::ANTLRInputStream input(std::cin);
    // create a lexer that feeds off of input CharStream
    ArrayInitLexer lexer(&input);
    // create a buffer of tokens pulled from the lexer
    antlr4::CommonTokenStream tokens(&lexer);
    // create a parser that feeds off the tokens buffer
    ArrayInitParser parser(&tokens);
    antlr4::tree::ParseTree *tree = parser.init();  // begin parsing at init rule

    // Create a generic parse tree walker that can trigger callbacks
    antlr4::tree::ParseTreeWalker walker;
    // Walk the tree created during the parse, trigger callbacks
    ShortToUnicodeString listener;
    walker.walk(&listener, tree);
    std::cout << std::endl; // print a \n after translation

    return 0;
}
