#include "Bureaucrat.h"
#include "Form.h"

int main(void) {
    std::cout << "----------------form << operator----------------" << std::endl;
    try {
        Form a = Form("a", 1, 1);
        std::cout << a << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "----------------test too high----------------" << std::endl;
    try {
        Form a = Form("a", 0, 1);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form a = Form("a", 1, 0);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "----------------test too low----------------" << std::endl;
    try {
        Form a = Form("a", 151, 1);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form a = Form("a", 1, 151);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "----------------test beSigned----------------" << std::endl;
    std::cout << "----------------OK----------------" << std::endl;
    try {
        Bureaucrat a = Bureaucrat("a", 1);
        Form b = Form("b", 1, 1);
        std::cout << b << std::endl;
        b.beSigned(a);
        std::cout << b << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "----------------NG----------------" << std::endl;
    try {
        Bureaucrat a = Bureaucrat("a", 10);
        Form b = Form("b", 1, 1);
        std::cout << b << std::endl;
        b.beSigned(a);
        std::cout << b << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "----------------test signForm----------------" << std::endl;
    std::cout << "----------------OK----------------" << std::endl;
    {
        Bureaucrat a = Bureaucrat("a", 1);
        Form b = Form("b", 10, 1);
        std::cout << b << std::endl;
        a.signForm(b);
        std::cout << b << std::endl;
    }

    std::cout << "----------------NG----------------" << std::endl;
    {
        Bureaucrat a = Bureaucrat("a", 10);
        Form b = Form("b", 1, 1);
        std::cout << b << std::endl;
        a.signForm(b);
        std::cout << b << std::endl;
    }
}
