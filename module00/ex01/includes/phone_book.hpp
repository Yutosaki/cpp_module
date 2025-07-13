#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "contact.hpp"

#include <iostream>
#include <iomanip>


class PhoneBook {
    private:
        Contact contacts[MAX_CONTACTS];
        int oldest;
    
    public:
        PhoneBook();
        void add();
        void search();
        void displayTruncated(const std::string &str) const;
};

#endif