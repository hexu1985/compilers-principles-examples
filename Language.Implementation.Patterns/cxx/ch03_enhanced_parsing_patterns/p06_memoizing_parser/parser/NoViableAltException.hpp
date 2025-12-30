#pragma once

#include "RecognitionException.hpp"

class NoViableAltException: public RecognitionException {
public:
    NoViableAltException(const std::string& what_arg): RecognitionException(what_arg) {}
};
