from . ASTList import ASTList

class BinaryExpr(ASTList):
    def __init__(self, c):
        super().__init__(c)

    def left(self):
        return self.child(0)

    def operator(self):
        return self.child(1).token().getText()

    def right(self):
        return self.child(2)
