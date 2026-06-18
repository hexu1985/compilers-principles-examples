#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <memory>

#include "CSVLexer.h"
#include "CSVParser.h"
#include "CSVBaseListener.h"

using namespace antlr4;

class Loader : public CSVBaseListener {
public:
    static const std::string EMPTY;
    
    /** Load a list of row maps that map field name to value */
    std::vector<std::map<std::string, std::string>> rows;
    /** List of column names */
    std::vector<std::string> header;
    /** Build up a list of fields in current row */
    std::vector<std::string> currentRowFieldValues;

    void exitHdr(CSVParser::HdrContext *ctx) override {
        header.clear();
        header.insert(header.end(), 
                     currentRowFieldValues.begin(), 
                     currentRowFieldValues.end());
    }

    void enterRow(CSVParser::RowContext *ctx) override {
        currentRowFieldValues.clear();
    }

    void exitRow(CSVParser::RowContext *ctx) override {
        // If this is the header row, do nothing
        if (ctx->getParent()->getRuleIndex() == CSVParser::RULE_hdr) {
            return;
        }
        
        // It's a data row
        std::map<std::string, std::string> m;
        size_t i = 0;
        for (const std::string& v : currentRowFieldValues) {
            if (i < header.size()) {
                m[header[i]] = v;
            }
            i++;
        }
        rows.push_back(m);
    }

    void exitString(CSVParser::StringContext *ctx) override {
        currentRowFieldValues.push_back(ctx->STRING()->getText());
    }

    void exitText(CSVParser::TextContext *ctx) override {
        currentRowFieldValues.push_back(ctx->TEXT()->getText());
    }

    void exitEmpty(CSVParser::EmptyContext *ctx) override {
        currentRowFieldValues.push_back(EMPTY);
    }

    void printRows() const {
        std::cout << "[";
        for (size_t i = 0; i < rows.size(); ++i) {
            if (i > 0) std::cout << ", ";
            std::cout << "{";
            size_t j = 0;
            for (const auto& pair : rows[i]) {
                if (j > 0) std::cout << ", ";
                std::cout << pair.first << "=" << pair.second;
                j++;
            }
            std::cout << "}";
        }
        std::cout << "]" << std::endl;
    }
};

const std::string Loader::EMPTY = "";

int main(int argc, char* argv[]) {
    std::string inputFile;
    if (argc > 1) {
        inputFile = argv[1];
    }
    
    std::ifstream stream;
    if (!inputFile.empty()) {
        stream.open(inputFile);
        if (!stream.is_open()) {
            std::cerr << "Cannot open file: " << inputFile << std::endl;
            return 1;
        }
    }

    // Create the lexer and parser
    ANTLRInputStream input(stream);
    CSVLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CSVParser parser(&tokens);

    // Build the parse tree
    parser.setBuildParseTree(true);
    tree::ParseTree* tree = parser.file();

    // Walk the tree
    tree::ParseTreeWalker walker;
    Loader loader;
    walker.walk(&loader, tree);
    
    // Print results
    loader.printRows();
    
    return 0;
}