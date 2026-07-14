
// Generated from VecMath.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "VecMathVisitor.h"


/**
 * This class provides an empty implementation of VecMathVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  VecMathBaseVisitor : public VecMathVisitor {
public:

  virtual std::any visitProg(VecMathParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStat(VecMathParser::StatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(VecMathParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultExpr(VecMathParser::MultExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimary(VecMathParser::PrimaryContext *ctx) override {
    return visitChildren(ctx);
  }


};

