#pragma once

#include <memory>
#include <vector>
#include <string>
#include <sstream>
#include "Token.hpp"

class AST {      // Homogeneous AST node type
public:
    std::shared_ptr<Token> token;        // From which token did we create node?
    std::vector<std::shared_ptr<AST>> children; // normalized list of children

    AST() = default;  // for making nil-rooted nodes
    AST(std::shared_ptr<Token> t) : token(t) {}
    /** Create node from token type; used mainly for imaginary tokens */
    explicit AST(int tokenType) : token(std::make_shared<Token>(tokenType)) {}

    /** External visitors need unique int per node for id purposes
     *  while walking.
     */
    int getNodeType() const { return token->type; }

    void addChild(std::shared_ptr<AST> t) {
        children.push_back(t);
    }

    bool isNil() const { return token == nullptr; }

    /** Compute string for single node */
    virtual std::string toString() const { return token->toString(); }

    /** Compute string for a whole tree not just a node */
    std::string toStringTree() const {
        if (children.empty()) {
            return toString();
        }
        std::ostringstream buf;
        if (!isNil()) {
            buf << "(" << toString() << " ";
        }
        for (size_t i = 0; i < children.size(); ++i) {
            auto t = children[i]; // normalized (unnamed) children
            if (i > 0) buf << ' ';
            buf << t->toStringTree();
        }
        if (!isNil()) {
            buf << ")";
        }
        return buf.str();
    }
};
