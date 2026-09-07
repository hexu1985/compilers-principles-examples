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
    std::vector<Scope*> scopeList;
    std::vector<Symbol*> symbolList;  // Track all created symbols for cleanup

    // Helper to check if postfixExpression has any suffixes (function calls or field access)
    bool hasSuffixes(CymbolParser::PostfixExpressionContext* ctx) {
        // postfixExpression: primary ( '(' expressionList ')' | '.' ID )*
        // If there are more than 1 direct children besides primary, there are suffixes
        return ctx->children.size() > 1;
    }

    bool isAssignment(CymbolParser::StatementContext* ctx) {
        // Check if it's an assignment: postfixExpression '=' expression
        if (ctx->postfixExpression() && ctx->expression()) {
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
        if (!tsym) {
            std::cerr << "Warning: Cannot resolve type '" << typeName << "' at line " 
                      << ctx->getStart()->getLine() << std::endl;
        }
        return tsym;
    }
    
    // Handle assignment: ^('=' ID .)
    void handleAssignment(CymbolParser::PostfixExpressionContext* postExpr) {
        // Only handle simple variable assignments (not field access or function calls)
        if (!hasSuffixes(postExpr) && postExpr->primary()) {
            auto* primary = postExpr->primary();
            if (primary->ID()) {
                antlr4::Token* id = primary->ID()->getSymbol();
                Symbol* sym = currentScope->resolve(id->getText());
                VariableSymbol* vs = dynamic_cast<VariableSymbol*>(sym);
                if (vs) {
                    std::cout << "line " << id->getLine() << ": assign to " << vs->toString() << std::endl;
                }
            }
        }
    }

    // Handle ID reference: {$start.hasAncestor(EXPR)}? ID
    void handleIdRef(CymbolParser::ExpressionContext* expr) {
        if (expr->addExpression()) {
            auto* addExpr = expr->addExpression();
            for (auto* postExpr : addExpr->postfixExpression()) {
                handlePostfixExpressionIdRef(postExpr);
            }
        }
    }

    // Handle ID reference in postfixExpression
    void handlePostfixExpressionIdRef(CymbolParser::PostfixExpressionContext* postExpr) {
        if (!postExpr->primary()) return;
        
        auto* primary = postExpr->primary();
        
        // Simple ID reference
        if (!hasSuffixes(postExpr) && primary->ID()) {
            antlr4::Token* id = primary->ID()->getSymbol();
            Symbol* s = currentScope->resolve(id->getText());
            if (s) {
                std::cout << "line " << id->getLine() << ": ref " << s->toString() << std::endl;
            } else {
                std::cout << "line " << id->getLine() << ": ref null" << std::endl;
            }
        }
    }

public:
    DefRefPhase(SymbolTable* symtab) : symtab(symtab), currentScope(symtab->globals) {
    }

    ~DefRefPhase() {
        // Clean up dynamically allocated scopes
        for (auto* scope : scopeList) {
            delete scope;
        }
        scopeList.clear();

        // Clean up dynamically allocated symbols
        for (auto* sym : symbolList) {
            delete sym;
        }
        symbolList.clear();
    }
    
    // S C O P E S
    void enterBlock(CymbolParser::BlockContext* ctx) override {
        // Push scope
        auto* localScope = new LocalScope(currentScope);
        currentScope = localScope;
        scopeList.push_back(localScope);
    }

    void exitBlock(CymbolParser::BlockContext* ctx) override {
        // Pop scope
        std::cout << "locals: " << currentScope->toString() << std::endl;
        currentScope = currentScope->getEnclosingScope();
    }
    
    void enterMethodDeclaration(CymbolParser::MethodDeclarationContext* ctx) override {
        if (!ctx->ID()) return;

        antlr4::Token* id = ctx->ID()->getSymbol();
        std::cout << "line " << id->getLine() << ": def method " << id->getText() << std::endl;
    
        Type* retType = getType(ctx->type());
        auto* ms = new MethodSymbol(id->getText(), retType, currentScope);
        symbolList.push_back(ms);
        currentScope->define(ms); // Define method in current scope
        currentScope = ms;       // Set current scope to method scope

        // Process formal parameters
        if (ctx->formalParameters()) {
            auto* params = ctx->formalParameters();
            auto types = params->type();
            auto ids = params->ID();

            for (size_t i = 0; i < types.size() && i < ids.size(); i++) {
                antlr4::Token* paramId = ids[i]->getSymbol();
                std::string paramName = paramId->getText();
                Type* paramType = getType(types[i]);

                auto* vs = new VariableSymbol(paramName, paramType);
                symbolList.push_back(vs);
                currentScope->define(vs);

                std::cout << "line " << paramId->getLine() << ": def " << paramName << std::endl;
            }
        }
    }

    void exitMethodDeclaration(CymbolParser::MethodDeclarationContext* ctx) override {
        std::cout << "args: " << currentScope->toString() << std::endl;
        currentScope = currentScope->getEnclosingScope(); // pop arg scope
    }
    
    // D e f i n e  s y m b o l s
    void enterVarDeclaration(CymbolParser::VarDeclarationContext* ctx) override {
        if (!ctx->ID()) return;
        
        antlr4::Token* id = ctx->ID()->getSymbol();
        std::cout << "line " << id->getLine() << ": def " << id->getText() << std::endl;
    
        Type* tsym = getType(ctx->type());
        auto* vs = new VariableSymbol(id->getText(), tsym);
        symbolList.push_back(vs);
        currentScope->define(vs);

        // Handle initializer expression if present
        for (auto* child : ctx->children) {
            if (auto* expr = dynamic_cast<CymbolParser::ExpressionContext*>(child)) {
                handleIdRef(expr);
            }
        }
    }
    
    // R e s o l v e  I D s
    void enterStatement(CymbolParser::StatementContext* ctx) override {
        if (isAssignment(ctx)) {
            // Handle right-hand side expression
            if (ctx->expression()) {
                handleIdRef(ctx->expression());
            }
            // Handle assignment: postfixExpression '=' expression
            if (ctx->postfixExpression()) {
                handleAssignment(ctx->postfixExpression());
            }
        } else {
            // Handle return statement
            if (ctx->expression()) {
                handleIdRef(ctx->expression());
            }
            // Handle other expressions in statement
            for (auto* child : ctx->children) {
                if (auto* postExpr = dynamic_cast<CymbolParser::PostfixExpressionContext*>(child)) {
                    handlePostfixExpressionIdRef(postExpr);
                }
            }
        }
    }
};
