#!/usr/bin/env python3
import sys
from stone import Lexer, BasicParser, BasicEnv, BasicInterpreter

def main():
    file_path = "test.txt"
    if len(sys.argv) > 1:
        file_path = sys.argv[1]

    with open(file_path) as f:
        l = Lexer(f)
        bp = BasicParser()
        env = BasicEnv()
        interpreter = BasicInterpreter()
        interpreter.run(l, bp, env)

main()
