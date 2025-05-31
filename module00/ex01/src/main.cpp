#include <phone_book.hpp>

int main(void){
    PhoneBook PhoneBook;

    while(1) {
        std::string command;

        std::cout << "enter command: ADD, SEARCH, EXIT: ";
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
