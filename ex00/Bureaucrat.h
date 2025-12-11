#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat {
public:
  Bureaucrat();
  Bureaucrat(const Bureaucrat &Bureaucrat);
  Bureaucrat(const std::string &name, int grade);
  ~Bureaucrat();

public:
};

#endif
