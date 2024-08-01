from . ASTLeaf import ASTLeaf

class Name(ASTLeaf):
    def __init__(self, t):
        super().__init__(t)

    def name(self):
        return self.token().getText()
