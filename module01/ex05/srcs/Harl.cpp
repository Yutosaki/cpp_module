#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::_debug() {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::_info() {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning() {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::_error() {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(const std::string &level) {
    typedef void (Harl::*ComplaintFunction)();

    ComplaintFunction complaints[NUM_COMPLAINTS] = {
        &Harl::_debug,
        &Harl::_info,
        &Harl::_warning,
        &Harl::_error
    };

    std::string levels[NUM_COMPLAINTS] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    for (int i = 0; i < NUM_COMPLAINTS; i++) {
        if (level == levels[i]) {
            (this->*complaints[i])();
            return;
        }
    }
    
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}