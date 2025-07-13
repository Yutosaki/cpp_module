#include <phone_book.hpp>

int main(void){
    PhoneBook PhoneBook;

    while(1) {
        std::string command;

        std::cout << "enter command: ADD, SEARCH, EXIT: ";
        if (!std::getline(std::cin, command)) {
            std::cout << "Error reading command." << std::endl;
            return 1;
        }
        if (command == "ADD") {
            PhoneBook.add();
        } else if (command == "SEARCH") {
            PhoneBook.search();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
        }
    }
}
