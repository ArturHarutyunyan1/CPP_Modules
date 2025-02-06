//
// Created by Artur Harutyunyan on 06.02.25.
//

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <cstdlib>
#include <stack>

class RPN {
private:
    std::stack<long> container;
    void validator(const std::string &input);
public:
    RPN();
    RPN(const RPN &copy);
    RPN &operator=(const RPN &copy);
    ~RPN();
    void calculator(const std::string &input);
};

#endif //RPN_HPP
