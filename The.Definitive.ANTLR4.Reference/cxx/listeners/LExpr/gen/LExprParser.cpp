
// Generated from LExpr.g4 by ANTLR 4.13.0


#include "LExprListener.h"
#include "LExprVisitor.h"

#include "LExprParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct LExprParserStaticData final {
  LExprParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LExprParserStaticData(const LExprParserStaticData&) = delete;
  LExprParserStaticData(LExprParserStaticData&&) = delete;
  LExprParserStaticData& operator=(const LExprParserStaticData&) = delete;
  LExprParserStaticData& operator=(LExprParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag lexprParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
LExprParserStaticData *lexprParserStaticData = nullptr;

void lexprParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (lexprParserStaticData != nullptr) {
    return;
  }
#else
  assert(lexprParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LExprParserStaticData>(
    std::vector<std::string>{
      "s", "e"
    },
    std::vector<std::string>{
      "", "'*'", "'+'"
    },
    std::vector<std::string>{
      "", "MULT", "ADD", "INT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,4,21,2,0,7,0,2,1,7,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	5,1,16,8,1,10,1,12,1,19,9,1,1,1,0,1,2,2,0,2,0,0,20,0,4,1,0,0,0,2,6,1,
  	0,0,0,4,5,3,2,1,0,5,1,1,0,0,0,6,7,6,1,-1,0,7,8,5,3,0,0,8,17,1,0,0,0,9,
  	10,10,3,0,0,10,11,5,1,0,0,11,16,3,2,1,4,12,13,10,2,0,0,13,14,5,2,0,0,
  	14,16,3,2,1,3,15,9,1,0,0,0,15,12,1,0,0,0,16,19,1,0,0,0,17,15,1,0,0,0,
  	17,18,1,0,0,0,18,3,1,0,0,0,19,17,1,0,0,0,2,15,17
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  lexprParserStaticData = staticData.release();
}

}

LExprParser::LExprParser(TokenStream *input) : LExprParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

LExprParser::LExprParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  LExprParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *lexprParserStaticData->atn, lexprParserStaticData->decisionToDFA, lexprParserStaticData->sharedContextCache, options);
}

LExprParser::~LExprParser() {
  delete _interpreter;
}

const atn::ATN& LExprParser::getATN() const {
  return *lexprParserStaticData->atn;
}

std::string LExprParser::getGrammarFileName() const {
  return "LExpr.g4";
}

const std::vector<std::string>& LExprParser::getRuleNames() const {
  return lexprParserStaticData->ruleNames;
}

const dfa::Vocabulary& LExprParser::getVocabulary() const {
  return lexprParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView LExprParser::getSerializedATN() const {
  return lexprParserStaticData->serializedATN;
}


//----------------- SContext ------------------------------------------------------------------

LExprParser::SContext::SContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LExprParser::EContext* LExprParser::SContext::e() {
  return getRuleContext<LExprParser::EContext>(0);
}


size_t LExprParser::SContext::getRuleIndex() const {
  return LExprParser::RuleS;
}

void LExprParser::SContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterS(this);
}

void LExprParser::SContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitS(this);
}


std::any LExprParser::SContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LExprVisitor*>(visitor))
    return parserVisitor->visitS(this);
  else
    return visitor->visitChildren(this);
}

LExprParser::SContext* LExprParser::s() {
  SContext *_localctx = _tracker.createInstance<SContext>(_ctx, getState());
  enterRule(_localctx, 0, LExprParser::RuleS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(4);
    e(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EContext ------------------------------------------------------------------

LExprParser::EContext::EContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LExprParser::EContext::getRuleIndex() const {
  return LExprParser::RuleE;
}

void LExprParser::EContext::copyFrom(EContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AddContext ------------------------------------------------------------------

std::vector<LExprParser::EContext *> LExprParser::AddContext::e() {
  return getRuleContexts<LExprParser::EContext>();
}

LExprParser::EContext* LExprParser::AddContext::e(size_t i) {
  return getRuleContext<LExprParser::EContext>(i);
}

tree::TerminalNode* LExprParser::AddContext::ADD() {
  return getToken(LExprParser::ADD, 0);
}

LExprParser::AddContext::AddContext(EContext *ctx) { copyFrom(ctx); }

void LExprParser::AddContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdd(this);
}
void LExprParser::AddContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdd(this);
}

std::any LExprParser::AddContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LExprVisitor*>(visitor))
    return parserVisitor->visitAdd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultContext ------------------------------------------------------------------

std::vector<LExprParser::EContext *> LExprParser::MultContext::e() {
  return getRuleContexts<LExprParser::EContext>();
}

LExprParser::EContext* LExprParser::MultContext::e(size_t i) {
  return getRuleContext<LExprParser::EContext>(i);
}

tree::TerminalNode* LExprParser::MultContext::MULT() {
  return getToken(LExprParser::MULT, 0);
}

LExprParser::MultContext::MultContext(EContext *ctx) { copyFrom(ctx); }

void LExprParser::MultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMult(this);
}
void LExprParser::MultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMult(this);
}

std::any LExprParser::MultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LExprVisitor*>(visitor))
    return parserVisitor->visitMult(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntContext ------------------------------------------------------------------

tree::TerminalNode* LExprParser::IntContext::INT() {
  return getToken(LExprParser::INT, 0);
}

LExprParser::IntContext::IntContext(EContext *ctx) { copyFrom(ctx); }

void LExprParser::IntContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInt(this);
}
void LExprParser::IntContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInt(this);
}

std::any LExprParser::IntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LExprVisitor*>(visitor))
    return parserVisitor->visitInt(this);
  else
    return visitor->visitChildren(this);
}

LExprParser::EContext* LExprParser::e() {
   return e(0);
}

LExprParser::EContext* LExprParser::e(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LExprParser::EContext *_localctx = _tracker.createInstance<EContext>(_ctx, parentState);
  LExprParser::EContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, LExprParser::RuleE, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<IntContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(7);
    match(LExprParser::INT);
    _ctx->stop = _input->LT(-1);
    setState(17);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(15);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultContext>(_tracker.createInstance<EContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleE);
          setState(9);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(10);
          match(LExprParser::MULT);
          setState(11);
          e(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddContext>(_tracker.createInstance<EContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleE);
          setState(12);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(13);
          match(LExprParser::ADD);
          setState(14);
          e(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(19);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool LExprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return eSempred(antlrcpp::downCast<EContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool LExprParser::eSempred(EContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void LExprParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  lexprParserInitialize();
#else
  ::antlr4::internal::call_once(lexprParserOnceFlag, lexprParserInitialize);
#endif
}
