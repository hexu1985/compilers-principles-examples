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

    std::unordered_map<std
    virtual std::unordered_map<std::string, Symbol*>* getMembers() = 0;

    std::string toString() const {
        // Build argument list string
        std::string args;
        bool first = true;
        for (const auto& pair : orderedArgs) {
            if (!first) args += ", ";
            args += pair.second->toString();
            first = false;
        }
        return "method" + Symbol::toString() + ":[" + args + "]";
    }

    // Accessor for orderedArgs if needed
    const std::unordered_map<std::string, Symbol*>& getArguments() const {
        return orderedArgs;
    }
};
