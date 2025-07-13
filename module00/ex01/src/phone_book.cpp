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
            }else if (input.empty()) {
                std::cerr << "Input cannot be empty." << std::endl;
            } else if (input.find_first_not_of(" \t\n\r\f\v") == std::string::npos) {
                std::cerr << "Input cannot contain only whitespace. Please try again." << std::endl;
            } else if (i == 3 && input.find_first_not_of("0123456789") != std::string::npos) {
                std::cerr << "Phone number must contain only digits. Please try again." << std::endl;
            } else {
                validInput = true;
            }
        }
        if (oldest == MAX_CONTACTS) {
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
    if (contacts[0].getFirstName().empty()) {
        std::cout << "Phonebook is empty. Use ADD to create a contact." << std::endl;
        return;
    }

    std::cout << "----------+----------+----------+----------" << std::endl;
    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nickname" << std::endl;
    std::cout << "----------+----------+----------+----------" << std::endl;
    
    for (int i = 0; i < MAX_CONTACTS ; i++) {
        if (contacts[i].getFirstName().empty()) {
            continue;
        }
        std::cout << std::setw(10) << i << "|";
        displayTruncated(contacts[i].getFirstName());
        std::cout << "|";
        displayTruncated(contacts[i].getLastName());
        std::cout << "|";
        displayTruncated(contacts[i].getNickname());
        std::cout << std::endl;
    }
    std::cout << "----------+----------+----------+----------" << std::endl;

    int index;
    std::string input;
    bool flag = true;
    while (flag) {
        std::cout << "Enter the index of the contact to display: ";
        if (!std::getline(std::cin, input)) {
            std::cout << "Error reading input." << std::endl;
            return;
        }else if (input.empty() || !std::isdigit(input[0]) || input.find_first_not_of("0123456789") != std::string::npos) {
            std::cerr << "Error: Please enter a valid index." << std::endl;
            continue;
        }else {
            index = std::atoi(input.c_str());
            if (index < 0 || index >= MAX_CONTACTS || contacts[index].getFirstName().empty()) {
                std::cerr << "Error: Invalid index. Please enter a valid index." << std::endl;
                continue;
            }
            flag = false;
        }
    }

    const Contact& contact = contacts[index];
    std::cout << "\n--- Contact Details (Index " << index << ") ---" << std::endl;
    std::cout << "First Name:     " << contact.getFirstName() << std::endl;
    std::cout << "Last Name:      " << contact.getLastName() << std::endl;
    std::cout << "Nickname:       " << contact.getNickname() << std::endl;
    std::cout << "Phone Number:   " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

void PhoneBook::displayTruncated(const std::string &str) const {
    if (str.length() > 10) {
        std::cout << std::setw(10) << (str.substr(0, 9) + ".");
    } else {
        std::cout << std::setw(10) << str;
    }
}
