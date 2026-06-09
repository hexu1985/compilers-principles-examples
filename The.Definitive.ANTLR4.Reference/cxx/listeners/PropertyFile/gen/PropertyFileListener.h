
// Generated from PropertyFile.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "PropertyFileParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by PropertyFileParser.
 */
class  PropertyFileListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(PropertyFileParser::FileContext *ctx) = 0;
  virtual void exitFile(PropertyFileParser::FileContext *ctx) = 0;

  virtual void enterProp(PropertyFileParser::PropContext *ctx) = 0;
  virtual void exitProp(PropertyFileParser::PropContext *ctx) = 0;


};

