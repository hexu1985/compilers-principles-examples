#pragma once

#include <string>
#include <unordered_map>

#include "GlobalScope.hpp"
#include "Symbol.hpp"
#include "BuiltInTypeSymbol.hpp"

class SymbolTable {
public:
    GlobalScope* globals = nullptr;
    
protected:
    void initTypeSystem() {
        globals->define(new BuiltInTypeSymbol("int"));
        globals->define(new BuiltInTypeSymbol("float"));
        globals->define(new BuiltInTypeSymbol("void")); // pseudo-type
    }
    
public:
    SymbolTable(): globals(new GlobalScope) {
        initTypeSystem();
    }

    ~SymbolTable() {
        delete globals;
    }

    SymbolTable(const SymbolTable&)=delete;
    const SymbolTable& operator =(const SymbolTable&)=delete;
};
