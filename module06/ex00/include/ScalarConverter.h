#ifndef SCALAR_CONVERTER_H
#define SCALAR_CONVERTER_H

#include "string"

class ScalarConverter {
   public:
    static void convert(const std::string &s);
    enum Type {
        T_CHAR,
        T_INT,
        T_FLOAT,
        T_DOUBLE,
        T_PSEUDO_FLOAT,
        T_PSEUDO_DOUBLE,
        T_INVALID
    };

   private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();
    static Type detectType(const std::string &s);
};

void printAll(char c);
void printAll(long c);
void printAll(double c, bool wasPseudo = false);

#endif
