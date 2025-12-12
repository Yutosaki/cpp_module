#include "Form.h"

#include "Bureaucrat.h"

Form::Form() : name_(""), isSigned_(false), gradeRequiredSign_(DEFAULT_GRADE), gradeRequiredExecute_(DEFAULT_GRADE) {}

Form::Form(const Form &form) : name_(form.getName()), isSigned_(form.getSigned()), gradeRequiredSign_(form.getGradeRequiredSign()), gradeRequiredExecute_(form.getGradeRequiredExecute()) {}
