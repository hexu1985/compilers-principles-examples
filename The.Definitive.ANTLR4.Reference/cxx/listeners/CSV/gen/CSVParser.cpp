
// Generated from CSV.g4 by ANTLR 4.13.0


#include "CSVListener.h"
#include "CSVVisitor.h"

#include "CSVParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CSVParserStaticData final {
  CSVParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CSVParserStaticData(const CSVParserStaticData&) = delete;
  CSVParserStaticData(CSVParserStaticData&&) = delete;
  CSVParserStaticData& operator=(const CSVParserStaticData&) = delete;
  CSVParserStaticData& operator=(CSVParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag csvParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
CSVParserStaticData *csvParserStaticData = nullptr;

void csvParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (csvParserStaticData != nullptr) {
    return;
  }
#else
  assert(csvParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CSVParserStaticData>(
    std::vector<std::string>{
      "file", "hdr", "row", "field"
    },
    std::vector<std::string>{
      "", "','", "'\\r'", "'\\n'"
    },
    std::vector<std::string>{
      "", "", "", "", "TEXT", "STRING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,5,35,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,1,0,4,0,11,8,0,11,0,12,0,
  	12,1,1,1,1,1,2,1,2,1,2,5,2,20,8,2,10,2,12,2,23,9,2,1,2,3,2,26,8,2,1,2,
  	1,2,1,3,1,3,1,3,3,3,33,8,3,1,3,0,0,4,0,2,4,6,0,0,35,0,8,1,0,0,0,2,14,
  	1,0,0,0,4,16,1,0,0,0,6,32,1,0,0,0,8,10,3,2,1,0,9,11,3,4,2,0,10,9,1,0,
  	0,0,11,12,1,0,0,0,12,10,1,0,0,0,12,13,1,0,0,0,13,1,1,0,0,0,14,15,3,4,
  	2,0,15,3,1,0,0,0,16,21,3,6,3,0,17,18,5,1,0,0,18,20,3,6,3,0,19,17,1,0,
  	0,0,20,23,1,0,0,0,21,19,1,0,0,0,21,22,1,0,0,0,22,25,1,0,0,0,23,21,1,0,
  	0,0,24,26,5,2,0,0,25,24,1,0,0,0,25,26,1,0,0,0,26,27,1,0,0,0,27,28,5,3,
  	0,0,28,5,1,0,0,0,29,33,5,4,0,0,30,33,5,5,0,0,31,33,1,0,0,0,32,29,1,0,
  	0,0,32,30,1,0,0,0,32,31,1,0,0,0,33,7,1,0,0,0,4,12,21,25,32
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  csvParserStaticData = staticData.release();
}

}

CSVParser::CSVParser(TokenStream *input) : CSVParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CSVParser::CSVParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CSVParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *csvParserStaticData->atn, csvParserStaticData->decisionToDFA, csvParserStaticData->sharedContextCache, options);
}

CSVParser::~CSVParser() {
  delete _interpreter;
}

const atn::ATN& CSVParser::getATN() const {
  return *csvParserStaticData->atn;
}

std::string CSVParser::getGrammarFileName() const {
  return "CSV.g4";
}

const std::vector<std::string>& CSVParser::getRuleNames() const {
  return csvParserStaticData->ruleNames;
}

const dfa::Vocabulary& CSVParser::getVocabulary() const {
  return csvParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CSVParser::getSerializedATN() const {
  return csvParserStaticData->serializedATN;
}


//----------------- FileContext ------------------------------------------------------------------

CSVParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSVParser::HdrContext* CSVParser::FileContext::hdr() {
  return getRuleContext<CSVParser::HdrContext>(0);
}

std::vector<CSVParser::RowContext *> CSVParser::FileContext::row() {
  return getRuleContexts<CSVParser::RowContext>();
}

CSVParser::RowContext* CSVParser::FileContext::row(size_t i) {
  return getRuleContext<CSVParser::RowContext>(i);
}


size_t CSVParser::FileContext::getRuleIndex() const {
  return CSVParser::RuleFile;
}

void CSVParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSVListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void CSVParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSVListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}


std::any CSVParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSVVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

CSVParser::FileContext* CSVParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, CSVParser::RuleFile);
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
    setState(8);
    hdr();
    setState(10); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(9);
      row();
      setState(12); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 62) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HdrContext ------------------------------------------------------------------

CSVParser::HdrContext::HdrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSVParser::RowContext* CSVParser::HdrContext::row() {
  return getRuleContext<CSVParser::RowContext>(0);
}


