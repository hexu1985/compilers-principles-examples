
// Generated from CSV.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "CSVListener.h"


/**
 * This class provides an empty implementation of CSVListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  CSVBaseListener : public CSVListener {
public:

  virtual void enterFile(CSVParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(CSVParser::FileContext * /*ctx*/) override { }

  virtual void enterHdr(CSVParser::HdrContext * /*ctx*/) override { }
  virtual void exitHdr(CSVParser::HdrContext * /*ctx*/) override { }

  virtual void enterRow(CSVParser::RowContext * /*ctx*/) override { }
  virtual void exitRow(CSVParser::RowContext * /*ctx*/) override { }

  virtual void enterText(CSVParser::TextContext * /*ctx*/) override { }
  virtual void exitText(CSVParser::TextContext * /*ctx*/) override { }

  virtual void enterString(CSVParser::StringContext * /*ctx*/) override { }
  virtual void exitString(CSVParser::StringContext * /*ctx*/) override { }

  virtual void enterEmpty(CSVParser::EmptyContext * /*ctx*/) override { }
  virtual void exitEmpty(CSVParser::EmptyContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

