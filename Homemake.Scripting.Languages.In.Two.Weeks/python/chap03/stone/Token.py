if __name__ == "__main__":
    import sys
    from pathlib import Path
    current_file = Path(__file__).resolve()
    parent_dir = current_file.parent.parent
    sys.path.append(str(parent_dir))

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
    print(f't.getLineNumber(): {t.getLineNumber()}')
    print(f't.isIdentifier(): {t.isIdentifier()}')
    print(f't.isNumber(): {t.isNumber()}')
    print(f't.isString(): {t.isString()}')
    try:
        print(f't.getNumber(): {t.getNumber()}')
    except Exception as e:
        print(f'error when t.getNumber(): {e}')
    print(f't.getText(): {t.getText()}')
