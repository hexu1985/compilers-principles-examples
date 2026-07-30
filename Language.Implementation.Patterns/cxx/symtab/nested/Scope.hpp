#pragma once

#include <string>

class Symbol; // 前向声明

class Scope {
public:
    virtual ~Scope() = default;
    
    virtual std::string getScopeName() const = 0;
    
    /** Where to look next for symbols, may return nullptr */
    virtual Scope* getEnclosingScope() = 0;
    
    /** Define a symbol in the current scope */
    virtual void define(Symbol* sym) = 0;
    
    /** Look up name in this scope or in enclosing scope if not here, may return nullptr */
    virtual Symbol* resolve(const std::string& name) = 0;
};
