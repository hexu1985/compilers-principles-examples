
// Generated from CSV.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "CSVVisitor.h"


/**
 * This class provides an empty implementation of CSVVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CSVBaseVisitor : public CSVVisitor {
public:

  virtual std::any visitFile(CSVParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHdr(CSVParser::HdrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRow(CSVParser::RowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitText(CSVParser::TextContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitString(CSVParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEmpty(CSVParser::EmptyContext *ctx) override {
    return visitChildren(ctx);
  }


};

