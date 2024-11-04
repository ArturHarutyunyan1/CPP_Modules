#ifndef SPAN
#define SPAN

#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>

class Span
{
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &copy);
        Span &operator=(const Span &copy);
        ~Span();
        void addNumber(unsigned int n);
        int shortestSpan() const;
        int longestSpan() const;
        template <typename T>
        void addRange(T start, T end);
    private:
        std::vector<int> arr;
        unsigned int n;
};

template <typename T>
void Span::addRange(T start, T end)
{
    size_t range = std::distance(start, end);

    if (arr.size() + range > n)
        throw std::out_of_range("Out of range");
    for (T it = start; it != end; it++)
    {
        addNumber(*it);
    }
}

#endif