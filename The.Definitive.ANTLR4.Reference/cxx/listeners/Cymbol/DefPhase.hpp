#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>
#include <memory>

#include "GlobalScope.hpp"
#include "FunctionSymbol.hpp"
#include "LocalScope.hpp"
#include "VariableSymbol.hpp"
#include "CheckSymbols.hpp"

#include <antlr4-runtime.h>
#include "CymbolBaseListener.h"

class DefPhase : public CymbolBaseListener {
public:
    // ParseTreeProperty<Scope> replacement
    std::unordered_map<antlr4::ParserRuleContext*, Scope*> scopes;
    GlobalScope* globals=nullptr;
    Scope* currentScope=nullptr; // define symbols in this scope
    std::vector<VariableSymbol*> variableSymbols;

public:
    DefPhase() : globals(nullptr), currentScope(nullptr) {}

    virtual ~DefPhase() {
        for (auto var: variableSymbols) {
            delete var;
        }
        for (auto item: scopes) {
            auto scope = item.second;
            delete scope;
        }
        delete globals;
    }

    void enterFile(CymbolParser::FileContext* ctx) override {
        globals = new GlobalScope(nullptr);
        currentScope = globals;
    }
    
    void exitFile(CymbolParser::FileContext* ctx) override {
        std::cout << globals->toString() << std::endl;
    }

    void enterFunctionDecl(CymbolParser::FunctionDeclContext* ctx) override {
        std::string name = ctx->ID()->getText();
        int typeTokenType = ctx->type()->start->getType();
        Symbol::Type type = CheckSymbols::getType(typeTokenType);
        
        // push new scope by making new one that points to enclosing scope
        FunctionSymbol* function = new FunctionSymbol(name, type, currentScope);
        currentScope->define(function); // Define function in current scope
        saveScope(ctx, function);      // Push: set function's parent to current
        currentScope = function;       // Current scope is now function scope
    }

    void saveScope(antlr4::ParserRuleContext* ctx, Scope* s) { 
        scopes[ctx] = s; 
    }

    void exitFunctionDecl(CymbolParser::FunctionDeclContext* ctx) override {
        std::cout << currentScope->toString() << std::endl;
        currentScope = currentScope->getEnclosingScope(); // pop scope
    }

    void enterBlock(CymbolParser::BlockContext* ctx) override {
        // push new local scope
        currentScope = new LocalScope(currentScope);
        saveScope(ctx, currentScope);
    }

    void exitBlock(CymbolParser::BlockContext* ctx) override {
        std::cout << currentScope->toString() << std::endl;
        currentScope = currentScope->getEnclosingScope(); // pop scope
    }

    void exitFormalParameter(CymbolParser::FormalParameterContext* ctx) override {
        defineVar(ctx->type(), ctx->ID()->getSymbol());
    }

    void exitVarDecl(CymbolParser::VarDeclContext* ctx) override {
        defineVar(ctx->type(), ctx->ID()->getSymbol());
    }

    void defineVar(CymbolParser::TypeContext* typeCtx, antlr4::Token* nameToken) {
        int typeTokenType = typeCtx->start->getType();
        Symbol::Type type = CheckSymbols::getType(typeTokenType);
        VariableSymbol* var = new VariableSymbol(nameToken->getText(), type);
        variableSymbols.push_back(var);
        currentScope->define(var); // Define symbol in current scope
    }

    // Accessor methods if needed
    Scope* getCurrentScope() const { return currentScope; }
    GlobalScope* getGlobals() const { return globals; }
    
    // Get scope for a context
    Scope* getScope(antlr4::ParserRuleContext* ctx) const {
        auto it = scopes.find(ctx);
        return (it != scopes.end()) ? it->second : nullptr;
    }
};
