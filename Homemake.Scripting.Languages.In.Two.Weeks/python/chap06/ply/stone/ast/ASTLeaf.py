from . ASTree import ASTree
from stone.StoneException import StoneException

class ASTLeaf(ASTree):
    def __init__(self, t):
        self._token = t

    def child(self, i):
        raise IndexError()

    def numChildren(self):
        return 0

    def children(self):
        return []

    def toString(self):
        return self._token.getText()

    def location(self):
        return "at line {}".format(self._token.getLineNumber())

    def token(self):
        return self._token

    def eval(self, env):
        raise StoneException("cannot eval: " + str(self), self)

