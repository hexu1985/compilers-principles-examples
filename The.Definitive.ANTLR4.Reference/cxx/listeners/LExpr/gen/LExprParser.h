
// Generated from LExpr.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  LExprParser : public antlr4::Parser {
public:
  enum {
    MULT = 1, ADD = 2, INT = 3, WS = 4
  };

  enum {
    RuleS = 0, RuleE = 1
  };

  explicit LExprParser(antlr4::TokenStream *input);

  LExprParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~LExprParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class SContext;
  class EContext; 

  class  SContext : public antlr4::ParserRuleContext {
  public:
    SContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EContext *e();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SContext* s();

  class  EContext : public antlr4::ParserRuleContext {
  public:
    EContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    EContext() = default;
    void copyFrom(EContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AddContext : public EContext {
  public:
    AddContext(EContext *ctx);

    std::vector<EContext *> e();
    EContext* e(size_t i);
    antlr4::tree::TerminalNode *ADD();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MultContext : public EContext {
  public:
    MultContext(EContext *ctx);

    std::vector<EContext *> e();
    EContext* e(size_t i);
    antlr4::tree::TerminalNode *MULT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntContext : public EContext {
  public:
    IntContext(EContext *ctx);

    antlr4::tree::TerminalNode *INT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  EContext* e();
  EContext* e(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool eSempred(EContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

