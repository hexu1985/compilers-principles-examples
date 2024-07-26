from stone.ast.ASTList import ASTList

class NegativeExpr(ASTList):
    def __init__(self, c):
        super().__init__(c)

    def operand(self):
        return self.child(0)

    def toString(self):
        return "-" + str(self.operand())

