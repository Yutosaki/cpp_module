#include "../include/Intern.h"

#include "../include/PresidentialPardonForm.h"
#include "../include/RobotomyRequestForm.h"
#include "../include/ShrubberyCreationForm.h"

Intern::Intern() {}

Intern::Intern(const Intern &intern) { *this = intern; }

Intern &Intern::operator=(const Intern &intern) {
    if (this == &intern)
        return *this;
    (void)intern;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &name, const std::string &target) {  // NOLINT
    AForm *(Intern::*makeFormFunctions[])(const std::string &) = {
        &Intern::makeShrubberyCreationForm,
        &Intern::makeRobotomyRequestForm,
        &Intern::makePresidentialPardonForm,
    };
    std::string forms[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon",
    };

    for (int i = 0; i < FORM_NUM; ++i) {
        if (name == forms[i]) {
            std::cout << "Intern creates " << name << "\n";
            return (this->*makeFormFunctions[i])(target);
        }
    }
    std::cout << "Intern can't create " << name << "\n";
    return NULL;
}

AForm *Intern::makeShrubberyCreationForm(const std::string &target) {  // NOLINT
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target) {  // NOLINT
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(const std::string &target) {  // NOLINT
    return new PresidentialPardonForm(target);
}
