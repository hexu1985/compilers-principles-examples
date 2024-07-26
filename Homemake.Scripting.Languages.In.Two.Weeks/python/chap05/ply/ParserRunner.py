import sys
from stone.Lexer import Lexer
from stone.Token import Token

def main():
    file_path = "test.txt"
    if len(sys.argv) > 1:
        file_path = sys.argv[1]

    with open(file_path) as f:
        l = Lexer(f)
        bp = BasicParser()
        while l.peek(0) != Token.EOF:
            ast = bp.parse(l);
            print("=> " + ast.toString())

main()

