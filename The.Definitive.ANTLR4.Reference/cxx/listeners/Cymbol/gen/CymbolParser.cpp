
// Generated from Cymbol.g4 by ANTLR 4.13.0


#include "CymbolListener.h"

#include "CymbolParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CymbolParserStaticData final {
  CymbolParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CymbolParserStaticData(const CymbolParserStaticData&) = delete;
  CymbolParserStaticData(CymbolParserStaticData&&) = delete;
  CymbolParserStaticData& operator=(const CymbolParserStaticData&) = delete;
  CymbolParserStaticData& operator=(CymbolParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag cymbolParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
CymbolParserStaticData *cymbolParserStaticData = nullptr;

void cymbolParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (cymbolParserStaticData != nullptr) {
    return;
  }
#else
  assert(cymbolParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CymbolParserStaticData>(
    std::vector<std::string>{
      "file", "varDecl", "type", "functionDecl", "formalParameters", "formalParameter", 
      "block", "stat", "expr", "exprList"
    },
    std::vector<std::string>{
      "", "'='", "';'", "'('", "')'", "','", "'{'", "'}'", "'if'", "'then'", 
      "'else'", "'return'", "'['", "']'", "'-'", "'!'", "'*'", "'+'", "'=='", 
      "'float'", "'int'", "'void'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "K_FLOAT", "K_INT", "K_VOID", "ID", "INT", "WS", "SL_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,25,137,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,1,0,1,0,4,0,23,8,0,11,0,12,0,24,1,1,1,1,1,1,1,1,
  	3,1,31,8,1,1,1,1,1,1,2,1,2,1,3,1,3,1,3,1,3,3,3,41,8,3,1,3,1,3,1,3,1,4,
  	1,4,1,4,5,4,49,8,4,10,4,12,4,52,9,4,1,5,1,5,1,5,1,6,1,6,5,6,59,8,6,10,
  	6,12,6,62,9,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,74,8,7,1,7,
  	1,7,3,7,78,8,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,89,8,7,1,8,1,8,
  	1,8,1,8,3,8,95,8,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,108,
  	8,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,5,8,124,8,
  	8,10,8,12,8,127,9,8,1,9,1,9,1,9,5,9,132,8,9,10,9,12,9,135,9,9,1,9,0,1,
  	16,10,0,2,4,6,8,10,12,14,16,18,0,2,1,0,19,21,2,0,14,14,17,17,150,0,22,
  	1,0,0,0,2,26,1,0,0,0,4,34,1,0,0,0,6,36,1,0,0,0,8,45,1,0,0,0,10,53,1,0,
  	0,0,12,56,1,0,0,0,14,88,1,0,0,0,16,107,1,0,0,0,18,128,1,0,0,0,20,23,3,
  	6,3,0,21,23,3,2,1,0,22,20,1,0,0,0,22,21,1,0,0,0,23,24,1,0,0,0,24,22,1,
  	0,0,0,24,25,1,0,0,0,25,1,1,0,0,0,26,27,3,4,2,0,27,30,5,22,0,0,28,29,5,
  	1,0,0,29,31,3,16,8,0,30,28,1,0,0,0,30,31,1,0,0,0,31,32,1,0,0,0,32,33,
  	5,2,0,0,33,3,1,0,0,0,34,35,7,0,0,0,35,5,1,0,0,0,36,37,3,4,2,0,37,38,5,
  	22,0,0,38,40,5,3,0,0,39,41,3,8,4,0,40,39,1,0,0,0,40,41,1,0,0,0,41,42,
  	1,0,0,0,42,43,5,4,0,0,43,44,3,12,6,0,44,7,1,0,0,0,45,50,3,10,5,0,46,47,
  	5,5,0,0,47,49,3,10,5,0,48,46,1,0,0,0,49,52,1,0,0,0,50,48,1,0,0,0,50,51,
  	1,0,0,0,51,9,1,0,0,0,52,50,1,0,0,0,53,54,3,4,2,0,54,55,5,22,0,0,55,11,
  	1,0,0,0,56,60,5,6,0,0,57,59,3,14,7,0,58,57,1,0,0,0,59,62,1,0,0,0,60,58,
  	1,0,0,0,60,61,1,0,0,0,61,63,1,0,0,0,62,60,1,0,0,0,63,64,5,7,0,0,64,13,
  	1,0,0,0,65,89,3,12,6,0,66,89,3,2,1,0,67,68,5,8,0,0,68,69,3,16,8,0,69,
  	70,5,9,0,0,70,73,3,14,7,0,71,72,5,10,0,0,72,74,3,14,7,0,73,71,1,0,0,0,
  	73,74,1,0,0,0,74,89,1,0,0,0,75,77,5,11,0,0,76,78,3,16,8,0,77,76,1,0,0,
  	0,77,78,1,0,0,0,78,79,1,0,0,0,79,89,5,2,0,0,80,81,3,16,8,0,81,82,5,1,
  	0,0,82,83,3,16,8,0,83,84,5,2,0,0,84,89,1,0,0,0,85,86,3,16,8,0,86,87,5,
  	2,0,0,87,89,1,0,0,0,88,65,1,0,0,0,88,66,1,0,0,0,88,67,1,0,0,0,88,75,1,
  	0,0,0,88,80,1,0,0,0,88,85,1,0,0,0,89,15,1,0,0,0,90,91,6,8,-1,0,91,92,
  	5,22,0,0,92,94,5,3,0,0,93,95,3,18,9,0,94,93,1,0,0,0,94,95,1,0,0,0,95,
  	96,1,0,0,0,96,108,5,4,0,0,97,98,5,14,0,0,98,108,3,16,8,8,99,100,5,15,
  	0,0,100,108,3,16,8,7,101,108,5,22,0,0,102,108,5,23,0,0,103,104,5,3,0,
  	0,104,105,3,16,8,0,105,106,5,4,0,0,106,108,1,0,0,0,107,90,1,0,0,0,107,
  	97,1,0,0,0,107,99,1,0,0,0,107,101,1,0,0,0,107,102,1,0,0,0,107,103,1,0,
  	0,0,108,125,1,0,0,0,109,110,10,6,0,0,110,111,5,16,0,0,111,124,3,16,8,
  	7,112,113,10,5,0,0,113,114,7,1,0,0,114,124,3,16,8,6,115,116,10,4,0,0,
  	116,117,5,18,0,0,117,124,3,16,8,5,118,119,10,9,0,0,119,120,5,12,0,0,120,
  	121,3,16,8,0,121,122,5,13,0,0,122,124,1,0,0,0,123,109,1,0,0,0,123,112,
  	1,0,0,0,123,115,1,0,0,0,123,118,1,0,0,0,124,127,1,0,0,0,125,123,1,0,0,
  	0,125,126,1,0,0,0,126,17,1,0,0,0,127,125,1,0,0,0,128,133,3,16,8,0,129,
  	130,5,5,0,0,130,132,3,16,8,0,131,129,1,0,0,0,132,135,1,0,0,0,133,131,
  	1,0,0,0,133,134,1,0,0,0,134,19,1,0,0,0,135,133,1,0,0,0,14,22,24,30,40,
  	50,60,73,77,88,94,107,123,125,133
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  cymbolParserStaticData = staticData.release();
}

}

CymbolParser::CymbolParser(TokenStream *input) : CymbolParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CymbolParser::CymbolParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CymbolParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *cymbolParserStaticData->atn, cymbolParserStaticData->decisionToDFA, cymbolParserStaticData->sharedContextCache, options);
}

