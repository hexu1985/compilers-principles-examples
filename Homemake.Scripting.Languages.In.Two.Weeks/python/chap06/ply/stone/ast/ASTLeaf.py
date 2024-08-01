from . ASTree import ASTree

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

