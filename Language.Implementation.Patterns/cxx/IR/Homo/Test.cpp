#include <iostream>

#include "Token.hpp"
#include "AST.hpp"

int main() {
    auto plus = std::make_shared<Token>(Token::PLUS, "+");
    auto one  = std::make_shared<Token>(Token::INT, "1");
    auto two  = std::make_shared<Token>(Token::INT, "2");

    AST root(plus);
    root.addChild(std::make_shared<AST>(one));
    root.addChild(std::make_shared<AST>(two));
    std::cout << "1+2 tree: " << root.toStringTree() << std::endl;

    AST list; // make nil node as root for a list
    list.addChild(std::make_shared<AST>(one));
    list.addChild(std::make_shared<AST>(two));
    std::cout << "1 and 2 in list: " << list.toStringTree() << std::endl;

    return 0;
}
