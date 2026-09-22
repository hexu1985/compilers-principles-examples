#include <iostream>
#include <fstream>
#include <memory>

#include "antlr4-runtime.h"
#include "CymbolLexer.h"
#include "CymbolParser.h"
#include "DefPhase.hpp"
#include "RefPhase.hpp"
#include "SymbolTable.hpp"

using namespace antlr4;

int main(int argc, char* argv[]) {
    std::string inputFile;
    if (argc > 1) inputFile = argv[1];

    std::unique_ptr<ANTLRInputStream> input;
    if (!inputFile.empty()) {
        auto fs = std::make_unique<ANTLRFileStream>();
        fs->loadFromFile(inputFile);
        input = std::move(fs);
    } else {
        input = std::make_unique<ANTLRInputStream>(std::cin);
    }

    CymbolLexer lexer(input.get());
    CommonTokenStream tokens(&lexer);
    CymbolParser parser(&tokens);
    parser.setBuildParseTree(true);

    tree::ParseTree* tree = parser.compilationUnit();

    // ------- 第一遍：Def -------
    SymbolTable symtab;
    DefPhase defPhase(&symtab);

    tree::ParseTreeWalker walker;
    walker.walk(&defPhase, tree);

    std::cout << "globals: " << symtab.toString() << std::endl;

    // ------- 第二遍：Ref -------
    RefPhase refPhase(&symtab, &defPhase.idScopes, &defPhase.idSymbols);
    walker.walk(&refPhase, tree);

    return 0;
}
