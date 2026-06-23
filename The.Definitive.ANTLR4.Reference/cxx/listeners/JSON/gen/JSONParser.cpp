
// Generated from JSON.g4 by ANTLR 4.13.0


#include "JSONListener.h"

#include "JSONParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct JSONParserStaticData final {
  JSONParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  JSONParserStaticData(const JSONParserStaticData&) = delete;
  JSONParserStaticData(JSONParserStaticData&&) = delete;
  JSONParserStaticData& operator=(const JSONParserStaticData&) = delete;
  JSONParserStaticData& operator=(JSONParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag jsonParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
JSONParserStaticData *jsonParserStaticData = nullptr;

void jsonParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (jsonParserStaticData != nullptr) {
    return;
  }
#else
  assert(jsonParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<JSONParserStaticData>(
    std::vector<std::string>{
      "json", "object", "array", "pair", "value"
    },
    std::vector<std::string>{
      "", "','", "'}'", "']'", "':'", "'true'", "'false'", "'null'", "'{'", 
      "'['"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "LCURLY", "LBRACK", "STRING", "NUMBER", 
      "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,12,58,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,1,0,1,0,3,0,13,8,0,
  	1,1,1,1,1,1,1,1,5,1,19,8,1,10,1,12,1,22,9,1,1,1,1,1,1,1,1,1,3,1,28,8,
  	1,1,2,1,2,1,2,1,2,5,2,34,8,2,10,2,12,2,37,9,2,1,2,1,2,1,2,1,2,3,2,43,
  	8,2,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,56,8,4,1,4,0,0,5,
  	0,2,4,6,8,0,0,63,0,12,1,0,0,0,2,27,1,0,0,0,4,42,1,0,0,0,6,44,1,0,0,0,
  	8,55,1,0,0,0,10,13,3,2,1,0,11,13,3,4,2,0,12,10,1,0,0,0,12,11,1,0,0,0,
  	13,1,1,0,0,0,14,15,5,8,0,0,15,20,3,6,3,0,16,17,5,1,0,0,17,19,3,6,3,0,
  	18,16,1,0,0,0,19,22,1,0,0,0,20,18,1,0,0,0,20,21,1,0,0,0,21,23,1,0,0,0,
  	22,20,1,0,0,0,23,24,5,2,0,0,24,28,1,0,0,0,25,26,5,8,0,0,26,28,5,2,0,0,
  	27,14,1,0,0,0,27,25,1,0,0,0,28,3,1,0,0,0,29,30,5,9,0,0,30,35,3,8,4,0,
  	31,32,5,1,0,0,32,34,3,8,4,0,33,31,1,0,0,0,34,37,1,0,0,0,35,33,1,0,0,0,
  	35,36,1,0,0,0,36,38,1,0,0,0,37,35,1,0,0,0,38,39,5,3,0,0,39,43,1,0,0,0,
  	40,41,5,9,0,0,41,43,5,3,0,0,42,29,1,0,0,0,42,40,1,0,0,0,43,5,1,0,0,0,
  	44,45,5,10,0,0,45,46,5,4,0,0,46,47,3,8,4,0,47,7,1,0,0,0,48,56,5,10,0,
  	0,49,56,5,11,0,0,50,56,3,2,1,0,51,56,3,4,2,0,52,56,5,5,0,0,53,56,5,6,
  	0,0,54,56,5,7,0,0,55,48,1,0,0,0,55,49,1,0,0,0,55,50,1,0,0,0,55,51,1,0,
  	0,0,55,52,1,0,0,0,55,53,1,0,0,0,55,54,1,0,0,0,56,9,1,0,0,0,6,12,20,27,
  	35,42,55
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  jsonParserStaticData = staticData.release();
}

}

JSONParser::JSONParser(TokenStream *input) : JSONParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

JSONParser::JSONParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  JSONParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *jsonParserStaticData->atn, jsonParserStaticData->decisionToDFA, jsonParserStaticData->sharedContextCache, options);
}

JSONParser::~JSONParser() {
  delete _interpreter;
}

const atn::ATN& JSONParser::getATN() const {
  return *jsonParserStaticData->atn;
}

std::string JSONParser::getGrammarFileName() const {
  return "JSON.g4";
}

const std::vector<std::string>& JSONParser::getRuleNames() const {
  return jsonParserStaticData->ruleNames;
}

