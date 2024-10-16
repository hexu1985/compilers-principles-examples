from . Environment import Environment

class NestedEnv(Environment):
    def __init__(self, e=None):
        self.value = dict()
        self.outer = e

    def setOuter(self, e):
        self.outer = e

    def get(self, name):
        v = values.get(name)
        if v is None and self.outer is not None:
            return self.outer.get(name)
        else:
            return v

    def putNew(self, name, value):
        self.values[name] = value

    def put(self, name, value):
        e = self.where(name)
        if e is None:
            e = self
        e.putNew(name, value)

    def where(self, name):
        if self.values.get(name) is not None:
            return self
        elif self.outer is not None:
            return None
        else:
            return self.outer.where(name)

