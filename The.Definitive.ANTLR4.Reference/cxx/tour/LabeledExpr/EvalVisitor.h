#pragma once

#include <unordered_map>
#include <string>
#include <iostream>
#include "LabeledExprBaseVisitor.h"
#include "LabeledExprParser.h"

class EvalVisitor : public LabeledExprBaseVisitor {
private:
    // "memory" for our calculator; variable/value pairs go here
    std::unordered_map<std::string, int> memory;

public:
    // ID '=' expr NEWLINE
    virtual std::any visitAssign(LabeledExprParser::AssignContext* ctx) override {
        std::string id = ctx->ID()->getText();  // id is left-hand side of '='
        int value = std::any_cast<int>(visit(ctx->expr()));   // compute value of expression on right
        memory[id] = value;           // store it in our memory
        return value;
    }

    // expr NEWLINE
    virtual std::any visitPrintExpr(LabeledExprParser::PrintExprContext* ctx) override {
        int value = std::any_cast<int>(visit(ctx->expr())); // evaluate the expr child
        std::cout << value << std::endl;         // print the result
        return 0;                          // return dummy value
    }

    // INT
    virtual std::any visitInt(LabeledExprParser::IntContext* ctx) override {
        return std::stoi(ctx->INT()->getText());
    }

    // ID
    virtual std::any visitId(LabeledExprParser::IdContext* ctx) override {
        std::string id = ctx->ID()->getText();
        auto it = memory.find(id);
        if (it != memory.end()) {
            return it->second;
        }
        return 0;
    }

    // expr op=('*'|'/') expr
    virtual std::any visitMulDiv(LabeledExprParser::MulDivContext* ctx) override {
        int left = std::any_cast<int>(visit(ctx->expr(0)));  // get value of left subexpression
        int right = std::any_cast<int>(visit(ctx->expr(1))); // get value of right subexpression

        if (ctx->op->getType() == LabeledExprParser::MUL) {
            return left * right;
        }
        return left / right; // must be DIV
    }

    // expr op=('+'|'-') expr
    virtual std::any visitAddSub(LabeledExprParser::AddSubContext* ctx) override {
        int left = std::any_cast<int>(visit(ctx->expr(0)));  // get value of left subexpression
        int right = std::any_cast<int>(visit(ctx->expr(1))); // get value of right subexpression

        if (ctx->op->getType() == LabeledExprParser::ADD) {
            return left + right;
        }
        return left - right; // must be SUB
    }

    // '(' expr ')'
    virtual std::any visitParens(LabeledExprParser::ParensContext* ctx) override {
        return visit(ctx->expr()); // return child expr's value
    }
};
