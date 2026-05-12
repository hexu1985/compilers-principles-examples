#pragma once

#include <iostream>
#include <memory>

#include "StatNode.hpp"
#include "ExprNode.hpp"
#include "Token.hpp"

class PrintNode : public StatNode {
public:
    std::shared_ptr<ExprNode> value;

    PrintNode(std::shared_ptr<Token> token, std::shared_ptr<ExprNode> value)
        : StatNode(token), value(value) { }

    void print() const override {
        std::cout << "print ";
        value->print();
        std::cout << std::endl;
    }
};
