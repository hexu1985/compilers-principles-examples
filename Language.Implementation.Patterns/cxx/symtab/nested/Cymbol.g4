grammar Cymbol;

// 起始规则：至少一个变量声明
compilationUnit
    :   varDeclaration+
    ;

// 类型规则
type
    :   'float'
    |   'int'
    ;

// 变量声明
varDeclaration
    :   type ID ('=' expression)? ';'
    ;

// 表达式
expression
    :   primary ('+' primary)*
    ;

// 基本表达式
primary
    :   ID
    |   INT
    |   '(' expression ')'
    ;

// 词法规则

ID  :   LETTER (LETTER | [0-9])*
    ;

fragment
LETTER  :   [a-zA-Z]
    ;

INT :   [0-9]+
    ;

WS  :   [ \t\r\n]+ -> skip
    ;

SL_COMMENT
    :   '//' ~[\r\n]* -> skip
    ;
