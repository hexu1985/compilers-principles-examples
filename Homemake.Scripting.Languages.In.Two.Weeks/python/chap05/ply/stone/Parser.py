import abc
from . Token import Token
from . ast import ASTree, ASTLeaf, ASTList
from . ParseException import ParseException

factoryName = "create"
class Factory:
    @abc.abstractmethod
    def make0(self, arg):
        pass

    def make(self, arg):
        return self.make0(arg)

    @staticmethod
    def getForASTList(clazz):
        f = Factory.get(clazz, list)
        if f == None:
            class ConcreteFactory(Factory):
                def make0(self, arg):
                    results = arg
                    if len(results) == 1:
                        return results[0]
                    else:
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

                def make0(self, arg):
                    return self.m(arg)
            return ConcreteFactory(m)
        except AttributeError as e:
            pass

        class ConcreteFactory(Factory):
            def __init__(self, clazz):
                self.clazz = clazz

            def make0(self, arg):
                return self.clazz(arg)
        return ConcreteFactory(clazz)



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
        res.append(self.parser.parse(lexer))

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
            res.append(p.parse(lexer))

    def match(self, lexer):
        return self.choose(lexer) != None

    def choose(self, lexer):
        for p in self.parsers:
            if p.match(lexer):
                return p

        return None

    def insert(self, p):
        self.parsers = [p] + self.parsers
        if p.factory == None:
            print("p.factory is None")


class Repeat(Element):
    def __init__(self, p, once):
        self.parser = p
        self.onlyOnce = once

    def parse(self, lexer, res):
        while self.parser.match(lexer):
            t = self.parser.parse(lexer)
            if isinstance(t, ASTList) or t.numChildren() > 0:
                res.append(t)
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
            res.append(leaf)
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
        return t.isIdentifier() and (t.getText() not in self.reserved)


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


class Leaf(Element):
    def __init__(self, pat):
        self.tokens = pat

    def parse(self, lexer, res):
        t = lexer.read()
        if t.isIdentifier():
            for token in self.tokens:
                if token == t.getText():
                    self.find(res, t)
                    return

        if len(self.tokens) > 0:
            raise ParseException(str(tokens[0]) + " expected.", t)
        else:
            raise ParseException(str(t))

    def find(self, res, t):
        res.append(t)

    def match(self, lexer):
        t = lexer.peek(0)
        if t.isIdentifier():
            for token in self.tokens:
                if token == t.getText():
                    return True

        return False


class Skip(Leaf):
    def __init__(self, t):
        super().__init__(t)

    def find(self, res, t):
        pass


class Precedence:
    def __init__(self, v, a):
        self.value = v
        self.leftAssoc = a


class Operators:
    LEFT = True
    RIGHT = False

    def __init__(self):
        self.operators = dict()

    def add(self, name, prec, leftAssoc):
        self.operators[name] = Precedence(prec, leftAssoc)

    def get(self, name):
        return self.operators.get(name)


class Expr(Element):
    def __init__(self, clazz, exp, map_):
        self.factory = Factory.getForASTList(clazz)
        self.ops = map_
        self.factor = exp

    def parse(self, lexer, res):
        right = self.factor.parse(lexer)

        prec = self.nextOperator(lexer)
        while prec != None:
            right = self.doShift(lexer, right, prec.value)
            prec = self.nextOperator(lexer)

        res.append(right)

    def doShift(self, lexer, left, prec):
        lyst = list()
        lyst.append(left)
        lyst.append(ASTLeaf(lexer.read()))
        right = self.factor.parse(lexer)
        next_ = self.nextOperator(lexer)
        while next_ != None and self.rightIsExpr(prec, next_):
            right = self.doShift(lexer, right, next_.value)
            next_ = self.nextOperator(lexer)

        lyst.append(right)

        return self.factory.make(lyst)

    def nextOperator(self, lexer):
        t = lexer.peek(0)
        if t.isIdentifier():
            return self.ops.get(t.getText())
        else:
            return None

    def rightIsExpr(self, prec, nextPrec):
        if nextPrec.leftAssoc:
            return prec < nextPrec.value
        else:
            return prec <= nextPrec.value

    def match(self, lexer):
        return self.factor.match(lexer)


class Parser:
    def __init__(self, *args):
        self.elements = None
        self.factory = None
        self.reset(*args)
        
    def clone(self):
        p = Parser(None)
        p.elements = self.elements
        p.factory = self.factory
    
    def parse(self, lexer):
        results = list()
        for e in self.elements:
            e.parse(lexer, results)

        return self.factory.make(results)

    def match(self, lexer):
        if len(self.elements) == 0:
            return True
        else:
            e = self.elements[0]
            return e.match(lexer)

    @staticmethod
    def rule(clazz=None):
        return Parser(clazz)

    def reset(self, *args ):
        self.elements = list()
        if len(args) == 0:
            return self
        clazz = args[0]
        self.factory = Factory.getForASTList(clazz)
        return self

    def number(self, clazz=None):
        self.elements.append(NumToken(clazz))
        return self

    def identifier(self, *args):
        clazz = None
        reserved = None
        if len(args) == 1:
            reserved = args[0]
        elif len(args) == 2:
            clazz = args[0]
            reserved = args[1]
        else:
            raise RuntimeError("invalid number of args: {}".format(len(args)))
        self.elements.append(IdToken(clazz, reserved))
        return self

    def string(self, clazz=None):
        self.elements.append(StrToken(clazz))
        return self
            
    def token(self, *pat):
        self.elements.append(Leaf(pat))
        return self

    def sep(self, *pat):
        self.elements.append(Skip(pat))
        return self

    def ast(self, p):
        self.elements.append(Tree(p))
        return self

    def or_(self, *p):
        self.elements.append(OrTree(p))
        return self

    def maybe(self, p):
        p2 = p.clone()
        p2.reset()
        self.elements.append(OrTree([p, p2]))
        return self

    def option(self, p):
        self.elements.append(Repeat(p, once=True))
        return self

    def repeat(self, p):
        self.elements.append(Repeat(p, once=False))
        return self

    def expression(self, *args):
        clazz = None
        subexp = None
        operators = None
        if len(args) == 2:
            subexp, operators = args
        elif len(args) == 3:
            clazz, subexp, operators = args
        else:
            raise RuntimeError("invalid number of args: {}".format(len(args)))
        self.elements.append(Expr(clazz, subexp, operators))
        return self

    def insertChoice(self, p):
        e = self.elements[0]
        if isinstance(e, OrTree):
            e.insert(p)
        else:
            otherwise = Parser(self)
            self.reset(None)
            or_(p, otherwise)
        return self


        

