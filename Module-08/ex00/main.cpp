#include "easyfind.hpp"

int main()
{
    std::vector<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);

    try
    {
        std::vector<int>::iterator r = easyfind(numbers, 4);
        std::cout << "Found value " << *r << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}