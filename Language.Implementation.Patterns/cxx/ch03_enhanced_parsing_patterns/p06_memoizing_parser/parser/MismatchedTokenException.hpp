#pragma once

#include "RecognitionException.hpp"

class MismatchedTokenException: public RecognitionException {
public:
    MismatchedTokenException(const std::string& what_arg): RecognitionException(what_arg) {}
};
