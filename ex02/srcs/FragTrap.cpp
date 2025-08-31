#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "Default constructor called for FragTrap" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
    std::cout << "Parameterized constructor called for FragTrap" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "Copy constructor called for FragTrap" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "Copy assignment operator called for FragTrap" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "Destructor called for FragTrap" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (this->_energyPoints == 0) {
        std::cout << "FragTrap " << this->_name << " has no energy to attack!" << std::endl;
        return;
    }
    if (this->_hitPoints == 0) {
        std::cout << "FragTrap " << this->_name << " is too damaged to attack!" << std::endl;
        return;
    }

    this->_energyPoints--;
    std::cout << "FragTrap " << this->_name << " powerfully attacks " << target
              << ", dealing " << this->_attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->_name << " is requesting a high five! ✋" << std::endl;
}