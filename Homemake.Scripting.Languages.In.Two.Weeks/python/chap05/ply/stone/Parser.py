import abc

factoryName = "create"
class Factory:
    @abc.abstractmethod
    def make0(arg):
        pass

    def make(arg):
        self.make0(arg)

    @staticmethod
    getForASTList(clazz):
        f = Factory.get(clazz, list)
        if f == None:
            class ConcreteFactory(Factory):
                def make0(arg):
                    results = arg
                    if len(results) == 1:
                        return results.get(0)
                    else
                    return ASTList(results)
            f = ConcreteFactory()
        return f

    @staticmethod
    def get(clazz, argType):
        if clazz == None:
            return None
        try:
            m = getattr(clazz, factoryName)
            class ConcreteFactory(Factory):
                def __init__(self, m):
                    self.m = m

                def make0(arg):
                    return self.m(arg)
            return ConcreteFactory(m)
        except AttributeError as e:
            pass

        try:
            c = getattr(clazz, "__init__")
            class ConcreteFactory(Factory):
                def __init__(self, c):
                    self.c = c

                def make0(arg):
                    return self.c(arg)
            return ConcreteFactory(c)
        except AttributeError as e:
            raise RuntimeError(e)


class Element:
    @abc.abstractmethod
    def parse(self, lexer, res):
        pass

    @abc.abstractmethod
    def match(self, lexer):
        pass


class Tree(Element):
    def __init__(self, p):
        self.parser = p

    def parse(self, lexer, res):
        res.add(self.parser.parse(lexer))

    def match(self, lexer):
        return self.parser.match(lexer)


class OrTree(Element):
    def __init__(self, p):
        self.parsers = p

    def parse(self, lexer, res):
        p = self.choose(lexer)
        if p == None:
            raise ParseException(lexer.peek(0))
        else:
            res.add(p.parse(lexer))

    def match(self, lexer):
        return self.choose(lexer) != None

    def choose(self, lexer):
        for p in self.parsers:
            if p.match(lexer):
                return p

        return None

    def insert(self, p):
        self.parsers = [p] + self.parsers


class Repeat(Element):
    def __init__(self, p, once):
        self.parser = p
        self.onlyOnce = once

    def parse(self, lexer, res):
        while self.parser.match(lexer):
            t = self.parser.parse(lexer)
            if isinstance(t, ASTList) or t.numChildren() > 0:
                res.add(t)
            if self.onlyOnce:
                break

    def match(self, lexer):
        return self.parser.match(lexer)


class AToken(Element):
    def __init__(self, type_):
        if type_ == None:
            type_ = ASTLeaf
        self.factory = Factory.get(type_, Token)

    def parse(self, lexer, res):
        t = lexer.read()
        if self.test(t):
            leaf = self.factory.make(t)
            res.add(leaf)
        else:
            raise ParseException(t)

    def match(self, lexer):
        return self.test(lexer.peek(0))

    @abc.abstractmethod
    def test(self, t):
        pass


class IdToken(AToken):
    def __init__(self, type_, r):
        super().__init__(type_)
        self.reserved = r if r != None else set()

    def test(self, t):
        return t.isIdentifier() and (t.getText() not in reserved)


class NumToken(AToken):
    def __init__(self, type_):
        super().__init__(type_)

    def test(self, t):
        return t.isNumber()


class StrToken(AToken):
    def __init__(self, type_):
        super().__init__(type_)

    def test(self, t):
        return t.isString()





        

