
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
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "ID", "LETTER", "INT", 
      "WS", "SL_COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,18,124,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,1,0,1,0,1,0,1,0,1,0,1,0,
  	1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,14,5,14,90,8,14,10,
  	14,12,14,93,9,14,1,15,1,15,1,16,4,16,98,8,16,11,16,12,16,99,1,17,4,17,
  	103,8,17,11,17,12,17,104,1,17,1,17,1,18,1,18,1,18,1,18,5,18,113,8,18,
  	10,18,12,18,116,9,18,1,18,3,18,119,8,18,1,18,1,18,1,18,1,18,0,0,19,1,
  	1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,
  	15,31,0,33,16,35,17,37,18,1,0,4,1,0,48,57,2,0,65,90,97,122,3,0,9,10,13,
  	13,32,32,2,0,10,10,13,13,128,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,
  	1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,
  	0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,
  	29,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,1,39,1,0,0,0,3,46,1,
  	0,0,0,5,48,1,0,0,0,7,50,1,0,0,0,9,52,1,0,0,0,11,54,1,0,0,0,13,56,1,0,
  	0,0,15,58,1,0,0,0,17,64,1,0,0,0,19,68,1,0,0,0,21,73,1,0,0,0,23,75,1,0,
  	0,0,25,82,1,0,0,0,27,84,1,0,0,0,29,86,1,0,0,0,31,94,1,0,0,0,33,97,1,0,
  	0,0,35,102,1,0,0,0,37,108,1,0,0,0,39,40,5,115,0,0,40,41,5,116,0,0,41,
  	42,5,114,0,0,42,43,5,117,0,0,43,44,5,99,0,0,44,45,5,116,0,0,45,2,1,0,
  	0,0,46,47,5,123,0,0,47,4,1,0,0,0,48,49,5,125,0,0,49,6,1,0,0,0,50,51,5,
  	59,0,0,51,8,1,0,0,0,52,53,5,40,0,0,53,10,1,0,0,0,54,55,5,41,0,0,55,12,
  	1,0,0,0,56,57,5,44,0,0,57,14,1,0,0,0,58,59,5,102,0,0,59,60,5,108,0,0,
  	60,61,5,111,0,0,61,62,5,97,0,0,62,63,5,116,0,0,63,16,1,0,0,0,64,65,5,
  	105,0,0,65,66,5,110,0,0,66,67,5,116,0,0,67,18,1,0,0,0,68,69,5,118,0,0,
  	69,70,5,111,0,0,70,71,5,105,0,0,71,72,5,100,0,0,72,20,1,0,0,0,73,74,5,
  	61,0,0,74,22,1,0,0,0,75,76,5,114,0,0,76,77,5,101,0,0,77,78,5,116,0,0,
  	78,79,5,117,0,0,79,80,5,114,0,0,80,81,5,110,0,0,81,24,1,0,0,0,82,83,5,
  	43,0,0,83,26,1,0,0,0,84,85,5,46,0,0,85,28,1,0,0,0,86,91,3,31,15,0,87,
  	90,3,31,15,0,88,90,7,0,0,0,89,87,1,0,0,0,89,88,1,0,0,0,90,93,1,0,0,0,
  	91,89,1,0,0,0,91,92,1,0,0,0,92,30,1,0,0,0,93,91,1,0,0,0,94,95,7,1,0,0,
  	95,32,1,0,0,0,96,98,7,0,0,0,97,96,1,0,0,0,98,99,1,0,0,0,99,97,1,0,0,0,
  	99,100,1,0,0,0,100,34,1,0,0,0,101,103,7,2,0,0,102,101,1,0,0,0,103,104,
  	1,0,0,0,104,102,1,0,0,0,104,105,1,0,0,0,105,106,1,0,0,0,106,107,6,17,
  	0,0,107,36,1,0,0,0,108,109,5,47,0,0,109,110,5,47,0,0,110,114,1,0,0,0,
  	111,113,8,3,0,0,112,111,1,0,0,0,113,116,1,0,0,0,114,112,1,0,0,0,114,115,
  	1,0,0,0,115,118,1,0,0,0,116,114,1,0,0,0,117,119,5,13,0,0,118,117,1,0,
  	0,0,118,119,1,0,0,0,119,120,1,0,0,0,120,121,5,10,0,0,121,122,1,0,0,0,
  	122,123,6,18,0,0,123,38,1,0,0,0,7,0,89,91,99,104,114,118,1,6,0,0
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
