#pragma once

#include "BaseScope.hpp"
#include <string>

class GlobalScope : public BaseScope {
public:
    GlobalScope(Scope* enclosingScope = nullptr) : BaseScope(enclosingScope) {}
    
    std::string getScopeName() const override { 
        return "globals"; 
    }
};
