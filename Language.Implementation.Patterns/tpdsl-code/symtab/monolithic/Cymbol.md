好的，我来帮你把文件1改写成ANTLR4风格，去掉所有内嵌Java代码，改为适合监听器/访问器模式的纯语法定义。

## 转换后的 ANTLR4 语法文件

```antlr
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
    :   ID          # VarRef
    |   INT         # IntLiteral
    |   '(' expression ')'  # ParenExpr
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
```

## 对应的访问器/监听器实现示例

### 1. 首先定义符号表相关类（Java）

```java
// Symbol.java - 符号基类
public class Symbol {
    protected String name;
    protected Type type;
    
    public Symbol(String name, Type type) {
        this.name = name;
        this.type = type;
    }
    
    public String getName() { return name; }
    public Type getType() { return type; }
}

// Type.java - 类型符号
public class Type extends Symbol {
    public Type(String name) {
        super(name, null);
    }
}

// VariableSymbol.java - 变量符号
public class VariableSymbol extends Symbol {
    public VariableSymbol(String name, Type type) {
        super(name, type);
    }
}

// SymbolTable.java - 符号表
import java.util.*;

public class SymbolTable {
    private Map<String, Symbol> symbols = new LinkedHashMap<>();
    private SymbolTable parent;
    
    public SymbolTable() {
        this(null);
        initPredefinedTypes();
    }
    
    public SymbolTable(SymbolTable parent) {
        this.parent = parent;
        if (parent == null) {
            initPredefinedTypes();
        }
    }
    
    private void initPredefinedTypes() {
        define(new Type("float"));
        define(new Type("int"));
    }
    
    public void define(Symbol sym) {
        symbols.put(sym.getName(), sym);
    }
    
    public Symbol resolve(String name) {
        Symbol sym = symbols.get(name);
        if (sym != null) return sym;
        if (parent != null) return parent.resolve(name);
        return null;
    }
    
    @Override
    public String toString() {
        return symbols.keySet().toString();
    }
}
```

### 2. 监听器实现（推荐用于符号定义和引用分析）

```java
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;

public class CymbolSymbolListener extends CymbolBaseListener {
    private SymbolTable symtab;
    
    public CymbolSymbolListener(SymbolTable symtab) {
        this.symtab = symtab;
    }
    
    @Override
    public void enterCompilationUnit(CymbolParser.CompilationUnitContext ctx) {
        System.out.println("开始分析编译单元");
    }
    
    @Override
    public void exitCompilationUnit(CymbolParser.CompilationUnitContext ctx) {
        System.out.println("分析完成，符号表内容: " + symtab);
    }
    
    @Override
    public void exitVarDeclaration(CymbolParser.VarDeclarationContext ctx) {
        // 获取类型和变量名
        String typeName = ctx.type().getText();
        String varName = ctx.ID().getText();
        int line = ctx.ID().getSymbol().getLine();
        
        // 从符号表解析类型
        Type type = (Type) symtab.resolve(typeName);
        
        // 定义变量符号
        VariableSymbol vs = new VariableSymbol(varName, type);
        symtab.define(vs);
        
        System.out.println("line " + line + ": def " + varName);
    }
    
    @Override
    public void enterType(CymbolParser.TypeContext ctx) {
        int line = ctx.getStart().getLine();
        String typeName = ctx.getText();
        Type type = (Type) symtab.resolve(typeName);
        System.out.println("line " + line + ": ref " + type.getName());
    }
    
    @Override
    public void exitVarRef(CymbolParser.VarRefContext ctx) {
        // 处理变量引用
        String varName = ctx.ID().getText();
        int line = ctx.ID().getSymbol().getLine();
        Symbol sym = symtab.resolve(varName);
        System.out.println("line " + line + ": ref to " + sym);
    }
    
    // 使用示例
    public static void main(String[] args) throws Exception {
        String input = "int i = 2; float f; int j = i + 1;";
        
        CymbolLexer lexer = new CymbolLexer(CharStreams.fromString(input));
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        CymbolParser parser = new CymbolParser(tokens);
        
        ParseTree tree = parser.compilationUnit();
        
        SymbolTable symtab = new SymbolTable();
        CymbolSymbolListener listener = new CymbolSymbolListener(symtab);
        
        ParseTreeWalker walker = new ParseTreeWalker();
        walker.walk(listener, tree);
    }
}
```

### 3. 访问器实现（另一种方式）

```java
public class CymbolSymbolVisitor extends CymbolBaseVisitor<Void> {
    private SymbolTable symtab;
    
    public CymbolSymbolVisitor(SymbolTable symtab) {
        this.symtab = symtab;
    }
    
    @Override
    public Void visitCompilationUnit(CymbolParser.CompilationUnitContext ctx) {
        System.out.println("开始分析编译单元");
        Void result = super.visitCompilationUnit(ctx);
        System.out.println("分析完成，符号表内容: " + symtab);
        return result;
    }
    
    @Override
    public Void visitVarDeclaration(CymbolParser.VarDeclarationContext ctx) {
        String typeName = ctx.type().getText();
        String varName = ctx.ID().getText();
        int line = ctx.ID().getSymbol().getLine();
        
        Type type = (Type) symtab.resolve(typeName);
        VariableSymbol vs = new VariableSymbol(varName, type);
        symtab.define(vs);
        
        System.out.println("line " + line + ": def " + varName);
        
        // 访问子节点（如果有初始化表达式）
        return super.visitVarDeclaration(ctx);
    }
    
    @Override
    public Void visitVarRef(CymbolParser.VarRefContext ctx) {
        String varName = ctx.ID().getText();
        int line = ctx.ID().getSymbol().getLine();
        Symbol sym = symtab.resolve(varName);
        System.out.println("line " + line + ": ref to " + sym);
        return null;
    }
    
    @Override
    public Void visitType(CymbolParser.TypeContext ctx) {
        int line = ctx.getStart().getLine();
        String typeName = ctx.getText();
        Type type = (Type) symtab.resolve(typeName);
        System.out.println("line " + line + ": ref " + type.getName());
        return null;
    }
    
    // 使用示例
    public static void main(String[] args) throws Exception {
        String input = "int i = 2; float f; int j = i + 1;";
        
        CymbolLexer lexer = new CymbolLexer(CharStreams.fromString(input));
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        CymbolParser parser = new CymbolParser(tokens);
        
        ParseTree tree = parser.compilationUnit();
        
        SymbolTable symtab = new SymbolTable();
        CymbolSymbolVisitor visitor = new CymbolSymbolVisitor(symtab);
        visitor.visit(tree);
    }
}
```

## 主要转换说明

1. **去除 `@members` 和参数传递**：符号表现在通过监听器/访问器的构造函数传入
2. **去除 `@init` 和 `@after`**：改用监听器的 `enter/exit` 方法或访问器的 `visit` 方法
3. **去除所有内嵌 `{}` 动作**：语义逻辑全部移到监听器/访问器中
4. **添加标签**：`primary` 规则的各个备选分支使用 `#` 标签（如 `# VarRef`），便于在监听器/访问器中区分
5. **词法规则现代化**：使用 `[0-9]` 替代 `'0'..'9'`，使用 `-> skip` 替代 `$channel=HIDDEN`
6. **正则优化**：`SL_COMMENT` 使用更简洁的 `~[\r\n]*`

这样转换后，语法定义完全与语义逻辑分离，更符合ANTLR4的最佳实践。