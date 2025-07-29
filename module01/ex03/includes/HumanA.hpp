#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

#include <iostream>

class HumanA {
    public:
        HumanA(const std::string &name, Weapon &weapon);
        ~HumanA();

        void attack() const;
        
    private:
        std::string name_;
        Weapon &weapon_;

};

#endif