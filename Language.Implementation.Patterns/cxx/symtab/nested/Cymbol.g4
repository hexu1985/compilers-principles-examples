grammar Cymbol;

// 解析器规则
compilationUnit
    :   (methodDeclaration | varDeclaration)+
    ;

// 方法声明 - ANTLR4不再使用^()重写语法，而是使用标签
methodDeclaration
    :   type ID '(' formalParameters? ')' block
    ;

formalParameters
    :   type ID (',' type ID)*
    ;

type:   'float'
    |   'int'
    |   'void'
    ;

// 代码块
block
    :   '{' statement* '}'
    ;

// 变量声明
varDeclaration
    :   type ID ('=' expression)? ';'
    ;

statement
    :   block
    |   varDeclaration
    |   'return' expression? ';'
    |   postfixExpression
        (   '=' expression
        |
        )
        ';'       
    ;

expressionList
    :   expression (',' expression)*
    |
    ;

expression
    :   addExpression
    ;

addExpression
    :   postfixExpression ( '+' postfixExpression )*
    ;

// 函数调用
postfixExpression
    :   primary ( '(' expressionList ')' )*
    ;

primary
    :   ID
    |   INT
    |   '(' expression ')'
    ;

// 词法分析器规则

ID  :   LETTER (LETTER | [0-9])*
    ;

fragment
LETTER  :   [a-zA-Z]
    ;

INT :   [0-9]+
    ;

WS  :   [ \r\t\n]+ -> skip
    ;

SL_COMMENT
    :   '//' ~[\r\n]* '\r'? '\n' -> skip
    ;
