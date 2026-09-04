#pragma once

#include "ScopeSymbol.hpp"
#include <unordered_map>
#include <string>
#include <vector>

class MethodSymbol : public ScopeSymbol {
private:
    std::unordered_map<std::string, Symbol*> orderedArgs;

public:
    MethodSymbol(const std::string& name, Type* retType, Scope* parent)
        : ScopeSymbol(name, retType, parent) {}

    ~MethodSymbol() {
        for (auto& arg: orderedArgs) {
            auto symbol = arg.second;
            delete symbol;
        }
    }

    std::unordered_map<std::string, Symbol*>& getMembers() override {
        return orderedArgs;
    }

    std::string toString() const {
        std::string result = name + "(";
        bool first = true;
        for (const auto& arg : orderedArgs) {
            if (!first) {
                result += ",";
            }
            result += arg.first;
            first = false;
        }
        result += ")";
        return result;
    }
};
