from . ASTLeaf import ASTLeaf

class StringLiteral(ASTLeaf):
    def __init__(self, t):
        super().__init__(t)

    def value(self):
        return self.token().getText()
