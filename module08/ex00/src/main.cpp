#include <iostream>
#include <list>
#include <vector>

#include "easyfind.h"

int main() {
    // --- テスト 1: std::vector (配列のようなコンテナ) ---
    std::cout << "--- Testing std::vector ---" << std::endl;
    std::vector<int> v;
    for (int i = 1; i <= 5; i++) v.push_back(i * 10);  // 10, 20, 30, 40, 50

    try {
        std::vector<int>::iterator it = easyfind(v, 30);
        std::cout << "Found: " << *it << " at index " << std::distance(v.begin(), it) << std::endl;

        std::cout << "Trying to find 100 (should fail)..." << std::endl;
        easyfind(v, 100);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n---------------------------\n"
              << std::endl;

    // --- テスト 2: std::list (連結リストコンテナ) ---
    std::cout << "--- Testing std::list ---" << std::endl;
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    try {
        std::list<int>::iterator it = easyfind(l, 2);
        std::cout << "Found: " << *it << std::endl;

        std::cout << "Trying to find 42 (should fail)..." << std::endl;
        easyfind(l, 42);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
