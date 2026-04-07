#pragma once

#include <memory>
#include "ExprNode.hpp"

class AddNode : public ExprNode {
public:
    AddNode(std::shared_ptr<ExprNode> left, std::shared_ptr<Token> addToken, 
            std::shared_ptr<ExprNode> right) 
        : ExprNode(addToken) {
        addChild(left);
        addChild(right);
    }
    
    int getEvalType() const override { // ...
        auto left = std::dynamic_pointer_cast<ExprNode>(children[0]);
        auto right = std::dynamic_pointer_cast<ExprNode>(children[1]);
        
        if (left->getEvalType() == tINTEGER && right->getEvalType() == tINTEGER) {
            return tINTEGER;
        }
        if (left->getEvalType() == tVECTOR && right->getEvalType() == tVECTOR) {
            return tVECTOR;
        }
        return tINVALID;
    }
};