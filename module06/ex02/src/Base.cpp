#include "../include/Base.h"

#include <stdlib.h>

#include <ctime>
#include <iostream>

#include "../include/A.h"
#include "../include/B.h"
#include "../include/C.h"

Base::~Base() {}

Base* generate(void) {
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }

    Base* res;
    switch (std::rand() % 3) {
        case 0:
            res = new A();
            std::cout << "create A instance\n";
            break;
        case 1:
            res = new B();
            std::cout << "create B instance\n";
            break;
        case 2:
            res = new C();
            std::cout << "create C instance\n";
            break;
    }
    return res;
}

void identify(Base* p) {
    if (!p) {
        return;
    }

    if (dynamic_cast<A*>(p)) {
        std::cout << "A\n";
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B\n";
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C\n";
    } else {
        std::cout << "Unkown\n";
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    } catch (const std::exception&) {
    }
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    } catch (const std::exception&) {
    }
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    } catch (const std::exception&) {
    }

    std::cout << "Unkown\n";
}
