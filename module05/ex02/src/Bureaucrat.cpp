#include "../include/Bureaucrat.h"

#include <iostream>
#include <string>

#include "../include/AForm.h"

Bureaucrat::Bureaucrat() : grade_(Bureaucrat::MIN_GRADE) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name), grade_(grade) {
    if (grade_ > MIN_GRADE) {
        throw GradeTooLowException();
    }
    if (grade_ < MAX_GRADE) {
        throw GradeTooHighException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name_(bureaucrat.getName()), grade_(bureaucrat.getGrade()) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
    if (this != &bureaucrat) {
        this->grade_ = bureaucrat.getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const {
    return name_;
}

int Bureaucrat::getGrade() const {
    return grade_;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

void Bureaucrat::IncrementGrade() {
    if (grade_ <= Bureaucrat::MAX_GRADE) {
        throw GradeTooHighException();
    }
    grade_--;
}

void Bureaucrat::DecrementGrade() {
    if (grade_ >= Bureaucrat::MIN_GRADE) {
        throw GradeTooLowException();
    }
    grade_++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}

void Bureaucrat::signAForm(AForm &form) const {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << "\n";
    } catch (const std::exception &e) {
        std::cout << this->getName() << " couldn’t sign " << form.getName()
                  << " because " << e.what() << "." << "\n";
    }
}

void Bureaucrat::executeAForm(const AForm &form) const {
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << "\n";
    } catch (const std::exception &e) {
        std::cout << this->getName() << " couldn't execute " << form.getName()
                  << " because " << e.what() << "\n";
    }
}
