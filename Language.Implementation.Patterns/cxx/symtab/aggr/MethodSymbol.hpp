#pragma once

#include "ScopedSymbol.hpp"
#include <unordered_map>
#include <string>
#include <vector>

class MethodSymbol : public ScopedSymbol {
private:
    std::unordered_map<std::string, Symbol*> orderedArgs;

public:
    MethodSymbol(const std::string& name, Type* retType, Scope* parent)
        : ScopedSymbol(name, retType, parent) {}

    std::unordered_map<std::string, Symbol*>& getMembers() override {
        return orderedArgs;
    }

    std::string getSymbolName() const override {
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
