#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "Token.hpp"
#include "ListLexer.hpp"
#include "ListParser.hpp"

TEST(RecursiveDescentTest, testOk)
{
    ListLexer* lexer = new ListLexer("[a,b]");
    ListParser parser{lexer};

    // no throw
    parser.list();
}

TEST(RecursiveDescentTest, testFail)
{
    ListLexer* lexer = new ListLexer("[a,]");
    ListParser parser{lexer};

    EXPECT_THROW(parser.list(), ParserError);
}

