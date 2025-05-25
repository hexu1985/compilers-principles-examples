from Token import Token
from Lexer import Lexer
from ListLexer import ListLexer

def test_lexer():
    input = "[a, b ]"
    lexer = ListLexer(input)

    expectedResult = []
    expectedResult.append(Token(Token.LBRACK, "["))
    expectedResult.append(Token(Token.NAME, "a"))
    expectedResult.append(Token(Token.COMMA, ","))
    expectedResult.append(Token(Token.NAME, "b"))
    expectedResult.append(Token(Token.RBRACK, "]"))

    actualResult = []

    t = lexer.nextToken()
    while t.type != Token.EOF_TYPE:
        actualResult.append(t)
        t = lexer.nextToken()

    assert len(expectedResult) == len(actualResult)

    for i in range(len(expectedResult)):
        assert expectedResult[i].text == actualResult[i].text
        assert expectedResult[i].type == actualResult[i].type


if __name__ == "__main__":
    test_lexer()
