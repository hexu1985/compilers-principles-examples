from . ASTList import ASTList

class WhileStmnt(ASTList):
    def __init__(self, c):
        super().__init__(c)
    
    def condition(self):
        return self.child(0)

    def body(self):
        return self.child(1)

    def toString(self):
        return "(while " + self.condition().toString() + " " \
                + self.body().toString() + ")"
