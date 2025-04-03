from . ASTList import ASTList

class PrimaryExpr(ASTList):
    def __init__(self, c):
        super().__init__(c)

    @staticmethod
    def create(c):
        return c[0] if len(c) == 1 else PrimaryExpr(c)

    def operand(self):
        return self.child(0)

    def postfix(self, nest):
        return self.child(self.numChildren() - nest - 1)

    def hasPostfix(self, nest):
        return self.numChildren() - nest > 1

    def eval(self, env):
        return self.evalSubExpr(env, 0)

    def evalSubExpr(env, nest):
        if self.hasPostfix(nest):
            target = self.evalSubExpr(env, nest + 1)
            return self.postfix(nest).eval(env, target)
        else:
            return self.operand().eval(env)
