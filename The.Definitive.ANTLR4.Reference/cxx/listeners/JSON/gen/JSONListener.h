
// Generated from JSON.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "JSONParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by JSONParser.
 */
class  JSONListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterJson(JSONParser::JsonContext *ctx) = 0;
  virtual void exitJson(JSONParser::JsonContext *ctx) = 0;

  virtual void enterAnObject(JSONParser::AnObjectContext *ctx) = 0;
  virtual void exitAnObject(JSONParser::AnObjectContext *ctx) = 0;

  virtual void enterEmptyObject(JSONParser::EmptyObjectContext *ctx) = 0;
  virtual void exitEmptyObject(JSONParser::EmptyObjectContext *ctx) = 0;

  virtual void enterArrayOfValues(JSONParser::ArrayOfValuesContext *ctx) = 0;
  virtual void exitArrayOfValues(JSONParser::ArrayOfValuesContext *ctx) = 0;

  virtual void enterEmptyArray(JSONParser::EmptyArrayContext *ctx) = 0;
  virtual void exitEmptyArray(JSONParser::EmptyArrayContext *ctx) = 0;

  virtual void enterPair(JSONParser::PairContext *ctx) = 0;
  virtual void exitPair(JSONParser::PairContext *ctx) = 0;

  virtual void enterString(JSONParser::StringContext *ctx) = 0;
  virtual void exitString(JSONParser::StringContext *ctx) = 0;

  virtual void enterAtom(JSONParser::AtomContext *ctx) = 0;
  virtual void exitAtom(JSONParser::AtomContext *ctx) = 0;

  virtual void enterObjectValue(JSONParser::ObjectValueContext *ctx) = 0;
  virtual void exitObjectValue(JSONParser::ObjectValueContext *ctx) = 0;

  virtual void enterArrayValue(JSONParser::ArrayValueContext *ctx) = 0;
  virtual void exitArrayValue(JSONParser::ArrayValueContext *ctx) = 0;


};

