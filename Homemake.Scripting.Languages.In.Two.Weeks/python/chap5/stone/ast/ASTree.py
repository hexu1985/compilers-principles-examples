import abc

class ASTree(abc.ABC):
    def __init__(self):
        pass

    @abc.abstractmethod
    def child(self, i):
        pass

    @abc.abstractmethod
    def numChildren(self):
        pass

    @abc.abstractmethod
    def children(self):
        pass

    @abc.abstractmethod
    def location(self):
        pass

    def __iter__(self):
        return self.children()


