import ply.lex as lex
from collections import deque 
import warnings

from stone.Token import Token
from stone.ParseException import ParseException

class NumToken(Token):
    def __init__(self, line, v):
        super().__init__(line)
        self.value = v

    def isNumber(self):
        return True

    def getText(self):
        return str(self.value)

    def getNumber(self):
        return self.value


class IdToken(Token):
    def __init__(self, line, id_):
        super().__init__(line)
        self.text = id_

    def isIdentifier(self):
        return True

    def getText(self):
        return self.text


class StrToken(Token):
    def __init__(self, line, str_):
        super().__init__(line)
        self.literal = str_

    def isString(self):
        return True

    def getText(self):
        return self.literal


class Lexer:
    # List of token names.   This is always required
    tokens = (
            'NUMBER',
            'STRING',
            'IDENTIFIER',
            'comment',
            'newline',
            )

    def t_comment(self, t):
        r'//.*'
        pass

    # A regular expression rule with some action code
    # Note addition of self parameter since we're in a class
    def t_NUMBER(self, t):
        r'[0-9]+'
        t.value = int(t.value)
        return t

    def t_STRING(self, t):
        r'"(\\"|\\\\|\\n|[^"])*"'
        t.value = t.value.strip('"')
        return t

    def t_IDENTIFIER(self, t):
        r'[A-Z_a-z][A-Z_a-z0-9]*|==|<=|>=|&&|\|\||[!"#$%&\'()*+,-./:;<=>?@[\\\]^_`{|}~]'
        return t

    # Define a rule so we can track line numbers
    def t_newline(self,t):
        r'\n'
        t.lexer.lineno += 1
        return t

    # A string containing ignored characters (spaces and tabs)
    t_ignore = ' \t'

    # Error handling rule
    def t_error(self,t):
        print("Illegal character '%s'" % t.value[0])
        raise ParseException("bad token at line " + str(t.lineno))
        #t.lexer.skip(1)

    # Build the lexer
    def __init__(self, f):
        self.queue = deque()
        self.hasMore = True
        self.lexer = lex.lex(module=self)
        self.lexer.input(f.read())

    def read(self):
        if (self.fillQueue(0)):
            return self.queue.popleft()
        else:
            return Token.EOF

    def peek(self, i):
        if self.fillQueue(i):
            return self.queue[i]
        else:
            return Token.EOF

    def fillQueue(self, i):
        while i >= len(self.queue):
            if self.hasMore:
                self.getNextToken()
            else:
                return False
        return True

    def getNextToken(self):
        tok = self.lexer.token()
        if not tok:
            self.hasMore = False
            return

        if tok.type == "NUMBER":
            self.queue.append(NumToken(tok.lineno, tok.value))
        elif tok.type == "STRING":
            self.queue.append(StrToken(tok.lineno, tok.value))
        elif tok.type == "IDENTIFIER":
            self.queue.append(IdToken(tok.lineno, tok.value))
        elif tok.type == "newline":
            self.queue.append(IdToken(tok.lineno, Token.EOL))
        else:
            raise ParseException("bad token at line " + str(tok.lineno))


def main():
    file_path = "test.txt"
    with open(file_path) as f:
        l = Lexer(f)
        t = l.read()
        while t != Token.EOF:
            print("=> " + t.getText())
            t = l.read()


if __name__ == "__main__":
    # Build the lexer and try it out
    main()
