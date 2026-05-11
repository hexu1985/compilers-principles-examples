#pragma once

#include <memory>
#include "ExprNode.hpp"

class IntNode : public ExprNode {
public:
    IntNode(std::shared_ptr<Token> t) : ExprNode(t) { }
};
