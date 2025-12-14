#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <fstream>

#include "AForm.h"

class ShrubberyCreationForm : public AForm {
   public:
    ShrubberyCreationForm();
    explicit ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &form);
    ShrubberyCreationForm &
    operator=(const ShrubberyCreationForm &form);
    ~ShrubberyCreationForm();
    const std::string &getTarget() const;
    void doExecute() const;

   private:
    static const int DEFAULT_GRADE_SIGN = 145;
    static const int DEFAULT_GRADE_EXEC = 137;
    const std::string target_;
};

#endif
