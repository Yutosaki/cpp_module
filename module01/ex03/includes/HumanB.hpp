#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

#include <iostream>

class HumanB {
    public:
        HumanB(const std::string &name);
        ~HumanB();

        void attack() const;
        void setWeapon(Weapon &weapon);

    private:
        std::string name_;
        Weapon *weapon_;
};

#endif