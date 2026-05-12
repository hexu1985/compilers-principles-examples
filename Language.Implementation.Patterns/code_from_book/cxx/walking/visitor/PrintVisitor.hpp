#pragma once

#include <iostream>
#include "VecMathVisitor.hpp"
#include "AssignNode.hpp"
#include "PrintNode.hpp"
#include "StatListNode.hpp"
#include "VarNode.hpp"
#include "AddNode.hpp"
#include "DotProductNode.hpp"
#include "IntNode.hpp"
#include "MultNode.hpp"
#include "VectorNode.hpp"

class PrintVisitor : public VecMathVisitor {
public:
    void visit(AssignNode* n) override {
        n->id->visit(this);
        std::cout << "=";
        n->value->visit(this);
        std::cout << std::endl;
    }

    void visit(StatListNode* n) override {
        for (auto stat : n->elements) {
            stat->visit(this);
        }
    }

    void visit(PrintNode* n) override {
        std::cout << "print ";
        n->value->visit(this);
        std::cout << std::endl;
    }

    void visit(AddNode* n) override {
        n->left->visit(this);
        std::cout << "+";
        n->right->visit(this);
    }

    void visit(DotProductNode* n) override {
        n->left->visit(this);
        std::cout << ".";
        n->right->visit(this);
    }

    void visit(MultNode* n) override {
        n->left->visit(this);
        std::cout << "*";
        n->right->visit(this);
    }

    void visit(IntNode* n) override {
        std::cout << n->toString();
    }

    void visit(VarNode* n) override {
        std::cout << n->toString();
    }

    void visit(VectorNode* n) override {
        std::cout << "[";
        if (!n->elements.empty()) {
            for (size_t i = 0; i < n->elements.size(); ++i) {
                if (i > 0) std::cout << ", ";
                n->elements[i]->visit(this);
            }
        }
        std::cout << "]";
    }
};
