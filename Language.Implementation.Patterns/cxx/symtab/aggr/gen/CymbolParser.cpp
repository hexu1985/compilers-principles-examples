
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
      "compilationUnit", "structDeclaration", "structMember", "methodDeclaration", 
      "formalParameters", "type", "block", "varDeclaration", "statement", 
      "expressionList", "expression", "addExpression", "postfixExpression", 
      "primary"
    },
    std::vector<std::string>{
      "", "'struct'", "'{'", "'}'", "';'", "'('", "')'", "','", "'float'", 
      "'int'", "'void'", "'='", "'return'", "'+'", "'.'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "ID", 
      "INT", "WS", "SL_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,18,152,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,1,0,1,0,
  	1,0,4,0,32,8,0,11,0,12,0,33,1,1,1,1,1,1,1,1,4,1,40,8,1,11,1,12,1,41,1,
  	1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,3,2,52,8,2,1,3,1,3,1,3,1,3,3,3,58,8,3,1,
  	3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,5,4,69,8,4,10,4,12,4,72,9,4,1,5,1,5,
  	1,6,1,6,5,6,78,8,6,10,6,12,6,81,9,6,1,6,1,6,1,7,1,7,1,7,1,7,3,7,89,8,
  	7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,3,8,98,8,8,1,8,1,8,1,8,1,8,1,8,3,8,105,
  	8,8,1,8,1,8,3,8,109,8,8,1,9,1,9,1,9,5,9,114,8,9,10,9,12,9,117,9,9,1,9,
  	3,9,120,8,9,1,10,1,10,1,11,1,11,1,11,5,11,127,8,11,10,11,12,11,130,9,
  	11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,5,12,139,8,12,10,12,12,12,142,9,
  	12,1,13,1,13,1,13,1,13,1,13,1,13,3,13,150,8,13,1,13,0,0,14,0,2,4,6,8,
  	10,12,14,16,18,20,22,24,26,0,1,2,0,8,10,15,15,159,0,31,1,0,0,0,2,35,1,
  	0,0,0,4,51,1,0,0,0,6,53,1,0,0,0,8,62,1,0,0,0,10,73,1,0,0,0,12,75,1,0,
  	0,0,14,84,1,0,0,0,16,108,1,0,0,0,18,119,1,0,0,0,20,121,1,0,0,0,22,123,
  	1,0,0,0,24,131,1,0,0,0,26,149,1,0,0,0,28,32,3,2,1,0,29,32,3,6,3,0,30,
  	32,3,14,7,0,31,28,1,0,0,0,31,29,1,0,0,0,31,30,1,0,0,0,32,33,1,0,0,0,33,
  	31,1,0,0,0,33,34,1,0,0,0,34,1,1,0,0,0,35,36,5,1,0,0,36,37,5,15,0,0,37,
  	39,5,2,0,0,38,40,3,4,2,0,39,38,1,0,0,0,40,41,1,0,0,0,41,39,1,0,0,0,41,
  	42,1,0,0,0,42,43,1,0,0,0,43,44,5,3,0,0,44,45,5,4,0,0,45,3,1,0,0,0,46,
  	47,3,10,5,0,47,48,5,15,0,0,48,49,5,4,0,0,49,52,1,0,0,0,50,52,3,2,1,0,
  	51,46,1,0,0,0,51,50,1,0,0,0,52,5,1,0,0,0,53,54,3,10,5,0,54,55,5,15,0,
  	0,55,57,5,5,0,0,56,58,3,8,4,0,57,56,1,0,0,0,57,58,1,0,0,0,58,59,1,0,0,
  	0,59,60,5,6,0,0,60,61,3,12,6,0,61,7,1,0,0,0,62,63,3,10,5,0,63,70,5,15,
  	0,0,64,65,5,7,0,0,65,66,3,10,5,0,66,67,5,15,0,0,67,69,1,0,0,0,68,64,1,
  	0,0,0,69,72,1,0,0,0,70,68,1,0,0,0,70,71,1,0,0,0,71,9,1,0,0,0,72,70,1,
  	0,0,0,73,74,7,0,0,0,74,11,1,0,0,0,75,79,5,2,0,0,76,78,3,16,8,0,77,76,
  	1,0,0,0,78,81,1,0,0,0,79,77,1,0,0,0,79,80,1,0,0,0,80,82,1,0,0,0,81,79,
  	1,0,0,0,82,83,5,3,0,0,83,13,1,0,0,0,84,85,3,10,5,0,85,88,5,15,0,0,86,
  	87,5,11,0,0,87,89,3,20,10,0,88,86,1,0,0,0,88,89,1,0,0,0,89,90,1,0,0,0,
  	90,91,5,4,0,0,91,15,1,0,0,0,92,109,3,12,6,0,93,109,3,2,1,0,94,109,3,14,
  	7,0,95,97,5,12,0,0,96,98,3,20,10,0,97,96,1,0,0,0,97,98,1,0,0,0,98,99,
  	1,0,0,0,99,109,5,4,0,0,100,104,3,24,12,0,101,102,5,11,0,0,102,105,3,20,
  	10,0,103,105,1,0,0,0,104,101,1,0,0,0,104,103,1,0,0,0,105,106,1,0,0,0,
  	106,107,5,4,0,0,107,109,1,0,0,0,108,92,1,0,0,0,108,93,1,0,0,0,108,94,
  	1,0,0,0,108,95,1,0,0,0,108,100,1,0,0,0,109,17,1,0,0,0,110,115,3,20,10,
  	0,111,112,5,7,0,0,112,114,3,20,10,0,113,111,1,0,0,0,114,117,1,0,0,0,115,
  	113,1,0,0,0,115,116,1,0,0,0,116,120,1,0,0,0,117,115,1,0,0,0,118,120,1,
  	0,0,0,119,110,1,0,0,0,119,118,1,0,0,0,120,19,1,0,0,0,121,122,3,22,11,
  	0,122,21,1,0,0,0,123,128,3,24,12,0,124,125,5,13,0,0,125,127,3,24,12,0,
  	126,124,1,0,0,0,127,130,1,0,0,0,128,126,1,0,0,0,128,129,1,0,0,0,129,23,
  	1,0,0,0,130,128,1,0,0,0,131,140,3,26,13,0,132,133,5,5,0,0,133,134,3,18,
  	9,0,134,135,5,6,0,0,135,139,1,0,0,0,136,137,5,14,0,0,137,139,5,15,0,0,
  	138,132,1,0,0,0,138,136,1,0,0,0,139,142,1,0,0,0,140,138,1,0,0,0,140,141,
  	1,0,0,0,141,25,1,0,0,0,142,140,1,0,0,0,143,150,5,15,0,0,144,150,5,16,
  	0,0,145,146,5,5,0,0,146,147,3,20,10,0,147,148,5,6,0,0,148,150,1,0,0,0,
  	149,143,1,0,0,0,149,144,1,0,0,0,149,145,1,0,0,0,150,27,1,0,0,0,17,31,
  	33,41,51,57,70,79,88,97,104,108,115,119,128,138,140,149
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

std::vector<CymbolParser::StructDeclarationContext *> CymbolParser::CompilationUnitContext::structDeclaration() {
  return getRuleContexts<CymbolParser::StructDeclarationContext>();
}

CymbolParser::StructDeclarationContext* CymbolParser::CompilationUnitContext::structDeclaration(size_t i) {
  return getRuleContext<CymbolParser::StructDeclarationContext>(i);
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
    setState(31); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(31);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(28);
        structDeclaration();
        break;
      }

      case 2: {
        setState(29);
        methodDeclaration();
        break;
      }

      case 3: {
        setState(30);
        varDeclaration();
        break;
      }

      default:
        break;
      }
      setState(33); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 34562) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructDeclarationContext ------------------------------------------------------------------

