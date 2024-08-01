from . ASTLeaf import ASTLeaf
from stone.StoneException import StoneException

class Name(ASTLeaf):
    def __init__(self, t):
        super().__init__(t)

    def name(self):
        return self.token().getText()

    def eval(self, env):
        value = env.get(self.name())
        if value == None:
            raise StoneException("undefined name: " + self.name(), self);
        else:
            return value
