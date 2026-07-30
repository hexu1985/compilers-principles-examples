
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
      "compilationUnit", "methodDeclaration", "formalParameters", "type", 
      "block", "varDeclaration", "statement", "expressionList", "expression", 
      "addExpression", "postfixExpression", "primary"
    },
    std::vector<std::string>{
      "", "'('", "')'", "','", "'float'", "'int'", "'void'", "'{'", "'}'", 
      "'='", "';'", "'return'", "'+'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "ID", "INT", "WS", 
      "SL_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,16,126,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,4,0,27,8,0,11,0,12,
  	0,28,1,1,1,1,1,1,1,1,3,1,35,8,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,5,
  	2,46,8,2,10,2,12,2,49,9,2,1,3,1,3,1,4,1,4,5,4,55,8,4,10,4,12,4,58,9,4,
  	1,4,1,4,1,5,1,5,1,5,1,5,3,5,66,8,5,1,5,1,5,1,6,1,6,1,6,1,6,3,6,74,8,6,
  	1,6,1,6,1,6,1,6,1,6,3,6,81,8,6,1,6,1,6,3,6,85,8,6,1,7,1,7,1,7,5,7,90,
  	8,7,10,7,12,7,93,9,7,1,7,3,7,96,8,7,1,8,1,8,1,9,1,9,1,9,5,9,103,8,9,10,
  	9,12,9,106,9,9,1,10,1,10,1,10,1,10,1,10,5,10,113,8,10,10,10,12,10,116,
  	9,10,1,11,1,11,1,11,1,11,1,11,1,11,3,11,124,8,11,1,11,0,0,12,0,2,4,6,
  	8,10,12,14,16,18,20,22,0,1,1,0,4,6,130,0,26,1,0,0,0,2,30,1,0,0,0,4,39,
  	1,0,0,0,6,50,1,0,0,0,8,52,1,0,0,0,10,61,1,0,0,0,12,84,1,0,0,0,14,95,1,
  	0,0,0,16,97,1,0,0,0,18,99,1,0,0,0,20,107,1,0,0,0,22,123,1,0,0,0,24,27,
  	3,2,1,0,25,27,3,10,5,0,26,24,1,0,0,0,26,25,1,0,0,0,27,28,1,0,0,0,28,26,
  	1,0,0,0,28,29,1,0,0,0,29,1,1,0,0,0,30,31,3,6,3,0,31,32,5,13,0,0,32,34,
  	5,1,0,0,33,35,3,4,2,0,34,33,1,0,0,0,34,35,1,0,0,0,35,36,1,0,0,0,36,37,
  	5,2,0,0,37,38,3,8,4,0,38,3,1,0,0,0,39,40,3,6,3,0,40,47,5,13,0,0,41,42,
  	5,3,0,0,42,43,3,6,3,0,43,44,5,13,0,0,44,46,1,0,0,0,45,41,1,0,0,0,46,49,
  	1,0,0,0,47,45,1,0,0,0,47,48,1,0,0,0,48,5,1,0,0,0,49,47,1,0,0,0,50,51,
  	7,0,0,0,51,7,1,0,0,0,52,56,5,7,0,0,53,55,3,12,6,0,54,53,1,0,0,0,55,58,
  	1,0,0,0,56,54,1,0,0,0,56,57,1,0,0,0,57,59,1,0,0,0,58,56,1,0,0,0,59,60,
  	5,8,0,0,60,9,1,0,0,0,61,62,3,6,3,0,62,65,5,13,0,0,63,64,5,9,0,0,64,66,
  	3,16,8,0,65,63,1,0,0,0,65,66,1,0,0,0,66,67,1,0,0,0,67,68,5,10,0,0,68,
  	11,1,0,0,0,69,85,3,8,4,0,70,85,3,10,5,0,71,73,5,11,0,0,72,74,3,16,8,0,
  	73,72,1,0,0,0,73,74,1,0,0,0,74,75,1,0,0,0,75,85,5,10,0,0,76,80,3,20,10,
  	0,77,78,5,9,0,0,78,81,3,16,8,0,79,81,1,0,0,0,80,77,1,0,0,0,80,79,1,0,
  	0,0,81,82,1,0,0,0,82,83,5,10,0,0,83,85,1,0,0,0,84,69,1,0,0,0,84,70,1,
  	0,0,0,84,71,1,0,0,0,84,76,1,0,0,0,85,13,1,0,0,0,86,91,3,16,8,0,87,88,
  	5,3,0,0,88,90,3,16,8,0,89,87,1,0,0,0,90,93,1,0,0,0,91,89,1,0,0,0,91,92,
  	1,0,0,0,92,96,1,0,0,0,93,91,1,0,0,0,94,96,1,0,0,0,95,86,1,0,0,0,95,94,
  	1,0,0,0,96,15,1,0,0,0,97,98,3,18,9,0,98,17,1,0,0,0,99,104,3,20,10,0,100,
  	101,5,12,0,0,101,103,3,20,10,0,102,100,1,0,0,0,103,106,1,0,0,0,104,102,
  	1,0,0,0,104,105,1,0,0,0,105,19,1,0,0,0,106,104,1,0,0,0,107,114,3,22,11,
  	0,108,109,5,1,0,0,109,110,3,14,7,0,110,111,5,2,0,0,111,113,1,0,0,0,112,
  	108,1,0,0,0,113,116,1,0,0,0,114,112,1,0,0,0,114,115,1,0,0,0,115,21,1,
  	0,0,0,116,114,1,0,0,0,117,124,5,13,0,0,118,124,5,14,0,0,119,120,5,1,0,
  	0,120,121,3,16,8,0,121,122,5,2,0,0,122,124,1,0,0,0,123,117,1,0,0,0,123,
  	118,1,0,0,0,123,119,1,0,0,0,124,23,1,0,0,0,14,26,28,34,47,56,65,73,80,
  	84,91,95,104,114,123
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

std::vector<CymbolParser::MethodDeclarationContext *> CymbolParser::CompilationUnitContext::methodDeclaration() {
  return getRuleContexts<CymbolParser::MethodDeclarationContext>();
}

CymbolParser::MethodDeclarationContext* CymbolParser::CompilationUnitContext::methodDeclaration(size_t i) {
  return getRuleContext<CymbolParser::MethodDeclarationContext>(i);
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
    setState(26); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(26);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(24);
        methodDeclaration();
        break;
      }

      case 2: {
        setState(25);
        varDeclaration();
        break;
      }

      default:
        break;
      }
      setState(28); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 112) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodDeclarationContext ------------------------------------------------------------------