const dfa::Vocabulary& JSONParser::getVocabulary() const {
  return jsonParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView JSONParser::getSerializedATN() const {
  return jsonParserStaticData->serializedATN;
}


//----------------- JsonContext ------------------------------------------------------------------

JSONParser::JsonContext::JsonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JSONParser::ObjectContext* JSONParser::JsonContext::object() {
  return getRuleContext<JSONParser::ObjectContext>(0);
}

JSONParser::ArrayContext* JSONParser::JsonContext::array() {
  return getRuleContext<JSONParser::ArrayContext>(0);
}


size_t JSONParser::JsonContext::getRuleIndex() const {
  return JSONParser::RuleJson;
}

void JSONParser::JsonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJson(this);
}

void JSONParser::JsonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJson(this);
}

JSONParser::JsonContext* JSONParser::json() {
  JsonContext *_localctx = _tracker.createInstance<JsonContext>(_ctx, getState());
  enterRule(_localctx, 0, JSONParser::RuleJson);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(12);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JSONParser::LCURLY: {
        enterOuterAlt(_localctx, 1);
        setState(10);
        object();
        break;
      }

      case JSONParser::LBRACK: {
        enterOuterAlt(_localctx, 2);
        setState(11);
        array();
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

//----------------- ObjectContext ------------------------------------------------------------------

JSONParser::ObjectContext::ObjectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t JSONParser::ObjectContext::getRuleIndex() const {
  return JSONParser::RuleObject;
}

void JSONParser::ObjectContext::copyFrom(ObjectContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AnObjectContext ------------------------------------------------------------------

tree::TerminalNode* JSONParser::AnObjectContext::LCURLY() {
  return getToken(JSONParser::LCURLY, 0);
}

std::vector<JSONParser::PairContext *> JSONParser::AnObjectContext::pair() {
  return getRuleContexts<JSONParser::PairContext>();
}

JSONParser::PairContext* JSONParser::AnObjectContext::pair(size_t i) {
  return getRuleContext<JSONParser::PairContext>(i);
}

JSONParser::AnObjectContext::AnObjectContext(ObjectContext *ctx) { copyFrom(ctx); }

void JSONParser::AnObjectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnObject(this);
}
void JSONParser::AnObjectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnObject(this);
}
//----------------- EmptyObjectContext ------------------------------------------------------------------

tree::TerminalNode* JSONParser::EmptyObjectContext::LCURLY() {
  return getToken(JSONParser::LCURLY, 0);
}

JSONParser::EmptyObjectContext::EmptyObjectContext(ObjectContext *ctx) { copyFrom(ctx); }

void JSONParser::EmptyObjectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmptyObject(this);
}
void JSONParser::EmptyObjectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmptyObject(this);
}
JSONParser::ObjectContext* JSONParser::object() {
  ObjectContext *_localctx = _tracker.createInstance<ObjectContext>(_ctx, getState());
  enterRule(_localctx, 2, JSONParser::RuleObject);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(27);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<JSONParser::AnObjectContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(14);
      match(JSONParser::LCURLY);
      setState(15);
      pair();
      setState(20);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == JSONParser::T__0) {
        setState(16);
        match(JSONParser::T__0);
        setState(17);
        pair();
        setState(22);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(23);
      match(JSONParser::T__1);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<JSONParser::EmptyObjectContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(25);
      match(JSONParser::LCURLY);
      setState(26);
      match(JSONParser::T__1);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayContext ------------------------------------------------------------------

JSONParser::ArrayContext::ArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t JSONParser::ArrayContext::getRuleIndex() const {
  return JSONParser::RuleArray;
}

void JSONParser::ArrayContext::copyFrom(ArrayContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArrayOfValuesContext ------------------------------------------------------------------

tree::TerminalNode* JSONParser::ArrayOfValuesContext::LBRACK() {
  return getToken(JSONParser::LBRACK, 0);
}

std::vector<JSONParser::ValueContext *> JSONParser::ArrayOfValuesContext::value() {
  return getRuleContexts<JSONParser::ValueContext>();
}

JSONParser::ValueContext* JSONParser::ArrayOfValuesContext::value(size_t i) {
  return getRuleContext<JSONParser::ValueContext>(i);
}

JSONParser::ArrayOfValuesContext::ArrayOfValuesContext(ArrayContext *ctx) { copyFrom(ctx); }

void JSONParser::ArrayOfValuesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayOfValues(this);
}
void JSONParser::ArrayOfValuesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayOfValues(this);
}
//----------------- EmptyArrayContext ------------------------------------------------------------------

tree::TerminalNode* JSONParser::EmptyArrayContext::LBRACK() {
  return getToken(JSONParser::LBRACK, 0);
}

JSONParser::EmptyArrayContext::EmptyArrayContext(ArrayContext *ctx) { copyFrom(ctx); }

