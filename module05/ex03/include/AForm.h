#ifndef FORM_H
#define FORM_H

#include <iostream>

#include "Bureaucrat.h"

class Bureaucrat;

class AForm {
   public:
    AForm();
    AForm(const AForm &AForm);
    AForm(const std::string &name, const int gradeRequiredSign, const int gradeRequireExecute);
    virtual ~AForm();

    AForm &operator=(const AForm &AForm);

    const std::string &getName() const;
    bool getSigned() const;
    int getGradeRequiredSign() const;
    int getGradeRequiredExecute() const;

    class GradeTooHighException : public std::exception {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char *what() const throw();
    };
    class FormNotSignedException : public std::exception {
        virtual const char *what() const throw();
    };

    void beSigned(const Bureaucrat &bureaucrat);
    void execute(Bureaucrat const &executor) const;
    virtual void doExecute() const = 0;

   private:
    const std::string name_;
    bool isSigned_;
    const int gradeRequiredSign_;
    const int gradeRequiredExecute_;
    static const int DEFAULT_GRADE = 1;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
