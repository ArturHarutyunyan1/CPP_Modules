#include "MutantStack.hpp"

int main() {
    // Test case 1: Basic operations
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element after pushes: " << mstack.top() << std::endl; // 17
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl; // 1
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Test case 2: Iterating through elements
    std::cout << "Iterating through elements:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << std::endl; // Should print all elements in the order they were added
    }

    // Test case 3: Copying the MutantStack
    MutantStack<int> copiedStack(mstack);
    std::cout << "Iterating through copied stack:" << std::endl;
    for (MutantStack<int>::iterator it = copiedStack.begin(); it != copiedStack.end(); ++it) {
        std::cout << *it << std::endl; // Should match the original stack
    }

    // Test case 4: Assigning one MutantStack to another
    MutantStack<int> assignedStack;
    assignedStack = mstack;
    std::cout << "Iterating through assigned stack:" << std::endl;
    for (MutantStack<int>::iterator it = assignedStack.begin(); it != assignedStack.end(); ++it) {
        std::cout << *it << std::endl; // Should match the original stack
    }

    // Test case 5: Size checks
    std::cout << "Size of mstack: " << mstack.size() << std::endl; // Should be 5
    mstack.pop();
    std::cout << "Size of mstack after pop: " << mstack.size() << std::endl; // Should be 4

    // Test case 6: Empty stack
    MutantStack<int> emptyStack;
    std::cout << "Is empty stack empty? " << (emptyStack.empty() ? "Yes" : "No") << std::endl; // Yes

    return 0;
}
