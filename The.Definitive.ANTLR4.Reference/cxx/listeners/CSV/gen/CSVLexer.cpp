
// Generated from CSV.g4 by ANTLR 4.13.0


#include "CSVLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct CSVLexerStaticData final {
  CSVLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CSVLexerStaticData(const CSVLexerStaticData&) = delete;
  CSVLexerStaticData(CSVLexerStaticData&&) = delete;
  CSVLexerStaticData& operator=(const CSVLexerStaticData&) = delete;
  CSVLexerStaticData& operator=(CSVLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag csvlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
CSVLexerStaticData *csvlexerLexerStaticData = nullptr;

void csvlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (csvlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(csvlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CSVLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "TEXT", "STRING"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "','", "'\\r'", "'\\n'"
    },
    std::vector<std::string>{
      "", "", "", "", "TEXT", "STRING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,5,33,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,1,0,1,0,1,1,1,1,
  	1,2,1,2,1,3,4,3,19,8,3,11,3,12,3,20,1,4,1,4,1,4,1,4,5,4,27,8,4,10,4,12,
  	4,30,9,4,1,4,1,4,0,0,5,1,1,3,2,5,3,7,4,9,5,1,0,2,4,0,10,10,13,13,34,34,
  	44,44,1,0,34,34,35,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,
  	9,1,0,0,0,1,11,1,0,0,0,3,13,1,0,0,0,5,15,1,0,0,0,7,18,1,0,0,0,9,22,1,
  	0,0,0,11,12,5,44,0,0,12,2,1,0,0,0,13,14,5,13,0,0,14,4,1,0,0,0,15,16,5,
  	10,0,0,16,6,1,0,0,0,17,19,8,0,0,0,18,17,1,0,0,0,19,20,1,0,0,0,20,18,1,
  	0,0,0,20,21,1,0,0,0,21,8,1,0,0,0,22,28,5,34,0,0,23,24,5,34,0,0,24,27,
  	5,34,0,0,25,27,8,1,0,0,26,23,1,0,0,0,26,25,1,0,0,0,27,30,1,0,0,0,28,26,
  	1,0,0,0,28,29,1,0,0,0,29,31,1,0,0,0,30,28,1,0,0,0,31,32,5,34,0,0,32,10,
  	1,0,0,0,4,0,20,26,28,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  csvlexerLexerStaticData = staticData.release();
}

}

CSVLexer::CSVLexer(CharStream *input) : Lexer(input) {
  CSVLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *csvlexerLexerStaticData->atn, csvlexerLexerStaticData->decisionToDFA, csvlexerLexerStaticData->sharedContextCache);
}

CSVLexer::~CSVLexer() {
  delete _interpreter;
}

std::string CSVLexer::getGrammarFileName() const {
  return "CSV.g4";
}

const std::vector<std::string>& CSVLexer::getRuleNames() const {
  return csvlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& CSVLexer::getChannelNames() const {
  return csvlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& CSVLexer::getModeNames() const {
  return csvlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& CSVLexer::getVocabulary() const {
  return csvlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CSVLexer::getSerializedATN() const {
  return csvlexerLexerStaticData->serializedATN;
}

const atn::ATN& CSVLexer::getATN() const {
  return *csvlexerLexerStaticData->atn;
}




void CSVLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  csvlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(csvlexerLexerOnceFlag, csvlexerLexerInitialize);
#endif
}
