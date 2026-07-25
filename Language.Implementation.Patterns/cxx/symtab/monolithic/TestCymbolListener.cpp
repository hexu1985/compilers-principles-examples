#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

#include "antlr4-runtime.h"
#include "CymbolLexer.h"
#include "CymbolParser.h"
#include "CymbolBaseListener.h"

#include "SymbolTable.hpp"
#include "VariableSymbol.hpp"

using namespace antlr4;

class MyCymbolListener : public CymbolBaseListener {
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
    MyCymbolListener(SymbolTable* table) : symtab(table) {}

    // 进入变量声明时触发
    void enterVarDeclaration(CymbolParser::VarDeclarationContext* ctx) override {
        // 获取类型名称
        std::string typeName = ctx->type()->getText();
        Type* type = resolveType(typeName);

        if (type == nullptr) {
            std::cerr << "Error: Unknown type '" << typeName << "'" << std::endl;
            return;
        }

        // 获取变量名
        std::string varName = ctx->ID()->getText();

        std::cout << "line " << ctx->ID()->getSymbol()->getLine()
                  << ": def " << varName << std::endl;

        // 创建符号并添加到符号表
        VariableSymbol* vs = new VariableSymbol(varName, type);
        symtab->define(vs);
    }

    // 进入类型规则时触发
    void enterType(CymbolParser::TypeContext* ctx) override {
        std::string typeName = ctx->getText();
        Type* type = resolveType(typeName);
        if (type != nullptr) {
            std::cout << "line " << ctx->getStart()->getLine()
                      << ": ref " << type->getName() << std::endl;
        }
    }

    // 进入主表达式时触发
    void enterPrimary(CymbolParser::PrimaryContext* ctx) override {
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
    }
};

std::unique_ptr<ANTLRFileStream> makeANTLRFileStream(const std::string& fileName) {
    auto input = std::make_unique<ANTLRFileStream>();
    input->loadFromFile(fileName);
    return input;
}

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

    parser.setBuildParseTree(true);
    tree::ParseTree* tree = parser.compilationUnit();

    // 显示树结构（文本形式）
    // std::cout << tree->toStringTree(&parser) << std::endl;

    // 遍历解析树
    tree::ParseTreeWalker walker;
    SymbolTable globals;
    MyCymbolListener listener{&globals};
    walker.walk(&listener, tree);

    std::cout << "globals: " << globals.toString() << std::endl;

    return 0;
}
