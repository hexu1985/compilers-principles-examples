### Stone语言的语法定义

```
program　　: [ def | statement ] (";" | EOL)
statement  : "if" expr block [ "else" block ]
　　　　　　 | "while" expr block
　　　　　　 | simple
simple     : expr [ args ]
block　　　: "{" [ statement ] { (";" | EOL) [ statement ] } "}"
expr　　　 : factor { OP factor }
factor　　 : "-" primary | primary
primary　　: ( "(" expr ")" | NUMBER | IDENTIFIER | STRING ) { postfix }
postfix    : "(" [ args ] ")"
args       : expr { "," expr }
def        : "def" IDENTIFIER param_list block
param_list : "(" [ params ] ")"
params     : param { "," param }
param      : IDENTIFIER
```

