from stone.Lexer import Lexer
from stone.Token import Token

test_data = """
while i < 10 {
    sum = sum + i
    i = i + 1
}
sum
"hello world"
""".strip('\n ')

l = Lexer(test_data)
t = l.read()
while t != Token.EOF:
    print("=> " + t.getText())
    t = l.read()

