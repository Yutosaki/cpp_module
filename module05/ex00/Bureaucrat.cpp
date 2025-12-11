#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>

class Bureaucrat {
public:
  Bureaucrat();
  Bureaucrat(const Bureaucrat &bureaucrat);
  Bureaucrat(const std::string &name, int grade);
  ~Bureaucrat();

public:
  Bureaucrat &operator=(const Bureaucrat &bureaucrat);

private:
  const std::string name_;
  int grade_;
};
Bureaucrat &operator<<(std::string &name, int grade);

#endif
