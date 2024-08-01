from . ASTList import ASTList
from . Name import Name
from stone.StoneException import StoneException

class BinaryExpr(ASTList):
    def __init__(self, c):
        super().__init__(c)

    def left(self):
        return self.child(0)

    def operator(self):
        return self.child(1).token().getText()

    def right(self):
        return self.child(2)

    def eval(self, env):
        op = self.operator()
        if op == "=":
            right = self.right().eval(env)
            self.computeAssign(env, right)
        else:
            left = self.left().eval(env)
            right = self.right().eval(env)
            return self.computeOp(left, op, right)

    def computeAssign(self, env, rvalue):
        l = self.left()
        if isinstance(l, Name):
            env.put(l.name(), rvalue)
            return rvalue
        else:
            raise StoneException("bad assignment", self)

    def computeOp(self, left, op, right):
        if isinstance(left, int) and isinstance(right, int):
            self.computeNumber(left, op, right)
        else:
            if op == "+":
                return str(left) + str(right)
            elif op == "==":
                if left == None:
                    return True if right == None else False
                else:
                    return True if left == right else False
            else:
                raise StoneException("bad type", self)

    def computeNumber(self, left, op, right):
        a = int(left)
        b = int(right)
        if op == "+":
            return a + b
        elif op == "-":
            return a - b
        elif op == "*":
            return a * b
        elif op == "/":
            return a / b
        elif op == "%":
            return a % b
        elif op == "==":
            return True if a == b else False
        elif op == ">":
            return True if a > b else False
        elif op == "<":
            return True if a < b else False
        else:
            raise StoneException("bad operator", self)
