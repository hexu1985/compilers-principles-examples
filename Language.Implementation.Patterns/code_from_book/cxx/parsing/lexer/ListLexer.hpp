#pragma once

#include "Token.hpp"
#include "Lexer.hpp"

#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>

// 前置声明（假设 Token 和 Lexer 已在其他头文件中定义）
class Token;

class ListLexer : public Lexer {
public:
    // 静态常量，在类内初始化（C++允许整型常量直接初始化）
    static const int NAME = 2;
    static const int COMMA = 3;
    static const int LBRACK = 4;
    static const int RBRACK = 5;

    // 静态字符串数组声明（必须在类外定义）
    static const char* tokenNames[];

    // 构造函数：直接调用基类构造函数
    ListLexer(const std::string& input) : Lexer(input) {}

    // 实现 getTokenName
    std::string getTokenName(int x) override {
        if (x >= 0 && x < 6)  // 数组大小已知为 6
            return tokenNames[x];
        else
            return "UNKNOWN";
    }

    // 判断当前字符是否为字母
    bool isLETTER() const {
        // c 是 int 类型，可能为 EOF(-1)，但调用此函数时已确保 c != EOF
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    // 获取下一个 Token，返回动态分配的 Token 对象（调用者负责释放）
    Token* nextToken() override {
        while (c != EOF) {
            switch (c) {
                case ' ':
                case '\t':
                case '\n':
                case '\r':
                    WS();
                    continue;
                case ',':
                    consume();
                    return new Token(COMMA, ",");
                case '[':
                    consume();
                    return new Token(LBRACK, "[");
                case ']':
                    consume();
                    return new Token(RBRACK, "]");
                default:
                    if (isLETTER())
                        return NAME_();
                    throw std::runtime_error(std::string("invalid character: ") + static_cast<char>(c));
            }
        }
        return new Token(EOF_TYPE, "<EOF>");
    }

    // 识别 NAME 词法单元
    Token* NAME_() {
        std::string buf;
        do {
            buf.push_back(static_cast<char>(c));
            consume();
        } while (isLETTER());
        return new Token(NAME, buf);
    }

    // 忽略空白字符
    void WS() {
        while (c == ' ' || c == '\t' || c == '\n' || c == '\r')
            consume();
    }
};
