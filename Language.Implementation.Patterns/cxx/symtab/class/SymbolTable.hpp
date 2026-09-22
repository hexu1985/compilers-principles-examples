#pragma once

#include "GlobalScope.hpp"
#include "Symbol.hpp"
#include "BuiltInTypeSymbol.hpp"
#include "ClassSymbol.hpp"
#include <vector>

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

    /** 'this' and 'super' 需要知道 enclosing class */
    static ClassSymbol* getEnclosingClass(Scope* s) {
        while (s != nullptr) {
            if (auto* cs = dynamic_cast<ClassSymbol*>(s)) return cs;
            s = s->getParentScope();
        }
        return nullptr;
    }

    std::string toString() { return globals->toString(); }
    
    SymbolTable(const SymbolTable&)=delete;
    const SymbolTable& operator =(const SymbolTable&)=delete;
};
