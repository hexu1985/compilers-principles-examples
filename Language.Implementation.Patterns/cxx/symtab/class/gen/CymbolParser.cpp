
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
      "compilationUnit", "classDefinition", "superClass", "classMember", 
      "methodDeclaration", "formalParameters", "type", "block", "varDeclaration", 
      "statement", "expressionList", "expression", "addExpression", "postfixExpression", 
      "primary"
    },
    std::vector<std::string>{
      "", "'class'", "'{'", "'}'", "';'", "':'", "'public'", "'='", "'('", 
      "')'", "','", "'float'", "'int'", "'void'", "'return'", "'+'", "'.'", 
      "'this'", "'super'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "ID", "INT", "WS", "SL_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,22,177,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,1,0,1,0,1,0,4,0,34,8,0,11,0,12,0,35,1,0,1,0,1,1,1,1,1,1,3,1,43,8,1,
  	1,1,1,1,4,1,47,8,1,11,1,12,1,48,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,3,1,3,1,
  	3,1,3,3,3,62,8,3,1,3,1,3,1,3,1,3,1,3,3,3,69,8,3,1,4,1,4,1,4,1,4,3,4,75,
  	8,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,5,5,86,8,5,10,5,12,5,89,9,5,1,
  	6,1,6,1,7,1,7,5,7,95,8,7,10,7,12,7,98,9,7,1,7,1,7,1,8,1,8,1,8,1,8,3,8,
  	106,8,8,1,8,1,8,1,9,1,9,1,9,1,9,3,9,114,8,9,1,9,1,9,1,9,1,9,1,9,3,9,121,
  	8,9,1,9,1,9,1,9,3,9,126,8,9,1,10,1,10,1,10,5,10,131,8,10,10,10,12,10,
  	134,9,10,1,10,3,10,137,8,10,1,11,1,11,1,12,1,12,1,12,5,12,144,8,12,10,
  	12,12,12,147,9,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,
  	13,1,13,1,13,5,13,162,8,13,10,13,12,13,165,9,13,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,3,14,175,8,14,1,14,0,0,15,0,2,4,6,8,10,12,14,16,18,
  	20,22,24,26,28,0,1,2,0,11,13,19,19,189,0,33,1,0,0,0,2,39,1,0,0,0,4,53,
  	1,0,0,0,6,68,1,0,0,0,8,70,1,0,0,0,10,79,1,0,0,0,12,90,1,0,0,0,14,92,1,
  	0,0,0,16,101,1,0,0,0,18,125,1,0,0,0,20,136,1,0,0,0,22,138,1,0,0,0,24,
  	140,1,0,0,0,26,148,1,0,0,0,28,174,1,0,0,0,30,34,3,2,1,0,31,34,3,16,8,
  	0,32,34,3,8,4,0,33,30,1,0,0,0,33,31,1,0,0,0,33,32,1,0,0,0,34,35,1,0,0,
  	0,35,33,1,0,0,0,35,36,1,0,0,0,36,37,1,0,0,0,37,38,5,0,0,1,38,1,1,0,0,
  	0,39,40,5,1,0,0,40,42,5,19,0,0,41,43,3,4,2,0,42,41,1,0,0,0,42,43,1,0,
  	0,0,43,44,1,0,0,0,44,46,5,2,0,0,45,47,3,6,3,0,46,45,1,0,0,0,47,48,1,0,
  	0,0,48,46,1,0,0,0,48,49,1,0,0,0,49,50,1,0,0,0,50,51,5,3,0,0,51,52,5,4,
  	0,0,52,3,1,0,0,0,53,54,5,5,0,0,54,55,5,6,0,0,55,56,5,19,0,0,56,5,1,0,
  	0,0,57,58,3,12,6,0,58,61,5,19,0,0,59,60,5,7,0,0,60,62,3,22,11,0,61,59,
  	1,0,0,0,61,62,1,0,0,0,62,63,1,0,0,0,63,64,5,4,0,0,64,69,1,0,0,0,65,69,
  	3,8,4,0,66,67,5,6,0,0,67,69,5,5,0,0,68,57,1,0,0,0,68,65,1,0,0,0,68,66,
  	1,0,0,0,69,7,1,0,0,0,70,71,3,12,6,0,71,72,5,19,0,0,72,74,5,8,0,0,73,75,
  	3,10,5,0,74,73,1,0,0,0,74,75,1,0,0,0,75,76,1,0,0,0,76,77,5,9,0,0,77,78,
  	3,14,7,0,78,9,1,0,0,0,79,80,3,12,6,0,80,87,5,19,0,0,81,82,5,10,0,0,82,
  	83,3,12,6,0,83,84,5,19,0,0,84,86,1,0,0,0,85,81,1,0,0,0,86,89,1,0,0,0,
  	87,85,1,0,0,0,87,88,1,0,0,0,88,11,1,0,0,0,89,87,1,0,0,0,90,91,7,0,0,0,
  	91,13,1,0,0,0,92,96,5,2,0,0,93,95,3,18,9,0,94,93,1,0,0,0,95,98,1,0,0,
  	0,96,94,1,0,0,0,96,97,1,0,0,0,97,99,1,0,0,0,98,96,1,0,0,0,99,100,5,3,
  	0,0,100,15,1,0,0,0,101,102,3,12,6,0,102,105,5,19,0,0,103,104,5,7,0,0,
  	104,106,3,22,11,0,105,103,1,0,0,0,105,106,1,0,0,0,106,107,1,0,0,0,107,
  	108,5,4,0,0,108,17,1,0,0,0,109,126,3,14,7,0,110,126,3,16,8,0,111,113,
  	5,14,0,0,112,114,3,22,11,0,113,112,1,0,0,0,113,114,1,0,0,0,114,115,1,
  	0,0,0,115,126,5,4,0,0,116,120,3,26,13,0,117,118,5,7,0,0,118,121,3,22,
  	11,0,119,121,1,0,0,0,120,117,1,0,0,0,120,119,1,0,0,0,121,122,1,0,0,0,
  	122,123,5,4,0,0,123,126,1,0,0,0,124,126,5,4,0,0,125,109,1,0,0,0,125,110,
  	1,0,0,0,125,111,1,0,0,0,125,116,1,0,0,0,125,124,1,0,0,0,126,19,1,0,0,
  	0,127,132,3,22,11,0,128,129,5,10,0,0,129,131,3,22,11,0,130,128,1,0,0,
  	0,131,134,1,0,0,0,132,130,1,0,0,0,132,133,1,0,0,0,133,137,1,0,0,0,134,
  	132,1,0,0,0,135,137,1,0,0,0,136,127,1,0,0,0,136,135,1,0,0,0,137,21,1,
  	0,0,0,138,139,3,24,12,0,139,23,1,0,0,0,140,145,3,26,13,0,141,142,5,15,
  	0,0,142,144,3,26,13,0,143,141,1,0,0,0,144,147,1,0,0,0,145,143,1,0,0,0,
  	145,146,1,0,0,0,146,25,1,0,0,0,147,145,1,0,0,0,148,163,3,28,14,0,149,
  	150,5,16,0,0,150,151,5,19,0,0,151,152,5,8,0,0,152,153,3,20,10,0,153,154,
  	5,9,0,0,154,162,1,0,0,0,155,156,5,16,0,0,156,162,5,19,0,0,157,158,5,8,
  	0,0,158,159,3,20,10,0,159,160,5,9,0,0,160,162,1,0,0,0,161,149,1,0,0,0,
  	161,155,1,0,0,0,161,157,1,0,0,0,162,165,1,0,0,0,163,161,1,0,0,0,163,164,
  	1,0,0,0,164,27,1,0,0,0,165,163,1,0,0,0,166,175,5,17,0,0,167,175,5,18,
  	0,0,168,175,5,19,0,0,169,175,5,20,0,0,170,171,5,8,0,0,171,172,3,22,11,
  	0,172,173,5,9,0,0,173,175,1,0,0,0,174,166,1,0,0,0,174,167,1,0,0,0,174,
  	168,1,0,0,0,174,169,1,0,0,0,174,170,1,0,0,0,175,29,1,0,0,0,19,33,35,42,
  	48,61,68,74,87,96,105,113,120,125,132,136,145,161,163,174
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

tree::TerminalNode* CymbolParser::CompilationUnitContext::EOF() {
  return getToken(CymbolParser::EOF, 0);
}

std::vector<CymbolParser::ClassDefinitionContext *> CymbolParser::CompilationUnitContext::classDefinition() {
  return getRuleContexts<CymbolParser::ClassDefinitionContext>();
}

CymbolParser::ClassDefinitionContext* CymbolParser::CompilationUnitContext::classDefinition(size_t i) {
  return getRuleContext<CymbolParser::ClassDefinitionContext>(i);
}

std::vector<CymbolParser::VarDeclarationContext *> CymbolParser::CompilationUnitContext::varDeclaration() {
  return getRuleContexts<CymbolParser::VarDeclarationContext>();
}

CymbolParser::VarDeclarationContext* CymbolParser::CompilationUnitContext::varDeclaration(size_t i) {
  return getRuleContext<CymbolParser::VarDeclarationContext>(i);
}

std::vector<CymbolParser::MethodDeclarationContext *> CymbolParser::CompilationUnitContext::methodDeclaration() {
  return getRuleContexts<CymbolParser::MethodDeclarationContext>();
}

CymbolParser::MethodDeclarationContext* CymbolParser::CompilationUnitContext::methodDeclaration(size_t i) {
  return getRuleContext<CymbolParser::MethodDeclarationContext>(i);
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
    setState(33); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(33);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(30);
        classDefinition();
        break;
      }

      case 2: {
        setState(31);
        varDeclaration();
        break;
      }

      case 3: {
        setState(32);
        methodDeclaration();
        break;
      }

      default:
        break;
      }
      setState(35); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 538626) != 0));
    setState(37);
    match(CymbolParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDefinitionContext ------------------------------------------------------------------

CymbolParser::ClassDefinitionContext::ClassDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CymbolParser::ClassDefinitionContext::ID() {
  return getToken(CymbolParser::ID, 0);
}

CymbolParser::SuperClassContext* CymbolParser::ClassDefinitionContext::superClass() {
  return getRuleContext<CymbolParser::SuperClassContext>(0);
}

std::vector<CymbolParser::ClassMemberContext *> CymbolParser::ClassDefinitionContext::classMember() {
  return getRuleContexts<CymbolParser::ClassMemberContext>();
}

CymbolParser::ClassMemberContext* CymbolParser::ClassDefinitionContext::classMember(size_t i) {
  return getRuleContext<CymbolParser::ClassMemberContext>(i);
}


size_t CymbolParser::ClassDefinitionContext::getRuleIndex() const {
  return CymbolParser::RuleClassDefinition;
}

void CymbolParser::ClassDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassDefinition(this);
}

