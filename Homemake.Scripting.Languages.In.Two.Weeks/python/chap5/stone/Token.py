from stone.StoneException import StoneException

class Token:
    EOF = None  # end of file
    EOL = "\\n" # end of line

    def __init__(self, line):
        self.lineNumber = line

    def getLineNumber(self):
        return self.lineNumber

    def isIdentifier(self):
        return False

    def isNumber(self):
        return False

    def isString(self):
        return False

    def getNumber(self):
        raise StoneException("not number token")

    def getText(self):
        return ""

Token.EOF = Token(-1)

if __name__ == "__main__":
    t = Token(13)
