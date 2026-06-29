#pragma once

#include <memory>

#include "ExprNode.hpp"
#include "Token.hpp"

class VarNode : public ExprNode {
public:
    VarNode(std::shared_ptr<Token> token) : ExprNode(token) { }
};
