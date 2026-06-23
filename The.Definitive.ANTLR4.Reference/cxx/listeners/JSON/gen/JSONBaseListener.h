
// Generated from JSON.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "JSONListener.h"


/**
 * This class provides an empty implementation of JSONListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  JSONBaseListener : public JSONListener {
public:

  virtual void enterJson(JSONParser::JsonContext * /*ctx*/) override { }
  virtual void exitJson(JSONParser::JsonContext * /*ctx*/) override { }

  virtual void enterAnObject(JSONParser::AnObjectContext * /*ctx*/) override { }
  virtual void exitAnObject(JSONParser::AnObjectContext * /*ctx*/) override { }

  virtual void enterEmptyObject(JSONParser::EmptyObjectContext * /*ctx*/) override { }
  virtual void exitEmptyObject(JSONParser::EmptyObjectContext * /*ctx*/) override { }

  virtual void enterArrayOfValues(JSONParser::ArrayOfValuesContext * /*ctx*/) override { }
  virtual void exitArrayOfValues(JSONParser::ArrayOfValuesContext * /*ctx*/) override { }

  virtual void enterEmptyArray(JSONParser::EmptyArrayContext * /*ctx*/) override { }
  virtual void exitEmptyArray(JSONParser::EmptyArrayContext * /*ctx*/) override { }

  virtual void enterPair(JSONParser::PairContext * /*ctx*/) override { }
  virtual void exitPair(JSONParser::PairContext * /*ctx*/) override { }

  virtual void enterString(JSONParser::StringContext * /*ctx*/) override { }
  virtual void exitString(JSONParser::StringContext * /*ctx*/) override { }

  virtual void enterAtom(JSONParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(JSONParser::AtomContext * /*ctx*/) override { }

  virtual void enterObjectValue(JSONParser::ObjectValueContext * /*ctx*/) override { }
  virtual void exitObjectValue(JSONParser::ObjectValueContext * /*ctx*/) override { }

  virtual void enterArrayValue(JSONParser::ArrayValueContext * /*ctx*/) override { }
  virtual void exitArrayValue(JSONParser::ArrayValueContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

