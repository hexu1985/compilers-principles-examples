
class Token:
    EOF_TYPE = 1
    NAME = 2
    COMMA = 3
    LBRACK = 4
    RBRACK = 5
    tokenNames = ["n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBRACK"]

    def __init__(self, type, text):
        self.type = type
        self.text = text

    def __str__(self):
        tname = Token.tokenNames[self.type]
        return "<'" + self.text + "'," + tname + ">"
