#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <exception>
#include <algorithm>

class RPN
{
    public:
        RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &copy);
        ~RPN();
        void ReversePolishNotation(char *input);
    private:
        std::stack<int> arr;
};

#endif