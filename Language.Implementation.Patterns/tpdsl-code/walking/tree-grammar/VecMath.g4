// START: header
grammar VecMath;

// ANTLR4默认生成解析树，不需要options {output=AST;}
// 使用@parser::members定义虚token的替代方案
@parser::members {
    // 可以在这里添加自定义代码
}
// END: header

// START: stat
// prog: stat+ ;                         // build list of stat trees
prog: stat+ ;

// stat: ID '=' expr  -> ^('=' ID expr)  // '=' is operator subtree root
//     | 'print' expr -> ^('print' expr) // 'print' is subtree root
//     ;
stat: ID '=' expr          # assignStat  // '=' is operator subtree root
    | 'print' expr         # printStat   // 'print' is subtree root
    ;
// END: stat

// START: expr
// expr: multExpr ('+'^ multExpr)* ;     // '+' is root node
expr: multExpr ('+' multExpr)* ;         // '+' is implicit root in parse tree

// multExpr
//     : primary (('*'^|'.'^) primary)*  // '*', '.' are roots
//     ;
multExpr
    : primary (('*'|'.') primary)*       // '*', '.' are implicit roots
    ;
    
// primary
//     : INT
//     | ID
//     | '[' expr (',' expr)* ']' -> ^(VEC expr+)
//     ;
primary
    : INT                                # intPrimary
    | ID                                 # idPrimary
    | '[' expr (',' expr)* ']'           # vecPrimary
    ;
// END: expr

// Lexer rules
ID  :   'a'..'z'+ ;
INT :   '0'..'9'+ ;
WS  :   (' '|'\r'|'\n')+ -> skip ;  // 使用 -> skip 替代 {skip();}
