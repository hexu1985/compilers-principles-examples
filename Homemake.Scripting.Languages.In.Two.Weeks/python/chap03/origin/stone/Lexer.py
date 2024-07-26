import re 
import io

from stone.LineNumberReader import LineNumberReader
from stone.ParseException import ParseException
from stone.Token import Token

class Lexer:
    regexPat = r'\s*((//.*)|([0-9]+)|("(\\"|\\\\|\\n|[^"])*")' \
                '|[A-Z_a-z][A-Z_a-z0-9]*|==|<=|>=|&&|\|\||[!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~])?'

    def __init__(self, r):  # r file
        self.pattern = re.compile(Lexer.regexPat)
        self.queue = list()
        self.hasMore = True
        self.reader = LineNumberReader(r)

    def read(self):
        if (self.fillQueue(0)):
            return self.queue.pop(0)
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
                self.readLine()
            else:
                return False
        return True

    def readLine(self):
        line = self.reader.readLine()
        if not line:
            self.hasMore = False
            return
        lineNo = self.reader.getLineNumber()

        pos = 0
        endPos = len(line)
        while pos < endPos:
            matcher = self.pattern.match(line, pos, endPos)
            if matcher is not None:
                self.addToken(lineNo, matcher)
                pos = matcher.end()
            else:
                raise ParseException("bad token at line " + str(lineNo))

    def addToken(self, lineNo, matcher):
        m = matcher.group(1)
        if m is not None:   # is not a space
            if matcher.group(2) is None:    # if not a comment
                token = None
                if matcher.group(3) is not None:
                    token = NumToken(lineNo, int(m))
                elif matcher.group(4) is not None:
                    token = StrToken(lineNo, self.toStringLiteral(m))
                else:
                    token = IdToken(lineNo, m)
                self.queue.append(token)

    def toStringLiteral(self, s):
        sb = io.StringIO()
        len_ = len(s) - 1
        for i in range(1, len_):
            c = s[i]
            if c == '\\' and i + 1 < len_:
                c2 = s[i + 1]
                if c2 == '"' or c2 == '\\':
                    i = i + 1
                    c = s[i]
                elif c2 == 'n':
                    i = i + 1
                    c = '\n'
            sb.write(c)
        return sb.getvalue()

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

if __name__ == "__main__":
    with open("test.txt") as f:
        l = Lexer(f)
        t = l.read()
        while t != Token.EOF:
            print("=> {}\t{}".format(t.getText(), type(t)))
            t = l.read()
