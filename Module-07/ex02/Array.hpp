#ifndef ARRAY
#define ARRAY

#include <iostream>
#include <stdexcept>

template <typename T>

class Array
{
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        Array &operator=(const Array &copy);
        T &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;
        ~Array();
        unsigned int size(void) const;
    private:
        T *arr;
        unsigned int arrSize;
};

#include "Array.tpp"

#endif