#pragma once

#include <iostream>
#include <string>
#include "JavaBaseListener.h"
#include "JavaParser.h"

class ExtractInterfaceListener : public JavaBaseListener {
private:
    JavaParser* parser;

public:
    ExtractInterfaceListener(JavaParser* parser) : parser(parser) {}

    /** Listen to matches of classDeclaration */
    void enterClassDeclaration(JavaParser::ClassDeclarationContext* ctx) override {
        std::cout << "interface I" << ctx->Identifier()->getText() << " {" << std::endl;
    }

    void exitClassDeclaration(JavaParser::ClassDeclarationContext* ctx) override {
        std::cout << "}" << std::endl;
    }

    /** Listen to matches of methodDeclaration */
    void enterMethodDeclaration(JavaParser::MethodDeclarationContext* ctx) override {
        // need parser to get tokens
        antlr4::TokenStream* tokens = parser->getTokenStream();
        std::string type = "void";

        if (ctx->type() != nullptr) {
            type = tokens->getText(ctx->type());
        }

        std::string args = tokens->getText(ctx->formalParameters());
        std::cout << "\t" << type << " " << ctx->Identifier()->getText() << args << ";" << std::endl;
    }
};
