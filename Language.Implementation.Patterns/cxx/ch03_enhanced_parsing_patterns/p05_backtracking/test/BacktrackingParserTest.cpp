#include <gtest/gtest.h>

#include "BacktrackLexer.hpp"
#include "BacktrackParser.hpp"
#include "RecognitionException.hpp"

TEST(BacktrackingParserTest, testAssignement)
{
    BacktrackLexer* lexer = new BacktrackLexer("[a,b] = [c,d]");
    BacktrackParser parser{lexer};

    EXPECT_NO_THROW(parser.stat()); // begin parsing at rule 'stat'
}

TEST(BacktrackingParserTest, testList)
{
    BacktrackLexer* lexer = new BacktrackLexer("[a,b]");
    BacktrackParser parser{lexer};

    EXPECT_NO_THROW(parser.stat()); // begin parsing at rule 'stat'
}

TEST(BacktrackingParserTest, testParseError)
{
    BacktrackLexer* lexer = new BacktrackLexer("[a,b] = [c,d");
    BacktrackParser parser{lexer};

    EXPECT_THROW(parser.stat(), RecognitionException);
}
