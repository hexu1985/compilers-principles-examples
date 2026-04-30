#pragma once

#include "antlr4-runtime.h"
#include "JavaBaseListener.h"

class InsertSerialIDListener : public JavaBaseListener {
public:
    antlr4::TokenStreamRewriter rewriter;

    InsertSerialIDListener(antlr4::TokenStream *tokens) : rewriter(tokens) {}

    virtual void enterClassBody(JavaParser::ClassBodyContext *ctx) override {
        std::string field = "\n\tpublic static final long serialVersionUID = 1L;";
        rewriter.insertAfter(ctx->getStart(), field);
    }
};
