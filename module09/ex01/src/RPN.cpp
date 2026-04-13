#include "../include/RPN.hpp"

#include <iostream>

RPN::RPN() {}
RPN::~RPN() {}

bool RPN::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::performOperation(char op) {
    if (_stack.size() < 2) throw std::runtime_error("Error");

    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();

    if (op == '+')
        _stack.push(a + b);
    else if (op == '-')
        _stack.push(a - b);
    else if (op == '*')
        _stack.push(a * b);
    else if (op == '/') {
        if (b == 0) throw std::runtime_error("Error: Division by zero");
        _stack.push(a / b);
    }
}

void RPN::calculate(const std::string& expression) {
    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        if (std::isspace(c)) continue;

        if (std::isdigit(c)) {
            _stack.push(c - '0');
        } else if (isOperator(c)) {
            try {
                performOperation(c);
            } catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
                return;
            }
        } else {
            std::cout << "Error" << std::endl;
            return;
        }
    }

    if (_stack.size() != 1) {
        std::cout << "Error" << std::endl;
    } else {
        std::cout << _stack.top() << std::endl;
    }
}
