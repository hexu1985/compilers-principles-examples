from . ASTList import ASTList

class WhileStmnt(ASTList):
    def __init__(self, c):
        super().__init__(c)
    
    def condition(self):
        return self.child(0)

    def body(self):
        return self.child(1)

    def toString(self):
        return "(while " + str(self.condition()) + " " + str(self.body()) + ")"

    def eval(self, env):
        result = 0
        while True:
            c = self.condition().eval(env)
            if isinstance(c, int) and c:
                return result
            else:
                result = self.body().eval(env)
