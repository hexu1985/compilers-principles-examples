#pragma once

#include <memory>
#include <vector>
#include "ExprNode.hpp"

class VectorNode : public ExprNode {
public:
    std::vector<std::shared_ptr<ExprNode>> elements;

    VectorNode(std::shared_ptr<Token> t, const std::vector<std::shared_ptr<ExprNode>>& elements)
        : ExprNode(t), elements(elements) { // track vector token; most likely it's an imaginary token
    }
};
