
// Generated from Cymbol.g4 by ANTLR 4.13.0


#include "CymbolLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct CymbolLexerStaticData final {
  CymbolLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CymbolLexerStaticData(const CymbolLexerStaticData&) = delete;
  CymbolLexerStaticData(CymbolLexerStaticData&&) = delete;
  CymbolLexerStaticData& operator=(const CymbolLexerStaticData&) = delete;
  CymbolLexerStaticData& operator=(CymbolLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag cymbollexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
CymbolLexerStaticData *cymbollexerLexerStaticData = nullptr;

void cymbollexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (cymbollexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(cymbollexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CymbolLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "ID", "LETTER", 
      "INT", "WS", "SL_COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'float'", "'int'", "'='", "';'", "'+'", "'('", "')'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "ID", "INT", "WS", "SL_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,11,78,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,1,0,1,0,1,0,1,0,
  	1,1,1,1,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,7,5,
  	7,49,8,7,10,7,12,7,52,9,7,1,8,1,8,1,9,4,9,57,8,9,11,9,12,9,58,1,10,4,
  	10,62,8,10,11,10,12,10,63,1,10,1,10,1,11,1,11,1,11,1,11,5,11,72,8,11,
  	10,11,12,11,75,9,11,1,11,1,11,0,0,12,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,
  	8,17,0,19,9,21,10,23,11,1,0,4,1,0,48,57,2,0,65,90,97,122,3,0,9,10,13,
  	13,32,32,2,0,10,10,13,13,81,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,
  	0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,19,1,0,0,0,
  	0,21,1,0,0,0,0,23,1,0,0,0,1,25,1,0,0,0,3,31,1,0,0,0,5,35,1,0,0,0,7,37,
  	1,0,0,0,9,39,1,0,0,0,11,41,1,0,0,0,13,43,1,0,0,0,15,45,1,0,0,0,17,53,
  	1,0,0,0,19,56,1,0,0,0,21,61,1,0,0,0,23,67,1,0,0,0,25,26,5,102,0,0,26,
  	27,5,108,0,0,27,28,5,111,0,0,28,29,5,97,0,0,29,30,5,116,0,0,30,2,1,0,
  	0,0,31,32,5,105,0,0,32,33,5,110,0,0,33,34,5,116,0,0,34,4,1,0,0,0,35,36,
  	5,61,0,0,36,6,1,0,0,0,37,38,5,59,0,0,38,8,1,0,0,0,39,40,5,43,0,0,40,10,
  	1,0,0,0,41,42,5,40,0,0,42,12,1,0,0,0,43,44,5,41,0,0,44,14,1,0,0,0,45,
  	50,3,17,8,0,46,49,3,17,8,0,47,49,7,0,0,0,48,46,1,0,0,0,48,47,1,0,0,0,
  	49,52,1,0,0,0,50,48,1,0,0,0,50,51,1,0,0,0,51,16,1,0,0,0,52,50,1,0,0,0,
  	53,54,7,1,0,0,54,18,1,0,0,0,55,57,7,0,0,0,56,55,1,0,0,0,57,58,1,0,0,0,
  	58,56,1,0,0,0,58,59,1,0,0,0,59,20,1,0,0,0,60,62,7,2,0,0,61,60,1,0,0,0,
  	62,63,1,0,0,0,63,61,1,0,0,0,63,64,1,0,0,0,64,65,1,0,0,0,65,66,6,10,0,
  	0,66,22,1,0,0,0,67,68,5,47,0,0,68,69,5,47,0,0,69,73,1,0,0,0,70,72,8,3,
  	0,0,71,70,1,0,0,0,72,75,1,0,0,0,73,71,1,0,0,0,73,74,1,0,0,0,74,76,1,0,
  	0,0,75,73,1,0,0,0,76,77,6,11,0,0,77,24,1,0,0,0,6,0,48,50,58,63,73,1,6,
  	0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  cymbollexerLexerStaticData = staticData.release();
}

}

CymbolLexer::CymbolLexer(CharStream *input) : Lexer(input) {
  CymbolLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *cymbollexerLexerStaticData->atn, cymbollexerLexerStaticData->decisionToDFA, cymbollexerLexerStaticData->sharedContextCache);
}

CymbolLexer::~CymbolLexer() {
  delete _interpreter;
}

std::string CymbolLexer::getGrammarFileName() const {
  return "Cymbol.g4";
}

const std::vector<std::string>& CymbolLexer::getRuleNames() const {
  return cymbollexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& CymbolLexer::getChannelNames() const {
  return cymbollexerLexerStaticData->channelNames;
}

const std::vector<std::string>& CymbolLexer::getModeNames() const {
  return cymbollexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& CymbolLexer::getVocabulary() const {
  return cymbollexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CymbolLexer::getSerializedATN() const {
  return cymbollexerLexerStaticData->serializedATN;
}

const atn::ATN& CymbolLexer::getATN() const {
  return *cymbollexerLexerStaticData->atn;
}




void CymbolLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  cymbollexerLexerInitialize();
#else
  ::antlr4::internal::call_once(cymbollexerLexerOnceFlag, cymbollexerLexerInitialize);
#endif
}