void CymbolParser::ClassDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassDefinition(this);
}


std::any CymbolParser::ClassDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitClassDefinition(this);
  else
    return visitor->visitChildren(this);
}

CymbolParser::ClassDefinitionContext* CymbolParser::classDefinition() {
  ClassDefinitionContext *_localctx = _tracker.createInstance<ClassDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 2, CymbolParser::RuleClassDefinition);
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
    match(CymbolParser::T__0);
    setState(40);
    match(CymbolParser::ID);
    setState(42);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CymbolParser::T__4) {
      setState(41);
      superClass();
    }
    setState(44);
    match(CymbolParser::T__1);
    setState(46); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(45);
      classMember();
      setState(48); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 538688) != 0));
    setState(50);
    match(CymbolParser::T__2);
    setState(51);
    match(CymbolParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SuperClassContext ------------------------------------------------------------------

CymbolParser::SuperClassContext::SuperClassContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CymbolParser::SuperClassContext::ID() {
  return getToken(CymbolParser::ID, 0);
}


size_t CymbolParser::SuperClassContext::getRuleIndex() const {
  return CymbolParser::RuleSuperClass;
}

void CymbolParser::SuperClassContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSuperClass(this);
}

void CymbolParser::SuperClassContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSuperClass(this);
}


