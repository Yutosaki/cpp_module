#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <cstdlib>
#include <ctime>

#include "AForm.h"
class RobotomyRequestForm : public AForm {
   public:
    RobotomyRequestForm();
    explicit RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &form);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &form);
    ~RobotomyRequestForm();
    const std::string &getTarget() const;
    void doExecute() const;

   private:
    static const int DEFAULT_GRADE_SIGN = 72;
    static const int DEFAULT_GRADE_EXEC = 45;
    const std::string target_;
};
#endif
