#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
   public:
    Array() : data_(NULL), size_(0) {}
    explicit Array(const unsigned int n) : data_(NULL), size_(n) {
        if (size_ > 0) {
            data_ = new T[size_];
        }
    }
    explicit Array(const unsigned int n, const T& value) : data_(NULL), size_(n) {
        if (size_ > 0) {
            data_ = new T[size_];
            for (std::size_t i = 0; i < size_; ++i) {
                data_[i] = value;
            }
        }
    }
    Array(const Array& other) : data_(NULL), size_(other.size_) {
        if (size_ > 0) {
            data_ = new T[size_];
            for (size_t i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        }
    }
    Array& operator=(const Array& rhs) {
        if (this != &rhs) {
            Array tmp(rhs);
            tmp.swap(*this);
        }
        return *this;
    }
    ~Array() { delete[] data_; }
    size_t size() const { return size_; }

    T& operator[](size_t i) {
        if (i >= size_) {
            throw std::out_of_range("Array: index out of range");
        }
        return data_[i];
    }

    const T& operator[](size_t i) const {
        if (i >= size_) {
            throw std::out_of_range("Array: index out of range");
        }
        return data_[i];
    }

   private:
    T* data_;
    std::size_t size_;
    void swap(Array& other) throw() {
        T* tmp = data_;
        data_ = other.data_;
        other.data_ = tmp;

        std::size_t tmp_size = size_;
        size_ = other.size_;
        other.size_ = tmp_size;
    }
};

#endif