CymbolParser::MethodDeclarationContext::MethodDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CymbolParser::TypeContext* CymbolParser::MethodDeclarationContext::type() {
  return getRuleContext<CymbolParser::TypeContext>(0);
}

tree::TerminalNode* CymbolParser::MethodDeclarationContext::ID() {
  return getToken(CymbolParser::ID, 0);
}

CymbolParser::BlockContext* CymbolParser::MethodDeclarationContext::block() {
  return getRuleContext<CymbolParser::BlockContext>(0);
}

CymbolParser::FormalParametersContext* CymbolParser::MethodDeclarationContext::formalParameters() {
  return getRuleContext<CymbolParser::FormalParametersContext>(0);
}


size_t CymbolParser::MethodDeclarationContext::getRuleIndex() const {
  return CymbolParser::RuleMethodDeclaration;
}

void CymbolParser::MethodDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodDeclaration(this);
}

void CymbolParser::MethodDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodDeclaration(this);
}


std::any CymbolParser::MethodDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitMethodDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CymbolParser::MethodDeclarationContext* CymbolParser::methodDeclaration() {
  MethodDeclarationContext *_localctx = _tracker.createInstance<MethodDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, CymbolParser::RuleMethodDeclaration);
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
    type();
    setState(31);
    match(CymbolParser::ID);
    setState(32);
    match(CymbolParser::T__0);
    setState(34);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 112) != 0)) {
      setState(33);
      formalParameters();
    }
    setState(36);
    match(CymbolParser::T__1);
    setState(37);
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

std::vector<CymbolParser::TypeContext *> CymbolParser::FormalParametersContext::type() {
  return getRuleContexts<CymbolParser::TypeContext>();
}

