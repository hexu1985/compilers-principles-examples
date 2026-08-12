#pragma once

#include "CymbolBaseListener.h"
#include "SymbolTable.hpp"
#include "Scope.hpp"
#include "Type.hpp"
#include "Symbol.hpp"
#include "VariableSymbol.hpp"
#include "MethodSymbol.hpp"
#include "LocalScope.hpp"

#include <iostream>
#include <vector>

using namespace antlr4;

class DefRefPhase : public CymbolBaseListener {
private:
    SymbolTable* symtab=nullptr;
    Scope* currentScope=nullptr;
    std::vector<Scope*> localScopeList;

    // Helper to check if postfixExpression has any suffixes
    bool hasSuffixes(CymbolParser::PostfixExpressionContext* ctx) {
        // In C++ ANTLR4 runtime, we need to check the children directly
        // postfixExpression: primary postfixExpressionSuffix*
        // So if we have more than 1 child, it means we have suffixes
        return ctx->children.size() > 1;
    }

    bool isAssignment(CymbolParser::StatementContext* ctx) {
        // 检查是否是赋值语句：表达式 '=' 表达式
        if (ctx->expression() && ctx->children.size() >= 3) {
            for (size_t i = 0; i < ctx->children.size(); i++) {
                if (ctx->children[i]->getText() == "=") {
                    return true;
                }
            }
        }
        return false;
    }

    Type* getType(CymbolParser::TypeContext* ctx) {
        std::string typeName = ctx->getText();
        Type* tsym = dynamic_cast<Type*>(currentScope->resolve(typeName));
        return tsym;
    }
    
    void handleAssignment(CymbolParser::PostfixExpressionContext* postExpr) {
        // Check if it's a simple ID without function calls
        if (!hasSuffixes(postExpr) && postExpr->primary()) {
            auto* primary = postExpr->primary();
            if (primary->ID()) {
                antlr4::Token* id = primary->ID()->getSymbol();
                VariableSymbol* vs = dynamic_cast<VariableSymbol*>(
                    currentScope->resolve(id->getText())
                );
                if (vs) {
                    std::cout << "line " << id->getLine() << ": assign to " << vs->toString() << std::endl;
                }
            }
        }
    }

    void handleIdRef(CymbolParser::ExpressionContext* expr) {
        // Navigate through the expression tree to find the ID reference
        if (expr->addExpression()) {
            auto* addExpr = expr->addExpression();
            if (addExpr->postfixExpression().size() > 0) {
                for (auto* postExpr : addExpr->postfixExpression()) {
                    // Only handle simple ID references, not function calls
                    if (!hasSuffixes(postExpr) && postExpr->primary()) {
                        auto* primary = postExpr->primary();
                        if (primary->ID()) {
                            antlr4::Token* id = primary->ID()->getSymbol();
                            Symbol* s = currentScope->resolve(id->getText());
                            if (s) {
                                std::cout << "line " << id->getLine() << ": ref " << s->toString() << std::endl;
                            } else {
                                std::cout << "line " << id->getLine() << ": ref null" << std::endl;
                            }
                        }
                    }
                }
            }
        }        
    }

public:
    DefRefPhase(SymbolTable* symtab): symtab(symtab), currentScope(symtab->globals) {
    }

    ~DefRefPhase() {
        for (auto localScope: localScopeList) {
            delete localScope;
        }
        localScopeList.clear();
    }
    
    // S C O P E S
    void enterBlock(CymbolParser::BlockContext* ctx) override {
        // push scope
        currentScope = new LocalScope(currentScope);
        localScopeList.push_back(currentScope);
    }

    void exitBlock(CymbolParser::BlockContext* ctx) override {
        // pop scope
        std::cout << "locals: " << currentScope->toString() << std::endl;
        currentScope = currentScope->getEnclosingScope();
    }
    
    void enterMethodDeclaration(CymbolParser::MethodDeclarationContext* ctx) override {
        if (!ctx->ID()) return;

        // match method with 0-or-more args
        antlr4::Token* id = ctx->ID()->getSymbol();
        std::cout << "line " << id->getLine() << ": def method " << id->getText() << std::endl;
    
        Type* retType = getType(ctx->type());
        MethodSymbol* ms = new MethodSymbol(id->getText(), retType, currentScope);
        currentScope->define(ms); // def method in globals
        currentScope = ms;       // set current scope to method scope
    }

    void exitMethodDeclaration(CymbolParser::MethodDeclarationContext* ctx) override {
        std::cout << "args: " << currentScope->toString() << std::endl;
        currentScope = currentScope->getEnclosingScope(); // pop arg scope
    }
    
    // D e f i n e  s y m b o l s
    void enterVarDeclaration(CymbolParser::VarDeclarationContext* ctx) override {
        // global, parameter, or local variable
        antlr4::Token* id = ctx->ID()->getSymbol();
        std::cout << "line " << id->getLine() << ": def " << id->getText() << std::endl;
    
        Type* tsym = getType(ctx->type());
        VariableSymbol* vs = new VariableSymbol(id->getText(), tsym);
        currentScope->define(vs);

        for (auto* child : ctx->children) {
            if (auto* expr = dynamic_cast<CymbolParser::ExpressionContext*>(child)) {
                handleIdRef(expr);
            }
        }
    }
    
    // R e s o l v e  I D s
    void enterStatement(CymbolParser::StatementContext* ctx) {
        if (isAssignment(ctx)) {
            // Find the left expression (first expression context in children)
            for (int i = ctx->children.size()-1; i >= 0; i--) {
                auto* child = ctx->children[i];
                if (auto* postExpr = dynamic_cast<CymbolParser::PostfixExpressionContext*>(child)) {
                    handleAssignment(postExpr);
                } else if (auto* expr = dynamic_cast<CymbolParser::ExpressionContext*>(child)) {
                    handleIdRef(expr);
                }
            }
        } else {
            for (auto* child : ctx->children) {
                if (auto* expr = dynamic_cast<CymbolParser::ExpressionContext*>(child)) {
                    handleIdRef(expr);
                }
            }
        }
    }
};
