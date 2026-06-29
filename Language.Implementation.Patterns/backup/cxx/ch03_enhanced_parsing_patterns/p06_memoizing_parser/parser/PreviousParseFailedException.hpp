#pragma once

#include "RecognitionException.hpp"

class PreviousParseFailedException: public RecognitionException {
public:
    PreviousParseFailedException(const std::string& what_arg="PreviousParseFailedException"): RecognitionException(what_arg) {}
};
