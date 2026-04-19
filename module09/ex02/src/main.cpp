#include <deque>
#include <iomanip>
#include <iostream>
#include <string>

#include "../include/PmergeMe.hpp"

void print_status(const std::vector<int>& v, const std::string& prefix) {
    std::cout << prefix << ": ";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i > 10) {
            std::cout << "[...]";
            break;
        }
        std::cout << v[i] << (i == v.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe pm;
    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i) {
        if (!pm.isValidInput(argv[i])) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        int val = std::atoi(argv[i]);
        vec.push_back(val);
        deq.push_back(val);
    }

    print_status(vec, "Before");

    // Vector 計測
    clock_t start_vec = clock();
    pm.sort(vec);
    clock_t end_vec = clock();

    // Deque 計測
    clock_t start_deq = clock();
    pm.sort(deq);
    clock_t end_deq = clock();

    print_status(vec, "After");

    double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1e6;
    double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "
              << std::fixed << std::setprecision(5) << time_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : "
              << std::fixed << std::setprecision(5) << time_deq << " us" << std::endl;

    return 0;
}
