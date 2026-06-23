
// Generated from JSON.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  JSONParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    LCURLY = 8, LBRACK = 9, STRING = 10, NUMBER = 11, WS = 12
  };

  enum {
    RuleJson = 0, RuleObject = 1, RuleArray = 2, RulePair = 3, RuleValue = 4
  };

  explicit JSONParser(antlr4::TokenStream *input);

  JSONParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~JSONParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class JsonContext;
  class ObjectContext;
  class ArrayContext;
  class PairContext;
  class ValueContext; 

  class  JsonContext : public antlr4::ParserRuleContext {
  public:
    JsonContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ObjectContext *object();
    ArrayContext *array();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  JsonContext* json();

  class  ObjectContext : public antlr4::ParserRuleContext {
  public:
    ObjectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ObjectContext() = default;
    void copyFrom(ObjectContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AnObjectContext : public ObjectContext {
  public:
    AnObjectContext(ObjectContext *ctx);

    antlr4::tree::TerminalNode *LCURLY();
    std::vector<PairContext *> pair();
    PairContext* pair(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  EmptyObjectContext : public ObjectContext {
  public:
    EmptyObjectContext(ObjectContext *ctx);

    antlr4::tree::TerminalNode *LCURLY();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ObjectContext* object();

  class  ArrayContext : public antlr4::ParserRuleContext {
  public:
    ArrayContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ArrayContext() = default;
    void copyFrom(ArrayContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ArrayOfValuesContext : public ArrayContext {
  public:
    ArrayOfValuesContext(ArrayContext *ctx);

    antlr4::tree::TerminalNode *LBRACK();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  EmptyArrayContext : public ArrayContext {
  public:
    EmptyArrayContext(ArrayContext *ctx);

    antlr4::tree::TerminalNode *LBRACK();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ArrayContext* array();

  class  PairContext : public antlr4::ParserRuleContext {
  public:
    PairContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();
    ValueContext *value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PairContext* pair();

  class  ValueContext : public antlr4::ParserRuleContext {
  public:
    ValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ValueContext() = default;
    void copyFrom(ValueContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ObjectValueContext : public ValueContext {
  public:
    ObjectValueContext(ValueContext *ctx);

    ObjectContext *object();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  StringContext : public ValueContext {
  public:
    StringContext(ValueContext *ctx);

    antlr4::tree::TerminalNode *STRING();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ArrayValueContext : public ValueContext {
  public:
    ArrayValueContext(ValueContext *ctx);

    ArrayContext *array();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  AtomContext : public ValueContext {
  public:
    AtomContext(ValueContext *ctx);

    antlr4::tree::TerminalNode *NUMBER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ValueContext* value();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

