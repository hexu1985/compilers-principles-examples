#pragma once

#include "Printable.hpp"

class Symbol;

class Scope: public virtual Printable {
public:
    virtual ~Scope() = default;

    /** Get the name of this scope */
    virtual std::string getScopeName() const = 0;

    /** Where to look next for symbols; superclass or enclosing scope */
    virtual Scope* getParentScope() const = 0;

    /** Scope in which this scope defined. For global scope, it's nullptr */
    virtual Scope* getEnclosingScope() const = 0;

    /** Define a symbol in the current scope */
    virtual void define(Symbol* sym) = 0;

    /** Look up name in this scope or in parent scope if not here, may return nullptr */
    virtual Symbol* resolve(const std::string& name) = 0;
};
