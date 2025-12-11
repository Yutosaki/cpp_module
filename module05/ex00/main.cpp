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
        } catch (const std::exception &e) {
            std::cerr << e.what() << "\n";
            a.IncrementGrade();
        }
        std::cout << '\n';
        {
            std::cout
                << "-------------------Grade is too low test-------------------\n";
            Bureaucrat a = Bureaucrat("a", Bureaucrat::MIN_GRADE);
            try {
                std::cout << a << "\n";
                a.DecrementGrade();
                std::cout << a << "\n";
            } catch (const std::exception &e) {
                std::cerr << e.what() << "\n";
            }
        }

        std::cout << '\n';
        {
            std::cout
                << "-------------------Grade is too high test-------------------\n";
            Bureaucrat b = Bureaucrat("b", Bureaucrat::MAX_GRADE);
            try {
                std::cout << b << "\n";
                b.IncrementGrade();
            } catch (const std::exception &e) {
                std::cerr << e.what() << "\n";
            }
        }
    }
}
