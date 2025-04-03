#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>
using namespace std;

class MinimumLengthException : public runtime_error {
public:
    MinimumLengthException() : runtime_error("ERROR : Password must be at least 10 characters long!") {}
};

class ContainsWhitespaceException : public runtime_error {
public:
    ContainsWhitespaceException() : runtime_error("ERROR : Password must NOT contain any whitespace!") {}
};

class NoDigitsException : public runtime_error {
public:
    NoDigitsException() : runtime_error("ERROR : Password must contain at least one digit(0-9)!") {}
};

class NoUppercaseException : public runtime_error {
public:
    NoUppercaseException() : runtime_error("ERROR : Password must contain at least one UPPERCASE character!") {}
};

#endif
