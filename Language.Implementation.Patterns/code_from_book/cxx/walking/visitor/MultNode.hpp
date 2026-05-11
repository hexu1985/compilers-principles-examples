#include <iostream>
#include <memory>

#include "ExprNode.hpp"
#include "Token.hpp"

class MultNode : public ExprNode {
public:
    std::shared_ptr<ExprNode> left, right; // named, node-specific, irregular children

    MultNode(std::shared_ptr<ExprNode> left, std::shared_ptr<Token> t, std::shared_ptr<ExprNode> right)
        : ExprNode(t), left(left), right(right) { }

    void print() const override {
        left->print();
        std::cout << "*";
        right->print();
    }
};
