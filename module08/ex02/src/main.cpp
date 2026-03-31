#include <iostream>
#include <list>

#include "../include/MutantStack.h"

int main() {
    std::cout << "=== Subject Test (MutantStack) ===" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;  // 17

    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;  // 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    std::cout << "\n=== Comparison Test (std::list) ===" << std::endl;
    std::list<int> l;
    l.push_back(5);
    l.push_back(17);
    l.pop_back();
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    l.push_back(0);
    std::list<int>::iterator lit = l.begin();
    std::list<int>::iterator lite = l.end();
    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }

    std::cout << "\n=== Extra Test (Reverse Iterator) ===" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }

    return 0;
}
