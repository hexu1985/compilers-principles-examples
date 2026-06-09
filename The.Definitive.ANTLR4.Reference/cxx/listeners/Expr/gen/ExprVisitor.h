
// Generated from Expr.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ExprParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ExprParser.
 */
class  ExprVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ExprParser.
   */
    virtual std::any visitS(ExprParser::SContext *context) = 0;

    virtual std::any visitE(ExprParser::EContext *context) = 0;


};

