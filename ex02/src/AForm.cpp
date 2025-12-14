#include "../include/AForm.h"

#include <iostream>
#include <string>

#include "../include/Bureaucrat.h"

AForm::AForm() : name_("default"), isSigned_(false), gradeRequiredSign_(DEFAULT_GRADE), gradeRequiredExecute_(DEFAULT_GRADE) {}

AForm::AForm(const AForm &form) : name_(form.getName()), isSigned_(form.getSigned()), gradeRequiredSign_(form.getGradeRequiredSign()), gradeRequiredExecute_(form.getGradeRequiredExecute()) {}

AForm::AForm(const std::string &name, const int gradeRequiredSign, const int gradeRequireExecute) : name_(name), isSigned_(false), gradeRequiredSign_(gradeRequiredSign), gradeRequiredExecute_(gradeRequireExecute) {  // NOLINT
    if (gradeRequiredExecute_ < Bureaucrat::MAX_GRADE || gradeRequiredSign_ < Bureaucrat::MAX_GRADE) {
        throw GradeTooHighException();
    }
    if (gradeRequiredExecute_ > Bureaucrat::MIN_GRADE || gradeRequiredSign_ > Bureaucrat::MIN_GRADE) {
        throw GradeTooLowException();
    }
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &form) {
    if (this != &form) {
        this->isSigned_ = form.getSigned();
    }
    return *this;
}

const std::string &AForm::getName() const { return name_; }

bool AForm::getSigned() const { return isSigned_; }

int AForm::getGradeRequiredSign() const {
    return gradeRequiredSign_;
}

int AForm::getGradeRequiredExecute() const { return gradeRequiredExecute_; }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= gradeRequiredSign_) {
        isSigned_ = true;
    } else {
        throw GradeTooLowException();
    }
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too Low";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form Not Signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << "name: " << form.getName() << "\n"
       << "signed: " << std::boolalpha << form.getSigned() << "\n"
       << "gradeRequiredSign: " << form.getGradeRequiredSign() << "\n"
       << "gradeRequireExecute: " << form.getGradeRequiredExecute() << "\n";
    return os;
}

void AForm::execute(Bureaucrat const &executor) const {
    if (!getSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > gradeRequiredExecute_) {
        throw GradeTooLowException();
    }
    doExecute();
}
