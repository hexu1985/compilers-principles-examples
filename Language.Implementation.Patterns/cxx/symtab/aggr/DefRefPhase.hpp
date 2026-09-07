#pragma once

#include "CymbolBaseListener.h"
#include "SymbolTable.hpp"
#include "Scope.hpp"
#include "Type.hpp"
#include "Symbol.hpp"
#include "VariableSymbol.hpp"
#include "MethodSymbol.hpp"
#include "StructSymbol.hpp"
#include "LocalScope.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <stack>

using namespace antlr4;

class DefRefPhase : public CymbolBaseListener {
private:
    SymbolTable* symtab=nullptr;
    Scope* currentScope=nullptr;
    std::vector<Scope*> scopeList;
    std::vector<Symbol*> symbolList;  // Track all created symbols for cleanup
    std::stack<bool> inStructScope;   // Track if we're inside a struct declaration

    // Helper to check if postfixExpression has any suffixes (function calls or field access)
    bool hasSuffixes(CymbolParser::PostfixExpressionContext* ctx) {
        return ctx->children.size() > 1;
    }

    // Check if this postfixExpression is a function call
    bool isFunctionCall(CymbolParser::PostfixExpressionContext* ctx) {
        for (auto* child : ctx->children) {
            if (child->getText() == "(") {
                return true;
            }
        }
        return false;
    }

    // Check if this postfixExpression has field access
    bool hasFieldAccess(CymbolParser::PostfixExpressionContext* ctx) {
        for (auto* child : ctx->children) {
            if (child->getText() == ".") {
                return true;
            }
        }
        return false;
    }

