#pragma once

#include <string>
#include "Symbol.hpp"

class VariableSymbol : public Symbol {
public:
    VariableSymbol(const std::string& name, Type type) 
        : Symbol(name, type) {}
    
    virtual ~VariableSymbol() = default;
};
