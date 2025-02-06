#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <limits>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);
        ~PmergeMe();
        void processInput(int argc, char **argv);
    private:
        std::vector<int> vectorList;
        std::deque<int> dequeList;
        void insertionSortVector(std::vector<int> &list);
        void insertionSortDeque(std::deque<int> &list);
        void insertVector(std::vector<int> &left, std::vector<int> &right);
        void insertDeque(std::deque<int> &left, std::deque<int> &right);
        void fordVector(std::vector<int> &list);
        void fordDeque(std::deque<int> &list);
        long long stringToLong(const std::string &str);
};

#endif