#pragma once

#include "BaseScope.hpp"
#include <string>

class LocalScope : public BaseScope {
public:
    LocalScope(Scope* parent) : BaseScope(parent) {}
    
    std::string getScopeName() const override { 
        return "local"; 
    }
};
