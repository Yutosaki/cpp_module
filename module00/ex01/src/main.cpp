#include <phone_book.hpp>

int main(void){
    PhoneBook PhoneBook;
    std::cout << "enter command: ADD, SEARCH, EXIT" << std::endl;

    while(1) {
        std::string command;
        std::getline(std::cin, command);
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
