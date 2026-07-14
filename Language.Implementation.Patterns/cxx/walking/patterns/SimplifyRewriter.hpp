#pragma once

#include "antlr4-runtime.h"
#include "VecMathParser.h"
#include "VecMathBaseVisitor.h"
#include <stack>
#include <memory>

class SimplifyRewriter : public VecMathBaseVisitor {
private:
    std::stack<std::any> valueStack;
    
    // 检查是否为整数0
    bool isIntZero(antlr4::tree::ParseTree *node) {
        std::cout << "isIntZero: " << std::endl;
        auto term = dynamic_cast<antlr4::tree::TerminalNode*>(node);
        if (term) {
            return term->getSymbol()->getType() == VecMathParser::INT && 
                   term->getText() == "0";
        }
        std::cout << "isIntZero:  false" << std::endl;
        return false;
    }
    
    // 获取整数值
    int getIntValue(antlr4::tree::ParseTree *node) {
        if (auto term = dynamic_cast<antlr4::tree::TerminalNode*>(node)) {
            return std::stoi(term->getText());
        }
        return 0;
    }

public:
    std::any visitMultExpr(VecMathParser::MultExprContext *ctx) override {
        std::cout << "visitMultExpr: " << std::endl;
        auto children = ctx->children;
        
        if (children.size() >= 3) {
            std::cout << "visitMultExpr1: " << std::endl;
            for (size_t i = 0; i < children.size() - 2; i += 2) {
                auto left = children[i];
                auto op = children[i + 1];
                auto right = children[i + 2];
                
                if (op->getText() == "*") {
                    // 简化规则：0 * x -> 0
                    if (isIntZero(left)) {
                        std::cout << "Applied rule: 0 * x -> 0" << std::endl;
                        return left;
                    }
                    // 简化规则：x * 0 -> 0
                    if (isIntZero(right)) {
                        std::cout << "Applied rule: x * 0 -> 0" << std::endl;
                        return right;
                    }
                    // 简化规则：scalar * VEC -> VEC(scalar * elements)
                    if (dynamic_cast<antlr4::tree::TerminalNode*>(left) && 
                        left->getText().find('[') != std::string::npos) {
                        // 向量乘法简化
                        std::cout << "Applied rule: scalar * VEC -> VEC(scalar * elements)" << std::endl;
                    }
                }
            }
        }
        
        return visitChildren(ctx);
    }
    
    std::any visitExpr(VecMathParser::ExprContext *ctx) override {
        auto children = ctx->children;
        
        if (children.size() >= 3) {
            for (size_t i = 0; i < children.size() - 2; i += 2) {
                auto left = children[i];
                auto op = children[i + 1];
                auto right = children[i + 2];
                
                if (op->getText() == "+") {
                    // 可以添加加法简化规则
                }
            }
        }
        
        return visitChildren(ctx);
    }
};

