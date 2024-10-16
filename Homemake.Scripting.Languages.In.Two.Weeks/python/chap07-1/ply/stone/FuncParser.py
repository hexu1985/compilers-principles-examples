from . BasicParser import BasicParser
from . Parser import Parser
from . ast import ParameterList, Arguments, DefStmnt


class FuncParser(BasicParser):
    def __init__(self):
        BasicParser.__init__(self)
        self.param = Parser.rule().identifier(self.reserved)
        self.params = Parser.rule(ParameterList).ast(self.param).repeat(Parser.rule().sep(",").ast(self.param))
        self.paramList = Parser.rule().sep("(").maybe(self.params).sep(")")
        self.def_ = Parser.rule(DefStmnt).sep("def").identifier(self.reserved).ast(self.paramList).ast(self.block)
        self.args = Parser.rule(Arguments).ast(self.expr).repeat(Parser.rule().sep(",").ast(self.expr))
        self.postfix = Parser.rule().sep("(").maybe(self.args).sep(")")

        self.reserved.add(")")
        self.primary.repeat(self.postfix)
        self.simple.option(self.args)
        self.program.insertChoice(self.def_)