std::any CymbolParser::SuperClassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitSuperClass(this);
  else
    return visitor->visitChildren(this);
}

CymbolParser::SuperClassContext* CymbolParser::superClass() {
  SuperClassContext *_localctx = _tracker.createInstance<SuperClassContext>(_ctx, getState());
  enterRule(_localctx, 4, CymbolParser::RuleSuperClass);

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
    match(CymbolParser::T__4);
    setState(54);
    match(CymbolParser::T__5);
    setState(55);
    match(CymbolParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassMemberContext ------------------------------------------------------------------

CymbolParser::ClassMemberContext::ClassMemberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CymbolParser::ClassMemberContext::getRuleIndex() const {
  return CymbolParser::RuleClassMember;
}

void CymbolParser::ClassMemberContext::copyFrom(ClassMemberContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MethodMemberContext ------------------------------------------------------------------

CymbolParser::MethodDeclarationContext* CymbolParser::MethodMemberContext::methodDeclaration() {
  return getRuleContext<CymbolParser::MethodDeclarationContext>(0);
}

CymbolParser::MethodMemberContext::MethodMemberContext(ClassMemberContext *ctx) { copyFrom(ctx); }

void CymbolParser::MethodMemberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodMember(this);
}
void CymbolParser::MethodMemberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodMember(this);
}

std::any CymbolParser::MethodMemberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitMethodMember(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AccessSpecContext ------------------------------------------------------------------

CymbolParser::AccessSpecContext::AccessSpecContext(ClassMemberContext *ctx) { copyFrom(ctx); }

void CymbolParser::AccessSpecContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAccessSpec(this);
}
void CymbolParser::AccessSpecContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAccessSpec(this);
}

