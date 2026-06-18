
// Generated from CSV.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "CSVParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CSVParser.
 */
class  CSVListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(CSVParser::FileContext *ctx) = 0;
  virtual void exitFile(CSVParser::FileContext *ctx) = 0;

  virtual void enterHdr(CSVParser::HdrContext *ctx) = 0;
  virtual void exitHdr(CSVParser::HdrContext *ctx) = 0;

  virtual void enterRow(CSVParser::RowContext *ctx) = 0;
  virtual void exitRow(CSVParser::RowContext *ctx) = 0;

  virtual void enterText(CSVParser::TextContext *ctx) = 0;
  virtual void exitText(CSVParser::TextContext *ctx) = 0;

  virtual void enterString(CSVParser::StringContext *ctx) = 0;
  virtual void exitString(CSVParser::StringContext *ctx) = 0;

  virtual void enterEmpty(CSVParser::EmptyContext *ctx) = 0;
  virtual void exitEmpty(CSVParser::EmptyContext *ctx) = 0;


};

