#pragma once

#include "Symbol.hpp"
#include "Scope.hpp"
#include <unordered_map>
#include <string>
#include <vector>

class MethodSymbol : public Symbol, public Scope {
private:
    std::unordered_map<std::string, Symbol*> orderedArgs;
    Scope* enclosingScope;

public:
    MethodSymbol(const std::string& name, Type* retType, Scope* enclosingScope)
        : Symbol(name, retType), enclosingScope(enclosingScope) {}

    // Scope interface implementation
    Symbol* resolve(const std::string& name) override {
        auto it = orderedArgs.find(name);
        if (it != orderedArgs.end()) {
            return it->second;
        }
        // if not here, check any enclosing scope
        if (getEnclosingScope() != nullptr) {
            return getEnclosingScope()->resolve(name);
        }
        return nullptr; // not found
    }

    void define(Symbol* sym) override {
        orderedArgs[sym->name] = sym;
        sym->scope = this; // track the scope in each symbol
    }

    Scope* getEnclosingScope() const override { 
        return enclosingScope; 
    }

    std::string getScopeName() const override { 
        return name; 
    }

    std::string toString() const {
        // Build argument list string
        std::string args;
        bool first = true;
        for (const auto& pair : orderedArgs) {
            if (!first) args += ", ";
            args += pair.second->toString();
            first = false;
        }
        return "method" + Symbol::toString() + ":[" + args + "]";
    }

    // Accessor for orderedArgs if needed
    const std::unordered_map<std::string, Symbol*>& getArguments() const {
        return orderedArgs;
    }
};
