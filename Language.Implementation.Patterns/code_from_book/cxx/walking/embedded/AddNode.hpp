#pragma once

#include <memory>
#include <sstream>
#include "ExprNode.hpp"

class AddNode : public ExprNode {
public:
    std::shared_ptr<ExprNode> left, right; // named, node-specific, irregular children

    AddNode(std::shared_ptr<ExprNode> left, std::shared_ptr<Token> addToken, std::shared_ptr<ExprNode> right)
        : ExprNode(addToken), left(left), right(right) { }

    std::string toStringTree() const override {
        if (left == nullptr || right == nullptr) return this->toString();
        std::ostringstream buf;
        buf << "("
            << this->toString()
            << ' '
            << left->toStringTree()
            << ' '
            << right->toStringTree()
            << ")";
        return buf.str();
    }
};
