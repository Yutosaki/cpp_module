#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "Default constructor called for ScavTrap" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
    std::cout << "Parameterized constructor called for ScavTrap" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "Copy constructor called for ScavTrap" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "Copy assignment operator called for ScavTrap" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "Destructor called for ScavTrap" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->_energyPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " has no energy to attack!" << std::endl;
        return;
    }
    if (this->_hitPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " is too damaged to attack!" << std::endl;
        return;
    }

    this->_energyPoints--;
    std::cout << "ScavTrap " << this->_name << " fiercely attacks " << target
              << ", dealing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->_name << " has entered Gate Keeper mode." << std::endl;
}