//
// Created by Artur Harutyunyan on 06.02.25.
//

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy) : container(copy.container) {}

RPN &RPN::operator=(const RPN &copy) {
    if (this != &copy)
        container = copy.container;
    return  (*this);
}

RPN::~RPN() {}

void RPN::validator(const std::string &input) {
    for (size_t i = 0; i < input.size(); i++)
    {
        if ((input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' && input[i] != ' ') && (!std::isdigit(input[i])))
            throw std::runtime_error("Error");
        if (std::isdigit(input[i]) && i + 1 < input.size() && input[i + 1] != ' ')
            throw std::runtime_error("Error: Multi digit numbers are not allowed");
        if ((input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') && (i + 1 < input.size() && input[i + 1] != ' '))
            throw std::runtime_error("Error: Invalid operator sequence");
    }
}


void RPN::calculator(const std::string &input) {
    validator(input);

    long a = 0, b = 0, result = 0;

    size_t i = 0;

    while (i < input.size()) {
        if (std::isdigit(input[i])) {
            int n = input[i] - '0';
            container.push(n);
            ++i;
        }
        else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*') {
            if (container.size() < 2)
                throw std::runtime_error("Error: Not enough operands");
            b = container.top(); container.pop();
            a = container.top(); container.pop();

            switch (input[i]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '/':
                    if (b == 0)
                        throw std::runtime_error("Error: Can't divide by 0");
                    result = a / b;
                    break;
                case '*':
                    result = a * b;
                    break;
            }
            if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
                throw std::runtime_error("Error: Overflow caught");
            container.push(result);
            ++i;
        }
        else
            ++i;
    }
    if (container.size() != 1)
        throw std::runtime_error("Error: Invalid RPN");
    std::cout << container.top() << std::endl;
}



