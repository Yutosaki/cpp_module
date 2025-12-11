#include "Bureaucrat.h"

int main(void) {
  {
    std::cout << "-------------------OK-------------------\n";
    Bureaucrat a = Bureaucrat("a", 2);
    try {
      std::cout << a << "\n";
      a.DecrementGrade();
      std::cout << a << "\n";
      std::cout << a << "\n";
    }catch (const std::exception &e) {
      std::cerror < e.what() << "\n";
      a.IncrementGrade();
      
    }
     std::cout << '\n';
  {
    std::cout
        << "-------------------Grade is too low test-------------------\n";
    Bureaucrat a = Bureaucrat("a", Bureaucrat::kMinGrade);
    try {
      std::cout << a << std::endl;
      a.DecrementGrade();
      std::cout << a << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  std::cout << '\n';
  {
    std::cout
        << "-------------------Grade is too high test-------------------\n";
    Bureaucrat b = Bureaucrat("b", Bureaucrat::kMaxGrade);
    try {
      std::cout << b << std::endl;
      b.IncrementGrade();
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
}
