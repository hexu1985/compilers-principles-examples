
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

  virtual void enterCompilationUnit(CymbolParser::CompilationUnitContext * /*ctx*/) override { }
  virtual void exitCompilationUnit(CymbolParser::CompilationUnitContext * /*ctx*/) override { }

  virtual void enterMethodDeclaration(CymbolParser::MethodDeclarationContext * /*ctx*/) override { }
  virtual void exitMethodDeclaration(CymbolParser::MethodDeclarationContext * /*ctx*/) override { }

  virtual void enterFormalParameters(CymbolParser::FormalParametersContext * /*ctx*/) override { }
  virtual void exitFormalParameters(CymbolParser::FormalParametersContext * /*ctx*/) override { }

  virtual void enterType(CymbolParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(CymbolParser::TypeContext * /*ctx*/) override { }

  virtual void enterBlock(CymbolParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(CymbolParser::BlockContext * /*ctx*/) override { }

  virtual void enterVarDeclaration(CymbolParser::VarDeclarationContext * /*ctx*/) override { }
  virtual void exitVarDeclaration(CymbolParser::VarDeclarationContext * /*ctx*/) override { }

  virtual void enterStatement(CymbolParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(CymbolParser::StatementContext * /*ctx*/) override { }

  virtual void enterExpressionList(CymbolParser::ExpressionListContext * /*ctx*/) override { }
  virtual void exitExpressionList(CymbolParser::ExpressionListContext * /*ctx*/) override { }

  virtual void enterExpression(CymbolParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(CymbolParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterAddExpression(CymbolParser::AddExpressionContext * /*ctx*/) override { }
  virtual void exitAddExpression(CymbolParser::AddExpressionContext * /*ctx*/) override { }

  virtual void enterPostfixExpression(CymbolParser::PostfixExpressionContext * /*ctx*/) override { }
  virtual void exitPostfixExpression(CymbolParser::PostfixExpressionContext * /*ctx*/) override { }

  virtual void enterPrimary(CymbolParser::PrimaryContext * /*ctx*/) override { }
  virtual void exitPrimary(CymbolParser::PrimaryContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

