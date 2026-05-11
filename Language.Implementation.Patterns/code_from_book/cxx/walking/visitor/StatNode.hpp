#pragma once

#include <memory>
#include "VecMathNode.hpp"

class StatNode : public VecMathNode {
public:
    StatNode() : VecMathNode() { }
    StatNode(std::shared_ptr<Token> token) : VecMathNode(token) { }
};
