#pragma once

#include <iostream>
#include "HeteroAST.hpp"

class VecMathNode : public HeteroAST {
public:
    VecMathNode() : HeteroAST() { }
    VecMathNode(std::shared_ptr<Token> token) : HeteroAST(token) { }

    // generic print tree-walker method
    virtual void print() const {
        if (token != nullptr) {
            std::cout << token->toString();
        } else {
            std::cout << "<null>";
        }
    }
};
