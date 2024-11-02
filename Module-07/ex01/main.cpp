#include "iter.hpp"

void printElement(int x) {
    std::cout << x << " ";
}

void incrementElement(int& x) {
    x += 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    iter(arr, length, printElement);
    std::cout << "\n";

    iter(arr, length, incrementElement);
    iter(arr, length, incrementElement);
    iter(arr, length, incrementElement);

    std::cout << "Modified array: ";
    iter(arr, length, printElement);
    std::cout << "\n";

    return 0;
}