size_t CSVParser::HdrContext::getRuleIndex() const {
  return CSVParser::RuleHdr;
}

void CSVParser::HdrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSVListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHdr(this);
}

void CSVParser::HdrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSVListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHdr(this);
}


std::any CSVParser::HdrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSVVisitor*>(visitor))
    return parserVisitor->visitHdr(this);
  else
    return visitor->visitChildren(this);
}

CSVParser::HdrContext* CSVParser::hdr() {
  HdrContext *_localctx = _tracker.createInstance<HdrContext>(_ctx, getState());
  enterRule(_localctx, 2, CSVParser::RuleHdr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(14);
    row();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RowContext ------------------------------------------------------------------

CSVParser::RowContext::RowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CSVParser::FieldContext *> CSVParser::RowContext::field() {
  return getRuleContexts<CSVParser::FieldContext>();
}

CSVParser::FieldContext* CSVParser::RowContext::field(size_t i) {
  return getRuleContext<CSVParser::FieldContext>(i);
}


size_t CSVParser::RowContext::getRuleIndex() const {
  return CSVParser::RuleRow;
}

void CSVParser::RowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSVListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRow(this);
}

void CSVParser::RowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSVListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRow(this);
}


std::any CSVParser::RowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSVVisitor*>(visitor))
    return parserVisitor->visitRow(this);
  else
    return visitor->visitChildren(this);
}

CSVParser::RowContext* CSVParser::row() {
  RowContext *_localctx = _tracker.createInstance<RowContext>(_ctx, getState());
  enterRule(_localctx, 4, CSVParser::RuleRow);
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
    setState(16);
    field();
    setState(21);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CSVParser::T__0) {
      setState(17);
      match(CSVParser::T__0);
      setState(18);
      field();
      setState(23);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(25);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CSVParser::T__1) {
      setState(24);
      match(CSVParser::T__1);
    }
    setState(27);
    match(CSVParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldContext ------------------------------------------------------------------

CSVParser::FieldContext::FieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSVParser::FieldContext::getRuleIndex() const {
  return CSVParser::RuleField;
}

void CSVParser::FieldContext::copyFrom(FieldContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StringContext ------------------------------------------------------------------

tree::TerminalNode* CSVParser::StringContext::STRING() {
  return getToken(CSVParser::STRING, 0);
}

CSVParser::StringContext::StringContext(FieldContext *ctx) { copyFrom(ctx); }

void CSVParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSVListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}
void CSVParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSVListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}

std::any CSVParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSVVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TextContext ------------------------------------------------------------------

tree::TerminalNode* CSVParser::TextContext::TEXT() {
  return getToken(CSVParser::TEXT, 0);
}

CSVParser::TextContext::TextContext(FieldContext *ctx) { copyFrom(ctx); }

void CSVParser::TextContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSVListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterText(this);
}
void CSVParser::TextContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSVListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitText(this);
}

std::any CSVParser::TextContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSVVisitor*>(visitor))
    return parserVisitor->visitText(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EmptyContext ------------------------------------------------------------------

CSVParser::EmptyContext::EmptyContext(FieldContext *ctx) { copyFrom(ctx); }

void CSVParser::EmptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSVListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmpty(this);
}
void CSVParser::EmptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CSVListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmpty(this);
}

std::any CSVParser::EmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSVVisitor*>(visitor))
    return parserVisitor->visitEmpty(this);
  else
    return visitor->visitChildren(this);
}
CSVParser::FieldContext* CSVParser::field() {
  FieldContext *_localctx = _tracker.createInstance<FieldContext>(_ctx, getState());
  enterRule(_localctx, 6, CSVParser::RuleField);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(32);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSVParser::TEXT: {
        _localctx = _tracker.createInstance<CSVParser::TextContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(29);
        match(CSVParser::TEXT);
        break;
      }

      case CSVParser::STRING: {
        _localctx = _tracker.createInstance<CSVParser::StringContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(30);
        match(CSVParser::STRING);
        break;
      }

      case CSVParser::T__0:
      case CSVParser::T__1:
      case CSVParser::T__2: {
        _localctx = _tracker.createInstance<CSVParser::EmptyContext>(_localctx);
        enterOuterAlt(_localctx, 3);

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

void CSVParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  csvParserInitialize();
#else
  ::antlr4::internal::call_once(csvParserOnceFlag, csvParserInitialize);
#endif
}
