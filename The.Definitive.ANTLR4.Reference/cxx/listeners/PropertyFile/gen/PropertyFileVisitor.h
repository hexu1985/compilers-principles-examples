
// Generated from PropertyFile.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "PropertyFileParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PropertyFileParser.
 */
class  PropertyFileVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PropertyFileParser.
   */
    virtual std::any visitFile(PropertyFileParser::FileContext *context) = 0;

    virtual std::any visitProp(PropertyFileParser::PropContext *context) = 0;


};

