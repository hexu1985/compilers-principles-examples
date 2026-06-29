grammar VecMath;

// Parser rules
prog: stat+;

stat: ID '=' expr     # Assign
    | 'print' expr    # Print
    ;

expr: multExpr (op='+' multExpr)* ;

multExpr: primary (op=('*'|'.') primary)* ;

primary: INT          # Int
       | ID           # Id
       | '[' expr (',' expr)* ']'  # Vector
       ;

// Lexer rules
ID  : [a-z]+ ;
INT : [0-9]+ ;
WS  : [ \r\n]+ -> skip ;
