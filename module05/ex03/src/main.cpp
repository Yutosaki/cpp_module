#include "../include/AForm.h"
#include "../include/Intern.h"

void printSeparator(std::string message) {
    std::cout << "---------------------" << message << "---------------------"
              << "\n";
}

int main(void) {
    {
        printSeparator("test shrubbery");
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        if (rrf) {
            std::cout << *rrf << "\n";
        }
        delete rrf;
    }
    std::cout << '\n';
    {
        printSeparator("test robotomy");
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            std::cout << *rrf << "\n";
        }
        delete rrf;
    }
    std::cout << '\n';
    {
        printSeparator("test presidential");
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        if (rrf) {
            std::cout << *rrf << "\n";
        }
        delete rrf;
    }
    std::cout << '\n';
    {
        printSeparator("test invalid name");
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("hoge", "Bender");
        if (rrf) {
            std::cout << *rrf << "\n";
        }
        delete rrf;
    }
}
