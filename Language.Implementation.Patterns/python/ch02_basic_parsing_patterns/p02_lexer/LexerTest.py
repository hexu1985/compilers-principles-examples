from Token import Token
from Lexer import Lexer
from ListLexer import ListLexer

def test_lexer():
    input = "[a, b ]"
    lexer = ListLexer(input)

    expectedResult = []
    expectedResult.append(Token(ListLexer.T_TYPE_LBRACK, "["))
    expectedResult.append(Token(ListLexer.T_TYPE_NAME, "a"))
    expectedResult.append(Token(ListLexer.T_TYPE_COMMA, ","))
    expectedResult.append(Token(ListLexer.T_TYPE_NAME, "b"))
    expectedResult.append(Token(ListLexer.T_TYPE_RBRACK, "]"))

    actualResult = []

    t = lexer.nextToken()
    while t.type != ListLexer.T_TYPE_EOF:
        actualResult.append(t)
        t = lexer.nextToken()

    assert len(expectedResult) == len(actualResult)

    for i in range(len(expectedResult)):
        assert expectedResult[i].text == actualResult[i].text
        assert expectedResult[i].type == actualResult[i].type


if __name__ == "__main__":
    test_lexer()
