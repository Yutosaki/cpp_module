#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ctime>
#include <string>

struct PairWithIndex {
    int smaller;
    int larger;
    size_t original_index;
    PairWithIndex(int s, int l, size_t idx) : smaller(s), larger(l), original_index(idx) {}
};

struct ChainElement {
    int value;
    size_t pair_index;
    ChainElement(int v, size_t idx) : value(v), pair_index(idx) {}
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
