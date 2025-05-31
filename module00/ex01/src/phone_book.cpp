#include <phone_book.hpp>

PhoneBook::PhoneBook() : oldest(0) {}

void PhoneBook::add() {
    std::string input;
    const std::string fieldNames[] = {
        " first name",
        " last name",
        " nickname",
        " phone number",
        " darkest secret"
    };

    for (int i = 0; i < FIELD_COUNT; i++) {
        bool validInput = false;

        while (!validInput) {
            std::cout << "Enter" << fieldNames[i] << ": ";
            if (!std::getline(std::cin, input)) {
                std::cerr << "Error reading input." << std::endl;
                return;
            }
            if (input.empty()) {
                std::cerr << "Input cannot be empty." << std::endl;
            } else {
                validInput = true;
            }
        }
        if (oldest == 8) {
            oldest = 0;
        }
        switch (i) {
            case 0: contacts[oldest].setFirstName(input); break;
            case 1: contacts[oldest].setLastName(input); break;
            case 2: contacts[oldest].setNickname(input); break;
            case 3: contacts[oldest].setPhoneNumber(input); break;
            case 4: contacts[oldest].setDarkestSecret(input); break;
        }
    }
    oldest++;
}

void PhoneBook::search() {

    std::cout << "Search functionality not yet implemented." << std::endl;
}