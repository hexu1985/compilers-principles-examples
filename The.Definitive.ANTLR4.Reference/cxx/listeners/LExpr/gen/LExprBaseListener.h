
// Generated from LExpr.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "LExprListener.h"


/**
 * This class provides an empty implementation of LExprListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  LExprBaseListener : public LExprListener {
public:

  virtual void enterS(LExprParser::SContext * /*ctx*/) override { }
  virtual void exitS(LExprParser::SContext * /*ctx*/) override { }

  virtual void enterAdd(LExprParser::AddContext * /*ctx*/) override { }
  virtual void exitAdd(LExprParser::AddContext * /*ctx*/) override { }

  virtual void enterMult(LExprParser::MultContext * /*ctx*/) override { }
  virtual void exitMult(LExprParser::MultContext * /*ctx*/) override { }

  virtual void enterInt(LExprParser::IntContext * /*ctx*/) override { }
  virtual void exitInt(LExprParser::IntContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

