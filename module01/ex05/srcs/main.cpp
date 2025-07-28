#include "Harl.hpp"

int main(void) {
    Harl harl;

    std::cout << "-- Test DEBUG --" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "-- Test INFO --" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "-- Test WARNING --" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "-- Test ERROR --" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "-- Test UNKNOWN --" << std::endl;
    harl.complain("UNKNOWN");
    std::cout << std::endl;

    return 0;   
}