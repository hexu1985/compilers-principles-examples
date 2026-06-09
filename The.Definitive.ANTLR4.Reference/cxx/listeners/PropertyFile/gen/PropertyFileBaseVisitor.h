
// Generated from PropertyFile.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "PropertyFileVisitor.h"


/**
 * This class provides an empty implementation of PropertyFileVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  PropertyFileBaseVisitor : public PropertyFileVisitor {
public:

  virtual std::any visitFile(PropertyFileParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProp(PropertyFileParser::PropContext *ctx) override {
    return visitChildren(ctx);
  }


};

