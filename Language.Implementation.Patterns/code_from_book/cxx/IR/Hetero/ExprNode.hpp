#pragma once

#include <string>
#include <memory>
#include "HeteroAST.hpp"

class ExprNode : public HeteroAST {
public:
    ExprNode(std::shared_ptr<Token> t) : HeteroAST(t) { }
};
