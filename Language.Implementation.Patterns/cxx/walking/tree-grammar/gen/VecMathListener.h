
// Generated from VecMath.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "VecMathParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by VecMathParser.
 */
class  VecMathListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(VecMathParser::ProgContext *ctx) = 0;
  virtual void exitProg(VecMathParser::ProgContext *ctx) = 0;

  virtual void enterAssign(VecMathParser::AssignContext *ctx) = 0;
  virtual void exitAssign(VecMathParser::AssignContext *ctx) = 0;

  virtual void enterPrint(VecMathParser::PrintContext *ctx) = 0;
  virtual void exitPrint(VecMathParser::PrintContext *ctx) = 0;

  virtual void enterExpr(VecMathParser::ExprContext *ctx) = 0;
  virtual void exitExpr(VecMathParser::ExprContext *ctx) = 0;

  virtual void enterMultExpr(VecMathParser::MultExprContext *ctx) = 0;
  virtual void exitMultExpr(VecMathParser::MultExprContext *ctx) = 0;

  virtual void enterInt(VecMathParser::IntContext *ctx) = 0;
  virtual void exitInt(VecMathParser::IntContext *ctx) = 0;

  virtual void enterId(VecMathParser::IdContext *ctx) = 0;
  virtual void exitId(VecMathParser::IdContext *ctx) = 0;

  virtual void enterVector(VecMathParser::VectorContext *ctx) = 0;
  virtual void exitVector(VecMathParser::VectorContext *ctx) = 0;


};

