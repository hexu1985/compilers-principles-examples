#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "Token.hpp"
#include "LookaheadLexer.hpp"
#include "LookaheadParser.hpp"

TEST(RecursiveDescentTest, testOk)
{
    LookaheadLexer* lexer = new LookaheadLexer("[a,b=c,[d,e]]");
    LookaheadParser parser(lexer, 2);

    // no throw
    parser.list();
}

TEST(RecursiveDescentTest, testFail)
{
    LookaheadLexer* lexer = new LookaheadLexer("[a,b=c,,[d,e]]");
    LookaheadParser parser(lexer, 2);

    EXPECT_THROW(parser.list(), ParserError);
}

