from . ASTList import ASTList

class Postfix(ASTList):
    def __init__(self, c):
        super().__init__(c)

    def eval(self, env, value):
        pass