std::any CymbolParser::AccessSpecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitAccessSpec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FieldMemberContext ------------------------------------------------------------------

CymbolParser::TypeContext* CymbolParser::FieldMemberContext::type() {
  return getRuleContext<CymbolParser::TypeContext>(0);
}

tree::TerminalNode* CymbolParser::FieldMemberContext::ID() {
  return getToken(CymbolParser::ID, 0);
}

CymbolParser::ExpressionContext* CymbolParser::FieldMemberContext::expression() {
  return getRuleContext<CymbolParser::ExpressionContext>(0);
}

CymbolParser::FieldMemberContext::FieldMemberContext(ClassMemberContext *ctx) { copyFrom(ctx); }

void CymbolParser::FieldMemberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFieldMember(this);
}
void CymbolParser::FieldMemberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CymbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFieldMember(this);
}

std::any CymbolParser::FieldMemberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CymbolVisitor*>(visitor))
    return parserVisitor->visitFieldMember(this);
  else
    return visitor->visitChildren(this);
}
CymbolParser::ClassMemberContext* CymbolParser::classMember() {
  ClassMemberContext *_localctx = _tracker.createInstance<ClassMemberContext>(_ctx, getState());
  enterRule(_localctx, 6, CymbolParser::RuleClassMember);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(68);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CymbolParser::FieldMemberContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(57);
      type();
      setState(58);
      match(CymbolParser::ID);
      setState(61);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CymbolParser::T__6) {
        setState(59);
        match(CymbolParser::T__6);
        setState(60);
        expression();
      }
      setState(63);
      match(CymbolParser::T__3);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CymbolParser::MethodMemberContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(65);
      methodDeclaration();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CymbolParser::AccessSpecContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(66);
      match(CymbolParser::T__5);
      setState(67);
      match(CymbolParser::T__4);
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
  enterRule(_localctx, 8, CymbolParser::RuleMethodDeclaration);
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
    setState(70);
    type();
    setState(71);
    match(CymbolParser::ID);
    setState(72);
    match(CymbolParser::T__7);
    setState(74);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 538624) != 0)) {
      setState(73);
      formalParameters();
    }
    setState(76);
    match(CymbolParser::T__8);
    setState(77);
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
  enterRule(_localctx, 10, CymbolParser::RuleFormalParameters);
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
    setState(79);
    type();
    setState(80);
    match(CymbolParser::ID);
    setState(87);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CymbolParser::T__9) {
      setState(81);
      match(CymbolParser::T__9);
      setState(82);
      type();
      setState(83);
      match(CymbolParser::ID);
      setState(89);
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
  enterRule(_localctx, 12, CymbolParser::RuleType);
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
    setState(90);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 538624) != 0))) {
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
  enterRule(_localctx, 14, CymbolParser::RuleBlock);
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
    setState(92);
    match(CymbolParser::T__1);
    setState(96);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1997076) != 0)) {
      setState(93);
      statement();
      setState(98);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(99);
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
  enterRule(_localctx, 16, CymbolParser::RuleVarDeclaration);
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
    setState(101);
    type();
    setState(102);
    match(CymbolParser::ID);
    setState(105);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CymbolParser::T__6) {
      setState(103);
      match(CymbolParser::T__6);
      setState(104);
      expression();
    }
    setState(107);
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
  enterRule(_localctx, 18, CymbolParser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(125);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(109);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(110);
      varDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(111);
      match(CymbolParser::T__13);
      setState(113);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1966336) != 0)) {
        setState(112);
        expression();
      }
      setState(115);
      match(CymbolParser::T__3);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(116);
      postfixExpression();
      setState(120);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case CymbolParser::T__6: {
          setState(117);
          match(CymbolParser::T__6);
          setState(118);
          expression();
          break;
        }

        case CymbolParser::T__3: {
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(122);
      match(CymbolParser::T__3);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(124);
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
  enterRule(_localctx, 20, CymbolParser::RuleExpressionList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(136);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CymbolParser::T__7:
      case CymbolParser::T__16:
      case CymbolParser::T__17:
      case CymbolParser::ID:
      case CymbolParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(127);
        expression();
        setState(132);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CymbolParser::T__9) {
          setState(128);
          match(CymbolParser::T__9);
          setState(129);
          expression();
          setState(134);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case CymbolParser::T__8: {
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
  enterRule(_localctx, 22, CymbolParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
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
  enterRule(_localctx, 24, CymbolParser::RuleAddExpression);
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
    setState(140);
    postfixExpression();
    setState(145);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CymbolParser::T__14) {
      setState(141);
      match(CymbolParser::T__14);
      setState(142);
      postfixExpression();
      setState(147);
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

std::vector<tree::TerminalNode *> CymbolParser::PostfixExpressionContext::ID() {
  return getTokens(CymbolParser::ID);
}

tree::TerminalNode* CymbolParser::PostfixExpressionContext::ID(size_t i) {
  return getToken(CymbolParser::ID, i);
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
  enterRule(_localctx, 26, CymbolParser::RulePostfixExpression);
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
    setState(148);
    primary();
    setState(163);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CymbolParser::T__7

    || _la == CymbolParser::T__15) {
      setState(161);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
      case 1: {
        setState(149);
        match(CymbolParser::T__15);
        setState(150);
        match(CymbolParser::ID);
        setState(151);
        match(CymbolParser::T__7);
        setState(152);
        expressionList();
        setState(153);
        match(CymbolParser::T__8);
        break;
      }

      case 2: {
        setState(155);
        match(CymbolParser::T__15);
        setState(156);
        match(CymbolParser::ID);
        break;
      }

      case 3: {
        setState(157);
        match(CymbolParser::T__7);
        setState(158);
        expressionList();
        setState(159);
        match(CymbolParser::T__8);
        break;
      }

      default:
        break;
      }
      setState(165);
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
  enterRule(_localctx, 28, CymbolParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(174);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CymbolParser::T__16: {
        enterOuterAlt(_localctx, 1);
        setState(166);
        match(CymbolParser::T__16);
        break;
      }

      case CymbolParser::T__17: {
        enterOuterAlt(_localctx, 2);
        setState(167);
        match(CymbolParser::T__17);
        break;
      }

      case CymbolParser::ID: {
        enterOuterAlt(_localctx, 3);
        setState(168);
        match(CymbolParser::ID);
        break;
      }

      case CymbolParser::INT: {
        enterOuterAlt(_localctx, 4);
        setState(169);
        match(CymbolParser::INT);
        break;
      }

      case CymbolParser::T__7: {
        enterOuterAlt(_localctx, 5);
        setState(170);
        match(CymbolParser::T__7);
        setState(171);
        expression();
        setState(172);
        match(CymbolParser::T__8);
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
