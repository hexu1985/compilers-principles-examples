
// Generated from Cymbol.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "CymbolListener.h"


/**
 * This class provides an empty implementation of CymbolListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  CymbolBaseListener : public CymbolListener {
public:

  virtual void enterFile(CymbolParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(CymbolParser::FileContext * /*ctx*/) override { }

  virtual void enterVarDecl(CymbolParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(CymbolParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterType(CymbolParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(CymbolParser::TypeContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(CymbolParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(CymbolParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterFormalParameters(CymbolParser::FormalParametersContext * /*ctx*/) override { }
  virtual void exitFormalParameters(CymbolParser::FormalParametersContext * /*ctx*/) override { }

  virtual void enterFormalParameter(CymbolParser::FormalParameterContext * /*ctx*/) override { }
  virtual void exitFormalParameter(CymbolParser::FormalParameterContext * /*ctx*/) override { }

  virtual void enterBlock(CymbolParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(CymbolParser::BlockContext * /*ctx*/) override { }

  virtual void enterStat(CymbolParser::StatContext * /*ctx*/) override { }
  virtual void exitStat(CymbolParser::StatContext * /*ctx*/) override { }

  virtual void enterCall(CymbolParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(CymbolParser::CallContext * /*ctx*/) override { }

  virtual void enterNot(CymbolParser::NotContext * /*ctx*/) override { }
  virtual void exitNot(CymbolParser::NotContext * /*ctx*/) override { }

  virtual void enterMult(CymbolParser::MultContext * /*ctx*/) override { }
  virtual void exitMult(CymbolParser::MultContext * /*ctx*/) override { }

  virtual void enterAddSub(CymbolParser::AddSubContext * /*ctx*/) override { }
  virtual void exitAddSub(CymbolParser::AddSubContext * /*ctx*/) override { }

  virtual void enterEqual(CymbolParser::EqualContext * /*ctx*/) override { }
  virtual void exitEqual(CymbolParser::EqualContext * /*ctx*/) override { }

  virtual void enterVar(CymbolParser::VarContext * /*ctx*/) override { }
  virtual void exitVar(CymbolParser::VarContext * /*ctx*/) override { }

  virtual void enterParens(CymbolParser::ParensContext * /*ctx*/) override { }
  virtual void exitParens(CymbolParser::ParensContext * /*ctx*/) override { }

  virtual void enterIndex(CymbolParser::IndexContext * /*ctx*/) override { }
  virtual void exitIndex(CymbolParser::IndexContext * /*ctx*/) override { }

  virtual void enterNegate(CymbolParser::NegateContext * /*ctx*/) override { }
  virtual void exitNegate(CymbolParser::NegateContext * /*ctx*/) override { }

  virtual void enterInt(CymbolParser::IntContext * /*ctx*/) override { }
  virtual void exitInt(CymbolParser::IntContext * /*ctx*/) override { }

  virtual void enterExprList(CymbolParser::ExprListContext * /*ctx*/) override { }
  virtual void exitExprList(CymbolParser::ExprListContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

