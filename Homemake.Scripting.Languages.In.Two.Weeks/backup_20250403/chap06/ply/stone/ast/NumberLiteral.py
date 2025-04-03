from . ASTLeaf import ASTLeaf

class NumberLiteral(ASTLeaf):
    def __init__(self, t):
        super().__init__(t)

    def value(self):
        return self.token().getNumber()

    def eval(self, env):
        return self.value()
