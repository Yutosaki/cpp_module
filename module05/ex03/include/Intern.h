#ifndef INTERN_H
#define INTERN_H

#include <string>

class AForm;

class Intern {
   public:
    Intern();
    Intern(const Intern &intern);
    Intern &operator=(const Intern &intern);
    ~Intern();

    AForm *makeForm(const std::string &name, const std::string &target);

   private:
    AForm *makeShrubberyCreationForm(const std::string &target);
    AForm *makeRobotomyRequestForm(const std::string &target);
    AForm *makePresidentialPardonForm(const std::string &target);
    static const int FORM_NUM = 3;
};

#endif
