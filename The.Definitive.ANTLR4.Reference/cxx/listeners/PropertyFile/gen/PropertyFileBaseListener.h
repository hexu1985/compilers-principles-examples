
// Generated from PropertyFile.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "PropertyFileListener.h"


/**
 * This class provides an empty implementation of PropertyFileListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  PropertyFileBaseListener : public PropertyFileListener {
public:

  virtual void enterFile(PropertyFileParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(PropertyFileParser::FileContext * /*ctx*/) override { }

  virtual void enterProp(PropertyFileParser::PropContext * /*ctx*/) override { }
  virtual void exitProp(PropertyFileParser::PropContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

