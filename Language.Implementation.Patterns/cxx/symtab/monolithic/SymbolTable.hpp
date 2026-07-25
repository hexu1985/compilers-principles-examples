#pragma once

#include <string>
#include <unordered_map>

#include "Scope.hpp"
#include "Symbol.hpp"
#include "BuiltInTypeSymbol.hpp"

class SymbolTable : public Scope { // single-scope symtab
private:
    std::unordered_map<std::string, Symbol*> symbols;
    
protected:
    void initTypeSystem() {
        define(new BuiltInTypeSymbol("int"));
        define(new BuiltInTypeSymbol("float"));
    }
    
public:
    SymbolTable() {
        initTypeSystem();
    }

    ~SymbolTable() {
        for (auto& item : symbols) {
            Symbol* symbol = item.second;
            delete symbol;
        }
        symbols.clear();
    }
    
    // Satisfy Scope interface
    std::string getScopeName() const override { return "global"; }
    
    Scope* getEnclosingScope() override { return nullptr; }
    
    void define(Symbol* sym) override { 
        symbols[sym->getName()] = sym; 
    }
    
    Symbol* resolve(const std::string& name) override { 
        auto it = symbols.find(name);
        if (it != symbols.end()) {
            return it->second;
        }
        return nullptr;
    }
    
    std::string toString() const {
        std::string result = getScopeName() + ":{";
        for (const auto& pair : symbols) {
            result += pair.first + "=" + pair.second->toString() + ", ";
        }
        result += "}";
        return result;
    }
};
