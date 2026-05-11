#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Token.hpp"
#include "IntNode.hpp"
#include "AddNode.hpp"
#include "VarNode.hpp"
#include "VectorNode.hpp"
#include "MultNode.hpp"
#include "PrintNode.hpp"
#include "StatListNode.hpp"
#include "AssignNode.hpp"

static std::shared_ptr<IntNode> I(int i) {
    return std::make_shared<IntNode>(std::make_shared<Token>(Token::INT, std::to_string(i)));
}

int main() {
    // x = 3+4
    std::vector<std::shared_ptr<StatNode>> stats;
    auto a = std::make_shared<AddNode>(I(3), std::make_shared<Token>(Token::PLUS), I(4));
    auto x = std::make_shared<VarNode>(std::make_shared<Token>(Token::ID, "x"));
    auto assign = std::make_shared<AssignNode>(x, std::make_shared<Token>(Token::ASSIGN, "="), a);
    stats.push_back(assign);

    // print x * [2, 3, 4]
    auto mult = std::make_shared<Token>(Token::MULT, "*");
    std::vector<std::shared_ptr<ExprNode>> elements;
    elements.push_back(I(2));
    elements.push_back(I(3));
    elements.push_back(I(4));
    auto v = std::make_shared<VectorNode>(std::make_shared<Token>(Token::VEC), elements);
    auto xref = std::make_shared<VarNode>(std::make_shared<Token>(Token::ID, "x"));
    auto pv = std::make_shared<MultNode>(xref, mult, v);
    auto p = std::make_shared<PrintNode>(std::make_shared<Token>(Token::PRINT, "print"), pv);
    stats.push_back(p);

    auto statlist = std::make_shared<StatListNode>(stats);
    statlist->print(); // Launch embedded walker

    return 0;
}
