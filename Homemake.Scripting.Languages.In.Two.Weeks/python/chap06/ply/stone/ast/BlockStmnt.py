from . ASTList import ASTList
from . NullStmnt import NullStmnt

class BlockStmnt(ASTList):
    def __init__(self, c):
        super().__init__(c)

    def eval(self, env):
        result = 0
        for t in self:
            if not isinstance(t, NullStmnt):
                result = t.eval(env)
        return result
