
// Generated from VecMath.g4 by ANTLR 4.13.0


#include "VecMathLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct VecMathLexerStaticData final {
  VecMathLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  VecMathLexerStaticData(const VecMathLexerStaticData&) = delete;
  VecMathLexerStaticData(VecMathLexerStaticData&&) = delete;
  VecMathLexerStaticData& operator=(const VecMathLexerStaticData&) = delete;
  VecMathLexerStaticData& operator=(VecMathLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag vecmathlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
VecMathLexerStaticData *vecmathlexerLexerStaticData = nullptr;

void vecmathlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (vecmathlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(vecmathlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<VecMathLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "ID", "INT", "WS", "MULT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'='", "'print'", "'+'", "'.'", "'['", "','", "']'", "'('", "')'", 
      "", "", "", "'*'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "ID", "INT", "WS", "MULT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,13,68,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,1,0,1,0,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,
  	1,8,1,9,4,9,51,8,9,11,9,12,9,52,1,10,4,10,56,8,10,11,10,12,10,57,1,11,
  	4,11,61,8,11,11,11,12,11,62,1,11,1,11,1,12,1,12,0,0,13,1,1,3,2,5,3,7,
  	4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,1,0,1,3,0,10,10,13,
  	13,32,32,70,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,
  	0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,
  	21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,1,27,1,0,0,0,3,29,1,0,0,0,5,35,1,
  	0,0,0,7,37,1,0,0,0,9,39,1,0,0,0,11,41,1,0,0,0,13,43,1,0,0,0,15,45,1,0,
  	0,0,17,47,1,0,0,0,19,50,1,0,0,0,21,55,1,0,0,0,23,60,1,0,0,0,25,66,1,0,
  	0,0,27,28,5,61,0,0,28,2,1,0,0,0,29,30,5,112,0,0,30,31,5,114,0,0,31,32,
  	5,105,0,0,32,33,5,110,0,0,33,34,5,116,0,0,34,4,1,0,0,0,35,36,5,43,0,0,
  	36,6,1,0,0,0,37,38,5,46,0,0,38,8,1,0,0,0,39,40,5,91,0,0,40,10,1,0,0,0,
  	41,42,5,44,0,0,42,12,1,0,0,0,43,44,5,93,0,0,44,14,1,0,0,0,45,46,5,40,
  	0,0,46,16,1,0,0,0,47,48,5,41,0,0,48,18,1,0,0,0,49,51,2,97,122,0,50,49,
  	1,0,0,0,51,52,1,0,0,0,52,50,1,0,0,0,52,53,1,0,0,0,53,20,1,0,0,0,54,56,
  	2,48,57,0,55,54,1,0,0,0,56,57,1,0,0,0,57,55,1,0,0,0,57,58,1,0,0,0,58,
  	22,1,0,0,0,59,61,7,0,0,0,60,59,1,0,0,0,61,62,1,0,0,0,62,60,1,0,0,0,62,
  	63,1,0,0,0,63,64,1,0,0,0,64,65,6,11,0,0,65,24,1,0,0,0,66,67,5,42,0,0,
  	67,26,1,0,0,0,4,0,52,57,62,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  vecmathlexerLexerStaticData = staticData.release();
}

}

VecMathLexer::VecMathLexer(CharStream *input) : Lexer(input) {
  VecMathLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *vecmathlexerLexerStaticData->atn, vecmathlexerLexerStaticData->decisionToDFA, vecmathlexerLexerStaticData->sharedContextCache);
}

VecMathLexer::~VecMathLexer() {
  delete _interpreter;
}

std::string VecMathLexer::getGrammarFileName() const {
  return "VecMath.g4";
}

const std::vector<std::string>& VecMathLexer::getRuleNames() const {
  return vecmathlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& VecMathLexer::getChannelNames() const {
  return vecmathlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& VecMathLexer::getModeNames() const {
  return vecmathlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& VecMathLexer::getVocabulary() const {
  return vecmathlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView VecMathLexer::getSerializedATN() const {
  return vecmathlexerLexerStaticData->serializedATN;
}

const atn::ATN& VecMathLexer::getATN() const {
  return *vecmathlexerLexerStaticData->atn;
}




void VecMathLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  vecmathlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(vecmathlexerLexerOnceFlag, vecmathlexerLexerInitialize);
#endif
}
