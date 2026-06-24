#pragma once

#include <unordered_map>
#include <string>

#include "GlobalScope.hpp"
#include "FunctionSymbol.hpp"
#include "VariableSymbol.hpp"
#include "CheckSymbols.hpp"

#include "CymbolBaseListener.h"

class RefPhase : public CymbolBaseListener {
private:
    std::unordered_map<antlr4::ParserRuleContext*, Scope*> scopes;
    GlobalScope* globals=nullptr;
    Scope* currentScope=nullptr; // resolve symbols starting in this scope

public:
    RefPhase(GlobalScope* globals_, std::unordered_map<antlr4::ParserRuleContext*, Scope*>& scopes_)
        : scopes(scopes_), globals(globals_), currentScope(nullptr) {
    }

    // Alternative constructor using const reference
    RefPhase(GlobalScope* globals_, const std::unordered_map<antlr4::ParserRuleContext*, Scope*>& scopes_)
        : scopes(scopes_), globals(globals_), currentScope(nullptr) {}

    void enterFile(CymbolParser::FileContext* ctx) override {
        currentScope = globals;
    }

    void enterFunctionDecl(CymbolParser::FunctionDeclContext* ctx) override {
        auto it = scopes.find(ctx);
        if (it != scopes.end()) {
            currentScope = it->second;
        }
    }

    void exitFunctionDecl(CymbolParser::FunctionDeclContext* ctx) override {
        if (currentScope) {
            currentScope = currentScope->getEnclosingScope();
        }
    }
    
    void enterBlock(CymbolParser::BlockContext* ctx) override {
        auto it = scopes.find(ctx);
        if (it != scopes.end()) {
            currentScope = it->second;
        }
    }

    void exitBlock(CymbolParser::BlockContext* ctx) override {
        if (currentScope) {
            currentScope = currentScope->getEnclosingScope();
        }
    }

    void exitVar(CymbolParser::VarContext* ctx) override {
        std::string name = ctx->ID()->getSymbol()->getText();
        Symbol* var = currentScope->resolve(name);
        if (var == nullptr) {
            CheckSymbols::error(ctx->ID()->getSymbol(), "no such variable: " + name);
        }
        if (dynamic_cast<FunctionSymbol*>(var) != nullptr) {
            CheckSymbols::error(ctx->ID()->getSymbol(), name + " is not a variable");
        }
    }

    void exitCall(CymbolParser::CallContext* ctx) override {
        // can only handle f(...) not expr(...)
        std::string funcName = ctx->ID()->getText();
        Symbol* meth = currentScope->resolve(funcName);
        if (meth == nullptr) {
            CheckSymbols::error(ctx->ID()->getSymbol(), "no such function: " + funcName);
        }
        if (dynamic_cast<VariableSymbol*>(meth) != nullptr) {
            CheckSymbols::error(ctx->ID()->getSymbol(), funcName + " is not a function");
        }
    }

    // Accessor methods
    Scope* getCurrentScope() const { return currentScope; }
    GlobalScope* getGlobals() const { return globals; }
};
