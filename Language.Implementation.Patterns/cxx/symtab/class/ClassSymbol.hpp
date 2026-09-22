#pragma once

#include "ScopedSymbol.hpp"
#include "Type.hpp"
#include "tsl/ordered_map.h"
#include <string>

class ClassSymbol : public ScopedSymbol, public Type {
public:
    ClassSymbol* superClass = nullptr;   // 注意：不是 enclosingScope 字段
    tsl::ordered_map<std::string, Symbol*> members;

    ClassSymbol(const std::string& name, Scope* enclosingScope, ClassSymbol* superClass)
        : ScopedSymbol(name, enclosingScope), superClass(superClass) {}

    /** superClass 优先于 enclosingScope */
    Scope* getParentScope() const override {
        if (superClass == nullptr) return enclosingScope;
        return superClass;
    }

    /** For a.b, only look in class hierarchy, not globals */
    Symbol* resolveMember(const std::string& name) {
        auto it = members.find(name);
        if (it != members.end()) return it->second;
        if (superClass != nullptr) return superClass->resolveMember(name);
        return nullptr;
    }

    tsl::ordered_map<std::string, Symbol*>& getMembers() override { return members; }

    std::string getName() const override { return Symbol::getSymbolName(); }

    std::string toString() const override {
        std::string result = "class " + name + ":{";
        bool first = true;
        for (const auto& m : members) {
            if (!first) result += ", ";
            result += m.first;
            first = false;
        }
        result += "}";
        return result;
    }
};
