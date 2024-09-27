
// Generated from ./SysYLexer.g4 by ANTLR 4.13.0


#include "SysYLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct SysYLexerStaticData final {
  SysYLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SysYLexerStaticData(const SysYLexerStaticData&) = delete;
  SysYLexerStaticData(SysYLexerStaticData&&) = delete;
  SysYLexerStaticData& operator=(const SysYLexerStaticData&) = delete;
  SysYLexerStaticData& operator=(SysYLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag sysylexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
SysYLexerStaticData *sysylexerLexerStaticData = nullptr;

void sysylexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (sysylexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(sysylexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<SysYLexerStaticData>(
    std::vector<std::string>{
      "CONST", "INT", "VOID", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", 
      "RETURN", "PLUS", "MINUS", "MUL", "DIV", "MOD", "ASSIGN", "EQ", "NEQ", 
      "LT", "GT", "LE", "GE", "NOT", "AND", "OR", "L_PAREN", "R_PAREN", 
      "L_BRACE", "R_BRACE", "L_BRACKT", "R_BRACKT", "COMMA", "SEMICOLON", 
      "IDENT", "INTEGER_CONST", "WS", "LINE_COMMENT", "MULTLINE_COMMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'const'", "'int'", "'void'", "'if'", "'else'", "'while'", "'break'", 
      "'continue'", "'return'", "'+'", "'-'", "'*'", "'/'", "'%'", "'='", 
      "'=='", "'!='", "'<'", "'>'", "'<='", "'>='", "'!'", "'&&'", "'||'", 
      "'('", "')'", "'{'", "'}'", "'['", "']'", "','", "';'"
    },
    std::vector<std::string>{
      "", "CONST", "INT", "VOID", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", 
      "RETURN", "PLUS", "MINUS", "MUL", "DIV", "MOD", "ASSIGN", "EQ", "NEQ", 
      "LT", "GT", "LE", "GE", "NOT", "AND", "OR", "L_PAREN", "R_PAREN", 
      "L_BRACE", "R_BRACE", "L_BRACKT", "R_BRACKT", "COMMA", "SEMICOLON", 
      "IDENT", "INTEGER_CONST", "WS", "LINE_COMMENT", "MULTLINE_COMMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,37,243,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,
  	2,1,2,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,
  	8,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,
  	15,1,15,1,15,1,16,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,19,1,20,1,
  	20,1,20,1,21,1,21,1,22,1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,25,1,25,1,
  	26,1,26,1,27,1,27,1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,1,32,1,32,5,
  	32,181,8,32,10,32,12,32,184,9,32,1,33,1,33,1,33,5,33,189,8,33,10,33,12,
  	33,192,9,33,1,33,1,33,4,33,196,8,33,11,33,12,33,197,1,33,1,33,1,33,1,
  	33,4,33,204,8,33,11,33,12,33,205,3,33,208,8,33,1,34,4,34,211,8,34,11,
  	34,12,34,212,1,34,1,34,1,35,1,35,1,35,1,35,5,35,221,8,35,10,35,12,35,
  	224,9,35,1,35,1,35,1,35,1,35,1,36,1,36,1,36,1,36,5,36,234,8,36,10,36,
  	12,36,237,9,36,1,36,1,36,1,36,1,36,1,36,2,222,235,0,37,1,1,3,2,5,3,7,
  	4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,
  	17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,
  	57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,36,73,37,1,0,7,3,0,65,90,
  	95,95,97,122,4,0,48,57,65,90,95,95,97,122,1,0,49,57,1,0,48,57,1,0,48,
  	55,3,0,48,57,65,70,97,102,3,0,9,10,13,13,32,32,252,0,1,1,0,0,0,0,3,1,
  	0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,
  	15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,
  	0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,
  	0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,
  	47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,
  	0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,
  	0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,1,75,1,0,0,0,3,81,1,0,0,0,5,
  	85,1,0,0,0,7,90,1,0,0,0,9,93,1,0,0,0,11,98,1,0,0,0,13,104,1,0,0,0,15,
  	110,1,0,0,0,17,119,1,0,0,0,19,126,1,0,0,0,21,128,1,0,0,0,23,130,1,0,0,
  	0,25,132,1,0,0,0,27,134,1,0,0,0,29,136,1,0,0,0,31,138,1,0,0,0,33,141,
  	1,0,0,0,35,144,1,0,0,0,37,146,1,0,0,0,39,148,1,0,0,0,41,151,1,0,0,0,43,
  	154,1,0,0,0,45,156,1,0,0,0,47,159,1,0,0,0,49,162,1,0,0,0,51,164,1,0,0,
  	0,53,166,1,0,0,0,55,168,1,0,0,0,57,170,1,0,0,0,59,172,1,0,0,0,61,174,
  	1,0,0,0,63,176,1,0,0,0,65,178,1,0,0,0,67,207,1,0,0,0,69,210,1,0,0,0,71,
  	216,1,0,0,0,73,229,1,0,0,0,75,76,5,99,0,0,76,77,5,111,0,0,77,78,5,110,
  	0,0,78,79,5,115,0,0,79,80,5,116,0,0,80,2,1,0,0,0,81,82,5,105,0,0,82,83,
  	5,110,0,0,83,84,5,116,0,0,84,4,1,0,0,0,85,86,5,118,0,0,86,87,5,111,0,
  	0,87,88,5,105,0,0,88,89,5,100,0,0,89,6,1,0,0,0,90,91,5,105,0,0,91,92,
  	5,102,0,0,92,8,1,0,0,0,93,94,5,101,0,0,94,95,5,108,0,0,95,96,5,115,0,
  	0,96,97,5,101,0,0,97,10,1,0,0,0,98,99,5,119,0,0,99,100,5,104,0,0,100,
  	101,5,105,0,0,101,102,5,108,0,0,102,103,5,101,0,0,103,12,1,0,0,0,104,
  	105,5,98,0,0,105,106,5,114,0,0,106,107,5,101,0,0,107,108,5,97,0,0,108,
  	109,5,107,0,0,109,14,1,0,0,0,110,111,5,99,0,0,111,112,5,111,0,0,112,113,
  	5,110,0,0,113,114,5,116,0,0,114,115,5,105,0,0,115,116,5,110,0,0,116,117,
  	5,117,0,0,117,118,5,101,0,0,118,16,1,0,0,0,119,120,5,114,0,0,120,121,
  	5,101,0,0,121,122,5,116,0,0,122,123,5,117,0,0,123,124,5,114,0,0,124,125,
  	5,110,0,0,125,18,1,0,0,0,126,127,5,43,0,0,127,20,1,0,0,0,128,129,5,45,
  	0,0,129,22,1,0,0,0,130,131,5,42,0,0,131,24,1,0,0,0,132,133,5,47,0,0,133,
  	26,1,0,0,0,134,135,5,37,0,0,135,28,1,0,0,0,136,137,5,61,0,0,137,30,1,
  	0,0,0,138,139,5,61,0,0,139,140,5,61,0,0,140,32,1,0,0,0,141,142,5,33,0,
  	0,142,143,5,61,0,0,143,34,1,0,0,0,144,145,5,60,0,0,145,36,1,0,0,0,146,
  	147,5,62,0,0,147,38,1,0,0,0,148,149,5,60,0,0,149,150,5,61,0,0,150,40,
  	1,0,0,0,151,152,5,62,0,0,152,153,5,61,0,0,153,42,1,0,0,0,154,155,5,33,
  	0,0,155,44,1,0,0,0,156,157,5,38,0,0,157,158,5,38,0,0,158,46,1,0,0,0,159,
  	160,5,124,0,0,160,161,5,124,0,0,161,48,1,0,0,0,162,163,5,40,0,0,163,50,
  	1,0,0,0,164,165,5,41,0,0,165,52,1,0,0,0,166,167,5,123,0,0,167,54,1,0,
  	0,0,168,169,5,125,0,0,169,56,1,0,0,0,170,171,5,91,0,0,171,58,1,0,0,0,
  	172,173,5,93,0,0,173,60,1,0,0,0,174,175,5,44,0,0,175,62,1,0,0,0,176,177,
  	5,59,0,0,177,64,1,0,0,0,178,182,7,0,0,0,179,181,7,1,0,0,180,179,1,0,0,
  	0,181,184,1,0,0,0,182,180,1,0,0,0,182,183,1,0,0,0,183,66,1,0,0,0,184,
  	182,1,0,0,0,185,208,5,48,0,0,186,190,7,2,0,0,187,189,7,3,0,0,188,187,
  	1,0,0,0,189,192,1,0,0,0,190,188,1,0,0,0,190,191,1,0,0,0,191,208,1,0,0,
  	0,192,190,1,0,0,0,193,195,5,48,0,0,194,196,7,4,0,0,195,194,1,0,0,0,196,
  	197,1,0,0,0,197,195,1,0,0,0,197,198,1,0,0,0,198,208,1,0,0,0,199,200,5,
  	48,0,0,200,201,5,120,0,0,201,203,1,0,0,0,202,204,7,5,0,0,203,202,1,0,
  	0,0,204,205,1,0,0,0,205,203,1,0,0,0,205,206,1,0,0,0,206,208,1,0,0,0,207,
  	185,1,0,0,0,207,186,1,0,0,0,207,193,1,0,0,0,207,199,1,0,0,0,208,68,1,
  	0,0,0,209,211,7,6,0,0,210,209,1,0,0,0,211,212,1,0,0,0,212,210,1,0,0,0,
  	212,213,1,0,0,0,213,214,1,0,0,0,214,215,6,34,0,0,215,70,1,0,0,0,216,217,
  	5,47,0,0,217,218,5,47,0,0,218,222,1,0,0,0,219,221,9,0,0,0,220,219,1,0,
  	0,0,221,224,1,0,0,0,222,223,1,0,0,0,222,220,1,0,0,0,223,225,1,0,0,0,224,
  	222,1,0,0,0,225,226,5,10,0,0,226,227,1,0,0,0,227,228,6,35,0,0,228,72,
  	1,0,0,0,229,230,5,47,0,0,230,231,5,42,0,0,231,235,1,0,0,0,232,234,9,0,
  	0,0,233,232,1,0,0,0,234,237,1,0,0,0,235,236,1,0,0,0,235,233,1,0,0,0,236,
  	238,1,0,0,0,237,235,1,0,0,0,238,239,5,42,0,0,239,240,5,47,0,0,240,241,
  	1,0,0,0,241,242,6,36,0,0,242,74,1,0,0,0,9,0,182,190,197,205,207,212,222,
  	235,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  sysylexerLexerStaticData = staticData.release();
}

}

SysYLexer::SysYLexer(CharStream *input) : Lexer(input) {
  SysYLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *sysylexerLexerStaticData->atn, sysylexerLexerStaticData->decisionToDFA, sysylexerLexerStaticData->sharedContextCache);
}

SysYLexer::~SysYLexer() {
  delete _interpreter;
}

std::string SysYLexer::getGrammarFileName() const {
  return "SysYLexer.g4";
}

const std::vector<std::string>& SysYLexer::getRuleNames() const {
  return sysylexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& SysYLexer::getChannelNames() const {
  return sysylexerLexerStaticData->channelNames;
}

const std::vector<std::string>& SysYLexer::getModeNames() const {
  return sysylexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& SysYLexer::getVocabulary() const {
  return sysylexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SysYLexer::getSerializedATN() const {
  return sysylexerLexerStaticData->serializedATN;
}

const atn::ATN& SysYLexer::getATN() const {
  return *sysylexerLexerStaticData->atn;
}




void SysYLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  sysylexerLexerInitialize();
#else
  ::antlr4::internal::call_once(sysylexerLexerOnceFlag, sysylexerLexerInitialize);
#endif
}
