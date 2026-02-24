#include "../include/iter.h"

void addExclamation(std::string& s) { s += "!"; }

int main(void) {
    std::cout << "------------int test------------\n";
    int nums[] = {1, 2, 3};
    // increment が非const で定義されているため、併用するとコンパイルエラーとなる
    // const int nums[] = {1, 2, 3};
    int nlen = sizeof(nums) / sizeof(int);
    iter(nums, nlen, &printx<int>);
    std::cout << '\n';
    iter(nums, nlen, &increment<int>);
    iter(nums, nlen, &printx<int>);
    std::cout << '\n';

    std::cout << "------------string test------------\n";
    std::string strs[] = {"apple", "banana", "cherry"};
    // addExclamation が非const で定義されているため、併用するとコンパイルエラーとなる
    // const std::string strs[] = {"apple", "banana", "cherry"};
    std::size_t slen = sizeof(strs) / sizeof(std::string);
    iter(strs, slen, &printx<std::string>);
    std::cout << '\n';
    iter(strs, slen, addExclamation);
    iter(strs, slen, &printx<std::string>);
}
