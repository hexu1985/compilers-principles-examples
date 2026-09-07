#pragma once

#include "Symbol.hpp"
#include "Scope.hpp"
#include "tsl/ordered_map.h"
#include <string>
#include <memory>

class ScopedSymbol : public Symbol, public Scope {
private:
    Scope* enclosingScope;

public:
    ScopedSymbol(const std::string& name, Type* type, Scope* enclosingScope)
        : Symbol(name, type), enclosingScope(enclosingScope) {}
    
    ScopedSymbol(const std::string& name, Scope* enclosingScope)
        : Symbol(name), enclosingScope(enclosingScope) {}

    Symbol* resolve(const std::string& name) override {
        auto s = getMembers().find(name);
        if (s != getMembers().end()) {
            return s->second;
        }
        // if not here, check any enclosing scope
        if (getEnclosingScope() != nullptr) {
            return getEnclosingScope()->resolve(name);
        }
        return nullptr; // not found
    }

    Symbol* resolveType(const std::string& name) {
        return resolve(name);
    }
    
    void define(Symbol* sym) override {
        getMembers()[sym->name] = sym;
        sym->scope = this; // track the scope in each symbol
    }

    Scope* getEnclosingScope() const override {
        return enclosingScope;
    }
    
    std::string getScopeName() const override {
        return name;
    }

    /** Indicate how subclasses store scope members. Allows us to
     *  factor out common code in this class.
     */
    virtual tsl::ordered_map<std::string, Symbol*>& getMembers() = 0;
};
