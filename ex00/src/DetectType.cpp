#include <cstdlib>

#include <cctype>
#include <iostream>
#include <limits>
#include <cerrno>

#include "ScalarConverter.h"

std::string trim(const std::string &s) {
    size_t start = 0;
    size_t end = s.size();

    while (start < s.size() && std::isspace(s[start])) {
        start++;
    }

    while (end > start && std::isspace(s[end - 1])) {
        end--;
    }
    return s.substr(start, end - start);
}

bool isPseudoFloat(const std::string &s) {
    return (s == "-inff" or s == "+inff" or s == "nanf");
}

bool isPseudoDouble(const std::string &s) {
    return (s == "-inf" or s == "+inf" or s == "nan");
}

bool isChar(const std::string &s) {
    if (s.size() == 1) {
        unsigned char c = static_cast<unsigned char>(s[0]);
        return (std::isprint(c) && !std::isdigit(c));
    }
    return false;
}

bool isSign(int ch) { return (ch == '+' or ch == '-'); }

bool isInt(const std::string &s) {
    char *ptr;
    errno = 0;
    long result = std::strtol(s.c_str(), &ptr, 10);

    if (s.c_str() == ptr || *ptr != '\0')
        return false;

    if (errno == ERANGE)
        return false;

    if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
        return false;

    return true;
}

bool isFloat(const std::string &s) {
    char *ptr;
    strtof(s.c_str(), &ptr);
    return (*ptr == 'f' && *(ptr + 1) == '\0');
}

bool isDouble(const std::string &s) {
    char *ptr;
    strtod(s.c_str(), &ptr);
    return (*ptr == '\0');
}

ScalarConverter::Type ScalarConverter::detectType(const std::string &raw) {
    if (raw[0] == ' ')
        return T_CHAR;
    const std::string s = trim(raw);
    if (raw.empty())
        return T_INVALID;

    if (isPseudoFloat(s))
        return T_PSEUDO_FLOAT;
    if (isPseudoDouble(s))
        return T_PSEUDO_DOUBLE;

    if (isChar(s))
        return T_CHAR;

    if (isInt(s))
        return T_INT;
    if (isFloat(s))
        return T_FLOAT;
    if (isDouble(s))
        return T_DOUBLE;

    return T_INVALID;
}
