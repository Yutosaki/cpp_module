#include <cmath>
#include <iostream>
#include <limits>

#include "../include/ScalarConverter.h"

const int ASCII_PRINTABLE_MIN = 32;
const int ASCII_PRINTABLE_MAX = 126;
bool ft_isfinite(double x) { return !std::isnan(x) && !std::isinf(x); }

// print function
void printChar(int value) {
    std::cout << "char: ";
    if (value >= ASCII_PRINTABLE_MIN && value <= ASCII_PRINTABLE_MAX) {
        std::cout << "'" << static_cast<char>(value) << "'" << "\n";
    } else if (value < std::numeric_limits<char>::min() ||
               value > std::numeric_limits<char>::max()) {
        std::cout << "impossible" << "\n";
    } else {
        std::cout << "Non displayable" << "\n";
    }
}

void printInt(long value) {
    if (!ft_isfinite(value) || value > std::numeric_limits<int>::max() ||
        value < std::numeric_limits<int>::min()) {
        std::cout << "int: impossible" << "\n";
        return;
    }
    std::cout << "int: " << static_cast<int>(value) << "\n";
}

void printFloat(double value, bool wasPseudo = false) {
    std::cout << "float: ";
    if (wasPseudo) {
        std::cout << static_cast<float>(value) << 'f' << "\n";
        return;
    }

    const double fmax = std::numeric_limits<float>::max();
    if (value > fmax || value < -fmax) {
        std::cout << "impossible" << "\n";
        return;
    }

    std::cout << static_cast<float>(value);
    if (value == static_cast<int>(value))
        std::cout << ".0";
    std::cout << "f" << "\n";
}

void printDouble(double value, bool wasPseudo = false) {
    std::cout << "double: ";
    if (wasPseudo) {
        std::cout << static_cast<double>(value) << "\n";
        ;
        return;
    }

    const double dmax = std::numeric_limits<double>::max();
    if (value > dmax || value < -dmax) {
        std::cout << "impossible" << "\n";
        return;
    }

    std::cout << value;
    if (value == static_cast<int>(value))
        std::cout << ".0";
    std::cout << "\n";
}

void printAll(char c) {
    printChar(static_cast<int>(c));
    printInt(static_cast<long>(c));
    printFloat(static_cast<double>(c));
    printDouble(static_cast<double>(c));
}

void printAll(long c) {
    printChar(static_cast<int>(c));
    printInt(c);
    printFloat(static_cast<double>(c));
    printDouble(static_cast<double>(c));
}

void printAll(double c, bool wasPseudo) {
    if (!wasPseudo) {
        printChar(static_cast<int>(c));
        printInt(static_cast<long>(c));
    } else {
        std::cout << "char: impossible" << "\n";
        std::cout << "int: impossible" << "\n";
    }
    printFloat(c, wasPseudo);
    printDouble(c, wasPseudo);
}