void JSONParser::EmptyArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmptyArray(this);
}
void JSONParser::EmptyArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmptyArray(this);
}
JSONParser::ArrayContext* JSONParser::array() {
  ArrayContext *_localctx = _tracker.createInstance<ArrayContext>(_ctx, getState());
  enterRule(_localctx, 4, JSONParser::RuleArray);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(42);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<JSONParser::ArrayOfValuesContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(29);
      match(JSONParser::LBRACK);
      setState(30);
      value();
      setState(35);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == JSONParser::T__0) {
        setState(31);
        match(JSONParser::T__0);
        setState(32);
        value();
        setState(37);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(38);
      match(JSONParser::T__2);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<JSONParser::EmptyArrayContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(40);
      match(JSONParser::LBRACK);
      setState(41);
      match(JSONParser::T__2);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PairContext ------------------------------------------------------------------

JSONParser::PairContext::PairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JSONParser::PairContext::STRING() {
  return getToken(JSONParser::STRING, 0);
}

JSONParser::ValueContext* JSONParser::PairContext::value() {
  return getRuleContext<JSONParser::ValueContext>(0);
}


size_t JSONParser::PairContext::getRuleIndex() const {
  return JSONParser::RulePair;
}

void JSONParser::PairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPair(this);
}

void JSONParser::PairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPair(this);
}

JSONParser::PairContext* JSONParser::pair() {
  PairContext *_localctx = _tracker.createInstance<PairContext>(_ctx, getState());
  enterRule(_localctx, 6, JSONParser::RulePair);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(44);
    match(JSONParser::STRING);
    setState(45);
    match(JSONParser::T__3);
    setState(46);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

JSONParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t JSONParser::ValueContext::getRuleIndex() const {
  return JSONParser::RuleValue;
}

void JSONParser::ValueContext::copyFrom(ValueContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ObjectValueContext ------------------------------------------------------------------

JSONParser::ObjectContext* JSONParser::ObjectValueContext::object() {
  return getRuleContext<JSONParser::ObjectContext>(0);
}

JSONParser::ObjectValueContext::ObjectValueContext(ValueContext *ctx) { copyFrom(ctx); }

void JSONParser::ObjectValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObjectValue(this);
}
void JSONParser::ObjectValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObjectValue(this);
}
//----------------- StringContext ------------------------------------------------------------------

tree::TerminalNode* JSONParser::StringContext::STRING() {
  return getToken(JSONParser::STRING, 0);
}

JSONParser::StringContext::StringContext(ValueContext *ctx) { copyFrom(ctx); }

void JSONParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}
void JSONParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}
//----------------- ArrayValueContext ------------------------------------------------------------------

JSONParser::ArrayContext* JSONParser::ArrayValueContext::array() {
  return getRuleContext<JSONParser::ArrayContext>(0);
}

JSONParser::ArrayValueContext::ArrayValueContext(ValueContext *ctx) { copyFrom(ctx); }

void JSONParser::ArrayValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayValue(this);
}
void JSONParser::ArrayValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayValue(this);
}
//----------------- AtomContext ------------------------------------------------------------------

tree::TerminalNode* JSONParser::AtomContext::NUMBER() {
  return getToken(JSONParser::NUMBER, 0);
}

JSONParser::AtomContext::AtomContext(ValueContext *ctx) { copyFrom(ctx); }

void JSONParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}
void JSONParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JSONListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}
JSONParser::ValueContext* JSONParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 8, JSONParser::RuleValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(55);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JSONParser::STRING: {
        _localctx = _tracker.createInstance<JSONParser::StringContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(48);
        match(JSONParser::STRING);
        break;
      }

      case JSONParser::NUMBER: {
        _localctx = _tracker.createInstance<JSONParser::AtomContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(49);
        match(JSONParser::NUMBER);
        break;
      }

      case JSONParser::LCURLY: {
        _localctx = _tracker.createInstance<JSONParser::ObjectValueContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(50);
        object();
        break;
      }

      case JSONParser::LBRACK: {
        _localctx = _tracker.createInstance<JSONParser::ArrayValueContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(51);
        array();
        break;
      }

      case JSONParser::T__4: {
        _localctx = _tracker.createInstance<JSONParser::AtomContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(52);
        match(JSONParser::T__4);
        break;
      }

      case JSONParser::T__5: {
        _localctx = _tracker.createInstance<JSONParser::AtomContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(53);
        match(JSONParser::T__5);
        break;
      }

      case JSONParser::T__6: {
        _localctx = _tracker.createInstance<JSONParser::AtomContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(54);
        match(JSONParser::T__6);
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

void JSONParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  jsonParserInitialize();
#else
  ::antlr4::internal::call_once(jsonParserOnceFlag, jsonParserInitialize);
#endif
}
