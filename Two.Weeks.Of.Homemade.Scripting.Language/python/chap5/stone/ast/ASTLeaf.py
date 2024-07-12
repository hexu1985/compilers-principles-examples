import io
from stone.ast.ASTree import ASTree

class ASTList(ASTree):
    def __init__(self, lyst):
        super().__init__()
        self._children = lyst

    def child(self, i):
        return self._children[i]

    def numChildren(self):
        return len(self._children)

    def children(self):
        return iter(self._children)

    def __str__(self):
        builder = io.StringIO()
        builder.write('(')
        sep = ''
        for t in self._children:
            builder.a
