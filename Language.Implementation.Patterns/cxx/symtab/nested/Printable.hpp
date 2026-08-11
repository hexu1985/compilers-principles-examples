#pragma once

#include <string>

class Printable {
public:
    Printable() = default;
    virtual ~Printable() = default;

    virtual std::string toString() const = 0;
};
