
// Generated from Cymbol.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "CymbolParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CymbolParser.
 */
class  CymbolListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(CymbolParser::FileContext *ctx) = 0;
  virtual void exitFile(CymbolParser::FileContext *ctx) = 0;

  virtual void enterVarDecl(CymbolParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(CymbolParser::VarDeclContext *ctx) = 0;

  virtual void enterType(CymbolParser::TypeContext *ctx) = 0;
  virtual void exitType(CymbolParser::TypeContext *ctx) = 0;

  virtual void enterFunctionDecl(CymbolParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(CymbolParser::FunctionDeclContext *ctx) = 0;

  virtual void enterFormalParameters(CymbolParser::FormalParametersContext *ctx) = 0;
  virtual void exitFormalParameters(CymbolParser::FormalParametersContext *ctx) = 0;

  virtual void enterFormalParameter(CymbolParser::FormalParameterContext *ctx) = 0;
  virtual void exitFormalParameter(CymbolParser::FormalParameterContext *ctx) = 0;

  virtual void enterBlock(CymbolParser::BlockContext *ctx) = 0;
  virtual void exitBlock(CymbolParser::BlockContext *ctx) = 0;

  virtual void enterStat(CymbolParser::StatContext *ctx) = 0;
  virtual void exitStat(CymbolParser::StatContext *ctx) = 0;

  virtual void enterCall(CymbolParser::CallContext *ctx) = 0;
  virtual void exitCall(CymbolParser::CallContext *ctx) = 0;

  virtual void enterNot(CymbolParser::NotContext *ctx) = 0;
  virtual void exitNot(CymbolParser::NotContext *ctx) = 0;

  virtual void enterMult(CymbolParser::MultContext *ctx) = 0;
  virtual void exitMult(CymbolParser::MultContext *ctx) = 0;

  virtual void enterAddSub(CymbolParser::AddSubContext *ctx) = 0;
  virtual void exitAddSub(CymbolParser::AddSubContext *ctx) = 0;

  virtual void enterEqual(CymbolParser::EqualContext *ctx) = 0;
  virtual void exitEqual(CymbolParser::EqualContext *ctx) = 0;

  virtual void enterVar(CymbolParser::VarContext *ctx) = 0;
  virtual void exitVar(CymbolParser::VarContext *ctx) = 0;

  virtual void enterParens(CymbolParser::ParensContext *ctx) = 0;
  virtual void exitParens(CymbolParser::ParensContext *ctx) = 0;

  virtual void enterIndex(CymbolParser::IndexContext *ctx) = 0;
  virtual void exitIndex(CymbolParser::IndexContext *ctx) = 0;

  virtual void enterNegate(CymbolParser::NegateContext *ctx) = 0;
  virtual void exitNegate(CymbolParser::NegateContext *ctx) = 0;

  virtual void enterInt(CymbolParser::IntContext *ctx) = 0;
  virtual void exitInt(CymbolParser::IntContext *ctx) = 0;

  virtual void enterExprList(CymbolParser::ExprListContext *ctx) = 0;
  virtual void exitExprList(CymbolParser::ExprListContext *ctx) = 0;


};