CymbolParser::~CymbolParser() {
  delete _interpreter;
}

const atn::ATN& CymbolParser::getATN() const {
  return *cymbolParserStaticData->atn;
}

std::string CymbolParser::getGrammarFileName() const {
  return "Cymbol.g4";
}

const std::vector<std::string>& CymbolParser::getRuleNames() const {
  return cymbolParserStaticData->ruleNames;
}

const dfa::Vocabulary& CymbolParser::getVocabulary() const {
  return cymbolParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CymbolParser::getSerializedATN() const {
  return cymbolParserStaticData->serializedATN;
}


//----------------- FileContext ------------------------------------------------------------------

CymbolParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CymbolParser::FunctionDeclContext *> CymbolParser::FileContext::functionDecl() {
  return getRuleContexts<CymbolParser::FunctionDeclContext>();
}

CymbolParser::FunctionDeclContext* CymbolParser::FileContext::functionDecl(size_t i) {
  return getRuleContext<CymbolParser::FunctionDeclContext>(i);
}

std::vector<CymbolParser::VarDeclContext *> CymbolParser::FileContext::varDecl() {
  return getRuleContexts<CymbolParser::VarDeclContext>();
}

CymbolParser::VarDeclContext* CymbolParser::FileContext::varDecl(size_t i) {
  return getRuleContext<CymbolParser::VarDeclContext>(i);
}


size_t CymbolParser::FileContext::getRuleIndex() const {
  return CymbolParser::RuleFile;
}

void CymbolParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void CymbolParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}

