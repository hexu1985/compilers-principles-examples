#pragma once

#include "CymbolBaseListener.h"
#include "SymbolTable.hpp"
#include "ClassSymbol.hpp"
#include "MethodSymbol.hpp"
#include "VariableSymbol.hpp"
#include "BuiltInTypeSymbol.hpp"

#include <iostream>
#include <unordered_map>

using namespace antlr4;

/**
 * RefPhase —— 对应 Java 的 Ref.g（tree grammar, filter=true）
 *
 * 关键职责：
 *  1. enterClass：解析 superClass，设置 ClassSymbol::superClass
 *  2. enterMethod：设置方法的返回类型
 *  3. enterVar/Field/FormalParams：设置变量/字段/参数的类型
 *  4. resolveExpr / assignment：解析表达式和赋值中的 ID
 */
class RefPhase : public CymbolBaseListener {
public:
    SymbolTable* symtab = nullptr;

    // 从 DefPhase 继承下来的映射
    std::unordered_map<tree::TerminalNode*, Scope*>* idScopes = nullptr;
    std::unordered_map<tree::TerminalNode*, Symbol*>* idSymbols = nullptr;

    // 当前正在遍历的 scope 栈（用于 RefPhase 里查找 ID 所在的 scope）
    // 因为 RefPhase 是第二次 walk，需要重新维护一个 currentScope
    Scope* currentScope = nullptr;
    std::vector<Scope*> scopeStack;

    // 记录当前 class 节点的 name ID，便于 enterMethod 里查找
    std::unordered_map<CymbolParser::ClassDefinitionContext*, CymbolParser::ClassDefinitionContext*> dummy;

public:
    RefPhase(SymbolTable* symtab,
             std::unordered_map<tree::TerminalNode*, Scope*>* idScopes,
             std::unordered_map<tree::TerminalNode*, Symbol*>* idSymbols)
        : symtab(symtab), idScopes(idScopes), idSymbols(idSymbols),
          currentScope(symtab->globals) {}

    // ---------------------------------------------------------------
    // S C O P E 维护（第二次 walk 也要模拟一遍）
    // ---------------------------------------------------------------
    void enterBlock(CymbolParser::BlockContext*) override {
        // 找当前 scope 下的 LocalScope：在 DefPhase 里已创建，
        // 这里简单地把 currentScope 保持为 method/class scope 即可，
        // 因为 RefPhase 主要处理类/方法级别。局部变量已在 DefPhase 定义。
    }
    void exitBlock(CymbolParser::BlockContext*) override {}

    void enterClassDefinition(CymbolParser::ClassDefinitionContext* ctx) override {
        auto* nameNode = ctx->ID();
        auto* nameTok = nameNode->getSymbol();

        // 从 idSymbols 里取出 DefPhase 定义的 ClassSymbol
        auto it = idSymbols->find(nameNode);
        if (it == idSymbols->end()) return;
        auto* cs = dynamic_cast<ClassSymbol*>(it->second);
        if (!cs) return;

        if (ctx->superClass() && ctx->superClass()->ID()) {
            auto* supNode = ctx->superClass()->ID();
            auto* supTok = supNode->getSymbol();

            // 找 sup ID 在 DefPhase 里记录的 scope
            auto sit = idScopes->find(supNode);
            Scope* supScope = (sit != idScopes->end()) ? sit->second : currentScope;

            Symbol* supSym = supScope->resolve(supTok->getText());
            cs->superClass = dynamic_cast<ClassSymbol*>(supSym);

            std::cout << "line " << nameTok->getLine() << ": set "
                      << nameTok->getText() << " super to "
                      << (cs->superClass ? cs->superClass->name : "null")
                      << std::endl;
        } else {
            std::cout << "line " << nameTok->getLine() << ": set "
                      << nameTok->getText() << std::endl;
        }

        currentScope = cs;
    }

    void exitClassDefinition(CymbolParser::ClassDefinitionContext*) override {
        currentScope = currentScope->getEnclosingScope();
    }

    void enterMethodDeclaration(CymbolParser::MethodDeclarationContext* ctx) override {
        auto* idNode = ctx->ID();
        auto* idTok = idNode->getSymbol();

        auto it = idSymbols->find(idNode);
        if (it == idSymbols->end()) return;
        auto* ms = dynamic_cast<MethodSymbol*>(it->second);
        if (!ms) return;

        // 解析返回类型
        Type* retType = resolveType(ctx->type(), idScopes->count(idNode) ? (*idScopes)[idNode] : currentScope);
        ms->type = retType;

        std::cout << "line " << idTok->getLine()
                  << ": set method type " << ms->toString() << std::endl;

        currentScope = ms;
    }

    void exitMethodDeclaration(CymbolParser::MethodDeclarationContext*) override {
        currentScope = currentScope->getEnclosingScope();
    }

    // ---------------------------------------------------------------
    // V A R / F I E L D / A R G 类型解析
    // ---------------------------------------------------------------
    void enterVarDeclaration(CymbolParser::VarDeclarationContext* ctx) override {
        resolveVarType(ctx->ID(), ctx->type());
    }

