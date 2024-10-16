from . Postfix import Postfix
from stone.Function import Function
from stone.StoneException import StoneException

class Arguments(Postfix):
    def __init__(self, c):
        super().__init__(c)

    def size(self):
        return self.numChildren()

    def eval(self, callerEnv, value):
        if not isinstance(value, Function):
            raise StoneException("bad function", self)
        func = value
        params = func.parameters()
        if self.size() != params.size():
            raise StoneException("bad number of arguments", self)
        newEnv = func.makeEnv()
        num = 0
        for a in self.children():
            params.eval(newEnv, num, a.eval(callerEnv))
            num += 1

        return func.body().eval(newEnv)
