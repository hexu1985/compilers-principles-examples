#pragma once
#include "Scope.hpp"
#include "Symbol.hpp"
#include "tsl/ordered_map.h"
#include <string>

class BaseScope : public Scope {
protected:
    Scope* enclosingScope = nullptr;
    tsl::ordered_map<std::string, Symbol*> symbols;

public:
    BaseScope(Scope* parent = nullptr) 
        : enclosingScope(parent) {}

    Symbol* resolve(const std::string& name) override {
        auto it = symbols.find(name);
        if (it != symbols.end()) {
            return it->second;
        }
        // if not here, check any enclosing scope
        if (getParentScope() != nullptr) {
            return getParentScope()->resolve(name);
        }
        return nullptr; // not found
    }

    void define(Symbol* sym) override {
        symbols[sym->name] = sym;
        sym->scope = this;
    }

	Scope* getParentScope() const override {
		return getEnclosingScope();
	}

    Scope* getEnclosingScope() const override { 
        return enclosingScope; 
    }

    std::string toString() const override {
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
    const tsl::ordered_map<std::string, Symbol*>& getSymbols() const {
        return symbols;
    }
};
