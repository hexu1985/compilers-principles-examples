#pragma once

#include "ScopedSymbol.hpp"
#include "Type.hpp"
#include <unordered_map>
#include <string>
#include <vector>

class StructSymbol : public ScopedSymbol, public Type {
private:
    std::unordered_map<std::string, Symbol*> fields;

public:
    StructSymbol(const std::string& name, Scope* parent) 
        : ScopedSymbol(name, parent) {}

    /** For a.b, only look in fields to resolve b, not up scope tree */
    Symbol* resolveMember(const std::string& name) {
        auto it = fields.find(name);
        if (it != fields.end()) {
            return it->second;
        }
        return nullptr;
    }

    std::unordered_map<std::string, Symbol*>& getMembers() override {
        return fields;
    }

    // 实现Type接口的纯虚函数
    std::string getName() const override {
        return Symbol::getSymbolName();
    }

    std::string toString() const override {
        std::string result = "struct " + name + ":{";
        bool first = true;
        for (const auto& field : fields) {
            if (!first) {
                result += ",";
            }
            result += field.first;
            first = false;
        }
        result += "}";
        return result;
    }
};
