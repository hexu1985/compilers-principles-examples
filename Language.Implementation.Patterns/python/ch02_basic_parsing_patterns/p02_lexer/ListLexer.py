import io
from Token import Token
from Lexer import Lexer

class ListLexer(Lexer):
    def __init__(self, input):
        super().__init__(input)

    def isLETTER(self):
        return 'a' <= self.c <= 'z' or 'A' <= self.c <= 'Z'

    def nextToken(self):
        while (self.c != Lexer.EOF):
            if self.c in [' ', '\t', '\n', '\r']:
                self.WS()
                continue
            elif self.c == ',':
                self.consume()
                return Token(Token.COMMA, ",")
            elif self.c == '[':
                self.consume()
                return Token(Token.LBRACK, "[")
            elif self.c == ']':
                self.consume()
                return Token(Token.RBRACK, "]")
            else:
                if self.isLETTER():
                    return self.NAME()
                else:
                    raise LexerError("invalid character: " + c)

        return Token(Token.EOF_TYPE, "<EOF>")

    def NAME(self):
        buf = io.StringIO()
        buf.write(self.c)
        self.consume()
        while self.isLETTER():
            buf.write(self.c)
            buf.consume()

        return Token(Token.NAME, buf.getvalue())

    def WS(self):
        while self.c in [' ', '\t', '\n', '\r']:
            self.consume()
