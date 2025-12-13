#include <exception>
#include <iostream>

#include "../include/Bureaucrat.h"
#include "../include/Form.h"

int main(void) {
    std::cout << "----------------form << operator----------------" << "\n";
    try {
        Form a = Form("a", 1, 1);
        std::cout << a << "\n";
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << "----------------test too high----------------" << "\n";
    try {
        Form a = Form("a", 0, 1);
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    try {
        Form a = Form("a", 1, 0);
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << "----------------test too low----------------" << "\n";
    try {
        Form a = Form("a", 151, 1);
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    try {
        Form a = Form("a", 1, 151);
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << "----------------test beSigned----------------" << "\n";
    std::cout << "----------------OK----------------" << "\n";
    try {
        Bureaucrat a = Bureaucrat("a", 1);
        Form b = Form("b", 1, 1);
        std::cout << b << "\n";
        b.beSigned(a);
        std::cout << b << "\n";
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << "----------------NG----------------" << "\n";
    try {
        Bureaucrat a = Bureaucrat("a", 10);
        Form b = Form("b", 1, 1);
        std::cout << b << "\n";
        b.beSigned(a);
        std::cout << b << "\n";
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << "----------------test signForm----------------" << "\n";
    std::cout << "----------------OK----------------" << "\n";
    {
        Bureaucrat a = Bureaucrat("a", 1);
        Form b = Form("b", 10, 1);
        std::cout << b << "\n";
        a.signForm(b);
        std::cout << b << "\n";
    }

    std::cout << "----------------NG----------------" << "\n";
    {
        Bureaucrat a = Bureaucrat("a", 10);
        Form b = Form("b", 1, 1);
        std::cout << b << "\n";
        a.signForm(b);
        std::cout << b << "\n";
    }
}
