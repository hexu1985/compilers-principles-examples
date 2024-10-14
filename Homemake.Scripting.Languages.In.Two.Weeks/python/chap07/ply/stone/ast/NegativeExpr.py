from . ASTList import ASTList
from stone.StoneException import StoneException

class NegativeExpr(ASTList):
    def __init__(self, c):
        super().__init__(c)

    def operand(self):
        return self.child(0)

    def toString(self):
        return "-" + str(self.operand()) +""

    def eval(self, env):
        v = self.operand().eval(env)
        if isinstance(v, int):
            return -v
        else:
            raise StoneException("bad type for -", self)