    // Check if this statement is an assignment
    bool isAssignment(CymbolParser::StatementContext* ctx) {
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

    // Resolve member access: a.b.c
    Type* resolveMember(CymbolParser::PostfixExpressionContext* postExpr) {
        if (!postExpr->primary() || !postExpr->primary()->ID()) {
            return nullptr;
        }

        antlr4::Token* firstId = postExpr->primary()->ID()->getSymbol();
        Symbol* s = currentScope->resolve(firstId->getText());
        
        if (!s) {
            std::cout << "line " << firstId->getLine() << ": ref " 
                      << firstId->getText() << "=null" << std::endl;
            return nullptr;
        }

        Type* currentType = s->type;
        std::cout << "line " << firstId->getLine() << ": ref " 
                  << firstId->getText() << "=" << s->toString() << std::endl;

        // Process field accesses: .ID
        if (hasFieldAccess(postExpr)) {
            std::string fullPath = firstId->getText();
            
            for (size_t i = 0; i < postExpr->children.size(); i++) {
                auto* child = postExpr->children[i];
                if (child->getText() == ".") {
                    // Next sibling should be the field ID
                    if (i + 1 < postExpr->children.size()) {
                        auto* fieldNode = postExpr->children[i + 1];
                        std::string fieldName = fieldNode->getText();
                        fullPath += "." + fieldName;
                        
                        auto* structSym = dynamic_cast<StructSymbol*>(currentType);
                        if (structSym && currentType) {
                            Symbol* fieldSym = structSym->resolveMember(fieldName);
                            if (fieldSym) {
                                std::cout << "line " << firstId->getLine() << ": ref "
                                          << fullPath << "=" << fieldSym->toString() << std::endl;
                                currentType = fieldSym->type;
                            } else {
                                std::cout << "line " << firstId->getLine() << ": ref "
                                          << fullPath << "=null" << std::endl;
                                return nullptr;
                            }
                        } else {
                            std::cout << "line " << firstId->getLine() << ": ref "
                                      << fullPath << "=null (not a struct)" << std::endl;
                            return nullptr;
                        }
                    }
                }
            }
        }
        
        return currentType;
    }

    // Handle assignment: ^( eq='=' member . )
    void handleAssignment(CymbolParser::StatementContext* ctx) {
        if (!ctx->postfixExpression()) return;
        
        auto* postExpr = ctx->postfixExpression();
        antlr4::Token* eqToken = nullptr;
        
        // Find the '=' token
        for (auto* child : ctx->children) {
            if (child->getText() == "=") {
                if (auto* termNode = dynamic_cast<antlr4::tree::TerminalNode*>(child)) {
                    eqToken = termNode->getSymbol();
                }
                break;
            }
        }
        
        // Resolve the member type
        Type* memberType = resolveMember(postExpr);
        
        if (eqToken && memberType) {
            std::cout << "line " << eqToken->getLine() << ": assign to type "
                      << memberType->getName() << std::endl;
        }
    }

public:
    DefRefPhase(SymbolTable* symtab) : symtab(symtab), currentScope(symtab->globals) {
        inStructScope.push(false);
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
        scopeList.push_back(localScope);
        currentScope = localScope;
    }

    void exitBlock(CymbolParser::BlockContext* ctx) override {
        // Pop scope
        std::cout << "locals: " << currentScope->toString() << std::endl;
        currentScope = currentScope->getEnclosingScope();
    }
    
    // START: struct
    void enterStructDeclaration(CymbolParser::StructDeclarationContext* ctx) override {
        if (!ctx->ID()) return;
        
        antlr4::Token* id = ctx->ID()->getSymbol();
        std::cout << "line " << id->getLine() << ": def struct " << id->getText() << std::endl;
        
        auto* ss = new StructSymbol(id->getText(), currentScope);
        symbolList.push_back(ss);
        currentScope->define(ss); // Define struct in current scope
        currentScope = ss;       // Set current scope to struct scope
        inStructScope.push(true);
    }

    void exitStructDeclaration(CymbolParser::StructDeclarationContext* ctx) override {
        std::cout << "fields: " << currentScope->toString() << std::endl;
        currentScope = currentScope->getEnclosingScope(); // Pop scope
        inStructScope.pop();
    }
    // END: struct

    // 新增：处理结构体成员
    void enterStructMember(CymbolParser::StructMemberContext* ctx) override {
        // 处理字段声明: type ID ';'
        if (ctx->type() && ctx->ID()) {
            antlr4::Token* id = ctx->ID()->getSymbol();
            Type* tsym = getType(ctx->type());
            
            if (tsym) {
                auto* vs = new VariableSymbol(id->getText(), tsym);
                symbolList.push_back(vs);
                currentScope->define(vs);
                
                std::cout << "line " << id->getLine() << ": def " << id->getText() << std::endl;
            }
        }
        // 如果是嵌套的结构体声明，会由 enterStructDeclaration 处理
    }

    void enterMethodDeclaration(CymbolParser::MethodDeclarationContext* ctx) override {
        if (!ctx->ID()) return;

        antlr4::Token* id = ctx->ID()->getSymbol();
        std::cout << "line " << id->getLine() << ": def method " << id->getText() << std::endl;
    
        Type* retType = getType(ctx->type());
        MethodSymbol* ms = new MethodSymbol(id->getText(), retType, currentScope);
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

                std::cout << "line " << paramId->getLine() << ": def " 
                          << paramName << std::endl;
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
                resolveExpression(expr);
            }
        }
    }
    
    // R e s o l v e  I D s
    void enterStatement(CymbolParser::StatementContext* ctx) override {
        if (isAssignment(ctx)) {
            // Handle right-hand side expression
            if (ctx->expression()) {
                resolveExpression(ctx->expression());
            }
			// Handle assignment
            handleAssignment(ctx);
        } else {
            // Handle return statement
            if (ctx->expression()) {
                resolveExpression(ctx->expression());
            }
            
            // Handle other postfix expressions (function calls, etc.)
            for (auto* child : ctx->children) {
                if (auto* postExpr = dynamic_cast<CymbolParser::PostfixExpressionContext*>(child)) {
                    resolveMember(postExpr);
                }
            }
        }
    }
    
    // Helper method to resolve expression
    void resolveExpression(CymbolParser::ExpressionContext* expr) {
        if (expr->addExpression()) {
            auto* addExpr = expr->addExpression();
            for (auto* postExpr : addExpr->postfixExpression()) {
                resolveMember(postExpr);
            }
        }
    }
};
