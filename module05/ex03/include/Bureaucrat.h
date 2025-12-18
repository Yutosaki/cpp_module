#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <exception>
#include <string>

#include "AForm.h"

class AForm;

class Bureaucrat {
   public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat &Bureaucrat);
    Bureaucrat(const std::string &name, int grade);
    ~Bureaucrat();

    Bureaucrat &operator=(const Bureaucrat &bureaucrat);

    const std::string &getName() const;
    int getGrade() const;

    class GradeTooHighException : public std::exception {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char *what() const throw();
    };

    void IncrementGrade();
    void DecrementGrade();
    static const int MAX_GRADE = 1;
    static const int MIN_GRADE = 150;

    void signForm(AForm &form) const;
    void executeForm(const AForm &form) const;

   private:
    const std::string name_;
    int grade_;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
