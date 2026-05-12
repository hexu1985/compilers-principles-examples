#pragma once

#include <memory>
#include <string>
#include "Token.hpp"

struct HeteroAST {   // Heterogeneous AST node type
    std::shared_ptr<Token> token;   // Node created from which token?

    HeteroAST() { }
    HeteroAST(std::shared_ptr<Token> t) : token(t) { }

    /** Create node from token type; used mainly for imaginary tokens */
    explicit HeteroAST(int tokenType) : token(std::make_shared<Token>(tokenType)) { }

    virtual ~HeteroAST();

    virtual std::string toString() const {
        return token->toString();
    }
};

