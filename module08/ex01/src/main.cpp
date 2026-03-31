#include <ctime>
#include <iostream>
#include <vector>

#include "../include/Span.h"

int main() {
    std::cout << "=== Subject Test ===" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest:  " << sp.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== 20,000 Numbers Test ===" << std::endl;
    try {
        Span bigSpan(20000);
        std::vector<int> v;
        std::srand(time(NULL));
        for (int i = 0; i < 20000; ++i)
            v.push_back(std::rand());

        bigSpan.addNumbers(v.begin(), v.end());
        std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest:  " << bigSpan.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
