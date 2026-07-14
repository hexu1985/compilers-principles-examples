
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

  virtual void enterStat(VecMathParser::StatContext *ctx) = 0;
  virtual void exitStat(VecMathParser::StatContext *ctx) = 0;

  virtual void enterExpr(VecMathParser::ExprContext *ctx) = 0;
  virtual void exitExpr(VecMathParser::ExprContext *ctx) = 0;

  virtual void enterMultExpr(VecMathParser::MultExprContext *ctx) = 0;
  virtual void exitMultExpr(VecMathParser::MultExprContext *ctx) = 0;

  virtual void enterPrimary(VecMathParser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(VecMathParser::PrimaryContext *ctx) = 0;


};

