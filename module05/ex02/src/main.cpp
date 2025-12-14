#include "../include/AForm.h"
#include "../include/Bureaucrat.h"
#include "../include/PresidentialPardonForm.h"
#include "../include/RobotomyRequestForm.h"
#include "../include/ShrubberyCreationForm.h"

void printSeparator(std::string message) {
    std::cout << "---------------------" << message << "---------------------"
              << "\n";
}

int main(void) {
    printSeparator("test ShrubberyCreationForm");
    {
        ShrubberyCreationForm a;
        Bureaucrat b = Bureaucrat("b", 1);
        b.signAForm(a);
        b.executeAForm(a);
        std::cout << '\n';
    }
    {
        printSeparator("exception form not signed");
        ShrubberyCreationForm a;
        Bureaucrat b = Bureaucrat("b", 1);
        try {
            b.executeAForm(a);
        } catch (const std::exception &e) {
            std::cerr << e.what() << "\n";
        }
        std::cout << '\n';
    }
    {
        printSeparator("exception grade is too low");
        ShrubberyCreationForm a;
        Bureaucrat b = Bureaucrat("b", 138);
        try {
            b.signAForm(a);
            b.executeAForm(a);
        } catch (const std::exception &e) {
            std::cerr << e.what() << "\n";
        }
    }

    std::cout << "\n\n";
    printSeparator("test RobotomyRequestForm");
    {
        RobotomyRequestForm a;
        Bureaucrat b = Bureaucrat("b", 1);
        try {
            b.signAForm(a);
            b.executeAForm(a);
        } catch (const std::exception &e) {
            std::cerr << e.what() << "\n";
        }
        std::cout << '\n';
    }
    {
        printSeparator("exception form not signed");
        RobotomyRequestForm a;
        Bureaucrat b = Bureaucrat("b", 1);
        try {
            b.executeAForm(a);
        } catch (const std::exception &e) {
            std::cerr << e.what() << "\n";
        }
        std::cout << '\n';
    }
    {
        printSeparator("exception grade is too low");
        RobotomyRequestForm a;
        Bureaucrat b = Bureaucrat("b", 46);
        try {
            b.signAForm(a);
            b.executeAForm(a);
        } catch (const std::exception &e) {
            std::cerr << e.what() << "\n";
        }
    }

    std::cout << "\n\n";
    printSeparator("test PresidentialPardonForm");
    {
        PresidentialPardonForm a;
        Bureaucrat b = Bureaucrat("b", 1);
        try {
            b.signAForm(a);
            b.executeAForm(a);
        } catch (const std::exception &e) {
            std::cerr << e.what() << "\n";
        }
        std::cout << '\n';
    }
    {
        printSeparator("exception form not signed");
        PresidentialPardonForm a;
        Bureaucrat b = Bureaucrat("b", 1);
        try {
            b.executeAForm(a);
        } catch (const std::exception &e) {
            std::cerr << e.what() << "\n";
        }
        std::cout << '\n';
    }
    {
        printSeparator("exception grade is too low");
        PresidentialPardonForm a;
        Bureaucrat b = Bureaucrat("b", 6);
        try {
            b.signAForm(a);
            b.executeAForm(a);
        } catch (const std::exception &e) {
            std::cerr << e.what() << "\n";
        }
    }
}
