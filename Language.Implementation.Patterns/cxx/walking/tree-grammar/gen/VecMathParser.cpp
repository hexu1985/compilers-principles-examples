
// Generated from VecMath.g4 by ANTLR 4.13.0


#include "VecMathListener.h"
#include "VecMathVisitor.h"

#include "VecMathParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct VecMathParserStaticData final {
  VecMathParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  VecMathParserStaticData(const VecMathParserStaticData&) = delete;
  VecMathParserStaticData(VecMathParserStaticData&&) = delete;
  VecMathParserStaticData& operator=(const VecMathParserStaticData&) = delete;
  VecMathParserStaticData& operator=(VecMathParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag vecmathParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
VecMathParserStaticData *vecmathParserStaticData = nullptr;

void vecmathParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (vecmathParserStaticData != nullptr) {
    return;
  }
#else
  assert(vecmathParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<VecMathParserStaticData>(
    std::vector<std::string>{
      "prog", "stat", "expr", "multExpr", "primary"
    },
    std::vector<std::string>{
      "", "'='", "'print'", "'+'", "'*'", "'.'", "'['", "','", "']'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "ID", "INT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,11,54,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,1,0,4,0,12,8,0,11,0,
  	12,0,13,1,1,1,1,1,1,1,1,1,1,3,1,21,8,1,1,2,1,2,1,2,5,2,26,8,2,10,2,12,
  	2,29,9,2,1,3,1,3,1,3,5,3,34,8,3,10,3,12,3,37,9,3,1,4,1,4,1,4,1,4,1,4,
  	1,4,5,4,45,8,4,10,4,12,4,48,9,4,1,4,1,4,3,4,52,8,4,1,4,0,0,5,0,2,4,6,
  	8,0,1,1,0,4,5,55,0,11,1,0,0,0,2,20,1,0,0,0,4,22,1,0,0,0,6,30,1,0,0,0,
  	8,51,1,0,0,0,10,12,3,2,1,0,11,10,1,0,0,0,12,13,1,0,0,0,13,11,1,0,0,0,
  	13,14,1,0,0,0,14,1,1,0,0,0,15,16,5,9,0,0,16,17,5,1,0,0,17,21,3,4,2,0,
  	18,19,5,2,0,0,19,21,3,4,2,0,20,15,1,0,0,0,20,18,1,0,0,0,21,3,1,0,0,0,
  	22,27,3,6,3,0,23,24,5,3,0,0,24,26,3,6,3,0,25,23,1,0,0,0,26,29,1,0,0,0,
  	27,25,1,0,0,0,27,28,1,0,0,0,28,5,1,0,0,0,29,27,1,0,0,0,30,35,3,8,4,0,
  	31,32,7,0,0,0,32,34,3,8,4,0,33,31,1,0,0,0,34,37,1,0,0,0,35,33,1,0,0,0,
  	35,36,1,0,0,0,36,7,1,0,0,0,37,35,1,0,0,0,38,52,5,10,0,0,39,52,5,9,0,0,
  	40,41,5,6,0,0,41,46,3,4,2,0,42,43,5,7,0,0,43,45,3,4,2,0,44,42,1,0,0,0,
  	45,48,1,0,0,0,46,44,1,0,0,0,46,47,1,0,0,0,47,49,1,0,0,0,48,46,1,0,0,0,
  	49,50,5,8,0,0,50,52,1,0,0,0,51,38,1,0,0,0,51,39,1,0,0,0,51,40,1,0,0,0,
  	52,9,1,0,0,0,6,13,20,27,35,46,51
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  vecmathParserStaticData = staticData.release();
}

}

VecMathParser::VecMathParser(TokenStream *input) : VecMathParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

VecMathParser::VecMathParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  VecMathParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *vecmathParserStaticData->atn, vecmathParserStaticData->decisionToDFA, vecmathParserStaticData->sharedContextCache, options);
}

VecMathParser::~VecMathParser() {
  delete _interpreter;
}

const atn::ATN& VecMathParser::getATN() const {
  return *vecmathParserStaticData->atn;
}

std::string VecMathParser::getGrammarFileName() const {
  return "VecMath.g4";
}

