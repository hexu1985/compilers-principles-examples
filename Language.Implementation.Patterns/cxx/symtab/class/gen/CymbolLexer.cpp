
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
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
      "T__17", "ID", "LETTER", "INT", "WS", "SL_COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,22,151,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,
  	4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,
  	10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,15,1,15,1,16,1,16,1,16,1,
  	16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,1,18,1,18,1,18,5,18,117,8,18,10,
  	18,12,18,120,9,18,1,19,1,19,1,20,4,20,125,8,20,11,20,12,20,126,1,21,4,
  	21,130,8,21,11,21,12,21,131,1,21,1,21,1,22,1,22,1,22,1,22,5,22,140,8,
  	22,10,22,12,22,143,9,22,1,22,3,22,146,8,22,1,22,1,22,1,22,1,22,0,0,23,
  	1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,
  	29,15,31,16,33,17,35,18,37,19,39,0,41,20,43,21,45,22,1,0,4,1,0,48,57,
  	2,0,65,90,97,122,3,0,9,10,13,13,32,32,2,0,10,10,13,13,155,0,1,1,0,0,0,
  	0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,
  	0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,
  	0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,
  	1,0,0,0,0,37,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,1,47,1,0,
  	0,0,3,53,1,0,0,0,5,55,1,0,0,0,7,57,1,0,0,0,9,59,1,0,0,0,11,61,1,0,0,0,
  	13,68,1,0,0,0,15,70,1,0,0,0,17,72,1,0,0,0,19,74,1,0,0,0,21,76,1,0,0,0,
  	23,82,1,0,0,0,25,86,1,0,0,0,27,91,1,0,0,0,29,98,1,0,0,0,31,100,1,0,0,
  	0,33,102,1,0,0,0,35,107,1,0,0,0,37,113,1,0,0,0,39,121,1,0,0,0,41,124,
  	1,0,0,0,43,129,1,0,0,0,45,135,1,0,0,0,47,48,5,99,0,0,48,49,5,108,0,0,
  	49,50,5,97,0,0,50,51,5,115,0,0,51,52,5,115,0,0,52,2,1,0,0,0,53,54,5,123,
  	0,0,54,4,1,0,0,0,55,56,5,125,0,0,56,6,1,0,0,0,57,58,5,59,0,0,58,8,1,0,
  	0,0,59,60,5,58,0,0,60,10,1,0,0,0,61,62,5,112,0,0,62,63,5,117,0,0,63,64,
  	5,98,0,0,64,65,5,108,0,0,65,66,5,105,0,0,66,67,5,99,0,0,67,12,1,0,0,0,
  	68,69,5,61,0,0,69,14,1,0,0,0,70,71,5,40,0,0,71,16,1,0,0,0,72,73,5,41,
  	0,0,73,18,1,0,0,0,74,75,5,44,0,0,75,20,1,0,0,0,76,77,5,102,0,0,77,78,
  	5,108,0,0,78,79,5,111,0,0,79,80,5,97,0,0,80,81,5,116,0,0,81,22,1,0,0,
  	0,82,83,5,105,0,0,83,84,5,110,0,0,84,85,5,116,0,0,85,24,1,0,0,0,86,87,
  	5,118,0,0,87,88,5,111,0,0,88,89,5,105,0,0,89,90,5,100,0,0,90,26,1,0,0,
  	0,91,92,5,114,0,0,92,93,5,101,0,0,93,94,5,116,0,0,94,95,5,117,0,0,95,
  	96,5,114,0,0,96,97,5,110,0,0,97,28,1,0,0,0,98,99,5,43,0,0,99,30,1,0,0,
  	0,100,101,5,46,0,0,101,32,1,0,0,0,102,103,5,116,0,0,103,104,5,104,0,0,
  	104,105,5,105,0,0,105,106,5,115,0,0,106,34,1,0,0,0,107,108,5,115,0,0,
  	108,109,5,117,0,0,109,110,5,112,0,0,110,111,5,101,0,0,111,112,5,114,0,
  	0,112,36,1,0,0,0,113,118,3,39,19,0,114,117,3,39,19,0,115,117,7,0,0,0,
  	116,114,1,0,0,0,116,115,1,0,0,0,117,120,1,0,0,0,118,116,1,0,0,0,118,119,
  	1,0,0,0,119,38,1,0,0,0,120,118,1,0,0,0,121,122,7,1,0,0,122,40,1,0,0,0,
  	123,125,7,0,0,0,124,123,1,0,0,0,125,126,1,0,0,0,126,124,1,0,0,0,126,127,
  	1,0,0,0,127,42,1,0,0,0,128,130,7,2,0,0,129,128,1,0,0,0,130,131,1,0,0,
  	0,131,129,1,0,0,0,131,132,1,0,0,0,132,133,1,0,0,0,133,134,6,21,0,0,134,
  	44,1,0,0,0,135,136,5,47,0,0,136,137,5,47,0,0,137,141,1,0,0,0,138,140,
  	8,3,0,0,139,138,1,0,0,0,140,143,1,0,0,0,141,139,1,0,0,0,141,142,1,0,0,
  	0,142,145,1,0,0,0,143,141,1,0,0,0,144,146,5,13,0,0,145,144,1,0,0,0,145,
  	146,1,0,0,0,146,147,1,0,0,0,147,148,5,10,0,0,148,149,1,0,0,0,149,150,
  	6,22,0,0,150,46,1,0,0,0,7,0,116,118,126,131,141,145,1,6,0,0
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
