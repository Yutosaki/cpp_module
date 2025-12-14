#include "../include/RobotomyRequestForm.h"

#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", DEFAULT_GRADE_SIGN, DEFAULT_GRADE_EXEC),
      target_("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", DEFAULT_GRADE_SIGN, DEFAULT_GRADE_EXEC),
      target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)
    : AForm(form), target_(form.target_) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &form) {
    if (this == &form) {
        return *this;
    }
    AForm::operator=(form);
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string &RobotomyRequestForm::getTarget() const { return target_; }

void RobotomyRequestForm::doExecute() const {
    std::cout << "~~drilling noises~~" << "\n";
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }
    if (std::rand() % 2) {
        std::cout << target_ << " has been robotomized successfully!" << "\n";
    } else {
        std::cout << "Robotomy failed on " << target_ << "\n";
    }
}
