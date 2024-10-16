import sys
from stone import Lexer, Token, FuncParser

def main():
    file_path = "test.txt"
    if len(sys.argv) > 1:
        file_path = sys.argv[1]

    with open(file_path) as f:
        l = Lexer(f)
        bp = FuncParser()
        while l.peek(0) != Token.EOF:
            ast = bp.parse(l);
            print("=> " + str(ast))

main()


