#include "../include/ScalarConverter.h"
#include "iostream"
#include "string"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./convert <literal>" << "\n";
        return 1;
    }
    std::string s = argv[1];
    ScalarConverter::convert(s);
    return 0;
}