const std::vector<std::string>& VecMathParser::getRuleNames() const {
  return vecmathParserStaticData->ruleNames;
}

const dfa::Vocabulary& VecMathParser::getVocabulary() const {
  return vecmathParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView VecMathParser::getSerializedATN() const {
  return vecmathParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

VecMathParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<VecMathParser::StatContext *> VecMathParser::ProgContext::stat() {
  return getRuleContexts<VecMathParser::StatContext>();
}

VecMathParser::StatContext* VecMathParser::ProgContext::stat(size_t i) {
  return getRuleContext<VecMathParser::StatContext>(i);
}


size_t VecMathParser::ProgContext::getRuleIndex() const {
  return VecMathParser::RuleProg;
}

void VecMathParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VecMathListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void VecMathParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VecMathListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}


std::any VecMathParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VecMathVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

VecMathParser::ProgContext* VecMathParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, VecMathParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(11); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(10);
      stat();
      setState(13); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == VecMathParser::T__1

    || _la == VecMathParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatContext ------------------------------------------------------------------

VecMathParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t VecMathParser::StatContext::getRuleIndex() const {
  return VecMathParser::RuleStat;
}

void VecMathParser::StatContext::copyFrom(StatContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PrintContext ------------------------------------------------------------------

VecMathParser::ExprContext* VecMathParser::PrintContext::expr() {
  return getRuleContext<VecMathParser::ExprContext>(0);
}

VecMathParser::PrintContext::PrintContext(StatContext *ctx) { copyFrom(ctx); }

void VecMathParser::PrintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VecMathListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrint(this);
}
void VecMathParser::PrintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VecMathListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrint(this);
}

std::any VecMathParser::PrintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VecMathVisitor*>(visitor))
    return parserVisitor->visitPrint(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignContext ------------------------------------------------------------------

tree::TerminalNode* VecMathParser::AssignContext::ID() {
  return getToken(VecMathParser::ID, 0);
}

VecMathParser::ExprContext* VecMathParser::AssignContext::expr() {
  return getRuleContext<VecMathParser::ExprContext>(0);
}

VecMathParser::AssignContext::AssignContext(StatContext *ctx) { copyFrom(ctx); }

void VecMathParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VecMathListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}
void VecMathParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VecMathListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}

std::any VecMathParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VecMathVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}
VecMathParser::StatContext* VecMathParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 2, VecMathParser::RuleStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(20);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case VecMathParser::ID: {
        _localctx = _tracker.createInstance<VecMathParser::AssignContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(15);
        match(VecMathParser::ID);
        setState(16);
        match(VecMathParser::T__0);
        setState(17);
        expr();
        break;
      }

      case VecMathParser::T__1: {
        _localctx = _tracker.createInstance<VecMathParser::PrintContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(18);
        match(VecMathParser::T__1);
        setState(19);
        expr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

VecMathParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<VecMathParser::MultExprContext *> VecMathParser::ExprContext::multExpr() {
  return getRuleContexts<VecMathParser::MultExprContext>();
}

VecMathParser::MultExprContext* VecMathParser::ExprContext::multExpr(size_t i) {
  return getRuleContext<VecMathParser::MultExprContext>(i);
}


size_t VecMathParser::ExprContext::getRuleIndex() const {
  return VecMathParser::RuleExpr;
}

void VecMathParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VecMathListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void VecMathParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VecMathListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any VecMathParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VecMathVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

VecMathParser::ExprContext* VecMathParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 4, VecMathParser::RuleExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(22);
    multExpr();
    setState(27);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == VecMathParser::T__2) {
      setState(23);
      antlrcpp::downCast<ExprContext *>(_localctx)->op = match(VecMathParser::T__2);
      setState(24);
      multExpr();
      setState(29);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultExprContext ------------------------------------------------------------------

VecMathParser::MultExprContext::MultExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<VecMathParser::PrimaryContext *> VecMathParser::MultExprContext::primary() {
  return getRuleContexts<VecMathParser::PrimaryContext>();
}

VecMathParser::PrimaryContext* VecMathParser::MultExprContext::primary(size_t i) {
  return getRuleContext<VecMathParser::PrimaryContext>(i);
}


size_t VecMathParser::MultExprContext::getRuleIndex() const {
  return VecMathParser::RuleMultExpr;
}

void VecMathParser::MultExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VecMathListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultExpr(this);
}

