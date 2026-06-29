#pragma once

#include <iostream>
#include "HeteroAST.hpp"
#include "VecMathVisitor.hpp"

class VecMathNode : public HeteroAST {
public:
    VecMathNode() : HeteroAST() { }
    VecMathNode(std::shared_ptr<Token> token) : HeteroAST(token) { }

    virtual void visit(VecMathVisitor* visitor) = 0;   // dispatcher
};
