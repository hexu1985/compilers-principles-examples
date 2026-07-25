#pragma once

#include <memory>

#include "Symbol.hpp"
#include "Type.hpp"

class VariableSymbol : public Symbol {
public:
    VariableSymbol(const std::string& name, Type* type) 
        : Symbol(name, type) {}
};
