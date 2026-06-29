#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>

#include "VecMathNode.hpp"
#include "Token.hpp"
#include "StatListNode.hpp"
#include "AssignNode.hpp"
#include "PrintNode.hpp"
#include "AddNode.hpp"
#include "DotProductNode.hpp"
#include "MultNode.hpp"
#include "IntNode.hpp"
#include "VarNode.hpp"
#include "VectorNode.hpp"
#include "ExprNode.hpp"

class IndependentPrintVisitor {
public:
    // Dispatch method based on token type
    void print(VecMathNode* n) {
        switch (n->token->type) {
            case Token::ID:
                print(static_cast<VarNode*>(n));
                break;
            case Token::ASSIGN:
                print(static_cast<AssignNode*>(n));
                break;
            case Token::PRINT:
                print(static_cast<PrintNode*>(n));
                break;
            case Token::PLUS:
                print(static_cast<AddNode*>(n));
                break;
            case Token::MULT:
                print(static_cast<MultNode*>(n));
                break;
            case Token::DOT:
                print(static_cast<DotProductNode*>(n));
                break;
            case Token::INT:
                print(static_cast<IntNode*>(n));
                break;
            case Token::VEC:
                print(static_cast<VectorNode*>(n));
                break;
            case Token::STAT_LIST:
                print(static_cast<StatListNode*>(n));
                break;
            default:
                throw std::runtime_error("Node " + std::string(typeid(*n).name()) + " not handled");
        }
    }

    void print(StatListNode* n) {
        for (auto p : n->elements) {
            print(p.get());
        }
    }

    void print(AssignNode* n) {
        print(n->id.get());
        std::cout << "=";
        print(n->value.get());
        std::cout << std::endl;
    }

    void print(PrintNode* n) {
        std::cout << "print ";
        print(n->value.get());
        std::cout << std::endl;
    }

    void print(AddNode* n) {
        print(n->left.get());
        std::cout << "+";
        print(n->right.get());
    }

    void print(DotProductNode* n) {
        print(n->left.get());
        std::cout << ".";
        print(n->right.get());
    }

    void print(MultNode* n) {
        print(n->left.get());
        std::cout << "*";
        print(n->right.get());
    }

    void print(IntNode* n) {
        std::cout << n->toString();
    }

    void print(VarNode* n) {
        std::cout << n->toString();
    }

    void print(VectorNode* n) {
        std::cout << "[";
        if (!n->elements.empty()) {
            for (size_t i = 0; i < n->elements.size(); ++i) {
                if (i > 0) std::cout << ", ";
                print(n->elements[i].get());
            }
        }
        std::cout << "]";
    }
};
