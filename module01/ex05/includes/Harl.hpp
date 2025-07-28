#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

const int NUM_COMPLAINTS = 4;

class Harl {
    public:
        Harl();
        ~Harl();

        void complain(const std::string &level);

    private:
        void _debug();
        void _info();
        void _warning();
        void _error();
};

#endif