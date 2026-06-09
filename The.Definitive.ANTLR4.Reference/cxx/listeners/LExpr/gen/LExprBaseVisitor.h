
// Generated from LExpr.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "LExprVisitor.h"


/**
 * This class provides an empty implementation of LExprVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  LExprBaseVisitor : public LExprVisitor {
public:

  virtual std::any visitS(LExprParser::SContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdd(LExprParser::AddContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMult(LExprParser::MultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInt(LExprParser::IntContext *ctx) override {
    return visitChildren(ctx);
  }


};

