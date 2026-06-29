#pragma once

#include <memory>
#include <iostream>
#include "ExprNode.hpp"

class AddNode : public ExprNode {
public:
    std::shared_ptr<ExprNode> left, right; // named, node-specific, irregular children

    AddNode(std::shared_ptr<ExprNode> left, std::shared_ptr<Token> t, std::shared_ptr<ExprNode> right)
        : ExprNode(t), left(left), right(right) { }

    void visit(VecMathVisitor* visitor) override {
        visitor->visit(this);
    }
};
