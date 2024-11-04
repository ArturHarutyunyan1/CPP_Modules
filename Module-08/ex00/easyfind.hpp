#ifndef EASYFIND
#define EASYFIND

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &arr, int n)
{
    typename T::iterator it = std::find(arr.begin(), arr.end(), n);

    if (it == arr.end())
        throw std::runtime_error("No occurance found");
    return (it);
}

#endif