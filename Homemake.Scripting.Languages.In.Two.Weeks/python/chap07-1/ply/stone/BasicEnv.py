from . Environment import Environment

class BasicEnv(Environment):
    def __init__(self):
        self.values = dict()

    def put(self, name, value):
        self.values[name] = value

    def get(self, name):
        return self.values.get(name)
