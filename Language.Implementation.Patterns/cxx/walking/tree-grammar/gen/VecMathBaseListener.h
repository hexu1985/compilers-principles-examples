
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

  virtual void enterAssign(VecMathParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(VecMathParser::AssignContext * /*ctx*/) override { }

  virtual void enterPrint(VecMathParser::PrintContext * /*ctx*/) override { }
  virtual void exitPrint(VecMathParser::PrintContext * /*ctx*/) override { }

  virtual void enterExpr(VecMathParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(VecMathParser::ExprContext * /*ctx*/) override { }

  virtual void enterMultExpr(VecMathParser::MultExprContext * /*ctx*/) override { }
  virtual void exitMultExpr(VecMathParser::MultExprContext * /*ctx*/) override { }

  virtual void enterInt(VecMathParser::IntContext * /*ctx*/) override { }
  virtual void exitInt(VecMathParser::IntContext * /*ctx*/) override { }

  virtual void enterId(VecMathParser::IdContext * /*ctx*/) override { }
  virtual void exitId(VecMathParser::IdContext * /*ctx*/) override { }

  virtual void enterVector(VecMathParser::VectorContext * /*ctx*/) override { }
  virtual void exitVector(VecMathParser::VectorContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

