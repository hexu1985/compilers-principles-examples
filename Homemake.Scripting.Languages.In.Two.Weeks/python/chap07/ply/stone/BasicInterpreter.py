from . ast import NullStmnt
from . Token import Token

class BasicInterpreter:
    def run(self, lexer, parser, env):
        while lexer.peek(0) != Token.EOF:
            t = parser.parse(lexer)
            if not isinstance(t, NullStmnt):
                r = t.eval(env)
                print("=> " + str(r))