CymbolParser::FileContext* CymbolParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, CymbolParser::RuleFile);
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
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(22);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(20);
        functionDecl();
        break;
      }

      case 2: {
        setState(21);
        varDecl();
        break;
      }

      default:
        break;
      }
      setState(24); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3670016) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

CymbolParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CymbolParser::TypeContext* CymbolParser::VarDeclContext::type() {
  return getRuleContext<CymbolParser::TypeContext>(0);
}

tree::TerminalNode* CymbolParser::VarDeclContext::ID() {
  return getToken(CymbolParser::ID, 0);
}

CymbolParser::ExprContext* CymbolParser::VarDeclContext::expr() {
  return getRuleContext<CymbolParser::ExprContext>(0);
}


size_t CymbolParser::VarDeclContext::getRuleIndex() const {
  return CymbolParser::RuleVarDecl;
}

void CymbolParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void CymbolParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}

CymbolParser::VarDeclContext* CymbolParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 2, CymbolParser::RuleVarDecl);
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
    setState(26);
    type();
    setState(27);
    match(CymbolParser::ID);
    setState(30);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CymbolParser::T__0) {
      setState(28);
      match(CymbolParser::T__0);
      setState(29);
      expr(0);
    }
    setState(32);
    match(CymbolParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

CymbolParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CymbolParser::TypeContext::K_FLOAT() {
  return getToken(CymbolParser::K_FLOAT, 0);
}

tree::TerminalNode* CymbolParser::TypeContext::K_INT() {
  return getToken(CymbolParser::K_INT, 0);
}

tree::TerminalNode* CymbolParser::TypeContext::K_VOID() {
  return getToken(CymbolParser::K_VOID, 0);
}


size_t CymbolParser::TypeContext::getRuleIndex() const {
  return CymbolParser::RuleType;
}

void CymbolParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void CymbolParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

CymbolParser::TypeContext* CymbolParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 4, CymbolParser::RuleType);
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
    setState(34);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3670016) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclContext ------------------------------------------------------------------

CymbolParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CymbolParser::TypeContext* CymbolParser::FunctionDeclContext::type() {
  return getRuleContext<CymbolParser::TypeContext>(0);
}

tree::TerminalNode* CymbolParser::FunctionDeclContext::ID() {
  return getToken(CymbolParser::ID, 0);
}

CymbolParser::BlockContext* CymbolParser::FunctionDeclContext::block() {
  return getRuleContext<CymbolParser::BlockContext>(0);
}

CymbolParser::FormalParametersContext* CymbolParser::FunctionDeclContext::formalParameters() {
  return getRuleContext<CymbolParser::FormalParametersContext>(0);
}


size_t CymbolParser::FunctionDeclContext::getRuleIndex() const {
  return CymbolParser::RuleFunctionDecl;
}

void CymbolParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void CymbolParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}

CymbolParser::FunctionDeclContext* CymbolParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, CymbolParser::RuleFunctionDecl);
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
    setState(36);
    type();
    setState(37);
    match(CymbolParser::ID);
    setState(38);
    match(CymbolParser::T__2);
    setState(40);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3670016) != 0)) {
      setState(39);
      formalParameters();
    }
    setState(42);
    match(CymbolParser::T__3);
    setState(43);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParametersContext ------------------------------------------------------------------

CymbolParser::FormalParametersContext::FormalParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CymbolParser::FormalParameterContext *> CymbolParser::FormalParametersContext::formalParameter() {
  return getRuleContexts<CymbolParser::FormalParameterContext>();
}

CymbolParser::FormalParameterContext* CymbolParser::FormalParametersContext::formalParameter(size_t i) {
  return getRuleContext<CymbolParser::FormalParameterContext>(i);
}


