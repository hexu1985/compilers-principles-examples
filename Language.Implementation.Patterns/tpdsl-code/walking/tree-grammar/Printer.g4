// Printer.g4 - 纯语法文件
grammar Printer;

import VecMath;

prog: stat+ ;

stat
    : ID '=' expr    # assignStat
    | 'print' expr   # printStat
    ;

expr
    : multExpr ('+' multExpr)*
    ;
    
multExpr
    : primary (('*'|'.') primary)*
    ;
    
primary
    : INT
    | ID
    | '[' expr (',' expr)* ']'
    ;
