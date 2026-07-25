
// Generated from Cymbol.g4 by ANTLR 4.13.0


#include "CymbolListener.h"
#include "CymbolVisitor.h"

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
      "compilationUnit", "type", "varDeclaration", "expression", "primary"
    },
    std::vector<std::string>{
      "", "'float'", "'int'", "'='", "';'", "'+'", "'('", "')'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "ID", "INT", "WS", "SL_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,11,42,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,1,0,4,0,12,8,0,11,0,
  	12,0,13,1,1,1,1,1,2,1,2,1,2,1,2,3,2,22,8,2,1,2,1,2,1,3,1,3,1,3,5,3,29,
  	8,3,10,3,12,3,32,9,3,1,4,1,4,1,4,1,4,1,4,1,4,3,4,40,8,4,1,4,0,0,5,0,2,
  	4,6,8,0,1,1,0,1,2,41,0,11,1,0,0,0,2,15,1,0,0,0,4,17,1,0,0,0,6,25,1,0,
  	0,0,8,39,1,0,0,0,10,12,3,4,2,0,11,10,1,0,0,0,12,13,1,0,0,0,13,11,1,0,
  	0,0,13,14,1,0,0,0,14,1,1,0,0,0,15,16,7,0,0,0,16,3,1,0,0,0,17,18,3,2,1,
  	0,18,21,5,8,0,0,19,20,5,3,0,0,20,22,3,6,3,0,21,19,1,0,0,0,21,22,1,0,0,
  	0,22,23,1,0,0,0,23,24,5,4,0,0,24,5,1,0,0,0,25,30,3,8,4,0,26,27,5,5,0,
  	0,27,29,3,8,4,0,28,26,1,0,0,0,29,32,1,0,0,0,30,28,1,0,0,0,30,31,1,0,0,
  	0,31,7,1,0,0,0,32,30,1,0,0,0,33,40,5,8,0,0,34,40,5,9,0,0,35,36,5,6,0,
  	0,36,37,3,6,3,0,37,38,5,7,0,0,38,40,1,0,0,0,39,33,1,0,0,0,39,34,1,0,0,
  	0,39,35,1,0,0,0,40,9,1,0,0,0,4,13,21,30,39
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


//----------------- CompilationUnitContext ------------------------------------------------------------------

CymbolParser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CymbolParser::VarDeclarationContext *> CymbolParser::CompilationUnitContext::varDeclaration() {
  return getRuleContexts<CymbolParser::VarDeclarationContext>();
}

CymbolParser::VarDeclarationContext* CymbolParser::CompilationUnitContext::varDeclaration(size_t i) {
  return getRuleContext<CymbolParser::VarDeclarationContext>(i);
}


size_t CymbolParser::CompilationUnitContext::getRuleIndex() const {
  return CymbolParser::RuleCompilationUnit;
}

void CymbolParser::CompilationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompilationUnit(this);
}

void CymbolParser::CompilationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompilationUnit(this);
}


std::any CymbolParser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitCompilationUnit(this);
  else
    return visitor->visitChildren(this);
}

CymbolParser::CompilationUnitContext* CymbolParser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, CymbolParser::RuleCompilationUnit);
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
      varDeclaration();
      setState(13); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CymbolParser::T__0

    || _la == CymbolParser::T__1);
   
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


std::any CymbolParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

CymbolParser::TypeContext* CymbolParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 2, CymbolParser::RuleType);
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
    setState(15);
    _la = _input->LA(1);
    if (!(_la == CymbolParser::T__0

    || _la == CymbolParser::T__1)) {
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

//----------------- VarDeclarationContext ------------------------------------------------------------------

CymbolParser::VarDeclarationContext::VarDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CymbolParser::TypeContext* CymbolParser::VarDeclarationContext::type() {
  return getRuleContext<CymbolParser::TypeContext>(0);
}

tree::TerminalNode* CymbolParser::VarDeclarationContext::ID() {
  return getToken(CymbolParser::ID, 0);
}

CymbolParser::ExpressionContext* CymbolParser::VarDeclarationContext::expression() {
  return getRuleContext<CymbolParser::ExpressionContext>(0);
}


size_t CymbolParser::VarDeclarationContext::getRuleIndex() const {
  return CymbolParser::RuleVarDeclaration;
}

void CymbolParser::VarDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDeclaration(this);
}

void CymbolParser::VarDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDeclaration(this);
}


std::any CymbolParser::VarDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitVarDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CymbolParser::VarDeclarationContext* CymbolParser::varDeclaration() {
  VarDeclarationContext *_localctx = _tracker.createInstance<VarDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, CymbolParser::RuleVarDeclaration);
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
    setState(17);
    type();
    setState(18);
    match(CymbolParser::ID);
    setState(21);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CymbolParser::T__2) {
      setState(19);
      match(CymbolParser::T__2);
      setState(20);
      expression();
    }
    setState(23);
    match(CymbolParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

CymbolParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CymbolParser::PrimaryContext *> CymbolParser::ExpressionContext::primary() {
  return getRuleContexts<CymbolParser::PrimaryContext>();
}

CymbolParser::PrimaryContext* CymbolParser::ExpressionContext::primary(size_t i) {
  return getRuleContext<CymbolParser::PrimaryContext>(i);
}


size_t CymbolParser::ExpressionContext::getRuleIndex() const {
  return CymbolParser::RuleExpression;
}

void CymbolParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void CymbolParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


std::any CymbolParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

CymbolParser::ExpressionContext* CymbolParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 6, CymbolParser::RuleExpression);
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
    setState(25);
    primary();
    setState(30);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CymbolParser::T__4) {
      setState(26);
      match(CymbolParser::T__4);
      setState(27);
      primary();
      setState(32);
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

CymbolParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CymbolParser::PrimaryContext::ID() {
  return getToken(CymbolParser::ID, 0);
}

tree::TerminalNode* CymbolParser::PrimaryContext::INT() {
  return getToken(CymbolParser::INT, 0);
}

CymbolParser::ExpressionContext* CymbolParser::PrimaryContext::expression() {
  return getRuleContext<CymbolParser::ExpressionContext>(0);
}


size_t CymbolParser::PrimaryContext::getRuleIndex() const {
  return CymbolParser::RulePrimary;
}

void CymbolParser::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}

void CymbolParser::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}


std::any CymbolParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

CymbolParser::PrimaryContext* CymbolParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 8, CymbolParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(39);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CymbolParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(33);
        match(CymbolParser::ID);
        break;
      }

      case CymbolParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(34);
        match(CymbolParser::INT);
        break;
      }

      case CymbolParser::T__5: {
        enterOuterAlt(_localctx, 3);
        setState(35);
        match(CymbolParser::T__5);
        setState(36);
        expression();
        setState(37);
        match(CymbolParser::T__6);
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

void CymbolParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  cymbolParserInitialize();
#else
  ::antlr4::internal::call_once(cymbolParserOnceFlag, cymbolParserInitialize);
#endif
}
