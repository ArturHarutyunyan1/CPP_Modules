#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN &copy) : arr(copy.arr)
{

}

RPN &RPN::operator=(const RPN &copy)
{
    if (this != &copy)
        arr = copy.arr;
    return (*this);
}

RPN::~RPN()
{

}

void processInput(std::string input)
{
    for (size_t i = 0; i < input.size(); i++)
    {
        if ((input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' && input[i] != ' ') && (!std::isdigit(input[i])))
        {
            std::cout << "Error" << std::endl;
            exit (1);
        }
        if (std::isdigit(input[i]) && i + 1 < input.size() && input[i + 1] != ' ')
        {
            std::cout << "Error: Multi-digit numbers are not allowed" << std::endl;
            exit(1);
        }
        if ((input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') && (i + 1 < input.size() && input[i + 1] != ' '))
        {
            std::cout << "Error: Invalid operator sequence" << std::endl;
            exit(1);
        }
    }
}

void RPN::ReversePolishNotation(char *input)
{
    std::string str = input;

    processInput(str);
    size_t i = 0;
    while (i < str.size())
    {
        if (std::isdigit(str[i]))
        {
            int num = str[i] - '0';
            arr.push(num);
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            if (arr.size() < 2)
            {
                std::cout << "Error: Not enough operands" << std::endl;
                exit (1);
            }
            long b = arr.top(); arr.pop();
            long a = arr.top(); arr.pop();

            long result = 0;
            switch (str[i])
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                if (b == 0)
                {
                    std::cout << "Error: Can't divide by 0" << std::endl;
                    exit (1);
                }
                result = a / b;
                break;
            default:
                std::cout << "Unknown operator" << std::endl;
                break;
            }
            if (result > std::numeric_limits<int>::max())
            {
                std::cout << "Error: Overflow caught" << std::endl;
                exit (1);
            }
            arr.push(result);
            ++i;
        }
        i++;
    }
    if (arr.size() != 1)
    {
        std::cout << "Error: Invalid RPN" << std::endl;
        exit(1);
    }
    std::cout << arr.top() << std::endl;
}