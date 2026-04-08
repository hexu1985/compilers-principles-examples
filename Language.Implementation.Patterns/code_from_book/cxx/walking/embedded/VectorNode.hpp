#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include "ExprNode.hpp"
#include "Token.hpp"

class VectorNode : public ExprNode {
public:
    std::vector<std::shared_ptr<ExprNode>> elements;

    VectorNode(std::shared_ptr<Token> token, const std::vector<std::shared_ptr<ExprNode>>& elements)
        : ExprNode(token), elements(elements) { // track vector token; most likely it's an imaginary token
    }

    void print() const override {
        std::cout << "[";
        if (!elements.empty()) {
            for (size_t i = 0; i < elements.size(); ++i) {
                if (i > 0) std::cout << ", ";
                elements[i]->print();
            }
        }
        std::cout << "]";
    }
};
