from abc import ABC, abstractmethod

class LexerError(Exception):
    pass

class Lexer(ABC):
    EOF = -1

    def __init__(self, input):
        self.input = input
        self.p = 0
        self.c = self.input[self.p] # prime lookahead

    def consume(self):
        self.p += 1
        if self.p >= len(self.input):
            self.c = Lexer.EOF
        else:
            self.c = self.input[self.p]

    def match(self, x):
        if self.c == x:
            self.consume()
        else:
            raise LexerError("expecting " + x + "; found " + self.c)

    @abstractmethod
    def nextToken(self):
        pass

