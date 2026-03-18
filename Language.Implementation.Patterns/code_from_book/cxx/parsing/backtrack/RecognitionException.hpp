#pragma once

#include <exception>
#include <string>

class RecognitionException: public std::exception {
public:
    RecognitionException(const std::string& msg): message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

