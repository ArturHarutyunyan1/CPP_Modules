#include "Base.hpp"

int main() {
    srand(static_cast<unsigned>(time(0)) + getpid());

    // Generate and identify 5 random instances using both identify functions
    for (int i = 0; i < 5; ++i) {
        Base* base = generate();
        std::cout << "Identify by pointer: ";
        identify(base);

        std::cout << "Identify by reference: ";
        identify(*base);

        delete base;
        std::cout << "------" << std::endl;
    }

    return 0;
}