#pragma once

#include "CymbolBaseListener.h"
#include "SymbolTable.hpp"
#include "ClassSymbol.hpp"
#include "MethodSymbol.hpp"
#include "VariableSymbol.hpp"
#include "LocalScope.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>

using namespace antlr4;

/**
 * DefPhase —— 对应 Java 的 Def.g（tree grammar, filter=true）
 *
 * 关键职责：
 *  1. 在 topdown 阶段：进入 class / method / block 时压入新 scope，
 *     定义 class / method / var / field / arg 符号。
 *  2. 在 bottomup 阶段：退出 class / method / block 时弹出 scope。
 *  3. 记录每个 ID 节点所在的 scope（用于 RefPhase 的 forward-ref 检查）。
 */
class DefPhase : public CymbolBaseListener {
public:
    SymbolTable* symtab = nullptr;
    Scope* currentScope = nullptr;

    // 记录 scope 对象的所有权
    std::vector<Scope*> ownedScopes;
    std::vector<Symbol*> ownedSymbols;

    // 关键：每个 ID 节点对应的 scope（替代 CymbolAST.scope）
    std::unordered_map<tree::TerminalNode*, Scope*> idScopes;
    // 每个 ID 节点对应的 Symbol（替代 CymbolAST.symbol）
    std::unordered_map<tree::TerminalNode*, Symbol*> idSymbols;

    // classDefinition 进入时暂存 superclass ID 节点，退出前记录它的 scope
    std::unordered_map<CymbolParser::ClassDefinitionContext*, tree::TerminalNode*> pendingSuperIds;

public:
    DefPhase(SymbolTable* symtab) : symtab(symtab), currentScope(symtab->globals) {}

    // ---------------------------------------------------------------
    // S C O P E S : enterBlock / exitBlock
    // ---------------------------------------------------------------
    void enterBlock(CymbolParser::BlockContext* ctx) override {
        auto* ls = new LocalScope(currentScope);
        currentScope = ls;
        ownedScopes.push_back(ls);
    }

    void exitBlock(CymbolParser::BlockContext* ctx) override {
        std::cout << "locals: " << currentScope->toString() << std::endl;
        currentScope = currentScope->getEnclosingScope();
    }

    // ---------------------------------------------------------------
    // C L A S S : enterClass / exitClass
    // ---------------------------------------------------------------
    void enterClassDefinition(CymbolParser::ClassDefinitionContext* ctx) override {
        auto* nameNode = ctx->ID();
        auto* nameTok = nameNode->getSymbol();
        std::cout << "line " << nameTok->getLine()
                  << ": def class " << nameTok->getText() << std::endl;

        // 如果有 superclass，先记下它的 ID 节点（scope 在当前 scope）
        if (ctx->superClass() && ctx->superClass()->ID()) {
            auto* supNode = ctx->superClass()->ID();
            idScopes[supNode] = currentScope;   // 记录 sup ID 的 scope
            pendingSuperIds[ctx] = supNode;
        }

        auto* cs = new ClassSymbol(nameTok->getText(), currentScope, nullptr);

        // 记录 name ID 的 symbol 和 scope
        idSymbols[nameNode] = cs;
        idScopes[nameNode] = currentScope;

        currentScope->define(cs);
        currentScope = cs;   // 进入 class 作用域

        ownedSymbols.push_back(cs);
    }

    void exitClassDefinition(CymbolParser::ClassDefinitionContext* ctx) override {
        std::cout << "members: " << currentScope->toString() << std::endl;
        currentScope = currentScope->getEnclosingScope();
    }

