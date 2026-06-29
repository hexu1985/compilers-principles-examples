#pragma once

#include <stdexcept>

class RecognitionException: public std::logic_error {
public:
    RecognitionException(const std::string& what_arg): std::logic_error(what_arg) {}
};