    void enterFieldMember(CymbolParser::FieldMemberContext* ctx) override {
        resolveVarType(ctx->ID(), ctx->type());
    }

    void enterFormalParameters(CymbolParser::FormalParametersContext* ctx) override {
        auto types = ctx->type();
        auto ids = ctx->ID();
        for (size_t i = 0; i < ids.size() && i < types.size(); i++) {
            resolveVarType(ids[i], types[i]);
        }
    }

    // ---------------------------------------------------------------
    // E X P R E S S I O N S
    // ---------------------------------------------------------------
    void enterPrimary(CymbolParser::PrimaryContext* ctx) override {
        if (ctx->ID()) {
            auto* id = ctx->ID();
            if (idSymbols->find(id) != idSymbols->end()) return;  // ← 已解析过就跳过
            resolveIDNode(id);
        }
        if (ctx->getText() == "this") {
            // ...
        }
    }

    void enterPostfixExpression(CymbolParser::PostfixExpressionContext* ctx) override {
        auto* primary = ctx->primary();
        if (!primary) return;

        Type* currentType = nullptr;
        Symbol* baseSym = nullptr;
        std::string baseName;

        if (primary->ID()) {
            // 普通 ID：a.x
            baseSym = resolveIDNode(primary->ID());
            if (!baseSym) return;
            currentType = baseSym->type;
            baseName = baseSym->getSymbolName();
        } else if (primary->getText() == "this") {
            // this.x —— 从当前 scope 往上找 enclosing class
            ClassSymbol* cs = SymbolTable::getEnclosingClass(currentScope);
            if (!cs) return;
            baseSym = cs;
            currentType = cs;
            baseName = "this";
        } else {
            return;
        }

        // 遍历 .ID 后缀
        for (size_t i = 0; i < ctx->children.size(); i++) {
            auto* child = ctx->children[i];
            if (child->getText() == ".") {
                if (i + 1 >= ctx->children.size()) continue;
                auto* fieldNode = dynamic_cast<tree::TerminalNode*>(ctx->children[i + 1]);
                if (!fieldNode) continue;

                std::string fieldName = fieldNode->getText();
                auto* cs = dynamic_cast<ClassSymbol*>(currentType);
                if (cs) {
                    Symbol* fieldSym = cs->resolveMember(fieldName);
                    (*idSymbols)[fieldNode] = fieldSym;

                    std::cout << "line " << fieldNode->getSymbol()->getLine()
                              << ": resolve " << baseName << "." << fieldName
                              << " to " << (fieldSym ? fieldSym->toString() : "null")
                              << std::endl;

                    if (fieldSym) {
                        currentType = fieldSym->type;
                        baseName = baseName + "." + fieldName;
                    }
                }
            }
        }
    }

    // ---------------------------------------------------------------
    // H E L P E R S
    // ---------------------------------------------------------------
    Type* resolveType(CymbolParser::TypeContext* typeCtx, Scope* scope) {
        if (!typeCtx) return nullptr;
        std::string typeName = typeCtx->getText();
        Symbol* s = scope ? scope->resolve(typeName) : nullptr;
        return dynamic_cast<Type*>(s);
    }

    void resolveVarType(tree::TerminalNode* idNode, CymbolParser::TypeContext* typeCtx) {
        if (!idNode) return;
        auto it = idSymbols->find(idNode);
        if (it == idSymbols->end()) return;
        Symbol* sym = it->second;

        auto sit = idScopes->find(idNode);
        Scope* scope = (sit != idScopes->end()) ? sit->second : currentScope;

        Type* t = resolveType(typeCtx, scope);
        sym->type = t;

        std::cout << "line " << idNode->getSymbol()->getLine()
                  << ": set var type " << sym->toString() << std::endl;
    }

    Symbol* resolveIDNode(tree::TerminalNode* idNode) {
        auto* tok = idNode->getSymbol();
        auto sit = idScopes->find(idNode);
        Scope* scope = (sit != idScopes->end()) ? sit->second : currentScope;

        Symbol* s = scope ? scope->resolve(tok->getText()) : nullptr;

        // forward-ref 检查
        if (s && s->defToken != nullptr) {
            int idLoc = tok->getTokenIndex();
            int defLoc = s->defToken->getTokenIndex();

            auto* idBase = dynamic_cast<BaseScope*>(scope);
            auto* symBase = dynamic_cast<BaseScope*>(s->scope);

            if (idBase && symBase && idLoc < defLoc) {
                std::cerr << "line " << tok->getLine()
                          << ": error: forward local var ref " << tok->getText()
                          << std::endl;
                return nullptr;
            }
        }

        std::cout << "line " << tok->getLine()
                  << ": resolve " << tok->getText()
                  << " to " << (s ? s->toString() : "null") << std::endl;

        (*idSymbols)[idNode] = s;
        return s;
    }
};
