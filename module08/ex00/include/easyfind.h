#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception {
   public:
    virtual const char* what() const throw() {
        return "Error: Target value not found in countainer";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int target) {
    typename T::iterator it = std::find(container.begin(), container.end(), target);

    if (it == container.end()) {
        throw NotFoundException();
    }
    return it;
}

#endif
