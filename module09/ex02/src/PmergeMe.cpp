#include "../include/PmergeMe.hpp"

#include <cctype>
#include <climits>
#include <cstdlib>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        (void)other;
    }
    return *this;
}

std::vector<int> PmergeMe::generateJacobsthalSequence(int n) {
    std::vector<int> jacob;
    if (n <= 0) return jacob;
    jacob.push_back(1);
    if (n == 1) return jacob;
    jacob.push_back(3);

    while (true) {
        // J(n) = J(n-1) + 2 * J(n-2)
        int next = jacob.back() + (2 * jacob[jacob.size() - 2]);
        if (next >= n) break;
        jacob.push_back(next);
    }
    return jacob;
}

bool PmergeMe::isValidInput(const std::string& s) {
    if (s.empty()) return false;
    for (size_t i = 0; i < s.length(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
    }

    char* endptr;
    long val = std::strtol(s.c_str(), &endptr, 10);

    return (*endptr == '\0' && val <= INT_MAX && val >= 0);
}
