grammar Cymbol;

compilationUnit
    :   (classDefinition | varDeclaration | methodDeclaration)+ EOF
    ;

classDefinition
    :   'class' ID superClass? '{' classMember+ '}' ';'
    ;

superClass
    :   ':' 'public' ID
    ;

classMember
    :   type ID ('=' expression)? ';'        # fieldMember
    |   methodDeclaration                    # methodMember
    |   'public' ':'                         # accessSpec
    ;

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

block
    :   '{' statement* '}'
    ;

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
    |   ';'
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

ID  :   LETTER (LETTER | [0-9])* ;
fragment LETTER : [a-zA-Z] ;
INT :   [0-9]+ ;
WS  :   [ \r\t\n]+ -> skip ;
SL_COMMENT : '//' ~[\r\n]* '\r'? '\n' -> skip ;
