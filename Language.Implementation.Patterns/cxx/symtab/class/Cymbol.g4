grammar Cymbol;

// 解析器规则

compilationUnit
    :   (classDefinition | varDeclaration | methodDeclaration)+ EOF
    ;

// 类定义
classDefinition
    :   'class' ID superClass? '{' classMember+ '}' ';'
    ;

superClass
    :   ':' 'public' ID
    ;

// 类成员
classMember
    :   type ID ('=' expression)? ';'
    |   methodDeclaration
    |   'public' ':'
    ;

// 方法声明
methodDeclaration
    :   type ID '(' formalParameters? ')' block
    ;

formalParameters
    :   type ID (',' type ID)*
    ;

type
    :   'float'
    |   'int'
    |   'void'
    |   ID // class type name
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
    |   ';' // empty statement
    ;

expressionList
    :   expression (',' expression)*
    |
    ;

expression
    :   addExpression
    ;

addExpression
    :   postfixExpression ('+' postfixExpression)*
    ;

// 函数调用和字段访问
postfixExpression
    :   primary
        (   '.' ID '(' expressionList ')'
        |   '.' ID
        |   '(' expressionList ')'
        )*
    ;

primary
    :   'this'
    |   'super'
    |   ID
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
