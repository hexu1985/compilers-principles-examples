#pragma once

#include <memory>
#include <string>
#include "Token.hpp"

class HeteroAST {   // Heterogeneous AST node type
    std::shared_ptr<Token> token;   // Node created from which token?

public:
    HeteroAST() { }
    HeteroAST(std::shared_ptr<Token> t) : token(t) { }

    /** Create node from token type; used mainly for imaginary tokens */
    explicit HeteroAST(int tokenType) : token(std::make_shared<Token>(tokenType)) { }

    virtual ~HeteroAST();

    /** Compute string for single node */
    virtual std::string toString() const {
        return token ? token->toString() : "";
    }

    /** Compute string for a whole tree not just node; default: print token */
    virtual std::string toStringTree() const {
        return toString();
    }
};
