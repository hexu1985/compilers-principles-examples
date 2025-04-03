if __name__ == "__main__":
    import sys
    from pathlib import Path
    current_file = Path(__file__).resolve()
    parent_dir = current_file.parent.parent
    sys.path.append(str(parent_dir))

from stone.Token import Token

class ParseException(Exception):
    def __init__(self, *args):
        msg = ""
        t = None
        if len(args) == 1:
            t = args[0]
        elif len(args) == 2:
            msg = args[0]
            t = args[1]
        else:
            print("invalid args number")

        super().__init__("syntax error around " + ParseException.location(t) + ". " + msg)

    @staticmethod
    def location(t):
        if t == Token.EOF:
            return "the last line"
        else:
            return "\"" + t.getText() + "\" at line " + str(t.getLineNumber())

if __name__ == '__main__':
    print(ParseException(Token.EOF))
    print(ParseException("Invalid expression", Token(20)))
