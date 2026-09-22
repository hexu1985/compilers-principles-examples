#pragma once

#include "BaseScope.hpp"
#include <string>

class GlobalScope : public BaseScope {
public:
    GlobalScope() : BaseScope(nullptr) {}
    
    std::string getScopeName() const override { 
        return "global"; 
    }
};
