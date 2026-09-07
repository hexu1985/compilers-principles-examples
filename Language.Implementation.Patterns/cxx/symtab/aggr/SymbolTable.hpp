#pragma once

#include <string>
#include <unordered_map>

#include "GlobalScope.hpp"
#include "Symbol.hpp"
#include "BuiltInTypeSymbol.hpp"

class SymbolTable {
public:
    GlobalScope* globals = nullptr;
    std::vector<Symbol*> symbolList;  // Track all created symbols for cleanup
    
protected:
    void initTypeSystem() {
        symbolList.push_back(new BuiltInTypeSymbol("int"));
        symbolList.push_back(new BuiltInTypeSymbol("float"));
        symbolList.push_back(new BuiltInTypeSymbol("void"));    // pseudo-type

        for (auto* sym: symbolList) {
            globals->define(sym);
        }
    }
    
public:
    SymbolTable(): globals(new GlobalScope) {
        initTypeSystem();
    }

    ~SymbolTable() {
        for (auto* sym : symbolList) {
            delete sym;
        }
        symbolList.clear();
        delete globals;
    }

    SymbolTable(const SymbolTable&)=delete;
    const SymbolTable& operator =(const SymbolTable&)=delete;
};