CymbolParser::StructDeclarationContext::StructDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CymbolParser::StructDeclarationContext::ID() {
  return getToken(CymbolParser::ID, 0);
}

std::vector<CymbolParser::StructMemberContext *> CymbolParser::StructDeclarationContext::structMember() {
  return getRuleContexts<CymbolParser::StructMemberContext>();
}

CymbolParser::StructMemberContext* CymbolParser::StructDeclarationContext::structMember(size_t i) {
  return getRuleContext<CymbolParser::StructMemberContext>(i);
}


size_t CymbolParser::StructDeclarationContext::getRuleIndex() const {
  return CymbolParser::RuleStructDeclaration;
}

void CymbolParser::StructDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclaration(this);
}

void CymbolParser::StructDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclaration(this);
}


std::any CymbolParser::StructDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitStructDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CymbolParser::StructDeclarationContext* CymbolParser::structDeclaration() {
  StructDeclarationContext *_localctx = _tracker.createInstance<StructDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, CymbolParser::RuleStructDeclaration);
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
    setState(35);
    match(CymbolParser::T__0);
    setState(36);
    match(CymbolParser::ID);
    setState(37);
    match(CymbolParser::T__1);
    setState(39); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(38);
      structMember();
      setState(41); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 34562) != 0));
    setState(43);
    match(CymbolParser::T__2);
    setState(44);
    match(CymbolParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructMemberContext ------------------------------------------------------------------

CymbolParser::StructMemberContext::StructMemberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CymbolParser::TypeContext* CymbolParser::StructMemberContext::type() {
  return getRuleContext<CymbolParser::TypeContext>(0);
}

tree::TerminalNode* CymbolParser::StructMemberContext::ID() {
  return getToken(CymbolParser::ID, 0);
}

CymbolParser::StructDeclarationContext* CymbolParser::StructMemberContext::structDeclaration() {
  return getRuleContext<CymbolParser::StructDeclarationContext>(0);
}


size_t CymbolParser::StructMemberContext::getRuleIndex() const {
  return CymbolParser::RuleStructMember;
}

void CymbolParser::StructMemberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructMember(this);
}

void CymbolParser::StructMemberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructMember(this);
}


std::any CymbolParser::StructMemberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitStructMember(this);
  else
    return visitor->visitChildren(this);
}

