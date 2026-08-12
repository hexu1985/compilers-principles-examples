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
    }
    
    // R e s o l v e  I D s
    void enterStatement(CymbolParser::StatementContext* ctx) {
        if (isAssignment(ctx)) {
            // 处理赋值语句
            auto primary = ctx->expression()->addExpression()->postfixExpression()[0]->primary();
            if (primary && primary->ID()) {
                auto id = primary->ID()->getSymbol();
                auto vs = dynamic_cast<VariableSymbol*>(currentScope->resolve(id->getText()));
                
                if (vs) {
                    std::cout << "line " << id->getLine() << ": assign to " << vs->toString() << std::endl;
                }
            }
        }
    }

    void enterPrimary(CymbolParser::PrimaryContext* ctx) {
        if (ctx->ID()) {
            auto id = ctx->ID()->getSymbol();
            auto s = currentScope->resolve(id->getText());

            if (s) {
                std::cout << "line " << id->getLine() << ": ref " << s->toString() << std::endl;
            } else {
                std::cout << "line " << id->getLine() << ": ref null" << std::endl;
            }
        }
    }
};
