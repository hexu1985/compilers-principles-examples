
// Generated from PropertyFile.g4 by ANTLR 4.13.0


#include "PropertyFileLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct PropertyFileLexerStaticData final {
  PropertyFileLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PropertyFileLexerStaticData(const PropertyFileLexerStaticData&) = delete;
  PropertyFileLexerStaticData(PropertyFileLexerStaticData&&) = delete;
  PropertyFileLexerStaticData& operator=(const PropertyFileLexerStaticData&) = delete;
  PropertyFileLexerStaticData& operator=(PropertyFileLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag propertyfilelexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
PropertyFileLexerStaticData *propertyfilelexerLexerStaticData = nullptr;

void propertyfilelexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (propertyfilelexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(propertyfilelexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<PropertyFileLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "ID", "STRING"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'='", "'\\n'"
    },
    std::vector<std::string>{
      "", "", "", "ID", "STRING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,4,27,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,1,0,1,1,1,1,1,2,4,2,
  	15,8,2,11,2,12,2,16,1,3,1,3,5,3,21,8,3,10,3,12,3,24,9,3,1,3,1,3,1,22,
  	0,4,1,1,3,2,5,3,7,4,1,0,1,1,0,97,122,28,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,
  	0,0,0,0,7,1,0,0,0,1,9,1,0,0,0,3,11,1,0,0,0,5,14,1,0,0,0,7,18,1,0,0,0,
  	9,10,5,61,0,0,10,2,1,0,0,0,11,12,5,10,0,0,12,4,1,0,0,0,13,15,7,0,0,0,
  	14,13,1,0,0,0,15,16,1,0,0,0,16,14,1,0,0,0,16,17,1,0,0,0,17,6,1,0,0,0,
  	18,22,5,34,0,0,19,21,9,0,0,0,20,19,1,0,0,0,21,24,1,0,0,0,22,23,1,0,0,
  	0,22,20,1,0,0,0,23,25,1,0,0,0,24,22,1,0,0,0,25,26,5,34,0,0,26,8,1,0,0,
  	0,3,0,16,22,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  propertyfilelexerLexerStaticData = staticData.release();
}

}

PropertyFileLexer::PropertyFileLexer(CharStream *input) : Lexer(input) {
  PropertyFileLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *propertyfilelexerLexerStaticData->atn, propertyfilelexerLexerStaticData->decisionToDFA, propertyfilelexerLexerStaticData->sharedContextCache);
}

PropertyFileLexer::~PropertyFileLexer() {
  delete _interpreter;
}

std::string PropertyFileLexer::getGrammarFileName() const {
  return "PropertyFile.g4";
}

const std::vector<std::string>& PropertyFileLexer::getRuleNames() const {
  return propertyfilelexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& PropertyFileLexer::getChannelNames() const {
  return propertyfilelexerLexerStaticData->channelNames;
}

const std::vector<std::string>& PropertyFileLexer::getModeNames() const {
  return propertyfilelexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& PropertyFileLexer::getVocabulary() const {
  return propertyfilelexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PropertyFileLexer::getSerializedATN() const {
  return propertyfilelexerLexerStaticData->serializedATN;
}

const atn::ATN& PropertyFileLexer::getATN() const {
  return *propertyfilelexerLexerStaticData->atn;
}




void PropertyFileLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  propertyfilelexerLexerInitialize();
#else
  ::antlr4::internal::call_once(propertyfilelexerLexerOnceFlag, propertyfilelexerLexerInitialize);
#endif
}
