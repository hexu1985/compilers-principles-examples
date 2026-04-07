#pragma once

#include <memory>
#include <vector>
#include "ExprNode.hpp"

class VectorNode : public ExprNode {
public:
    VectorNode(std::shared_ptr<Token> t, const std::vector<std::shared_ptr<ExprNode>>& elements)
        : ExprNode(t) {
        evalType = tVECTOR; // track vector token; likely to be imaginary token
        for (const auto& e : elements) {
            addChild(e); // add as kids
        }
    }
};
