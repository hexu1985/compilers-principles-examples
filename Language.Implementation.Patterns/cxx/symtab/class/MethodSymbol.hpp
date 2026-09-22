#pragma once

#include "ScopedSymbol.hpp"
#include "tsl/ordered_map.h"
#include <string>
#include <vector>

class MethodSymbol : public ScopedSymbol {
private:
    tsl::ordered_map<std::string, Symbol*> orderedArgs;

public:
    MethodSymbol(const std::string& name, Type* retType, Scope* parent)
        : ScopedSymbol(name, retType, parent) {}

    tsl::ordered_map<std::string, Symbol*>& getMembers() override {
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
