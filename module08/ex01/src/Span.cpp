#include "../include/Span.h"

#include <climits>

Span::Span(unsigned int n) : _n(n) {
    _vec.reserve(n);
}

Span::Span(const Span& other) : _n(other._n), _vec(other._vec) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _n = other._n;
        _vec = other._vec;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_vec.size() >= _n)
        throw SpanFullException();
    _vec.push_back(number);
}

long Span::longestSpan() const {
    if (_vec.size() < 2)
        throw NoSpanException();

    int min_val = *std::min_element(_vec.begin(), _vec.end());
    int max_val = *std::max_element(_vec.begin(), _vec.end());

    return static_cast<long>(max_val) - min_val;
}

long Span::shortestSpan() const {
    if (_vec.size() < 2)
        throw NoSpanException();

    std::vector<int> sorted = _vec;
    std::sort(sorted.begin(), sorted.end());

    long min_diff = LONG_MAX;
    for (size_t i = 0; i < sorted.size() - 1; ++i) {
        long diff = static_cast<long>(sorted[i + 1]) - sorted[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}
