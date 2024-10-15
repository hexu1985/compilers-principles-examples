import abc

class Environment(abc.ABC):
    @abc.abstractmethod
    def put(self, name, value):
        pass

    @abc.abstractmethod
    def get(self, name):
        pass

    @abc.abstractmethod
    def putNew(self, name, value):
        pass

    @abc.abstractmethod
    def where(self, name):
        pass

    @abc.abstractmethod
    def setOuter(self, e):
        pass

