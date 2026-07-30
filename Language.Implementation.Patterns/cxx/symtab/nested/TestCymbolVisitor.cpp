#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <any>


#include "antlr4-runtime.h"
#include "CymbolLexer.h"
#include "CymbolParser.h"
#include "CymbolBaseVisitor.h"

#include "SymbolTable.hpp"
#include "VariableSymbol.hpp"

using namespace antlr4;

class MyCymbolVisitor : public CymbolBaseVisitor {
private:
    SymbolTable* symtab;
    
    Type* resolveType(const std::string& typeName) {
        // 通过符号表解析类型
        Symbol* sym = symtab->resolve(typeName);
        if (sym != nullptr) {
            return sym->getType();
        }
        return nullptr;
    }

public:
    MyCymbolVisitor(SymbolTable* table) : symtab(table) {}
    
    // 访问编译单元
    std::any visitCompilationUnit(CymbolParser::CompilationUnitContext* ctx) override {
        // 遍历所有变量声明
        for (auto varDecl : ctx->varDeclaration()) {
            visit(varDecl);
        }
        return std::any();
    }
    
    // 访问变量声明
    virtual std::any visitVarDeclaration(CymbolParser::VarDeclarationContext* ctx) override {
        // 访问类型规则（获取类型符号）
        auto typeResult = visit(ctx->type());
        Type* type = std::any_cast<Type*>(typeResult);
        
        // 获取变量名
        std::string varName = ctx->ID()->getText();
        
        std::cout << "line " << ctx->ID()->getSymbol()->getLine() 
                  << ": def " << varName << std::endl;
        
        // 创建符号并添加到符号表
        VariableSymbol* vs = new VariableSymbol(varName, type);
        symtab->define(vs);
        
        // 如果有初始化表达式，访问它
        if (ctx->expression()) {
            visit(ctx->expression());
        }
        
        return std::any();
    }
    
    // 访问类型规则（返回类型符号）
    std::any visitType(CymbolParser::TypeContext* ctx) override {
        std::string typeName = ctx->getText();
        Type* type = resolveType(typeName);
        if (type != nullptr) {
            std::cout << "line " << ctx->getStart()->getLine() 
                << ": ref " << type->getName() << std::endl;
        }
        return type;
    }
    
    // 访问表达式
    std::any visitExpression(CymbolParser::ExpressionContext* ctx) override {
        // 访问第一个 primary
        visit(ctx->primary(0));
        
        // 如果有多个 primary，访问它们
        for (size_t i = 1; i < ctx->primary().size(); i++) {
            visit(ctx->primary(i));
        }
        return std::any();
    }
    
    // 访问 primary
    std::any visitPrimary(CymbolParser::PrimaryContext* ctx) override {
        if (ctx->ID()) {
            std::string varName = ctx->ID()->getText();
            Symbol* resolved = symtab->resolve(varName);
            std::cout << "line " << ctx->ID()->getSymbol()->getLine() 
                      << ": ref to "; 
            if (resolved != nullptr) {
                std::cout << resolved->toString();
            } else {
                std::cout << "undefined symbol '" << varName << "'";
            }
            std::cout << std::endl;
        }
        // INT 或括号表达式，暂时忽略
        return std::any();
    }
};

std::unique_ptr<ANTLRFileStream> makeANTLRFileStream(const std::string& fileName) {
    auto input = std::make_unique<ANTLRFileStream>();
    input->loadFromFile(fileName);
    return input;
}

// ==================== 主函数 ====================
int main(int argc, char* argv[]) {
    std::string inputFile;
    if (argc > 1) {
        inputFile = argv[1];
    }

    std::unique_ptr<ANTLRInputStream> input;
    if (!inputFile.empty()) {
        input = makeANTLRFileStream(inputFile);
    } else {
        input = std::make_unique<ANTLRInputStream>(std::cin);
    }
    CymbolLexer lexer(input.get());
    CommonTokenStream tokens(&lexer);
    CymbolParser parser(&tokens);

    parser.setBuildParseTree(true);  // 告诉 ANTLR 构建语法树
    tree::ParseTree* tree = parser.compilationUnit();

    // 以文本形式显示语法树
    //std::cout << tree->toStringTree(&parser) << std::endl;

    SymbolTable globals;
    MyCymbolVisitor visitor{&globals};
    visitor.visit(tree);

    std::cout << "globals: " << globals.toString() << std::endl;

    return 0;
}
