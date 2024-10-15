from . NestedEnv import NestedEnv

class Function:
    def __init__(self, parameters, doby, env):
        self._parameters = parameters
        self._body = body
        self._env = env

    def parameters(self):
        return self._parameters

    def body(self):
        return self._body

    def makeEnv(self):
        return NestedEnv(self._env)

    def toString(self):
        return "<fun:" + hash(self) + ">"
