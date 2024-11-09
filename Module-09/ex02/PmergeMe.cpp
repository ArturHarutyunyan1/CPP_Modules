#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &copy) : vectorList(copy.vectorList), dequeList(copy.dequeList)
{

}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    if (this != &copy)
    {
        vectorList = copy.vectorList;
        dequeList = copy.dequeList;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{

}

void insertionSortVector(std::vector<int> &list)
{
    for (size_t i = 1; i < list.size(); i++)
    {
        int j = i;
        while (j > 0 && list[j - 1] > list[j])
        {
            std::swap(list[j - 1], list[j]);
            j--;
        }
    }
}

void insertionSortDeque(std::deque<int> &list)
{
    for (size_t i = 1; i < list.size(); i++)
    {
        int j = i;
        while (j > 0 && list[j - 1] > list[j])
        {
            std::swap(list[j - 1], list[j]);
            j--;
        }
    }
}

void insertVector(std::vector<int> &left, std::vector<int> &right)
{
    size_t n = 0;
    size_t power = 0;
    size_t start = 0;
    size_t end = 0;

    for (size_t i = 0; i < right.size();)
    {
        ++power;
        n = pow(2, power);
        start += n;
        end = start - n;

        if (start > right.size())
            start = right.size();
        for (size_t j = start - 1; j >= end;)
        {
            left.insert(std::upper_bound(left.begin(), left.end(), right[j]), right[j]);
            ++i;
            if (j == 0)
                break;
            --j;
        }
    }
}

void insertDeque(std::deque<int> &left, std::deque<int> &right)
{
    size_t n = 0;
    size_t power = 0;
    size_t start = 0;
    size_t end = 0;

    for (size_t i = 0; i < right.size();)
    {
        ++power;
        n = pow(2, power);
        start += n;
        end = start - n;

        if (start > right.size())
            start = right.size();
        for (size_t j = start - 1; j >= end;)
        {
            left.insert(std::upper_bound(left.begin(), left.end(), right[j]), right[j]);
            ++i;
            if (j == 0)
                break;
            --j;
        }
    }
}

void fordVector(std::vector<int> &list)
{
    std::vector<int> left;
    std::vector<int> right;

    if (list.size() < 4)
    {
        insertionSortVector(list);
        return;
    }
    for (size_t i = 0; i < list.size() / 2; i++)
    {
        int a = list[2 * i];
        int b = list[2 * i + 1];

        if (a > b)
        {
            left.push_back(b);
            right.push_back(a);
        }
        else
        {
            left.push_back(a);
            right.push_back(b);
        }
    }
    if (list.size() % 2 == 1)
        right.push_back(list[list.size() - 1]);
    fordVector(left);
    insertVector(left, right);
    list = left;
}

void fordDeque(std::deque<int> &list)
{
    std::deque<int> left;
    std::deque<int> right;

    if (list.size() < 4)
    {
        insertionSortDeque(list);
        return;
    }
    for (size_t i = 0; i < list.size() / 2; i++)
    {
        int a = list[2 * i];
        int b = list[2 * i + 1];

        if (a > b)
        {
            left.push_back(b);
            right.push_back(a);
        }
        else
        {
            left.push_back(a);
            right.push_back(b);
        }
    }
    if (list.size() % 2 == 1)
        right.push_back(list[list.size() - 1]);
    fordDeque(left);
    insertDeque(left, right);
    list = left;
}

void processLine(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(str[i]) && str[i] != ' ')
        {
            std::cout << "Only positive numbers allowed" << std::endl;
            exit (1);
        }
    }
}

void PmergeMe::processInput(int argc, char **argv)
{
    int i;
    for (i = 1; i < argc; i++)
    {
        long num;
        processLine(argv[i]);
        num = std::stol(argv[i]);
        if (num < 0)
        {
            std::cout << "Only positive numbers allowed" << std::endl;
            exit (1);
        }
        if (num > std::numeric_limits<int>::max())
        {
            std::cout << "Too large value" << std::endl;
            exit (1);
        }
        vectorList.push_back(num);
        dequeList.push_back(num);
    }
    std::cout << "Before: ";
    size_t count = vectorList.size();
    for (size_t i = 0; i < (count > 10 ? 10 : count); i++)
        std::cout << vectorList[i] << " ";
    std::cout << std::endl;
    clock_t vStart = clock();
    fordVector(vectorList);
    clock_t vEnd = clock();
    double vectorTime = static_cast<double>(vEnd - vStart) / CLOCKS_PER_SEC;
    clock_t dStart = clock();
    fordDeque(dequeList);
    clock_t dEnd = clock();
    double dequeTime = static_cast<double>(dEnd - dStart) / CLOCKS_PER_SEC;
    std::cout << "After: ";
    for (size_t i = 0; i < (count > 10 ? 10 : count); i++)
        std::cout << vectorList[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << i - 1 << " elements with std::vector : " << std::fixed << std::setprecision(5) << vectorTime << " seconds." << std::endl;
    std::cout << "Time to process a range of " << i - 1 << " elements with std::deque : " << std::fixed << std::setprecision(5) << dequeTime << " seconds." << std::endl;
}