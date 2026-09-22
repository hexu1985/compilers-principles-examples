#pragma once
#include <string>
#include "Type.hpp"
#include "Scope.hpp"
#include "antlr4-runtime.h"

class Symbol : public virtual Printable {
public:
    std::string name;
    Type* type = nullptr;
    Scope* scope = nullptr;
    antlr4::Token* defToken = nullptr;   // points at ID token in tree

    Symbol(const std::string& name) : name(name) {}
    Symbol(const std::string& name, Type* type) : name(name), type(type) {}

    virtual ~Symbol() = default;

    virtual std::string getSymbolName() const { return name; }

    Type* getType() const { return type; }
    
    std::string toString() const override {
        std::string s = "";
        if (scope != nullptr) {
            s = scope->getScopeName() + ".";
        }
        if (type != nullptr) {
            return '<' + s + getSymbolName() + ":" + type->toString() + '>';
        }
        return s + getSymbolName();
    }
};
