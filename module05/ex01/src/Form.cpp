#include "../include/Form.h"

#include <iostream>
#include <string>

#include "../include/Bureaucrat.h"

Form::Form() : isSigned_(false), gradeRequiredSign_(DEFAULT_GRADE), gradeRequiredExecute_(DEFAULT_GRADE) {}

Form::Form(const Form &form) : name_(form.getName()), isSigned_(form.getSigned()), gradeRequiredSign_(form.getGradeRequiredSign()), gradeRequiredExecute_(form.getGradeRequiredExecute()) {}

Form::Form(const std::string &name, const int gradeRequiredSign, const int gradeRequireExecute) : name_(name), isSigned_(false), gradeRequiredSign_(gradeRequiredSign), gradeRequiredExecute_(gradeRequireExecute) {  // NOLINT
    if (gradeRequiredExecute_ < Bureaucrat::MAX_GRADE || gradeRequiredSign_ < Bureaucrat::MAX_GRADE) {
        throw GradeTooHighException();
    }
    if (gradeRequiredExecute_ > Bureaucrat::MIN_GRADE || gradeRequiredSign_ > Bureaucrat::MIN_GRADE) {
        throw GradeTooLowException();
    }
}

Form::~Form() {}

const std::string &Form::getName() const { return name_; }

bool Form::getSigned() const { return isSigned_; }

int Form::getGradeRequiredSign() const {
    return gradeRequiredSign_;
}

int Form::getGradeRequiredExecute() const { return gradeRequiredExecute_; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= gradeRequiredSign_) {
        isSigned_ = true;
    } else {
        throw GradeTooLowException();
    }
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too Low";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "name: " << form.getName() << "\n"
       << "signed: " << std::boolalpha << form.getSigned() << "\n"
       << "gradeRequiredSign: " << form.getGradeRequiredSign() << "\n"
       << "gradeRequireExecute: " << form.getGradeRequiredExecute() << "\n";
    return os;
}
