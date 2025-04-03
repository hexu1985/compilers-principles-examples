import abc

class Environment(abc.ABC):
    @abc.abstractmethod
    def put(self, name, value):
        pass

    @abc.abstractmethod
    def get(self, name):
        pass

