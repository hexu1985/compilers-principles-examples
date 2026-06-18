
// Generated from CSV.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "CSVParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CSVParser.
 */
class  CSVVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CSVParser.
   */
    virtual std::any visitFile(CSVParser::FileContext *context) = 0;

    virtual std::any visitHdr(CSVParser::HdrContext *context) = 0;

    virtual std::any visitRow(CSVParser::RowContext *context) = 0;

    virtual std::any visitText(CSVParser::TextContext *context) = 0;

    virtual std::any visitString(CSVParser::StringContext *context) = 0;

    virtual std::any visitEmpty(CSVParser::EmptyContext *context) = 0;


};

