#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ctime>
#include <string>

// ペアとその位置情報を表現する構造体
struct PairWithIndex {
    int larger;
    int smaller;
    size_t index;  // 元のペア配列でのインデックス

    PairWithIndex() : larger(0), smaller(0), index(0) {}
    PairWithIndex(int a, int b, size_t idx)
        : larger(a > b ? a : b), smaller(a > b ? b : a), index(idx) {}
};

// main_chainの各要素とそのペア情報を紐付ける構造体
struct ChainElement {
    int value;          // main_chainの値
    size_t pair_index;  // 対応するペアのインデックス

    ChainElement() : value(0), pair_index(0) {}
    ChainElement(int val, size_t idx) : value(val), pair_index(idx) {}
};

template <typename Container>
class PmergeMe {
    Container container;

   private:
    clock_t time_start_;
    clock_t time_end_;

    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    bool parsePositiveInt(char* s, int& out) const;

    std::string container_type() const;

   public:
    typedef typename Container::value_type ValueType;
    typedef typename Container::iterator Iterator;

    PmergeMe();
    PmergeMe(char** argv);
    ~PmergeMe();

    bool load_container(char** argv);
    void print_elements(const char* label) const;
    void sort_binary_insert();
    void sort_ford_johnson();
    void print_elapsed_time() const;

    typename Container::iterator begin();
    typename Container::iterator end();
};

#endif
