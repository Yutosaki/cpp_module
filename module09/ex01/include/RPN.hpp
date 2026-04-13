#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <stack>
#include <string>

class RPN {
   private:
    std::stack<int> _stack;
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    static bool isOperator(char c);
    void performOperation(char op);

   public:
    RPN();
    ~RPN();

    void calculate(const std::string& expression);
};

#endif
