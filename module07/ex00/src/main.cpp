#include <iostream>
#include <string>

#include "../include/whatever.h"
int main(void) {
    std::cout << "-----------int test-----------" << std::endl;
    int a = 5;
    int b = 1;
    std::cout << "a: " << a << " " << "b: " << b << std::endl;
    ::swap(a, b);
    std::cout << "swp: a: " << a << " " << "b: " << b << std::endl;

    std::cout << "min: " << ::min(a, b) << std::endl;
    std::cout << "max: " << ::max(a, b) << std::endl;

    std::cout << "-----------double test-----------" << std::endl;
    double c = 1.1;
    double d = 1.2;
    std::cout << "c: " << c << " " << "d: " << d << std::endl;
    ::swap(c, d);
    std::cout << "swp: c: " << c << " " << "d: " << d << std::endl;

    std::cout << "min: " << ::min(c, d) << std::endl;
    std::cout << "max: " << ::max(c, d) << std::endl;

    std::cout << "-----------string test-----------" << std::endl;
    std::string e = "chaine1";
    std::string f = "chaine2";
    std::cout << "e: " << e << " " << "f: " << f << std::endl;
    ::swap(e, f);
    std::cout << "swp: e: " << e << " " << "f: " << f << std::endl;

    std::cout << "min: " << ::min(e, f) << std::endl;
    std::cout << "max: " << ::max(e, f) << std::endl;
}
