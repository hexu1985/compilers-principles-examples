
class Token:
    def __init__(self, type, text):
        self.type = type
        self.text = text

    def __str__(self):
        from ListLexer import ListLexer
        tname = ListLexer.tokenNames[self.type]
        return "<'" + self.text + "'," + tname + ">"