size_t CymbolParser::FormalParametersContext::getRuleIndex() const {
  return CymbolParser::RuleFormalParameters;
}

void CymbolParser::FormalParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormalParameters(this);
}

void CymbolParser::FormalParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormalParameters(this);
}

CymbolParser::FormalParametersContext* CymbolParser::formalParameters() {
  FormalParametersContext *_localctx = _tracker.createInstance<FormalParametersContext>(_ctx, getState());
  enterRule(_localctx, 8, CymbolParser::RuleFormalParameters);
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
    setState(45);
    formalParameter();
    setState(50);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CymbolParser::T__4) {
      setState(46);
      match(CymbolParser::T__4);
      setState(47);
      formalParameter();
      setState(52);
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

//----------------- FormalParameterContext ------------------------------------------------------------------

CymbolParser::FormalParameterContext::FormalParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CymbolParser::TypeContext* CymbolParser::FormalParameterContext::type() {
  return getRuleContext<CymbolParser::TypeContext>(0);
}

tree::TerminalNode* CymbolParser::FormalParameterContext::ID() {
  return getToken(CymbolParser::ID, 0);
}


size_t CymbolParser::FormalParameterContext::getRuleIndex() const {
  return CymbolParser::RuleFormalParameter;
}

void CymbolParser::FormalParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormalParameter(this);
}

void CymbolParser::FormalParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormalParameter(this);
}

CymbolParser::FormalParameterContext* CymbolParser::formalParameter() {
  FormalParameterContext *_localctx = _tracker.createInstance<FormalParameterContext>(_ctx, getState());
  enterRule(_localctx, 10, CymbolParser::RuleFormalParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    type();
    setState(54);
    match(CymbolParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

CymbolParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CymbolParser::StatContext *> CymbolParser::BlockContext::stat() {
  return getRuleContexts<CymbolParser::StatContext>();
}

CymbolParser::StatContext* CymbolParser::BlockContext::stat(size_t i) {
  return getRuleContext<CymbolParser::StatContext>(i);
}


size_t CymbolParser::BlockContext::getRuleIndex() const {
  return CymbolParser::RuleBlock;
}

void CymbolParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void CymbolParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

CymbolParser::BlockContext* CymbolParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 12, CymbolParser::RuleBlock);
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
    setState(56);
    match(CymbolParser::T__5);
    setState(60);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16304456) != 0)) {
      setState(57);
      stat();
      setState(62);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(63);
    match(CymbolParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatContext ------------------------------------------------------------------

CymbolParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CymbolParser::BlockContext* CymbolParser::StatContext::block() {
  return getRuleContext<CymbolParser::BlockContext>(0);
}

CymbolParser::VarDeclContext* CymbolParser::StatContext::varDecl() {
  return getRuleContext<CymbolParser::VarDeclContext>(0);
}

std::vector<CymbolParser::ExprContext *> CymbolParser::StatContext::expr() {
  return getRuleContexts<CymbolParser::ExprContext>();
}

CymbolParser::ExprContext* CymbolParser::StatContext::expr(size_t i) {
  return getRuleContext<CymbolParser::ExprContext>(i);
}

std::vector<CymbolParser::StatContext *> CymbolParser::StatContext::stat() {
  return getRuleContexts<CymbolParser::StatContext>();
}

CymbolParser::StatContext* CymbolParser::StatContext::stat(size_t i) {
  return getRuleContext<CymbolParser::StatContext>(i);
}


size_t CymbolParser::StatContext::getRuleIndex() const {
  return CymbolParser::RuleStat;
}

void CymbolParser::StatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStat(this);
}

void CymbolParser::StatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStat(this);
}

CymbolParser::StatContext* CymbolParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 14, CymbolParser::RuleStat);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(88);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(65);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(66);
      varDecl();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(67);
      match(CymbolParser::T__7);
      setState(68);
      expr(0);
      setState(69);
      match(CymbolParser::T__8);
      setState(70);
      stat();
      setState(73);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
      case 1: {
        setState(71);
        match(CymbolParser::T__9);
        setState(72);
        stat();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(75);
      match(CymbolParser::T__10);
      setState(77);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 12632072) != 0)) {
        setState(76);
        expr(0);
      }
      setState(79);
      match(CymbolParser::T__1);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(80);
      expr(0);
      setState(81);
      match(CymbolParser::T__0);
      setState(82);
      expr(0);
      setState(83);
      match(CymbolParser::T__1);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(85);
      expr(0);
      setState(86);
      match(CymbolParser::T__1);
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