    // ---------------------------------------------------------------
    // M E T H O D : enterMethod / exitMethod
    // ---------------------------------------------------------------
    void enterMethodDeclaration(CymbolParser::MethodDeclarationContext* ctx) override {
        auto* idNode = ctx->ID();
        auto* idTok = idNode->getSymbol();
        std::cout << "line " << idTok->getLine()
                  << ": def method " << idTok->getText() << std::endl;

        // 记录返回类型节点的 scope（实际在 RefPhase 用）
        // 这里先记录 ID 节点自己的 scope
        idScopes[idNode] = currentScope;

        auto* ms = new MethodSymbol(idTok->getText(), nullptr, currentScope);

        idSymbols[idNode] = ms;
        currentScope->define(ms);
        currentScope = ms;   // 进入 method 作用域

        ownedSymbols.push_back(ms);
    }

    void exitMethodDeclaration(CymbolParser::MethodDeclarationContext* ctx) override {
        std::cout << "args: " << currentScope->toString() << std::endl;
        currentScope = currentScope->getEnclosingScope();
    }

    // ---------------------------------------------------------------
    // V A R / F I E L D / A R G 定义
    // ---------------------------------------------------------------
    void enterVarDeclaration(CymbolParser::VarDeclarationContext* ctx) override {
        auto* idNode = ctx->ID();
        if (!idNode) return;
        auto* idTok = idNode->getSymbol();
        std::cout << "line " << idTok->getLine()
                  << ": def " << idTok->getText() << std::endl;

        idScopes[idNode] = currentScope;

        auto* vs = new VariableSymbol(idTok->getText(), nullptr);
        idSymbols[idNode] = vs;
        currentScope->define(vs);

        ownedSymbols.push_back(vs);
    }

    // 处理字段：classMember 的 #fieldMember 分支
    void enterFieldMember(CymbolParser::FieldMemberContext* ctx) override {
        auto* idNode = ctx->ID();
        if (!idNode) return;
        auto* idTok = idNode->getSymbol();
        std::cout << "line " << idTok->getLine()
                  << ": def " << idTok->getText() << std::endl;

        idScopes[idNode] = currentScope;

        auto* vs = new VariableSymbol(idTok->getText(), nullptr);
        idSymbols[idNode] = vs;
        currentScope->define(vs);

        ownedSymbols.push_back(vs);
    }

    // 处理形参：formalParameters 里的 type ID
    void enterFormalParameters(CymbolParser::FormalParametersContext* ctx) override {
        auto ids = ctx->ID();
        for (auto* idNode : ids) {
            auto* idTok = idNode->getSymbol();
            std::cout << "line " << idTok->getLine()
                      << ": def " << idTok->getText() << std::endl;

            idScopes[idNode] = currentScope;

            auto* vs = new VariableSymbol(idTok->getText(), nullptr);
            idSymbols[idNode] = vs;
            currentScope->define(vs);

            ownedSymbols.push_back(vs);
        }
    }

    // ---------------------------------------------------------------
    // A T O M S : 记录表达式/赋值中的 ID 的 scope（用于 Ref 阶段）
    // 在 ANTLR4 listener 里，只需在遇到 primary 的 ID 或 this 时记录即可。
    // ---------------------------------------------------------------
    void enterPrimary(CymbolParser::PrimaryContext* ctx) override {
        if (ctx->ID()) {
            idScopes[ctx->ID()] = currentScope;
        }
        // 'this' 节点本身不是 ID，Ref 阶段从 scope 里找 enclosing class
    }

    // postfixExpression 里的 .ID 也要记录
    void enterPostfixExpression(CymbolParser::PostfixExpressionContext* ctx) override {
        // postfixExpression 的子节点中，所有作为 field access 的 ID
        for (auto* child : ctx->children) {
            if (auto* term = dynamic_cast<tree::TerminalNode*>(child)) {
                if (term->getSymbol()->getType() == CymbolLexer::ID) {
                    // 这里的 ID 可能是 primary 里的，也可能是 .ID 里的
                    // 都统一记录当前 scope（Ref 阶段会按需覆盖）
                    if (idScopes.find(term) == idScopes.end()) {
                        idScopes[term] = currentScope;
                    }
                }
            }
        }
    }
};
