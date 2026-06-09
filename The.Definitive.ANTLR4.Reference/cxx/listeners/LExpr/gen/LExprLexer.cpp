
// Generated from LExpr.g4 by ANTLR 4.13.0


#include "LExprLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct LExprLexerStaticData final {
  LExprLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LExprLexerStaticData(const LExprLexerStaticData&) = delete;
  LExprLexerStaticData(LExprLexerStaticData&&) = delete;
  LExprLexerStaticData& operator=(const LExprLexerStaticData&) = delete;
  LExprLexerStaticData& operator=(LExprLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag lexprlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
LExprLexerStaticData *lexprlexerLexerStaticData = nullptr;

void lexprlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (lexprlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(lexprlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LExprLexerStaticData>(
    std::vector<std::string>{
      "MULT", "ADD", "INT", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'*'", "'+'"
    },
    std::vector<std::string>{
      "", "MULT", "ADD", "INT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,4,25,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,1,0,1,1,1,1,1,2,4,2,
  	15,8,2,11,2,12,2,16,1,3,4,3,20,8,3,11,3,12,3,21,1,3,1,3,0,0,4,1,1,3,2,
  	5,3,7,4,1,0,2,1,0,48,57,2,0,9,10,32,32,26,0,1,1,0,0,0,0,3,1,0,0,0,0,5,
  	1,0,0,0,0,7,1,0,0,0,1,9,1,0,0,0,3,11,1,0,0,0,5,14,1,0,0,0,7,19,1,0,0,
  	0,9,10,5,42,0,0,10,2,1,0,0,0,11,12,5,43,0,0,12,4,1,0,0,0,13,15,7,0,0,
  	0,14,13,1,0,0,0,15,16,1,0,0,0,16,14,1,0,0,0,16,17,1,0,0,0,17,6,1,0,0,
  	0,18,20,7,1,0,0,19,18,1,0,0,0,20,21,1,0,0,0,21,19,1,0,0,0,21,22,1,0,0,
  	0,22,23,1,0,0,0,23,24,6,3,0,0,24,8,1,0,0,0,3,0,16,21,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  lexprlexerLexerStaticData = staticData.release();
}

}

LExprLexer::LExprLexer(CharStream *input) : Lexer(input) {
  LExprLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *lexprlexerLexerStaticData->atn, lexprlexerLexerStaticData->decisionToDFA, lexprlexerLexerStaticData->sharedContextCache);
}

LExprLexer::~LExprLexer() {
  delete _interpreter;
}

std::string LExprLexer::getGrammarFileName() const {
  return "LExpr.g4";
}

const std::vector<std::string>& LExprLexer::getRuleNames() const {
  return lexprlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& LExprLexer::getChannelNames() const {
  return lexprlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& LExprLexer::getModeNames() const {
  return lexprlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& LExprLexer::getVocabulary() const {
  return lexprlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView LExprLexer::getSerializedATN() const {
  return lexprlexerLexerStaticData->serializedATN;
}

const atn::ATN& LExprLexer::getATN() const {
  return *lexprlexerLexerStaticData->atn;
}




void LExprLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  lexprlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(lexprlexerLexerOnceFlag, lexprlexerLexerInitialize);
#endif
}
