from . Token import Token
from . Parser import Parser, Operators
from . ast import PrimaryExpr, NumberLiteral, Name, StringLiteral, NegativeExpr, BinaryExpr, BlockStmnt, IfStmnt, WhileStmnt, NullStmnt

class BasicParser:
    def __init__(self):
        self.reserved = set()    
        self.operators = Operators()

        self.expr0 = Parser.rule()
        self.primary = Parser.rule(PrimaryExpr).or_(
                Parser.rule().sep("(").ast(self.expr0).sep(")"),
                Parser.rule().number(NumberLiteral),
                Parser.rule().identifier(Name, self.reserved),
                Parser.rule().string(StringLiteral))
        self.factor = Parser.rule().or_(
                Parser.rule(NegativeExpr).sep("-").ast(self.primary),
                self.primary)
        self.expr = self.expr0.expression(BinaryExpr, self.factor, self.operators)

        self.statement0 = Parser.rule()
        self.block = Parser.rule(BlockStmnt) \
                            .sep("{").option(self.statement0) \
                            .repeat(Parser.rule().sep(";", Token.EOL).option(self.statement0)) \
                            .sep("}")

        self.simple = Parser.rule(PrimaryExpr).ast(self.expr)
        self.statement = self.statement0.or_(
                Parser.rule(IfStmnt).sep("if").ast(self.expr).ast(self.block)
                                    .option(Parser.rule().sep("else").ast(self.block)),
                Parser.rule(WhileStmnt).sep("while").ast(self.expr).ast(self.block),
                self.simple)

        self.program = Parser.rule().or_(self.statement, Parser.rule(NullStmnt)).sep(";", Token.EOL)

        self.reserved.add(";")
        self.reserved.add("}")
        self.reserved.add(Token.EOL)
        
        self.operators.add("=", 1, Operators.RIGHT)
        self.operators.add("==", 2, Operators.LEFT)
        self.operators.add(">", 2, Operators.LEFT)
        self.operators.add("<", 2, Operators.LEFT)
        self.operators.add("+", 3, Operators.LEFT)
        self.operators.add("-", 3, Operators.LEFT)
        self.operators.add("*", 4, Operators.LEFT)
        self.operators.add("/", 4, Operators.LEFT)
        self.operators.add("%", 4, Operators.LEFT)

    def parse(self, lexer):
        return self.program.parse(lexer)

