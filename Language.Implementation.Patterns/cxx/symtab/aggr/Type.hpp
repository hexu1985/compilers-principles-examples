#pragma once

#include <string>

class Type {
public:
    virtual ~Type() = default;
    virtual std::string getName() const = 0;  // 纯虚函数，相当于Java的抽象方法
};

