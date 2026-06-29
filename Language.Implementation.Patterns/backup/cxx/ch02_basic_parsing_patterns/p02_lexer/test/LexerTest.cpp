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
    expectedResult.push_back(Token{ListLexer::LBRACK, "["});
    expectedResult.push_back(Token{ListLexer::NAME, "a"});
    expectedResult.push_back(Token{ListLexer::COMMA, ","});
    expectedResult.push_back(Token{ListLexer::NAME, "b"});
    expectedResult.push_back(Token{ListLexer::RBRACK, "]"});

    std::vector<Token> actualResult;

    Token t = lexer.nextToken();
    while (t.type != Lexer::EOF_TYPE) {
        actualResult.push_back(t);
        t = lexer.nextToken();
    }

    ASSERT_EQ(expectedResult.size(), actualResult.size());

    for (int i = 0; i < expectedResult.size(); ++i) {
        ASSERT_EQ(expectedResult.at(i).text, actualResult.at(i).text);
        ASSERT_EQ(expectedResult.at(i).type, actualResult.at(i).type);
    }
}
