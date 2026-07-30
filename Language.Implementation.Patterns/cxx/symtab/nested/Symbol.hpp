#pragma once

#include <string>
#include <memory>

#include "Type.hpp"
#include "Scope.hpp"

class Symbol { // A generic programming language symbol
protected:
    std::string name;      // All symbols at least have a name
    Type* type = nullptr;
    Scope* scope = nullptr;
    
public:
    Symbol(const std::string& name) : name(name), type(nullptr) {}
    
    Symbol(const std::string& name, Type* type) : name(name), type(type) {}

    virtual ~Symbol() = default;

    std::string getName() const { return name; }

    Type* getType() const { return type; }
    
    std::string toString() const {
        if (type != nullptr) {
            return '<' + getName() + ":" + type->getName() + '>';
        }
        return getName();
    }
};
