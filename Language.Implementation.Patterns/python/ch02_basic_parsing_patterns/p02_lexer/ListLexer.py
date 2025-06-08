import io
from Token import Token
from Lexer import Lexer
from Lexer import LexerError

class ListLexer(Lexer):
    T_TYPE_EOF = 1
    T_TYPE_NAME = 2
    T_TYPE_COMMA = 3
    T_TYPE_LBRACK = 4
    T_TYPE_RBRACK = 5
    tokenNames = ["n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBRACK"]

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
                return Token(ListLexer.T_TYPE_COMMA, ",")
            elif self.c == '[':
                self.consume()
                return Token(ListLexer.T_TYPE_LBRACK, "[")
            elif self.c == ']':
                self.consume()
                return Token(ListLexer.T_TYPE_RBRACK, "]")
            else:
                if self.isLETTER():
                    return self.NAME()
                else:
                    raise LexerError("invalid character: " + c)

        return Token(ListLexer.T_TYPE_EOF, "<EOF>")

    def NAME(self):
        buf = io.StringIO()
        buf.write(self.c)
        self.consume()
        while self.isLETTER():
            buf.write(self.c)
            buf.consume()

        return Token(ListLexer.T_TYPE_NAME, buf.getvalue())

    def WS(self):
        while self.c in [' ', '\t', '\n', '\r']:
            self.consume()