//----------------- ExprContext ------------------------------------------------------------------

CymbolParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CymbolParser::ExprContext::getRuleIndex() const {
  return CymbolParser::RuleExpr;
}

void CymbolParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CallContext ------------------------------------------------------------------

tree::TerminalNode* CymbolParser::CallContext::ID() {
  return getToken(CymbolParser::ID, 0);
}

CymbolParser::ExprListContext* CymbolParser::CallContext::exprList() {
  return getRuleContext<CymbolParser::ExprListContext>(0);
}

CymbolParser::CallContext::CallContext(ExprContext *ctx) { copyFrom(ctx); }

void CymbolParser::CallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall(this);
}
void CymbolParser::CallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall(this);
}
//----------------- NotContext ------------------------------------------------------------------

CymbolParser::ExprContext* CymbolParser::NotContext::expr() {
  return getRuleContext<CymbolParser::ExprContext>(0);
}

CymbolParser::NotContext::NotContext(ExprContext *ctx) { copyFrom(ctx); }

void CymbolParser::NotContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNot(this);
}
void CymbolParser::NotContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNot(this);
}
//----------------- MultContext ------------------------------------------------------------------

std::vector<CymbolParser::ExprContext *> CymbolParser::MultContext::expr() {
  return getRuleContexts<CymbolParser::ExprContext>();
}

CymbolParser::ExprContext* CymbolParser::MultContext::expr(size_t i) {
  return getRuleContext<CymbolParser::ExprContext>(i);
}

CymbolParser::MultContext::MultContext(ExprContext *ctx) { copyFrom(ctx); }

void CymbolParser::MultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMult(this);
}
void CymbolParser::MultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMult(this);
}
//----------------- AddSubContext ------------------------------------------------------------------

std::vector<CymbolParser::ExprContext *> CymbolParser::AddSubContext::expr() {
  return getRuleContexts<CymbolParser::ExprContext>();
}

CymbolParser::ExprContext* CymbolParser::AddSubContext::expr(size_t i) {
  return getRuleContext<CymbolParser::ExprContext>(i);
}

CymbolParser::AddSubContext::AddSubContext(ExprContext *ctx) { copyFrom(ctx); }

void CymbolParser::AddSubContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddSub(this);
}
void CymbolParser::AddSubContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddSub(this);
}
//----------------- EqualContext ------------------------------------------------------------------

std::vector<CymbolParser::ExprContext *> CymbolParser::EqualContext::expr() {
  return getRuleContexts<CymbolParser::ExprContext>();
}

CymbolParser::ExprContext* CymbolParser::EqualContext::expr(size_t i) {
  return getRuleContext<CymbolParser::ExprContext>(i);
}

CymbolParser::EqualContext::EqualContext(ExprContext *ctx) { copyFrom(ctx); }

void CymbolParser::EqualContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqual(this);
}
void CymbolParser::EqualContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqual(this);
}
//----------------- VarContext ------------------------------------------------------------------

tree::TerminalNode* CymbolParser::VarContext::ID() {
  return getToken(CymbolParser::ID, 0);
}

CymbolParser::VarContext::VarContext(ExprContext *ctx) { copyFrom(ctx); }

void CymbolParser::VarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar(this);
}
void CymbolParser::VarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar(this);
}
//----------------- ParensContext ------------------------------------------------------------------

CymbolParser::ExprContext* CymbolParser::ParensContext::expr() {
  return getRuleContext<CymbolParser::ExprContext>(0);
}

CymbolParser::ParensContext::ParensContext(ExprContext *ctx) { copyFrom(ctx); }

void CymbolParser::ParensContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParens(this);
}
void CymbolParser::ParensContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParens(this);
}
//----------------- IndexContext ------------------------------------------------------------------

std::vector<CymbolParser::ExprContext *> CymbolParser::IndexContext::expr() {
  return getRuleContexts<CymbolParser::ExprContext>();
}

