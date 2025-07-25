#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) 
    : name_(name), weapon_(NULL) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon_ = &weapon;
}

void HumanB::attack() const {
    if (weapon_) {
        std::cout << this->name_ << " attacks with their " << weapon_->getType() << std::endl;
    } else {
        std::cout << this->name_ << " is unarmed." << std::endl;
    }
}