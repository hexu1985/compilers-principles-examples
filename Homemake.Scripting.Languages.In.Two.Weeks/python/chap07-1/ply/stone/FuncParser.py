from . BasicParser import BasicParser
from . Parser import Parser
from . ast import ParameterList, Arguments, DefStmnt


class FuncParser(BasicParser):
    def __init__(self):
        BasicParser.__init__(self)
        self.param = Parser.rule().identifier(self.reserved)
        self.params = Parser.rule(ParameterList).ast(param).repeat(Parser.rule().sep(",").ast(param))
        self.paramList = Parser.rule().sep("(").maybe(params).sep(")")
        self.def_ = Parser.rule(DefStmnt).ast(expr).repeat(rule().sep(",").ast(expr))
        sefl.args = Parser.rule(Arguments).ast(expr).repeat(rule().sep(",").ast(expr))
        self.postfix = Parser.rule().sep("(").maybe(args).sep(")")

        self.reserved.add(")")
        self.primary.repeat(self.postfix)
        self.simple.option(self.args)
        self.program.insertChoice(self.def_)

