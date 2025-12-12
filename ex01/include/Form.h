#ifndef FORM_H
#define FORM_H

#include <iostream>

class Form {
   public:
    Form();
    Form(const Form &Form);
    Form(const std::string &name, const int gradeRequiredSign, const int gradeRequireExecute);
    ~Form();

    Form &operator=(const Form &Form);

    const std::string &getName() const;
    bool getSigned() const;

    int getGradeRequiredSign() const;
    int getGradeRequiredExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char *what() const throw();
    };

   private:
    const std::string name_;
    bool isSigned_;
    const int gradeRequiredSign;
    const int gradeRequiredExecute_;
    static const int DEFAULT_GRADE = 1;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
