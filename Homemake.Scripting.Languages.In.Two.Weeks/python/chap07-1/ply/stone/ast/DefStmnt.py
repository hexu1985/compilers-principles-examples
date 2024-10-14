from . ASTList import ASTList

class DefStmnt(ASTList):
    def __init__(self, c):
        super().__init__()

    def name(self):
        return self.child(i).token().getText()

    def parameters(self):
        return self.child(1)

    def body(self):
        return self.child(2)

    def toString(self):
        return "(def" + str(self.name()) + " " + str(self.parameters()) + " " + str(self.body()) + ")"
