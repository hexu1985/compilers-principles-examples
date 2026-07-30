
// Generated from Cymbol.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "CymbolParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CymbolParser.
 */
class  CymbolVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CymbolParser.
   */
    virtual std::any visitCompilationUnit(CymbolParser::CompilationUnitContext *context) = 0;

    virtual std::any visitMethodDeclaration(CymbolParser::MethodDeclarationContext *context) = 0;

    virtual std::any visitFormalParameters(CymbolParser::FormalParametersContext *context) = 0;

    virtual std::any visitType(CymbolParser::TypeContext *context) = 0;

    virtual std::any visitBlock(CymbolParser::BlockContext *context) = 0;

    virtual std::any visitVarDeclaration(CymbolParser::VarDeclarationContext *context) = 0;

    virtual std::any visitStatement(CymbolParser::StatementContext *context) = 0;

    virtual std::any visitExpressionList(CymbolParser::ExpressionListContext *context) = 0;

    virtual std::any visitExpression(CymbolParser::ExpressionContext *context) = 0;

    virtual std::any visitAddExpression(CymbolParser::AddExpressionContext *context) = 0;

    virtual std::any visitPostfixExpression(CymbolParser::PostfixExpressionContext *context) = 0;

    virtual std::any visitPrimary(CymbolParser::PrimaryContext *context) = 0;


};