CymbolParser::TypeContext* CymbolParser::FormalParametersContext::type(size_t i) {
  return getRuleContext<CymbolParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> CymbolParser::FormalParametersContext::ID() {
  return getTokens(CymbolParser::ID);
}

tree::TerminalNode* CymbolParser::FormalParametersContext::ID(size_t i) {
  return getToken(CymbolParser::ID, i);
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


std::any CymbolParser::FormalParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitFormalParameters(this);
  else
    return visitor->visitChildren(this);
}

CymbolParser::FormalParametersContext* CymbolParser::formalParameters() {
  FormalParametersContext *_localctx = _tracker.createInstance<FormalParametersContext>(_ctx, getState());
  enterRule(_localctx, 4, CymbolParser::RuleFormalParameters);
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
    setState(39);
    type();
    setState(40);
    match(CymbolParser::ID);
    setState(47);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CymbolParser::T__2) {
      setState(41);
      match(CymbolParser::T__2);
      setState(42);
      type();
      setState(43);
      match(CymbolParser::ID);
      setState(49);
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
  enterRule(_localctx, 6, CymbolParser::RuleType);
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
    setState(50);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 112) != 0))) {
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

//----------------- BlockContext ------------------------------------------------------------------

CymbolParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CymbolParser::StatementContext *> CymbolParser::BlockContext::statement() {
  return getRuleContexts<CymbolParser::StatementContext>();
}

CymbolParser::StatementContext* CymbolParser::BlockContext::statement(size_t i) {
  return getRuleContext<CymbolParser::StatementContext>(i);
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


std::any CymbolParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

CymbolParser::BlockContext* CymbolParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 8, CymbolParser::RuleBlock);
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
    setState(52);
    match(CymbolParser::T__6);
    setState(56);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 26866) != 0)) {
      setState(53);
      statement();
      setState(58);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(59);
    match(CymbolParser::T__7);
   
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
  enterRule(_localctx, 10, CymbolParser::RuleVarDeclaration);
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
    setState(61);
    type();
    setState(62);
    match(CymbolParser::ID);
    setState(65);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CymbolParser::T__8) {
      setState(63);
      match(CymbolParser::T__8);
      setState(64);
      expression();
    }
    setState(67);
    match(CymbolParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

CymbolParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CymbolParser::BlockContext* CymbolParser::StatementContext::block() {
  return getRuleContext<CymbolParser::BlockContext>(0);
}

CymbolParser::VarDeclarationContext* CymbolParser::StatementContext::varDeclaration() {
  return getRuleContext<CymbolParser::VarDeclarationContext>(0);
}

CymbolParser::ExpressionContext* CymbolParser::StatementContext::expression() {
  return getRuleContext<CymbolParser::ExpressionContext>(0);
}

CymbolParser::PostfixExpressionContext* CymbolParser::StatementContext::postfixExpression() {
  return getRuleContext<CymbolParser::PostfixExpressionContext>(0);
}


size_t CymbolParser::StatementContext::getRuleIndex() const {
  return CymbolParser::RuleStatement;
}

void CymbolParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void CymbolParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any CymbolParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

CymbolParser::StatementContext* CymbolParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 12, CymbolParser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(84);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CymbolParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(69);
        block();
        break;
      }

      case CymbolParser::T__3:
      case CymbolParser::T__4:
      case CymbolParser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(70);
        varDeclaration();
        break;
      }

      case CymbolParser::T__10: {
        enterOuterAlt(_localctx, 3);
        setState(71);
        match(CymbolParser::T__10);
        setState(73);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 24578) != 0)) {
          setState(72);
          expression();
        }
        setState(75);
        match(CymbolParser::T__9);
        break;
      }

      case CymbolParser::T__0:
      case CymbolParser::ID:
      case CymbolParser::INT: {
        enterOuterAlt(_localctx, 4);
        setState(76);
        postfixExpression();
        setState(80);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case CymbolParser::T__8: {
            setState(77);
            match(CymbolParser::T__8);
            setState(78);
            expression();
            break;
          }

          case CymbolParser::T__9: {
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(82);
        match(CymbolParser::T__9);
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

//----------------- ExpressionListContext ------------------------------------------------------------------

CymbolParser::ExpressionListContext::ExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CymbolParser::ExpressionContext *> CymbolParser::ExpressionListContext::expression() {
  return getRuleContexts<CymbolParser::ExpressionContext>();
}

CymbolParser::ExpressionContext* CymbolParser::ExpressionListContext::expression(size_t i) {
  return getRuleContext<CymbolParser::ExpressionContext>(i);
}


size_t CymbolParser::ExpressionListContext::getRuleIndex() const {
  return CymbolParser::RuleExpressionList;
}

void CymbolParser::ExpressionListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionList(this);
}

void CymbolParser::ExpressionListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionList(this);
}


