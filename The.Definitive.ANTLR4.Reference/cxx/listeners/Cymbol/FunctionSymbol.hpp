#pragma once

#include "Symbol.hpp"
#include "Scope.hpp"
#include <unordered_map>
#include <string>
#include <vector>

class FunctionSymbol : public Symbol, public Scope {
private:
    std::unordered_map<std::string, Symbol*> arguments;
    Scope* enclosingScope;

public:
    FunctionSymbol(const std::string& name, Type retType, Scope* enclosingScope)
        : Symbol(name, retType), enclosingScope(enclosingScope) {}

    // Scope interface implementation
    Symbol* resolve(const std::string& name) override {
        auto it = arguments.find(name);
        if (it != arguments.end()) {
            return it->second;
        }
        // if not here, check any enclosing scope
        if (getEnclosingScope() != nullptr) {
            return getEnclosingScope()->resolve(name);
        }
        return nullptr; // not found
    }

    void define(Symbol* sym) override {
        arguments[sym->name] = sym;
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
        for (const auto& pair : arguments) {
            if (!first) args += ", ";
            args += pair.second->toString();
            first = false;
        }
        return "function" + Symbol::toString() + ":[" + args + "]";
    }

    // Accessor for arguments if needed
    const std::unordered_map<std::string, Symbol*>& getArguments() const {
        return arguments;
    }
};
