from . ASTList import ASTList

class ParameterList(ASTList):
    def __init__(self, c):
        super().__init__(c)

    def name(self, i):
        return self.child(i).token().getText()

    def size(self):
        return self.numChildren()


