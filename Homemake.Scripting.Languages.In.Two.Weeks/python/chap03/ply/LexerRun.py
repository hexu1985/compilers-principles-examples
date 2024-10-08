import sys
from stone.Lexer import Lexer
from stone.Token import Token

def main():
    file_path = "test.txt"
    if len(sys.argv) > 1:
        file_path = sys.argv[1]

    with open(file_path) as f:
        l = Lexer(f)
        t = l.read()
        while t != Token.EOF:
            print("=> " + t.getText())
            t = l.read()

main()
