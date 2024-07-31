from . ASTList import ASTList

class IfStmnt(ASTList):
    def __init__(self, c):
        super().__init__(c)

    def condition(self):
        return self.child(0)

    def thenBlock(self):
        return self.child(1)

    def elseBlock(self):
        return self.child(2) if self.numChildren() > 2 else None

    def toString(self):
        return "(if " + self.condition().toString() + " " \
                + self.thenBlock().toString() + " else " \
                + ("" if self.elseBlock() == None else self.elseBlock().toString()) + ")"
