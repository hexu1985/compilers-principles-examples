#pragma once

#include "Scope.hpp"
#include "Symbol.hpp"
#include <unordered_map>
#include <string>
#include <vector>

class BaseScope : public Scope {
protected:
    Scope* enclosingScope=nullptr; // null if global (outermost) scope
    std::unordered_map<std::string, Symbol*> symbols;

public:
    BaseScope(Scope* enclosingScope = nullptr) 
        : enclosingScope(enclosingScope) {}

    ~BaseScope() override {
        for (auto& item: symbols) {
            auto symbol = item.second;
            delete symbol;
        }
    }

    Symbol* resolve(const std::string& name) override {
        auto it = symbols.find(name);
        if (it != symbols.end()) {
            return it->second;
        }
        // if not here, check any enclosing scope
        if (enclosingScope != nullptr) {
            return enclosingScope->resolve(name);
        }
        return nullptr; // not found
    }

    void define(Symbol* sym) override {
        symbols[sym->name] = sym;
        sym->scope = this; // track the scope in each symbol
    }

    Scope* getEnclosingScope() const override { 
        return enclosingScope; 
    }

    std::string toString() const {
        // Build a string representation of the keys
        std::string keys;
        bool first = true;
        for (const auto& pair : symbols) {
            if (!first) keys += ", ";
            keys += pair.first;
            first = false;
        }
        return "[" + keys + "]";
    }

    // Provide access to the symbols map if needed
    const std::unordered_map<std::string, Symbol*>& getSymbols() const {
        return symbols;
    }
};
