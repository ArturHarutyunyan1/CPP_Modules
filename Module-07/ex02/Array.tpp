#include "Array.hpp"

template <typename T>
Array<T>::Array() : arr(NULL), arrSize(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arrSize(n)
{
    arr = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &copy) : arrSize(copy.arrSize)
{
    arr = new T[arrSize];
    for (unsigned int i = 0; i < arrSize; i++)
        arr[i] = copy.arr[i];
};

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
    if (this != &copy)
    {
        delete[] arr;
        arrSize = copy.arrSize;
        arr = new T[arrSize];
        for (unsigned int i = 0; i < arrSize; i++)
            arr[i] = copy.arr[i];
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= arrSize)
        throw std::out_of_range("Index is out of bounds");
    return (arr[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= arrSize)
        throw std::out_of_range("Index is out of bounds");
    return (arr[index]);
}

template <typename T>
Array<T>::~Array()
{
    delete[] arr;
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return (arrSize);
}