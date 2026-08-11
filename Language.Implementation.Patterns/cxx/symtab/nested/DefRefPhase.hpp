#pragma once

#include "CymbolBaseListener.h"
#include "SymbolTable.hpp"
#include "Scope.hpp"
#include "Type.hpp"
#include "Symbol.hpp"
#include "VariableSymbol.hpp"
#include "MethodSymbol.hpp"

#include <iostream>
#include <stack>

using namespace antlr4;

class DefRefPhase : public CymbolBaseListener {
private:
    SymbolTable* symtab=nullptr;
    Scope* currentScope=nullptr;
    std::stack<Scope*> scopeStack;
    
    Type* getType(CymbolParser::TypeContext* ctx) {
        std::string typeName = ctx->getText();
        Type* tsym = dynamic_cast<Type*>(currentScope->resolve(typeName));
        return tsym;
    }

    void handleAssignment(CymbolParser::ExpressionContext* expr) {
        // Check if this is an ID assignment
        if (expr->children.size() == 1) {
            CymbolParser::AddExpressionContext* addExpr = expr->addExpression();
            if (addExpr->children.size() == 1) {
                CymbolParser::PostfixExpressionContext* postExpr = addExpr->postfixExpression(0);
                if (postExpr->postfixExpressionSuffix().size() == 0) {
                    CymbolParser::PrimaryContext* primary = postExpr->primary();
                    if (primary->ID() != nullptr) {
                        antlr4::Token* id = primary->ID()->getSymbol();
                        VariableSymbol* vs = dynamic_cast<VariableSymbol*>(
                            currentScope->resolve(id->getText())
                        );
                        std::cout << "line " << id->getLine() << ": assign to " << vs << std::endl;
                    }
                }
            }
        }
    }

    void handleIdRef(CymbolParser::ExpressionContext* expr) {
        // Check if this expression contains an ID reference
        if (expr->children.size() == 1) {
            CymbolParser::AddExpressionContext* addExpr = expr->addExpression();
            if (addExpr->children.size() == 1) {
                CymbolParser::PostfixExpressionContext* postExpr = addExpr->postfixExpression(0);
                if (postExpr->postfixExpressionSuffix().size() == 0) {
                    CymbolParser::PrimaryContext* primary = postExpr->primary();
                    if (primary->ID() != nullptr) {
                        antlr4::Token* id = primary->ID()->getSymbol();
                        Symbol* s = currentScope->resolve(id->getText());
                        std::cout << "line " << id->getLine() << ": ref " << s << std::endl;
                    }
                }
            }
        }        
    }

public:
    DefRefPhase(SymbolTable* symtab): symtab(symtab), currentScope(symtab->globals) {
    }

    ~DefRefPhase() = default;
    
    // S C O P E S
    void enterBlock(CymbolParser::BlockContext* ctx) override {
        // push scope
        scopeStack.push(currentScope);
        currentScope = new LocalScope(currentScope);
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
        scopeStack.push(currentScope);
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
        // Handle assignment: expression '=' expression ';'
        if (ctx->children.size() >= 3 && ctx->children[1]->getText() == "=") {
            CymbolParser::ExpressionContext* leftExpr = ctx->expression(0);
            handleAssignment(leftExpr);
        }
        // Handle idref: expression ';'
        else if (ctx->children.size() == 2 && ctx->expression(0) != nullptr) {
            handleIdRef(ctx->expression(0));
        }
    }
};