std::any CymbolParser::ExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitExpressionList(this);
  else
    return visitor->visitChildren(this);
}

CymbolParser::ExpressionListContext* CymbolParser::expressionList() {
  ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 14, CymbolParser::RuleExpressionList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(95);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CymbolParser::T__0:
      case CymbolParser::ID:
      case CymbolParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(86);
        expression();
        setState(91);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CymbolParser::T__2) {
          setState(87);
          match(CymbolParser::T__2);
          setState(88);
          expression();
          setState(93);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case CymbolParser::T__1: {
        enterOuterAlt(_localctx, 2);

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

//----------------- ExpressionContext ------------------------------------------------------------------

CymbolParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CymbolParser::AddExpressionContext* CymbolParser::ExpressionContext::addExpression() {
  return getRuleContext<CymbolParser::AddExpressionContext>(0);
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
  enterRule(_localctx, 16, CymbolParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    addExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddExpressionContext ------------------------------------------------------------------

CymbolParser::AddExpressionContext::AddExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CymbolParser::PostfixExpressionContext *> CymbolParser::AddExpressionContext::postfixExpression() {
  return getRuleContexts<CymbolParser::PostfixExpressionContext>();
}

CymbolParser::PostfixExpressionContext* CymbolParser::AddExpressionContext::postfixExpression(size_t i) {
  return getRuleContext<CymbolParser::PostfixExpressionContext>(i);
}


size_t CymbolParser::AddExpressionContext::getRuleIndex() const {
  return CymbolParser::RuleAddExpression;
}

void CymbolParser::AddExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExpression(this);
}

void CymbolParser::AddExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExpression(this);
}


std::any CymbolParser::AddExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitAddExpression(this);
  else
    return visitor->visitChildren(this);
}

CymbolParser::AddExpressionContext* CymbolParser::addExpression() {
  AddExpressionContext *_localctx = _tracker.createInstance<AddExpressionContext>(_ctx, getState());
  enterRule(_localctx, 18, CymbolParser::RuleAddExpression);
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
    setState(99);
    postfixExpression();
    setState(104);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CymbolParser::T__11) {
      setState(100);
      match(CymbolParser::T__11);
      setState(101);
      postfixExpression();
      setState(106);
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

//----------------- PostfixExpressionContext ------------------------------------------------------------------

CymbolParser::PostfixExpressionContext::PostfixExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CymbolParser::PrimaryContext* CymbolParser::PostfixExpressionContext::primary() {
  return getRuleContext<CymbolParser::PrimaryContext>(0);
}

std::vector<CymbolParser::ExpressionListContext *> CymbolParser::PostfixExpressionContext::expressionList() {
  return getRuleContexts<CymbolParser::ExpressionListContext>();
}

CymbolParser::ExpressionListContext* CymbolParser::PostfixExpressionContext::expressionList(size_t i) {
  return getRuleContext<CymbolParser::ExpressionListContext>(i);
}


size_t CymbolParser::PostfixExpressionContext::getRuleIndex() const {
  return CymbolParser::RulePostfixExpression;
}

void CymbolParser::PostfixExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostfixExpression(this);
}

void CymbolParser::PostfixExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostfixExpression(this);
}


std::any CymbolParser::PostfixExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitPostfixExpression(this);
  else
    return visitor->visitChildren(this);
}

CymbolParser::PostfixExpressionContext* CymbolParser::postfixExpression() {
  PostfixExpressionContext *_localctx = _tracker.createInstance<PostfixExpressionContext>(_ctx, getState());
  enterRule(_localctx, 20, CymbolParser::RulePostfixExpression);
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
    setState(107);
    primary();
    setState(114);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CymbolParser::T__0) {
      setState(108);
      match(CymbolParser::T__0);
      setState(109);
      expressionList();
      setState(110);
      match(CymbolParser::T__1);
      setState(116);
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
  enterRule(_localctx, 22, CymbolParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(123);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CymbolParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(117);
        match(CymbolParser::ID);
        break;
      }

      case CymbolParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(118);
        match(CymbolParser::INT);
        break;
      }

      case CymbolParser::T__0: {
        enterOuterAlt(_localctx, 3);
        setState(119);
        match(CymbolParser::T__0);
        setState(120);
        expression();
        setState(121);
        match(CymbolParser::T__1);
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