CymbolParser::ExprContext* CymbolParser::IndexContext::expr(size_t i) {
  return getRuleContext<CymbolParser::ExprContext>(i);
}

CymbolParser::IndexContext::IndexContext(ExprContext *ctx) { copyFrom(ctx); }

void CymbolParser::IndexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndex(this);
}
void CymbolParser::IndexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndex(this);
}
//----------------- NegateContext ------------------------------------------------------------------

CymbolParser::ExprContext* CymbolParser::NegateContext::expr() {
  return getRuleContext<CymbolParser::ExprContext>(0);
}

CymbolParser::NegateContext::NegateContext(ExprContext *ctx) { copyFrom(ctx); }

void CymbolParser::NegateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNegate(this);
}
void CymbolParser::NegateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNegate(this);
}
//----------------- IntContext ------------------------------------------------------------------

tree::TerminalNode* CymbolParser::IntContext::INT() {
  return getToken(CymbolParser::INT, 0);
}

CymbolParser::IntContext::IntContext(ExprContext *ctx) { copyFrom(ctx); }

void CymbolParser::IntContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInt(this);
}
void CymbolParser::IntContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInt(this);
}

CymbolParser::ExprContext* CymbolParser::expr() {
   return expr(0);
}

CymbolParser::ExprContext* CymbolParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CymbolParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  CymbolParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 16;
  enterRecursionRule(_localctx, 16, CymbolParser::RuleExpr, precedence);

    size_t _la = 0;

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
    setState(107);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(91);
      match(CymbolParser::ID);
      setState(92);
      match(CymbolParser::T__2);
      setState(94);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 12632072) != 0)) {
        setState(93);
        exprList();
      }
      setState(96);
      match(CymbolParser::T__3);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<NegateContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(97);
      match(CymbolParser::T__13);
      setState(98);
      expr(8);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<NotContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(99);
      match(CymbolParser::T__14);
      setState(100);
      expr(7);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<VarContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(101);
      match(CymbolParser::ID);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<IntContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(102);
      match(CymbolParser::INT);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ParensContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(103);
      match(CymbolParser::T__2);
      setState(104);
      expr(0);
      setState(105);
      match(CymbolParser::T__3);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(125);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(123);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(109);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(110);
          match(CymbolParser::T__15);
          setState(111);
          expr(7);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(112);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(113);
          _la = _input->LA(1);
          if (!(_la == CymbolParser::T__13

          || _la == CymbolParser::T__16)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(114);
          expr(6);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<EqualContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(115);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(116);
          match(CymbolParser::T__17);
          setState(117);
          expr(5);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<IndexContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(118);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(119);
          match(CymbolParser::T__11);
          setState(120);
          expr(0);
          setState(121);
          match(CymbolParser::T__12);
          break;
        }

        default:
          break;
        } 
      }
      setState(127);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExprListContext ------------------------------------------------------------------

CymbolParser::ExprListContext::ExprListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CymbolParser::ExprContext *> CymbolParser::ExprListContext::expr() {
  return getRuleContexts<CymbolParser::ExprContext>();
}

CymbolParser::ExprContext* CymbolParser::ExprListContext::expr(size_t i) {
  return getRuleContext<CymbolParser::ExprContext>(i);
}


size_t CymbolParser::ExprListContext::getRuleIndex() const {
  return CymbolParser::RuleExprList;
}

void CymbolParser::ExprListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprList(this);
}

void CymbolParser::ExprListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprList(this);
}

CymbolParser::ExprListContext* CymbolParser::exprList() {
  ExprListContext *_localctx = _tracker.createInstance<ExprListContext>(_ctx, getState());
  enterRule(_localctx, 18, CymbolParser::RuleExprList);
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
    setState(128);
    expr(0);
    setState(133);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CymbolParser::T__4) {
      setState(129);
      match(CymbolParser::T__4);
      setState(130);
      expr(0);
      setState(135);
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

bool CymbolParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 8: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CymbolParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);
    case 3: return precpred(_ctx, 9);

  default:
    break;
  }
  return true;
}

void CymbolParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  cymbolParserInitialize();
#else
  ::antlr4::internal::call_once(cymbolParserOnceFlag, cymbolParserInitialize);
#endif
}
