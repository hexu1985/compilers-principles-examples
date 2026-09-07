#pragma once

#include <string>
#include <memory>

#include "Type.hpp"
#include "Scope.hpp"

class Symbol: public virtual Printable { // A generic programming language symbol
public:
    std::string name;      // All symbols at least have a name
    Type* type = nullptr;
    Scope* scope = nullptr;
    
public:
    Symbol(const std::string& name) : name(name), type(nullptr) {}
    
    Symbol(const std::string& name, Type* type) : name(name), type(type) {}

    virtual ~Symbol() = default;

    std::string getName() const { return name; }

    Type* getType() const { return type; }
    
    std::string toString() const override {
        std::string s = "";
        if (scope != nullptr) {
            s = scope->getScopeName() + ".";
        }
        if (type != nullptr) {
            return '<' + s + getName() + ":" + type->getFullName() + '>';
        }
        return s + getName();
    }
};
