#pragma once

#include <memory>
#include <vector>

#include "VecMathNode.hpp"
#include "StatNode.hpp"
#include "Token.hpp"

/** A flat tree ==  tree with no root: (nil child1 child2 ...) */
class StatListNode : public VecMathNode {
public:
    std::vector<std::shared_ptr<StatNode>> elements;

    StatListNode(const std::vector<std::shared_ptr<StatNode>>& elements)
        : VecMathNode(std::make_shared<Token>(Token::STAT_LIST)), elements(elements) {  // create imaginary token
    }

    void visit(VecMathVisitor* visitor) override {
        visitor->visit(this);
    }
};
