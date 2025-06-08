import sys

from Token import Token
from Lexer import Lexer
from ListLexer import ListLexer

def main():
    file_path = "test.txt"
    if len(sys.argv) > 1:
        file_path = sys.argv[1]

    with open(file_path) as f:
        lexer = ListLexer(f.read())
        t = lexer.nextToken()
        while t.type != ListLexer.T_TYPE_EOF:
            print("=> {}".format(t))
            t = lexer.nextToken()

main()
