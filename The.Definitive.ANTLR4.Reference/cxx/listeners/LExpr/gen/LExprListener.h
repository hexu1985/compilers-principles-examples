
// Generated from LExpr.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "LExprParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by LExprParser.
 */
class  LExprListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterS(LExprParser::SContext *ctx) = 0;
  virtual void exitS(LExprParser::SContext *ctx) = 0;

  virtual void enterAdd(LExprParser::AddContext *ctx) = 0;
  virtual void exitAdd(LExprParser::AddContext *ctx) = 0;

  virtual void enterMult(LExprParser::MultContext *ctx) = 0;
  virtual void exitMult(LExprParser::MultContext *ctx) = 0;

  virtual void enterInt(LExprParser::IntContext *ctx) = 0;
  virtual void exitInt(LExprParser::IntContext *ctx) = 0;


};

