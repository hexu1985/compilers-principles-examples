#pragma once

#include "RecognitionException.hpp"

class NoViableAltException: public RecognitionException {
public:
    NoViableAltException(const std::string& msg): RecognitionException(msg) {}
};
