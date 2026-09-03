#pragma once

#include <string>

#include "Symbol.hpp"
#include "Type.hpp"

class BuiltInTypeSymbol : public Symbol, public Type {
public:
    BuiltInTypeSymbol(const std::string& name) : Symbol(name) {
        Symbol::type = this;
    }

    // 实现Type接口的纯虚函数
    std::string getName() const override {
        return Symbol::getName();  // 使用Symbol的getName方法
    }
};
