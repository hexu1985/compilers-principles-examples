#pragma once

#include <iostream>
#include <memory>

#include "VarNode.hpp"
#include "StatNode.hpp"
#include "ExprNode.hpp"

class AssignNode : public StatNode {
public:
    std::shared_ptr<VarNode> id;
    std::shared_ptr<ExprNode> value;

    AssignNode(std::shared_ptr<VarNode> id, std::shared_ptr<Token> token, std::shared_ptr<ExprNode> value)
        : StatNode(token), id(id), value(value) { }

    void print() const override {
        id->print();            // walk left child
        std::cout << "=";       // print operator
        value->print();         // walk right child
        std::cout << std::endl; // print newline (equivalent to println)
    }
};
