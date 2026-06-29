#pragma once

#include "RecognitionException.hpp"

class MismatchedTokenException: public RecognitionException {
public:
    MismatchedTokenException(const std::string& msg): RecognitionException(msg) {}
};
