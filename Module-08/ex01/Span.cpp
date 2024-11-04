#include "Span.hpp"

Span::Span() : arr(0), n(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Span::Span(unsigned int N) : arr(), n(N)
{
    std::cout << "Constructor with parameter called" << std::endl;
    arr.reserve(n);
}

Span::Span(const Span &copy) : n(copy.n)
{
    std::cout << "Copy constructor called" << std::endl;
    arr = copy.arr;
}

Span &Span::operator=(const Span &copy)
{
    std::cout << "Copy assignment called" << std::endl;
    if (this != &copy)
    {
        n = copy.n;
        arr = copy.arr;
    }
    return (*this);
}

Span::~Span()
{
    std::cout << "Span was destroyed :((" << std::endl;
}

void Span::addNumber(unsigned int N)
{
    if (arr.size() < n)
        arr.push_back(N);
    else
        throw std::out_of_range("Out of range");
}

int Span::shortestSpan() const
{
    if (arr.size() < 2)
        throw std::runtime_error("Not enough members");
    std::vector<int> sortedList = arr;
    std::sort(sortedList.begin(), sortedList.end());
    int min = std::numeric_limits<int>::max();

    for (size_t i = 1; i < sortedList.size(); i++)
    {
        int span = sortedList[i] - sortedList[i - 1];
        if (span < min)
            min = span;
    }
    return (min);
}

int Span::longestSpan() const
{
    if (arr.size() < 2)
        throw std::runtime_error("Not enough members");
    int min = arr[0];
    int max = arr[0];

    for (size_t i = 1; i < arr.size(); i++)
    {
        if (min > arr[i])
            min = arr[i];
    }
    for (size_t i = 1; i < arr.size(); i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return (max - min);
}