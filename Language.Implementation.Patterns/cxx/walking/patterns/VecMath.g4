// START: header
grammar VecMath;

// START: stat
prog: stat+ ;                                  // build list of stat trees
stat: ID '=' expr                              // '=' is operator subtree root
    | 'print' expr                             // 'print' is subtree root
    ;
// END: stat

// START: expr
expr: multExpr ('+' multExpr)* ;               // '+' is root node

multExpr
    : primary (('*' | '.') primary)*           // '*', '.' are roots
    ;
    
primary
    : INT
    | ID
    | '[' expr (',' expr)* ']'                 // VEC vector literal
    | '(' expr ')'
    ;
// END: expr

ID  : 'a'..'z'+ ;
INT : '0'..'9'+ ;
WS  : (' '|'\r'|'\n')+ -> skip ;               // skip whitespace

MULT: '*' ;
