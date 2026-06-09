
// Generated from PropertyFile.g4 by ANTLR 4.13.0


#include "PropertyFileListener.h"

#include "PropertyFileParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct PropertyFileParserStaticData final {
  PropertyFileParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PropertyFileParserStaticData(const PropertyFileParserStaticData&) = delete;
  PropertyFileParserStaticData(PropertyFileParserStaticData&&) = delete;
  PropertyFileParserStaticData& operator=(const PropertyFileParserStaticData&) = delete;
  PropertyFileParserStaticData& operator=(PropertyFileParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag propertyfileParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
PropertyFileParserStaticData *propertyfileParserStaticData = nullptr;

void propertyfileParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (propertyfileParserStaticData != nullptr) {
    return;
  }
#else
  assert(propertyfileParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<PropertyFileParserStaticData>(
    std::vector<std::string>{
      "file", "prop"
    },
    std::vector<std::string>{
      "", "'='", "'\\n'"
    },
    std::vector<std::string>{
      "", "", "", "ID", "STRING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,4,15,2,0,7,0,2,1,7,1,1,0,4,0,6,8,0,11,0,12,0,7,1,1,1,1,1,1,1,1,1,
  	1,1,1,0,0,2,0,2,0,0,13,0,5,1,0,0,0,2,9,1,0,0,0,4,6,3,2,1,0,5,4,1,0,0,
  	0,6,7,1,0,0,0,7,5,1,0,0,0,7,8,1,0,0,0,8,1,1,0,0,0,9,10,5,3,0,0,10,11,
  	5,1,0,0,11,12,5,4,0,0,12,13,5,2,0,0,13,3,1,0,0,0,1,7
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  propertyfileParserStaticData = staticData.release();
}

}

PropertyFileParser::PropertyFileParser(TokenStream *input) : PropertyFileParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

PropertyFileParser::PropertyFileParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  PropertyFileParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *propertyfileParserStaticData->atn, propertyfileParserStaticData->decisionToDFA, propertyfileParserStaticData->sharedContextCache, options);
}

PropertyFileParser::~PropertyFileParser() {
  delete _interpreter;
}

const atn::ATN& PropertyFileParser::getATN() const {
  return *propertyfileParserStaticData->atn;
}

std::string PropertyFileParser::getGrammarFileName() const {
  return "PropertyFile.g4";
}

const std::vector<std::string>& PropertyFileParser::getRuleNames() const {
  return propertyfileParserStaticData->ruleNames;
}

const dfa::Vocabulary& PropertyFileParser::getVocabulary() const {
  return propertyfileParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PropertyFileParser::getSerializedATN() const {
  return propertyfileParserStaticData->serializedATN;
}


//----------------- FileContext ------------------------------------------------------------------

PropertyFileParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PropertyFileParser::PropContext *> PropertyFileParser::FileContext::prop() {
  return getRuleContexts<PropertyFileParser::PropContext>();
}

PropertyFileParser::PropContext* PropertyFileParser::FileContext::prop(size_t i) {
  return getRuleContext<PropertyFileParser::PropContext>(i);
}


size_t PropertyFileParser::FileContext::getRuleIndex() const {
  return PropertyFileParser::RuleFile;
}

void PropertyFileParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PropertyFileListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void PropertyFileParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PropertyFileListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}

PropertyFileParser::FileContext* PropertyFileParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, PropertyFileParser::RuleFile);
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
    setState(5); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(4);
      prop();
      setState(7); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == PropertyFileParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropContext ------------------------------------------------------------------

PropertyFileParser::PropContext::PropContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PropertyFileParser::PropContext::ID() {
  return getToken(PropertyFileParser::ID, 0);
}

tree::TerminalNode* PropertyFileParser::PropContext::STRING() {
  return getToken(PropertyFileParser::STRING, 0);
}


size_t PropertyFileParser::PropContext::getRuleIndex() const {
  return PropertyFileParser::RuleProp;
}

void PropertyFileParser::PropContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PropertyFileListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProp(this);
}

void PropertyFileParser::PropContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PropertyFileListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProp(this);
}

PropertyFileParser::PropContext* PropertyFileParser::prop() {
  PropContext *_localctx = _tracker.createInstance<PropContext>(_ctx, getState());
  enterRule(_localctx, 2, PropertyFileParser::RuleProp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(9);
    match(PropertyFileParser::ID);
    setState(10);
    match(PropertyFileParser::T__0);
    setState(11);
    match(PropertyFileParser::STRING);
    setState(12);
    match(PropertyFileParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void PropertyFileParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  propertyfileParserInitialize();
#else
  ::antlr4::internal::call_once(propertyfileParserOnceFlag, propertyfileParserInitialize);
#endif
}
