from . BasicParser import BasicParser
from . Parser import Parser
from . ast import 


class FuncParser(BasicParser):
    def __init__(self):
        BasicParser.__init__(self)
        self.param = Parser.rule().identifier(self.reserved)
        self.params = Parser.rule(ParameterList)