void VecMathParser::MultExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VecMathListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultExpr(this);
}


std::any VecMathParser::MultExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VecMathVisitor*>(visitor))
    return parserVisitor->visitMultExpr(this);
  else
    return visitor->visitChildren(this);
}

VecMathParser::MultExprContext* VecMathParser::multExpr() {
  MultExprContext *_localctx = _tracker.createInstance<MultExprContext>(_ctx, getState());
  enterRule(_localctx, 6, VecMathParser::RuleMultExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    primary();
    setState(35);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == VecMathParser::T__3

    || _la == VecMathParser::T__4) {
      setState(31);
      antlrcpp::downCast<MultExprContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == VecMathParser::T__3

      || _la == VecMathParser::T__4)) {
        antlrcpp::downCast<MultExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(32);
      primary();
      setState(37);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

VecMathParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t VecMathParser::PrimaryContext::getRuleIndex() const {
  return VecMathParser::RulePrimary;
}

void VecMathParser::PrimaryContext::copyFrom(PrimaryContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IdContext ------------------------------------------------------------------

tree::TerminalNode* VecMathParser::IdContext::ID() {
  return getToken(VecMathParser::ID, 0);
}

VecMathParser::IdContext::IdContext(PrimaryContext *ctx) { copyFrom(ctx); }

void VecMathParser::IdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VecMathListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterId(this);
}
void VecMathParser::IdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VecMathListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitId(this);
}

std::any VecMathParser::IdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VecMathVisitor*>(visitor))
    return parserVisitor->visitId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VectorContext ------------------------------------------------------------------

std::vector<VecMathParser::ExprContext *> VecMathParser::VectorContext::expr() {
  return getRuleContexts<VecMathParser::ExprContext>();
}

VecMathParser::ExprContext* VecMathParser::VectorContext::expr(size_t i) {
  return getRuleContext<VecMathParser::ExprContext>(i);
}

VecMathParser::VectorContext::VectorContext(PrimaryContext *ctx) { copyFrom(ctx); }

void VecMathParser::VectorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VecMathListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVector(this);
}
void VecMathParser::VectorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VecMathListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVector(this);
}

std::any VecMathParser::VectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VecMathVisitor*>(visitor))
    return parserVisitor->visitVector(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntContext ------------------------------------------------------------------

tree::TerminalNode* VecMathParser::IntContext::INT() {
  return getToken(VecMathParser::INT, 0);
}

VecMathParser::IntContext::IntContext(PrimaryContext *ctx) { copyFrom(ctx); }

void VecMathParser::IntContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VecMathListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInt(this);
}
void VecMathParser::IntContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VecMathListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInt(this);
}

std::any VecMathParser::IntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VecMathVisitor*>(visitor))
    return parserVisitor->visitInt(this);
  else
    return visitor->visitChildren(this);
}
VecMathParser::PrimaryContext* VecMathParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 8, VecMathParser::RulePrimary);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(51);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case VecMathParser::INT: {
        _localctx = _tracker.createInstance<VecMathParser::IntContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(38);
        match(VecMathParser::INT);
        break;
      }

      case VecMathParser::ID: {
        _localctx = _tracker.createInstance<VecMathParser::IdContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(39);
        match(VecMathParser::ID);
        break;
      }

      case VecMathParser::T__5: {
        _localctx = _tracker.createInstance<VecMathParser::VectorContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(40);
        match(VecMathParser::T__5);
        setState(41);
        expr();
        setState(46);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == VecMathParser::T__6) {
          setState(42);
          match(VecMathParser::T__6);
          setState(43);
          expr();
          setState(48);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(49);
        match(VecMathParser::T__7);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void VecMathParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  vecmathParserInitialize();
#else
  ::antlr4::internal::call_once(vecmathParserOnceFlag, vecmathParserInitialize);
#endif
}
