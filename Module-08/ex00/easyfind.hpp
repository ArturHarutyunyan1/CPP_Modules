#ifndef EASYFIND
#define EASYFIND

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &arr, int val)
{
   typename T::iterator n = std::find(arr.begin(), arr.end(), val);

    if (n == arr.end())
        throw std::runtime_error("No occurance found");
    return (n);
}

#endif