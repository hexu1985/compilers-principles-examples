#pragma once

#include "RecognitionException.hpp"

class PreviousParseFailedException: public RecognitionException {
public:
    PreviousParseFailedException(): RecognitionException("PreviousParseFailedException") {}
};
