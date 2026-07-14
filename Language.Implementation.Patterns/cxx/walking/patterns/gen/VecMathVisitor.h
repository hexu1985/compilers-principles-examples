
// Generated from VecMath.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "VecMathParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by VecMathParser.
 */
class  VecMathVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by VecMathParser.
   */
    virtual std::any visitProg(VecMathParser::ProgContext *context) = 0;

    virtual std::any visitStat(VecMathParser::StatContext *context) = 0;

    virtual std::any visitExpr(VecMathParser::ExprContext *context) = 0;

    virtual std::any visitMultExpr(VecMathParser::MultExprContext *context) = 0;

    virtual std::any visitPrimary(VecMathParser::PrimaryContext *context) = 0;


};

