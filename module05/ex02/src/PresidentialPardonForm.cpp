#include "../include/PresidentialPardonForm.h"

#include "../include/Bureaucrat.h"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", DEFAULT_GRADE_SIGN, DEFAULT_GRADE_EXEC), target_("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", DEFAULT_GRADE_SIGN, DEFAULT_GRADE_EXEC), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : AForm(form), target_(form.target_) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &form) {
    if (this == &form) {
        return *this;
    }
    AForm::operator=(form);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string &PresidentialPardonForm::getTarget() const { return target_; }

void PresidentialPardonForm::doExecute() const {
    std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << "\n";
}
