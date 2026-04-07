#include <iostream>
#include <memory>
#include "Token.hpp"
#include "IntNode.hpp"
#include "AddNode.hpp"

int main() {
    auto plus = std::make_shared<Token>(Token::PLUS, "+");
    auto one = std::make_shared<Token>(Token::INT, "1");
    auto two = std::make_shared<Token>(Token::INT, "2");
    
    auto root = std::make_shared<AddNode>(
        std::make_shared<IntNode>(one),
        plus,
        std::make_shared<IntNode>(two)
    );
    
    std::cout << root->toStringTree() << std::endl;
    
    return 0;
}