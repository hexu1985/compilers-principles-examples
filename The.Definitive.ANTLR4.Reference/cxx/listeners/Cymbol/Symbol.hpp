#pragma once

#include "Printable.hpp"

#include <string>
#include <memory>

class Scope; // Forward declaration

class Symbol: public virtual Printable { // A generic programming language symbol
public:
    enum class Type { tINVALID, tVOID, tINT, tFLOAT };

    std::string name;      // All symbols at least have a name
    Type type;
    Scope* scope=nullptr;  // All symbols know what scope contains them.

    Symbol(const std::string& name) : name(name), type(Type::tINVALID) {}
    Symbol(const std::string& name, Type type) : name(name), type(type) {}
    
    const std::string& getName() const { return name; }

    std::string toString() const override {
        if (type != Type::tINVALID) {
            return "<" + getName() + ":" + typeToString(type) + ">";
        }
        return getName();
    }

private:
    static std::string typeToString(Type t) {
        switch (t) {
            case Type::tINVALID: return "tINVALID";
            case Type::tVOID:    return "tVOID";
            case Type::tINT:     return "tINT";
            case Type::tFLOAT:   return "tFLOAT";
            default:             return "unknown";
        }
    }
};
