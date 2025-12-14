#include "../include/ShrubberyCreationForm.h"

#include <stdexcept>

#include "../include/AForm.h"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", DEFAULT_GRADE_SIGN, DEFAULT_GRADE_EXEC),
      target_("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", DEFAULT_GRADE_SIGN, DEFAULT_GRADE_EXEC),
      target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm &form)
    : AForm(form) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &form) {
    if (this == &form) {
        return *this;
    }
    AForm::operator=(form);
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string &ShrubberyCreationForm::getTarget() const { return target_; }

void ShrubberyCreationForm::doExecute() const {
    const std::string fileName = target_ + "_shrubbery";
    std::ofstream file(fileName.c_str());
    if (!file.is_open())
        throw std::runtime_error("can't open file");
    std::string shrubbery =
        "       _-_\n"
        "    /~~   ~~\\\n"
        " /~~         ~~\\\n"
        "{               }\n"
        " \\  _-     -_  /\n"
        "   ~  \\\\ //  ~\n"
        "_- -   | | _- _\n"
        "  _ -  | |   -_\n"
        "      // \\\\\n";
    file << shrubbery;
    file.close();
}
