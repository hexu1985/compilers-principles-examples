
// Generated from VecMath.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "VecMathListener.h"


/**
 * This class provides an empty implementation of VecMathListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  VecMathBaseListener : public VecMathListener {
public:

  virtual void enterProg(VecMathParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(VecMathParser::ProgContext * /*ctx*/) override { }

  virtual void enterStat(VecMathParser::StatContext * /*ctx*/) override { }
  virtual void exitStat(VecMathParser::StatContext * /*ctx*/) override { }

  virtual void enterExpr(VecMathParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(VecMathParser::ExprContext * /*ctx*/) override { }

  virtual void enterMultExpr(VecMathParser::MultExprContext * /*ctx*/) override { }
  virtual void exitMultExpr(VecMathParser::MultExprContext * /*ctx*/) override { }

  virtual void enterPrimary(VecMathParser::PrimaryContext * /*ctx*/) override { }
  virtual void exitPrimary(VecMathParser::PrimaryContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

