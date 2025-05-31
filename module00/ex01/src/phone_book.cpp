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
    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nickname" << std::endl;
    std::cout << "----------+----------+----------+----------" << std::endl;
    
    for (int i = 0; i < 8 ; i++) {
        if (contacts[i].getFirstName().empty()) {
            continue;
        }
        std::cout << std::setw(10) << i + 1 << "|";
        displayTruncated(contacts[i].getFirstName());
        std::cout << "|";
        displayTruncated(contacts[i].getLastName());
        std::cout << "|";
        displayTruncated(contacts[i].getNickname());
        std::cout << std::endl;
    }
    std::cout << "----------+----------+----------+----------" << std::endl;
}

void PhoneBook::displayTruncated(const std::string &str) const {
    if (str.length() > 10) {
        std::cout << std::setw(10) << (str.substr(0, 9) + ".");
    } else {
        std::cout << std::setw(10) << str;
    }
}
