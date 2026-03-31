#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iterator>
#include <vector>

class Span {
   private:
    unsigned int _n;
    std::vector<int> _vec;

   public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);

    template <typename T>
    void addNumbers(T begin, T end) {
        if (_vec.size() + std::distance(begin, end) > _n)
            throw SpanFullException();
        _vec.insert(_vec.end(), begin, end);
    }

    long shortestSpan() const;
    long longestSpan() const;

    class SpanFullException : public std::exception {
        virtual const char* what() const throw() { return "Span: Storage is full"; }
    };

    class NoSpanException : public std::exception {
        virtual const char* what() const throw() { return "Span: Not enough numbers to find a span"; }
    };
};

#endif
