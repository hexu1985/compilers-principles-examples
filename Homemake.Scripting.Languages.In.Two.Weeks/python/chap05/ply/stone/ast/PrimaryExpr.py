from . ASTList import ASTList

class PrimaryExpr(ASTList):
    def __init__(self, c):
        super().__init__(c)

    @staticmethod
    def create(c):
        return c[0] if len(c) == 1 else PrimaryExpr(c)
