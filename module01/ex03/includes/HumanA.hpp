#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

#include <iostream>

class HumanA {
    private:
        std::string name_;
        Weapon &weapon_;

    public:
        HumanA(const std::string &name, Weapon &weapon);
        ~HumanA();

        void attack() const;
};

#endif