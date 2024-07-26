import abc

class ASTree:
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

