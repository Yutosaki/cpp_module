#include "../include/PmergeMe.hpp"

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <typeinfo>
#include <vector>

template <typename Container>
bool PmergeMe<Container>::parsePositiveInt(char* s, int& out) const {
    char* endp;
    long val = std::strtol(s, &endp, 10);
    if (*endp != '\0' || val <= 0 || val > INT_MAX) return false;
    out = static_cast<int>(val);
    return true;
}

template <typename Container>
bool PmergeMe<Container>::load_container(char** argv) {
    for (int i = 1; argv[i]; ++i) {
        int x;
        if (!parsePositiveInt(argv[i], x)) {
            std::cerr << "Error: only positive integer accepted." << std::endl;
            return false;
        }
        container.push_back(x);
    }
    return true;
}

template <typename Container>
PmergeMe<Container>::PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(char** argv) {
    if (!load_container(argv))
        throw std::runtime_error("Fail to load cotent");
}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& other) { (void)other; }

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe& other) {
    (void)other;
    return *this;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
typename Container::iterator PmergeMe<Container>::begin() {
    return container.begin();
}

template <typename Container>
typename Container::iterator PmergeMe<Container>::end() {
    return container.end();
}

template <typename Container>
void PmergeMe<Container>::print_elapsed_time() const {
    double elapsed_time = static_cast<double>(time_end_ - time_start_) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << container.size()
              << " elements with " << container_type() << " : "
              << std::fixed << std::setprecision(6) << elapsed_time
              << " us" << std::endl;
}

template <typename Container>
std::string PmergeMe<Container>::container_type() const {
    if (typeid(container) == typeid(std::vector<int>))
        return "std::vector";
    else if (typeid(container) == typeid(std::deque<int>))
        return "std::deque";
    return "neither match vector and deque";
}

template <typename Container>
void PmergeMe<Container>::print_elements(const char* label) const {
    std::cout << label;

    size_t count = 0;
    size_t max = 10;
    for (typename Container::const_iterator it = container.begin(); it != container.end() && count < max; ++it, ++count) {
        std::cout << (count ? " " : "") << *it;
    }
    if (container.size() > max) std::cout << " [...]";
    std::cout << std::endl;
}

// 二分探索でelementを[left, right)の範囲に挿入する関数
// left, rightはイテレータで、comp_countは比較回数カウント用
// 戻り値は挿入後のイテレータ
namespace {
template <typename Container, typename Iterator, typename T>
Iterator binary_insert(Container& cont, Iterator left, Iterator right, const T& element) {
    while (left < right) {
        Iterator mid = left + (right - left) / 2;
        if (*mid < element) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return cont.insert(left, element);
}
}  // namespace

// Jacobstal Numberを返す閉形式
namespace {
template <typename Container>
int jacobsthal(int k) {
    double result = (std::pow(2, k) - std::pow(-1, k)) / 3.0;
    return static_cast<int>(result + 0.5);  // C++98でのround代替
}
}  // namespace

// Jacobstal Numberを基準に並び替え順を作る関数
namespace {
template <typename Container>
Container generate_jacobsthal_order(size_t n) {
    if (n == 0) return Container();

    Container order;  // 生成される順序の本体
    Container added;  // そのインデックスを既に追加したかのフラグ (0/1)
    for (size_t i = 0; i < n; ++i) added.push_back(0);

    // ヤコブスタール数列を生成
    Container jacobsthal_nums;
    int k = 3;  // J(3) = 3から開始（J(0) = 0, J(1) = 1, J(2) = 1は区間を生まないため不要）
    while (true) {
        int jk = jacobsthal<Container>(k);
        if (jk > static_cast<int>(n)) break;
        jacobsthal_nums.push_back(jk);
        k++;
    }

    // 最初の要素は常にインデックス0（1番目の要素）
    if (n > 0) {
        order.push_back(0);
        added[0] = 1;
    }

    size_t current_pos = 1;  // 次に挿入する位置

    // ヤコブスタール数列に基づいて挿入順序を決定
    for (size_t i = 0; i < jacobsthal_nums.size(); ++i) {
        int jk = jacobsthal_nums[i];

        // jkからcurrent_posまで逆順で挿入
        for (int idx = std::min(jk, static_cast<int>(n)) - 1; idx >= static_cast<int>(current_pos); --idx) {
            if (!added[idx]) {
                order.push_back(idx);
                added[idx] = 1;
            }
        }

        current_pos = jk;
    }

    // 残りの要素を順番に追加
    for (size_t i = 0; i < n; ++i) {
        if (!added[i]) {
            order.push_back(i);
        }
    }

    return order;
}
}  // namespace

namespace {
template <typename Container>
void ford_johnson(Container& v) {
    const size_t n = v.size();
    if (n <= 1) return;

    // step 1. ペアを作る（位置情報付き）
    std::vector<PairWithIndex> pairs;
    bool is_odd = (n % 2) != 0;
    int odd_val = 0;
    for (size_t i = 0; i + 1 < n; i += 2) {
        int a = v[i];
        int b = v[i + 1];
        pairs.push_back(PairWithIndex(a, b, i / 2));
    }
    if (is_odd) odd_val = v[n - 1];

    // step 2. ペアの大きい方だけ抜き出して main_chain を作る
    // main_chainを値＋ペアインデックスで作る
    std::vector<std::pair<int, size_t> > main_chain;
    for (size_t i = 0; i < pairs.size(); ++i)
        main_chain.push_back(std::make_pair(pairs[i].larger, i));

    // main_chain_valuesはContainer型で作成（vectorでもdequeでもOK）
    Container main_chain_values;
    for (size_t i = 0; i < main_chain.size(); ++i)
        main_chain_values.push_back(main_chain[i].first);
    ford_johnson(main_chain_values);
    // main_chain_valuesの順序に合わせてmain_chainを並び替え
    std::vector<std::pair<int, size_t> > sorted_main_chain;
    for (size_t i = 0; i < main_chain_values.size(); ++i) {
        for (size_t j = 0; j < main_chain.size(); ++j) {
            if (main_chain[j].first == main_chain_values[i]) {
                sorted_main_chain.push_back(main_chain[j]);
                main_chain.erase(main_chain.begin() + j);
                break;
            }
        }
    }
    main_chain = sorted_main_chain;

    Container result;
    // main_chain[0]に対応するsmallerの要素を見つけて最初に挿入
    if (!main_chain.empty()) {
        const size_t main_chain_0_idx = main_chain[0].second;
        result.push_back(pairs[main_chain_0_idx].smaller);
        result.push_back(main_chain[0].first);
    }
    // pending_with_info生成
    std::vector<ChainElement> pending_with_info;
    for (size_t i = 0; i < main_chain.size(); ++i) {
        const size_t pair_idx = main_chain[i].second;
        pending_with_info.push_back(ChainElement(pairs[pair_idx].smaller, pair_idx));
    }
    // 奇数個の場合は余った要素もpending_with_infoに追加
    if (is_odd) {
        pending_with_info.push_back(ChainElement(odd_val, pairs.size()));
    }

    // Jacobsthal数列に基づく挿入順序
    Container insertion_order = generate_jacobsthal_order<Container>(pending_with_info.size());

    // main_chainの残りの要素を追加
    for (size_t i = 1; i < main_chain.size(); ++i) {
        result.push_back(main_chain[i].first);
    }

    // pending要素をJacobsthal順序で二分挿入
    for (size_t i = 0; i < insertion_order.size(); ++i) {
        size_t idx = insertion_order[i];
        if (idx < pending_with_info.size()) {
            int element = pending_with_info[idx].value;
            size_t pair_idx = pending_with_info[idx].pair_index;

            // main_chain[0]に対応するsmallerの要素は既に処理済みなのでスキップ
            size_t main_chain_0_idx = static_cast<size_t>(-1);
            for (size_t j = 0; j < pairs.size(); ++j) {
                if (pairs[j].larger == main_chain[0].first) {
                    main_chain_0_idx = j;
                    break;
                }
            }
            if (pair_idx == main_chain_0_idx) {
                continue;  // 既に処理済みなのでスキップ
            }

            // 奇数要素（pair_idx == pairs.size()）の場合は全範囲で挿入
            if (pair_idx == pairs.size()) {
                binary_insert(result, result.begin(), result.end(), element);
                continue;
            }

            // ペアの相手(pairs[pair_idx].larger)の位置を見つける
            typename Container::iterator partner_pos = result.end();
            for (typename Container::iterator it = result.begin(); it != result.end(); ++it) {
                if (*it == pairs[pair_idx].larger) {
                    partner_pos = it;
                    break;
                }
            }

            // 挿入範囲を設定: 開始からペアの相手の位置まで
            binary_insert(result, result.begin(), partner_pos, element);
        }
    }

    // 結果を元のコンテナに反映
    v.assign(result.begin(), result.end());
}
}  // namespace

template <typename Container>
void PmergeMe<Container>::sort_ford_johnson() {
    time_start_ = std::clock();
    const size_t n = container.size();
    if (n <= 1) {
        time_end_ = std::clock();
        return;
    }
    ford_johnson(container);
    time_end_ = std::clock();
}

template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;
