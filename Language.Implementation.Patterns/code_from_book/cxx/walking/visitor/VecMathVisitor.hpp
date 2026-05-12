#pragma once

// Forward declarations for all node types to avoid circular dependencies
class AssignNode;
class PrintNode;
class StatListNode;
class VarNode;
class AddNode;
class DotProductNode;
class IntNode;
class MultNode;
class VectorNode;

// Abstract base class (interface) for visitors
class VecMathVisitor {
public:
    // Pure virtual methods for each node type
    virtual void visit(AssignNode* n) = 0;
    virtual void visit(PrintNode* n) = 0;
    virtual void visit(StatListNode* n) = 0;
    virtual void visit(VarNode* n) = 0;
    virtual void visit(AddNode* n) = 0;
    virtual void visit(DotProductNode* n) = 0;
    virtual void visit(IntNode* n) = 0;
    virtual void visit(MultNode* n) = 0;
    virtual void visit(VectorNode* n) = 0;
    
    virtual ~VecMathVisitor();
};
