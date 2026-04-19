#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <string>
#include <vector>

class PmergeMe {
   private:
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    static std::vector<int> generateJacobsthalSequence(int n);

   public:
    PmergeMe();
    ~PmergeMe();

    template <typename Container>
    void sort(Container& c);

    template <typename Container>
    void binaryInsertion(Container& main, int value);

    static bool isValidInput(const std::string& s);
};

template <typename Container>
void PmergeMe::sort(Container& c) {
    if (c.size() <= 1) return;

    bool has_straggler = (c.size() % 2 != 0);
    int straggler = 0;
    if (has_straggler) {
        straggler = c.back();
        c.pop_back();
    }

    Container main_chain;
    Container pending;
    for (size_t i = 0; i < c.size(); i += 2) {
        if (c[i] < c[i + 1]) {
            pending.push_back(c[i]);
            main_chain.push_back(c[i + 1]);
        } else {
            pending.push_back(c[i + 1]);
            main_chain.push_back(c[i]);
        }
    }

    sort(main_chain);

    main_chain.insert(main_chain.begin(), pending[0]);

    std::vector<int> jacob = generateJacobsthalSequence(pending.size());
    std::vector<bool> inserted(pending.size(), false);
    inserted[0] = true;

    for (size_t i = 0; i < jacob.size(); ++i) {
        int target_idx = jacob[i] - 1;
        if (target_idx >= (int)pending.size()) target_idx = pending.size() - 1;

        for (int j = target_idx; j >= 0; --j) {
            if (!inserted[j]) {
                typename Container::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pending[j]);
                main_chain.insert(it, pending[j]);
                inserted[j] = true;
            }
        }
    }

    if (has_straggler) {
        typename Container::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
        main_chain.insert(it, straggler);
    }

    c = main_chain;
}

template <typename Container>
void PmergeMe::binaryInsertion(Container& main, int value) {
    typename Container::iterator it = std::lower_bound(main.begin(), main.end(), value);

    main.insert(it, value);
}

#endif
