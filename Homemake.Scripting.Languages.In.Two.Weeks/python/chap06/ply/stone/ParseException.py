from stone.Token import Token

class ParseException(Exception):
    def __init__(self, msg, t=None):
        if t is None:
            super().__init__(msg)
        else:
            super().__init__("syntaxerroraround"+ParseException.location(t)+"."+msg)

    @staticmethod
    def location(t):
        if t == Token.EOF:
            return "the last line"
        else:
            return "\"" + t.getText() + "\" at line " + str(t.getLineNumber())

if __name__ == '__main__':
    token = Token.EOF
    exception = ParseException("eof token error", token)
    print(exception)