CymbolParser::StructMemberContext* CymbolParser::structMember() {
  StructMemberContext *_localctx = _tracker.createInstance<StructMemberContext>(_ctx, getState());
  enterRule(_localctx, 4, CymbolParser::RuleStructMember);

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
      case CymbolParser::T__7:
      case CymbolParser::T__8:
      case CymbolParser::T__9:
      case CymbolParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(46);
        type();
        setState(47);
        match(CymbolParser::ID);
        setState(48);
        match(CymbolParser::T__3);
        break;
      }

      case CymbolParser::T__0: {
        enterOuterAlt(_localctx, 2);
        setState(50);
        structDeclaration();
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
  enterRule(_localctx, 6, CymbolParser::RuleMethodDeclaration);
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
    setState(53);
    type();
    setState(54);
    match(CymbolParser::ID);
    setState(55);
    match(CymbolParser::T__4);
    setState(57);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 34560) != 0)) {
      setState(56);
      formalParameters();
    }
    setState(59);
    match(CymbolParser::T__5);
    setState(60);
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
    setState(62);
    type();
    setState(63);
    match(CymbolParser::ID);
    setState(70);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CymbolParser::T__6) {
      setState(64);
      match(CymbolParser::T__6);
      setState(65);
      type();
      setState(66);
      match(CymbolParser::ID);
      setState(72);
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

tree::TerminalNode* CymbolParser::TypeContext::ID() {
  return getToken(CymbolParser::ID, 0);
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
  enterRule(_localctx, 10, CymbolParser::RuleType);
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
    setState(73);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 34560) != 0))) {
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
    setState(75);
    match(CymbolParser::T__1);
    setState(79);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 104230) != 0)) {
      setState(76);
      statement();
      setState(81);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(82);
    match(CymbolParser::T__2);
   
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
  enterRule(_localctx, 14, CymbolParser::RuleVarDeclaration);
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
    setState(84);
    type();
    setState(85);
    match(CymbolParser::ID);
    setState(88);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CymbolParser::T__10) {
      setState(86);
      match(CymbolParser::T__10);
      setState(87);
      expression();
    }
    setState(90);
    match(CymbolParser::T__3);
   
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

CymbolParser::StructDeclarationContext* CymbolParser::StatementContext::structDeclaration() {
  return getRuleContext<CymbolParser::StructDeclarationContext>(0);
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
  enterRule(_localctx, 16, CymbolParser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(108);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(92);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(93);
      structDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(94);
      varDeclaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(95);
      match(CymbolParser::T__11);
      setState(97);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 98336) != 0)) {
        setState(96);
        expression();
      }
      setState(99);
      match(CymbolParser::T__3);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(100);
      postfixExpression();
      setState(104);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case CymbolParser::T__10: {
          setState(101);
          match(CymbolParser::T__10);
          setState(102);
          expression();
          break;
        }

        case CymbolParser::T__3: {
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(106);
      match(CymbolParser::T__3);
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
  enterRule(_localctx, 18, CymbolParser::RuleExpressionList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(119);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CymbolParser::T__4:
      case CymbolParser::ID:
      case CymbolParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(110);
        expression();
        setState(115);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CymbolParser::T__6) {
          setState(111);
          match(CymbolParser::T__6);
          setState(112);
          expression();
          setState(117);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case CymbolParser::T__5: {
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
  enterRule(_localctx, 20, CymbolParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
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
  enterRule(_localctx, 22, CymbolParser::RuleAddExpression);
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
    setState(123);
    postfixExpression();
    setState(128);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CymbolParser::T__12) {
      setState(124);
      match(CymbolParser::T__12);
      setState(125);
      postfixExpression();
      setState(130);
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

std::vector<tree::TerminalNode *> CymbolParser::PostfixExpressionContext::ID() {
  return getTokens(CymbolParser::ID);
}

tree::TerminalNode* CymbolParser::PostfixExpressionContext::ID(size_t i) {
  return getToken(CymbolParser::ID, i);
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
  enterRule(_localctx, 24, CymbolParser::RulePostfixExpression);
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
    setState(131);
    primary();
    setState(140);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CymbolParser::T__4

    || _la == CymbolParser::T__13) {
      setState(138);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case CymbolParser::T__4: {
          setState(132);
          match(CymbolParser::T__4);
          setState(133);
          expressionList();
          setState(134);
          match(CymbolParser::T__5);
          break;
        }

        case CymbolParser::T__13: {
          setState(136);
          match(CymbolParser::T__13);
          setState(137);
          match(CymbolParser::ID);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(142);
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
  enterRule(_localctx, 26, CymbolParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(149);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CymbolParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(143);
        match(CymbolParser::ID);
        break;
      }

      case CymbolParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(144);
        match(CymbolParser::INT);
        break;
      }

      case CymbolParser::T__4: {
        enterOuterAlt(_localctx, 3);
        setState(145);
        match(CymbolParser::T__4);
        setState(146);
        expression();
        setState(147);
        match(CymbolParser::T__5);
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
