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
        auto primary = dynamic_cast<VecMathParser::PrimaryContext*>(node);
        if (primary) {
            if (primary->INT()) {
                return primary->INT()->getText() == "0";
            }
        }
        return false;
    }

    bool isScalar(antlr4::tree::ParseTree *node) {
        auto primary = dynamic_cast<VecMathParser::PrimaryContext*>(node);
        if (primary) {
            return true;
        }
        return false;
    }
    
public:
#if 1
    std::any visitMultExpr(VecMathParser::MultExprContext *ctx) override {
        auto children = ctx->children;
        
        if (children.size() >= 3) {
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
                    if (isScalar(left) &&
                        right->getText().find('[') != std::string::npos) {
                        // 向量乘法简化
                        std::cout << "Applied rule: scalar * VEC -> VEC(scalar * elements)" << std::endl;
                    }
                }
            }
        }
        
        return visitChildren(ctx);
    }
#else
    std::any visitMultExpr(VecMathParser::MultExprContext *ctx) override {
        std::cout << "\n=== MultExpr Debug ===" << std::endl;

        for (size_t i = 0; i < ctx->children.size(); i++) {
            auto* child = ctx->children[i];
            std::cout << "Child[" << i << "]: " << child->getText() << std::endl;
            std::cout << "  Type: " << typeid(*child).name() << std::endl;

            // 尝试各种转换
            if (dynamic_cast<antlr4::tree::TerminalNode*>(child)) {
                auto* term = dynamic_cast<antlr4::tree::TerminalNode*>(child);
                std::cout << "  Is TerminalNode: YES" << std::endl;
                std::cout << "  Token type: " << term->getSymbol()->getType() << std::endl;
                std::cout << "  Token text: '" << term->getText() << "'" << std::endl;

                if (term->getSymbol()->getType() == VecMathParser::INT) {
                    std::cout << "  Is INT: YES, Value = " << std::stoi(term->getText()) << std::endl;
                }
            } else if (dynamic_cast<VecMathParser::PrimaryContext*>(child)) {
                std::cout << "  Is PrimaryContext: YES" << std::endl;
                auto* primary = dynamic_cast<VecMathParser::PrimaryContext*>(child);
                if (primary->INT()) {
                    std::cout << "  Contains INT: " << primary->INT()->getText() << std::endl;
                }
            } else if (dynamic_cast<antlr4::RuleContext*>(child)) {
                std::cout << "  Is RuleContext: YES" << std::endl;
            } else {
                std::cout << "  Is Other type" << std::endl;
            }
        }

        return visitChildren(ctx);
    }
#endif
    
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

