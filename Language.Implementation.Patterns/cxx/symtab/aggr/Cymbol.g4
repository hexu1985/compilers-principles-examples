grammar Cymbol;

// 解析器规则
compilationUnit
    :   (structDeclaration | methodDeclaration | varDeclaration)+
    ;

// 结构体声明
structDeclaration
    :   'struct' ID '{' structMember+ '}' ';'
    ;

// 结构体成员
structMember
    :   type ID ';'
    |   structDeclaration
    ;

// 方法声明
methodDeclaration
    :   type ID '(' formalParameters? ')' block
    ;

formalParameters
    :   type ID (',' type ID)*
    ;

type:   'float'
    |   'int'
    |   'void'
    |   ID
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
    |   structDeclaration
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

// 函数调用和字段访问
postfixExpression
    :   primary
        (   '(' expressionList ')'
        |   '.' ID
        )*
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
