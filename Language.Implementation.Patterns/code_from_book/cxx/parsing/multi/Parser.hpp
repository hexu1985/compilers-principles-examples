#pragma once

#include <string>
#include <memory>
#include <stdexcept>
#include "Token.hpp"
#include "Lexer.hpp"

class Parser {
protected:
    std::unique_ptr<Lexer> input;     // from where do we get tokens?
    std::unique_ptr<Token> lookahead; // the current lookahead token

public:
    Parser(std::unique_ptr<Lexer> input_) : input(std::move(input_)) {
        consume();
    }

    virtual ~Parser() = 0;

    /** If lookahead token type matches x, consume & return else error */
    void match(int x) {
        if (lookahead->type == x) {
            consume();
        } else {
            throw std::runtime_error("expecting " + input->getTokenName(x) +
                                     "; found " + lookahead->toString());
        }
    }

    void consume() {
        lookahead = std::move(input->nextToken());
    }
};

