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
    
    // Helper to get expression from statement context
    CymbolParser::ExpressionContext* getExpression(CymbolParser::StatementContext* ctx) {
        // In C++ runtime, expression() returns the first expression context
        // Since statement has multiple alternatives, we need to check which one matches
        if (ctx->expression()) {
            return ctx->expression();
        }
        // For assignment: expression '=' expression ';'
        // The left expression is the first one
        for (auto* child : ctx->children) {
            if (auto* expr = dynamic_cast<CymbolParser::ExpressionContext*>(child)) {
                return expr;
            }
        }
        return nullptr;        
    }

    Type* getType(CymbolParser::TypeContext* ctx) {
        std::string typeName = ctx->getText();
        Type* tsym = dynamic_cast<Type*>(currentScope->resolve(typeName));
        return tsym;
    }

    void handleAssignment(CymbolParser::ExpressionContext* expr) {
        // Navigate through the expression tree to find the ID
        // expression: addExpression
        if (expr->addExpression()) {
            auto* addExpr = expr->addExpression();
            // addExpression: postfixExpression ('+' postfixExpression)*
            if (addExpr->postfixExpression().size() > 0) {
                auto* postExpr = addExpr->postfixExpression(0);
                // Check if it's a simple ID without function calls
                if (!hasSuffixes(postExpr) && postExpr->primary()) {
                    auto* primary = postExpr->primary();
                    if (primary->ID()) {
                        antlr4::Token* id = primary->ID()->getSymbol();
                        VariableSymbol* vs = dynamic_cast<VariableSymbol*>(
                            currentScope->resolve(id->getText())
                        );
                        if (vs) {
                            std::cout << "line " << id->getLine() << ": assign to " << vs << std::endl;
                        }
                    }
                }
            }
        }
    }

    void handleIdRef(CymbolParser::ExpressionContext* expr) {
        // Navigate through the expression tree to find the ID reference
        if (expr->addExpression()) {
            auto* addExpr = expr->addExpression();
            if (addExpr->postfixExpression().size() > 0) {
                auto* postExpr = addExpr->postfixExpression(0);
                // Only handle simple ID references, not function calls
                if (!hasSuffixes(postExpr) && postExpr->primary()) {
                    auto* primary = postExpr->primary();
                    if (primary->ID()) {
                        antlr4::Token* id = primary->ID()->getSymbol();
                        Symbol* s = currentScope->resolve(id->getText());
                        if (s) {
                            std::cout << "line " << id->getLine() << ": ref " << s << std::endl;
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
        std::cout << "locals: " << currentScope << std::endl;
        currentScope = currentScope->getEnclosingScope();
    }
    
    void enterMethodDeclaration(CymbolParser::MethodDeclarationContext* ctx) override {
        // match method with 0-or-more args
        antlr4::Token* id = ctx->ID()->getSymbol();
        std::cout << "line " << id->getLine() << ": def method " << id->getText() << std::endl;
    
        Type* retType = getType(ctx->type());
        MethodSymbol* ms = new MethodSymbol(id->getText(), retType, currentScope);
        currentScope->define(ms); // def method in globals
        currentScope = ms;       // set current scope to method scope
    }

    void exitMethodDeclaration(CymbolParser::MethodDeclarationContext* ctx) override {
        std::cout << "args: " << currentScope << std::endl;
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
    }
    
    // R e s o l v e  I D s
    void exitStatement(CymbolParser::StatementContext* ctx) override {
        // Handle different statement types based on the structure
        // Check if this is an assignment: expression '=' expression ';'
        bool isAssignment = false;
        for (size_t i = 0; i < ctx->children.size(); i++) {
            if (ctx->children[i]->getText() == "=") {
                isAssignment = true;
                break;
            }
        }

        if (isAssignment && ctx->children.size() >= 3) {
            // Find the left expression (first expression context in children)
            for (auto* child : ctx->children) {
                if (auto* expr = dynamic_cast<CymbolParser::ExpressionContext*>(child)) {
                    handleAssignment(expr);
                    break;
                }
            }
        }
        // Handle expression statements: expression ';'
        else if (!isAssignment) {
            auto* expr = getExpression(ctx);
            if (expr != nullptr) {
                handleIdRef(expr);
            }
        }
    }
};
