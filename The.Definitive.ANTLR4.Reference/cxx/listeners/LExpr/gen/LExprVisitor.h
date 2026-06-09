
// Generated from LExpr.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "LExprParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by LExprParser.
 */
class  LExprVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by LExprParser.
   */
    virtual std::any visitS(LExprParser::SContext *context) = 0;

    virtual std::any visitAdd(LExprParser::AddContext *context) = 0;

    virtual std::any visitMult(LExprParser::MultContext *context) = 0;

    virtual std::any visitInt(LExprParser::IntContext *context) = 0;


};

