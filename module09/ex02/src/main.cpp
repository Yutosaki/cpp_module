#include <deque>
#include <iostream>
#include <vector>

#include "../include/PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe <numbers>" << std::endl;
        return 1;
    }
    try {
        PmergeMe<std::vector<int> > v_ford_johnson(argv);
        PmergeMe<std::deque<int> > d_ford_johnson(argv);

        v_ford_johnson.print_elements("Before: ");

        v_ford_johnson.sort_ford_johnson();
        d_ford_johnson.sort_ford_johnson();

        v_ford_johnson.print_elements("After: ");
        v_ford_johnson.print_elapsed_time();
        d_ford_johnson.print_elapsed_time();
    } catch (...) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}
