#pragma once

#include <iostream>
#include <cstdio>
#include <string>
#include "ArrayInitBaseListener.h"
#include "ArrayInitParser.h"

class ShortToUnicodeString : public ArrayInitBaseListener {
public:
    // Translate { to "
    void enterInit(ArrayInitParser::InitContext *ctx) override {
        std::cout << '"';
    }

    // Translate } to "
    void exitInit(ArrayInitParser::InitContext *ctx) override {
        std::cout << '"';
    }

    // Translate integers to 4-digit hexadecimal strings prefixed with \\u
    void enterValue(ArrayInitParser::ValueContext *ctx) override {
        // Assumes no nested array initializers
        int value = std::stoi(ctx->INT()->getText());
        printf("\\u%04x", value);
    }
};
