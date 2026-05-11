#pragma once

#include <string>
#include <memory>
#include "VecMathNode.hpp"

class ExprNode : public VecMathNode {
public:
    ExprNode(std::shared_ptr<Token> t) : VecMathNode(t) { }
};
