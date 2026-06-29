
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

  virtual std::any visitAssign(VecMathParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrint(VecMathParser::PrintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(VecMathParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultExpr(VecMathParser::MultExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInt(VecMathParser::IntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitId(VecMathParser::IdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVector(VecMathParser::VectorContext *ctx) override {
    return visitChildren(ctx);
  }


};

