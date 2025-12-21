#include "../include/ScalarConverter.h"

#include <cctype>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cerrno>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    if (this == &other) {
        return *this;
    }
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

char convertChar(const std::string &s) {
    return static_cast<char>(s[0]);
}

long convertInt(const std::string &s) {
    char *end;
    long res = std::strtol(s.c_str(), &end, 10);
    return res;
}

double convertDouble(const std::string &s) {
    char *end;
    double res = std::strtod(s.c_str(), &end);
    return res;
}

double convertFloat(const std::string &s) {
    double d = convertDouble(s);
    return (d);
}

float convertPseudoFloat(const std::string &s) {
    if (s == "+inff")
        return std::numeric_limits<float>::infinity();
    if (s == "-inff")
        return -std::numeric_limits<float>::infinity();
    return std::numeric_limits<float>::quiet_NaN();
}

double convertPseudoDouble(const std::string &s) {
    if (s == "+inf")
        return std::numeric_limits<double>::infinity();
    if (s == "-inf")
        return -std::numeric_limits<double>::infinity();
    return std::numeric_limits<double>::quiet_NaN();
}

void ScalarConverter::convert(const std::string &s) {
    switch (detectType(s)) {
        case T_CHAR: {
            char c = convertChar(s);
            printAll(c);
            break;
        }
        case T_INT: {
            long i = convertInt(s);
            printAll(i);
            break;
        }
        case T_FLOAT: {
            double f = convertFloat(s);
            printAll(f);
            break;
        }
        case T_DOUBLE: {
            double d = convertDouble(s);
            printAll(d);
            break;
        }
        case T_PSEUDO_FLOAT: {
            double f = convertPseudoFloat(s);
            printAll(f, true);
            break;
        }
        case T_PSEUDO_DOUBLE: {
            double d = convertPseudoDouble(s);
            printAll(d, true);
            break;
        }
        default:
            std::cout << "Invalid input\n";
    }
}
