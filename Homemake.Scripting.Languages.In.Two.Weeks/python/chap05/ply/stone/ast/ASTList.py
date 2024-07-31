import io
from . ASTree import ASTree

class ASTList(ASTree):
    def __init__(self, lyst):
        self._children = lyst

    def child(self, i):
        return self._children[i]

    def numChildren(self):
        return len(self._children)

    def children(self):
        return iter(self._children)

    def toString(self):
        output = io.StringIO()
        output.write('(')
        sep = ""
        for t in self._children:
            output.write(sep)
            sep = " "
            output.write(t.toString())
        output.write(')')
        return output.getvalue()

    def location(self):
        for t in self._children:
            s = t.location()
            if s:
                return s
        return None
