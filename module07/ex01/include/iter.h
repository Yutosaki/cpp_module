#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T, typename F>
void iter(T* array, std::size_t len, F f) {
    for (std::size_t i = 0; i < len; i++) {
        f(array[i]);
    }
}

template <typename T>
void increment(T& a) {
    a++;
}

template <typename T>
void printx(T const& x) {
    std::cout << x << ' ';
}
#endif
