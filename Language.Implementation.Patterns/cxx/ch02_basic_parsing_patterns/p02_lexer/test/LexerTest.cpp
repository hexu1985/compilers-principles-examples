#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "Token.hpp"
#include "ListLexer.hpp"

TEST(Lexer, nextToken)
{
    std::string input = "[a, b ]";

    ListLexer lexer{input};
    std::vector<Token> expectedResult;
    expectedResult.push_back(Token{ListLexer::T_TYPE_LBRACK, "["});
    expectedResult.push_back(Token{ListLexer::T_TYPE_NAME, "a"});
    expectedResult.push_back(Token{ListLexer::T_TYPE_COMMA, ","});
    expectedResult.push_back(Token{ListLexer::T_TYPE_NAME, "b"});
    expectedResult.push_back(Token{ListLexer::T_TYPE_RBRACK, "]"});

    std::vector<Token> actualResult;

    Token t = lexer.nextToken();
    while (t.type != ListLexer::T_TYPE_EOF) {
        actualResult.push_back(t);
        t = lexer.nextToken();
    }

    ASSERT_EQ(expectedResult.size(), actualResult.size());

    for (int i = 0; i < expectedResult.size(); ++i) {
        ASSERT_EQ(expectedResult.at(i).text, actualResult.at(i).text);
        ASSERT_EQ(expectedResult.at(i).type, actualResult.at(i).type);
    }
}
