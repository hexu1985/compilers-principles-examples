#pragma once

class RecognitionError: public std::logic_error {
public:
    RecognitionError(const std::string& what_arg): std::logic_error(what_arg) {}
};

