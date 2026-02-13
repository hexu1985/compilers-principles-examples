#pragma once

#include <string>
#include <stdexcept>

// 前置声明 Token 类（需在其他地方定义）
class Token;

class Lexer {
public:
    // 常量：用 int 表示文件结束，避免 char 的符号问题
#ifndef EOF
    static const int EOF = -1;
#endif
    static const int EOF_TYPE = 1;

protected:
    std::string input;   // 输入字符串
    int p;               // 当前字符索引
    int c;               // 当前字符（int 类型，可安全表示 EOF）

public:
    // 构造函数：初始化输入和当前字符
    Lexer(const std::string& input) : input(input), p(0) {
        if (input.empty())
            c = EOF;
        else
            c = static_cast<unsigned char>(input[0]); // 提升为 int，保证非负
    }

    virtual ~Lexer() = default;   // 虚析构函数，保证多态

    // 消耗一个字符，到达末尾时置为 EOF
    void consume() {
        ++p;
        if (p >= static_cast<int>(input.length()))
            c = EOF;
        else
            c = static_cast<unsigned char>(input[p]);
    }

    // 确保下一个字符与 x 匹配，否则抛出异常
    void match(char x) {
        if (c == x) {
            consume();
        } else {
            std::string msg = "expecting ";
            msg += x;
            msg += "; found ";
            if (c == EOF)
                msg += "EOF";
            else
                msg += static_cast<char>(c);
            throw std::runtime_error(msg);
        }
    }

    // 抽象方法：获取下一个 Token
    virtual Token* nextToken() = 0;

    // 抽象方法：根据 token 类型获取其名称
    virtual std::string getTokenName(int tokenType) = 0;
};
