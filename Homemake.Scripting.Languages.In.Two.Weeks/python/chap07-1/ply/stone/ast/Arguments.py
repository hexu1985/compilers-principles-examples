from . Postfix import Postfix

class Arguments(Postfix):
    def __init__(self, c):
        super().__init__(c)

    def size(self):
        return self.numChildren()
