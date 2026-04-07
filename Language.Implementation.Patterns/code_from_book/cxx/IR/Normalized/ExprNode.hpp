#pragma once

#include <string>
#include <memory>
#include "AST.hpp"

class ExprNode : public AST {
public:
    static constexpr int tINVALID = 0; // invalid expression type
    static constexpr int tINTEGER = 1; // integer expression type
    static constexpr int tVECTOR = 2;  // vector expression type
    
    /** Track expression type (integer or vector) for each expr node.
     *  This is the type of the associated value not the getNodeType()
     *  used by an external visitor to distinguish between nodes. */
    int evalType;
    
    virtual int getEvalType() const { return evalType; }
    
    ExprNode(std::shared_ptr<Token> payload) : AST(payload), evalType(tINVALID) {}
    
    /** ExprNode's know about the type of an expresson, include that */
    std::string toString() const override {
        if (evalType != tINVALID) {
            std::string typeStr = (evalType == tINTEGER) ? "tINTEGER" : "tVECTOR";
            return AST::toString() + "<type=" + typeStr + ">";
        }
        return AST::toString();
    }
};
