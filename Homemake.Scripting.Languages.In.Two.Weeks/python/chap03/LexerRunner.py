import tkinter as tk
from stone.Lexer import Lexer
from stone.Token import Token

def on_ok():
    """OK 按钮的回调函数：获取输入内容并显示，然后关闭窗口"""
    user_input = text_input.get("1.0", tk.END).strip()  # 获取全部文本
    l = Lexer(user_input)
    t = l.read()
    while t != Token.EOF:
        print("=> " + t.getText())
        t = l.read()

def on_cancel():
    """Cancel 按钮的回调函数：直接关闭窗口"""
    root.destroy()

# 创建主窗口
root = tk.Tk()
root.title("文本输入对话框")
root.geometry("400x300")  # 窗口大小

# 多行文本输入框（带滚动条）
frame = tk.Frame(root)
frame.pack(pady=10)

scrollbar = tk.Scrollbar(frame)
scrollbar.pack(side=tk.RIGHT, fill=tk.Y)

text_input = tk.Text(
    frame,
    height=10,
    width=40,
    yscrollcommand=scrollbar.set,
    wrap=tk.WORD  # 自动换行
)
text_input.pack(side=tk.LEFT, fill=tk.BOTH)

scrollbar.config(command=text_input.yview)

# 按钮区域
button_frame = tk.Frame(root)
button_frame.pack(pady=10)

btn_ok = tk.Button(
    button_frame,
    text="OK",
    width=10,
    command=on_ok
)
btn_ok.pack(side=tk.LEFT, padx=10)

btn_cancel = tk.Button(
    button_frame,
    text="Cancel",
    width=10,
    command=on_cancel
)
btn_cancel.pack(side=tk.LEFT)

# 运行主循环
root.mainloop()
