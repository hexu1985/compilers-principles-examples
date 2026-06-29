// PrinterListener.java - 单独的监听器类
import org.antlr.v4.runtime.tree.TerminalNode;

public class PrinterListener extends VecMathBaseListener {
    private void print(String s) {
        System.out.print(s);
    }
    
    @Override
    public void enterAssignStat(VecMathParser.AssignStatContext ctx) {
        print(ctx.ID().getText() + " = ");
    }
    
    @Override
    public void enterPrintStat(VecMathParser.PrintStatContext ctx) {
        print("print ");
    }
    
    @Override
    public void exitAssignStat(VecMathParser.AssignStatContext ctx) {
        print("\n");
    }
    
    @Override
    public void exitPrintStat(VecMathParser.PrintStatContext ctx) {
        print("\n");
    }
    
    @Override
    public void enterExpr(VecMathParser.ExprContext ctx) {
        // 处理'+'操作符
        if (ctx.getChildCount() == 3 && ctx.getChild(1).getText().equals("+")) {
            // 在进入时打印运算符可能不太方便
            // 更好的做法是在退出时处理
        }
    }
    
    @Override
    public void exitExpr(VecMathParser.ExprContext ctx) {
        // 如果表达式是二元的，打印运算符
        if (ctx.getChildCount() == 3) {
            String op = ctx.getChild(1).getText();
            if (op.equals("+") || op.equals("*") || op.equals(".")) {
                print(op);
            }
        }
    }
    
    @Override
    public void visitTerminal(TerminalNode node) {
        String text = node.getText();
        if (text.matches("[0-9]+") || text.matches("[a-z]+")) {
            print(text);
        }
        // 处理VEC（向量）的打印逻辑比较复杂
        // 需要在enter/exit方法中处理
    }
}
