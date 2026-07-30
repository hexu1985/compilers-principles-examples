
// Generated from Cymbol.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "CymbolVisitor.h"


/**
 * This class provides an empty implementation of CymbolVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CymbolBaseVisitor : public CymbolVisitor {
public:

  virtual std::any visitCompilationUnit(CymbolParser::CompilationUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(CymbolParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDeclaration(CymbolParser::VarDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(CymbolParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimary(CymbolParser::PrimaryContext *ctx) override {
    return visitChildren(ctx);
  }


};

